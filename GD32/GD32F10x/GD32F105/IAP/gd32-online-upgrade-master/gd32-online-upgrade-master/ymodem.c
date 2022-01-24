/*******************************************************************************
* File Name          : ymodem.c
* Author             : lizhifei
* Description        : This file provides all the ymodem functions.

* History:
* 2020/03/17 : version V1.00
*******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "ymodem.h"
#include "flash.h"
#include "uart_driver.h"
#include "menu.h"
#include "common.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
uint8_t aPacketData[PACKET_1K_SIZE + PACKET_DATA_INDEX + PACKET_TRAILER_SIZE];
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/* Public functions ---------------------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
uint16_t UpdateCRC16(uint16_t crc_in, uint8_t byte);
uint16_t Cal_CRC16(const uint8_t* p_data, uint32_t size);
uint8_t CalcChecksum(const uint8_t *p_data, uint32_t size);

/**
  * @brief  Receive a packet from sender
  * @param  data
  * @param  length
  *     0: end of transmission
  *     2: abort by sender
  *    >0: packet length
  * @param  timeout
  * @retval HAL_OK: normally return
  *         HAL_BUSY: abort by user
  */
static HAL_StatusTypeDef ReceivePacket(uint8_t *p_data, uint32_t *p_length, uint32_t timeout)
{
  uint32_t crc;
  uint32_t packet_size = 0;
  HAL_StatusTypeDef status;
  uint8_t char1;

  *p_length = 0;
  status = IAP_SerialGetStr(USART1, &char1, 1, timeout);

  if (status == HAL_OK)
  {
    switch (char1)
    {
      case SOH:
        packet_size = PACKET_SIZE;
//				Serial_PutString("SOH\r\n");
        break;
      case STX:
        packet_size = PACKET_1K_SIZE;
//				Serial_PutString("STX\r\n");
        break;
      case EOT:
//				Serial_PutString("EOT\r\n");
        break;
      case CA:
        if ((IAP_SerialGetStr(USART1, &char1, 1, timeout) == HAL_OK) && (char1 == CA))
        {
          packet_size = 2;
        }
        else
        {
          status = HAL_ERROR;
        }
//				Serial_PutString("CA\r\n");
        break;
      case ABORT1:
      case ABORT2:
        status = HAL_BUSY;
        break;
      default:
        status = HAL_ERROR;
        break;
    }
    *p_data = char1;
		
    if (packet_size >= PACKET_SIZE )
    {
      status = IAP_SerialGetStr(USART1, &p_data[PACKET_NUMBER_INDEX], packet_size + PACKET_OVERHEAD_SIZE, timeout);
      /* Simple packet sanity check */
      if (status == HAL_OK )
      {
        if (p_data[PACKET_NUMBER_INDEX] != ((p_data[PACKET_CNUMBER_INDEX]) ^ NEGATIVE_BYTE))
        {
          packet_size = 0;
          status = HAL_ERROR;
        }
        else
        {
          /* Check packet CRC */
          crc = p_data[ packet_size + PACKET_DATA_INDEX ] << 8;
          crc += p_data[ packet_size + PACKET_DATA_INDEX + 1 ];
          if (Cal_CRC16(&p_data[PACKET_DATA_INDEX], packet_size) != crc )
          {
            packet_size = 0;
            status = HAL_ERROR;
          }
        }
      }
      else
      {
        packet_size = 0;
      }
    }
		*p_length = packet_size;
  }
	else if(status == HAL_TIMEOUT)
	{
		status = HAL_TIMEOUT;
	}
  return status;
}


/**
  * @brief  Update CRC16 for input byte
  * @param  crc_in input value 
  * @param  input byte
  * @retval None
  */
uint16_t UpdateCRC16(uint16_t crc_in, uint8_t byte)
{
  uint32_t crc = crc_in;
  uint32_t in = byte | 0x100;

  do
  {
    crc <<= 1;
    in <<= 1;
    if(in & 0x100)
      ++crc;
    if(crc & 0x10000)
      crc ^= 0x1021;
  }
  
  while(!(in & 0x10000));

  return crc & 0xffffu;
}

/**
  * @brief  Cal CRC16 for YModem Packet
  * @param  data
  * @param  length
  * @retval None
  */
uint16_t Cal_CRC16(const uint8_t* p_data, uint32_t size)
{
  uint32_t crc = 0;
  const uint8_t* dataEnd = p_data+size;

  while(p_data < dataEnd)
    crc = UpdateCRC16(crc, *p_data++);
 
  crc = UpdateCRC16(crc, 0);
  crc = UpdateCRC16(crc, 0);

  return crc&0xffffu;
}

/**
  * @brief  Calculate Check sum for YModem Packet
  * @param  p_data Pointer to input data
  * @param  size length of input data
  * @retval uint8_t checksum value
  */
uint8_t CalcChecksum(const uint8_t *p_data, uint32_t size)
{
  uint32_t sum = 0;
  const uint8_t *p_data_end = p_data + size;

  while (p_data < p_data_end )
  {
    sum += *p_data++;
  }

  return (sum & 0xffu);
}


/**
  * @brief  Receive a file using the ymodem protocol with CRC16.
  * @param  p_size The size of the file.
  * @retval COM_StatusTypeDef result of reception/programming
  */
COM_StatusTypeDef Ymodem_Receive ( uint32_t *p_size )
{
  uint32_t i, packet_length, session_done = 0, file_done, errors = 0, session_begin = 0;
  uint32_t flashdestination, ramsource, filesize;
  uint8_t *file_ptr;
  uint8_t file_size[FILE_SIZE_LENGTH], packets_received;
//	uint8_t Serial[3];
  COM_StatusTypeDef result = COM_OK;
	//uint32_t cnt;
  /* Initialize flashdestination variable */
  flashdestination = APPLICATION_ADDRESS;

  while ((session_done == 0) && (result == COM_OK))
  {
    packets_received = 0;
    file_done = 0;
    while ((file_done == 0) && (result == COM_OK))
    {
      switch (ReceivePacket(aPacketData, &packet_length, DOWNLOAD_TIMEOUT))//超时时间1S
      {
				
        case HAL_OK:
				Seria1DbgPrintf(LogInfoCtl,"\r\n ReceivePacket: HAL_OK");
		  //TickHardwareWatchdog();
          errors = 0;
          switch (packet_length)
          {
            case 2:
              /* Abort by sender */
							Seria1DbgPrintf(LogInfoCtl,"\r\n Abort by sender ");
              Serial_PutByte(ACK);
              result = COM_ABORT;
              break;
            case 0:
              /* End of transmission */
						  Seria1DbgPrintf(LogInfoCtl,"\r\n  End of transmission");
              Serial_PutByte(ACK);
              file_done = 1;
              break;
            default:						
              /* Normal packet */
							Seria1DbgPrintf(LogInfoCtl,"\r\n  Normal packet \r\n ");
              if (aPacketData[PACKET_NUMBER_INDEX] != packets_received)
              {
                Serial_PutByte(NAK); 
              }
              else
              {								
                if (packets_received == 0)  //第一包数据  文件名 文件长度
                {									
                  /* File name packet */
                  if (aPacketData[PACKET_DATA_INDEX] != 0)   //文件名
                  {
                    /* File name extraction */
                    i = 0;
                    file_ptr = aPacketData + PACKET_DATA_INDEX;
                    while ( (*file_ptr != 0) && (i < FILE_NAME_LENGTH))
                    {
                      aFileName[i++] = *file_ptr++;
                    }

                    /* File size extraction */
                    aFileName[i++] = '\0';							
										
                    i = 0;
                    file_ptr ++;
                    while ( (*file_ptr != ' ') && (*file_ptr != 0) && (i < FILE_SIZE_LENGTH))
                    {
                      file_size[i++] = *file_ptr++;
                    }
                    file_size[i++] = '\0';
										
                    Str2Int(file_size, &filesize);

                    /* Test the size of the image to be sent */
                    /* Image size is greater than Flash size */
                    if (*p_size > (USER_FLASH_SIZE + 1))//??unkown
                    {
                      /* End session */
                      //tmp = CA;
                      Serial_PutByte(CA);//HAL_UART_Transmit(&huart2, &tmp, 1, NAK_TIMEOUT);
                      Serial_PutByte(CA);//HAL_UART_Transmit(&huart2, &tmp, 1, NAK_TIMEOUT);
                      result = COM_LIMIT;
                    }
                    /* erase user application area */
                    FLASH_If_Erase(APPLICATION_ADDRESS,USER_FLASH_END_ADDRESS);
                    *p_size = filesize;

                    Serial_PutByte(ACK);
                    Serial_PutByte(CRC16);
										Seria1DbgPrintf(LogInfoCtl,"\r\n  START YMODEM");
										
                  }
                  /* File header packet is empty, end session */
                  else
                  {
                    Serial_PutByte(ACK);
                    file_done = 1;
                    session_done = 1;
                    break;
                  }
                }
                else /* Data packet */   
                {
                  ramsource = (uint32_t) & aPacketData[PACKET_DATA_INDEX];

                  /* Write received data in Flash */
                  if (FLASH_If_Write(flashdestination, (uint32_t*) ramsource, packet_length/4) == FLASHIF_OK)                   
                  {
                    flashdestination += packet_length;
                    Serial_PutByte(ACK);
                  }
                  else /* An error occurred while writing to Flash memory */
                  {
                    /* End session */
                    Serial_PutByte(CA);
                    Serial_PutByte(CA);
                    result = COM_DATA;
                  }
                }
                packets_received ++;
                session_begin = 1;
              }
              break;
          }
          break;
        case HAL_BUSY: /* Abort actually */
          Serial_PutByte(CA);
          Serial_PutByte(CA);
				
          result = COM_ABORT;
          break;
        default: //超时
				Seria1DbgPrintf(LogInfoCtl,"\r\n ReceivePacket: TIMEOUT");	
          if (session_begin > 0)
          {
            errors ++;
          }
          if (errors > MAX_ERRORS)
					{
							/* Abort communication */
							Serial_PutByte(CA);
							Serial_PutByte(CA);
				      result = COM_ABORT;
          }
          else
          {
            Serial_PutByte(CRC16); /* Ask for a packet */
          }
          break;
      }
    }
  }
  return result;
}

