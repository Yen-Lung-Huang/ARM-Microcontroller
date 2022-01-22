/*******************************************************************************
* File Name          : uart_driver.c
* Author             : xuaige
* Description        : This file provides all the uart_driver functions.

* History:
* 2018/12/29 : version V1.00
*******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "uart_driver.h"
#include "usart.h"
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <ctype.h>
#include "ymodem.h"
#include "systick.h"

void DumpMem(char *Disp, unsigned char *pBuff, int size, u8 PrintFlag);

static u8   gMCUFirmwareUpgrade = FALSE;


__IO u8 USART1_RX_NUM = 0;
__IO u8 USART2_RX_NUM = 0;
__IO u8 USART3_RX_NUM = 0;
__IO u8 USART5_RX_NUM = 0;


__IO u16 Uart2RxCount = 0;
__IO u16 Uart1RxCount = 0;
__IO u16 Uart3RxCount = 0;
u8 Uart1RxBuffer[USART1_RX_BUFFER_SIZE] 	= {'\0'};
u8 Uart2RxBuffer[USART2_RX_BUFFER_SIZE] 	= {'\0'};
u8 Uart3RxBuffer[USART3_RX_BUFFER_SIZE] 	= {'\0'};
u8 Uart5RxBuffer[USART_BUF_MAX_LENGTH] 	= {'\0'};

static u8 ToUperChar( u8 ch )
{
   if( ch >='a' && ch <= 'z' )
			return (u8)( ch + ('A' - 'a') );
   return ch;
}

static void StringToUper(u8* s)
{
   int len = strlen((char *)s);
   int i;

   for(i = 0; i < len; i++)
	s[i] = ToUperChar(s[i]);

}

u32 Hexstring2int(u8* str, u16 dataLen, u8* des)
{
	u8 t[16];
	u16	idx;
	u8 var=0;
	
	// Check valid
	if( dataLen == 0)
		return FALSE;

	//strupr(str);
	StringToUper(str);

	for (idx = 0; idx < dataLen; idx++)
	{
		if (str[idx] >= 'A' && str[idx] <= 'F')
			t[idx] = str[idx] -55;
		else
			t[idx] = str[idx] -48;
	}

	for(idx = 0;idx < 8;idx++)
	{
		des[idx] = (t[2*idx]<<4) + t[2*idx+1];
	}
	return var;
} 

int strnicmp(const char *dst,const char *src,int count)
{
   int ch1, ch2;
   do
   {
      if (((ch1 = (unsigned char)(*(dst++))) >= 'A') &&(ch1 <= 'Z'))
        ch1 += 0x20;
      if (((ch2 = (unsigned char)(*(src++))) >= 'A') &&(ch2 <= 'Z'))
        ch2 += 0x20;
	  
   } while ( --count && ch1 && (ch1 == ch2) );
   return (ch1 - ch2);
}

u8 StringToInt(u8 *dataBuf, u16 dataLen, u16 *idxSearch, int *rtnInt)
{
	u16	idx;
	u16	numLen;
	u8	numString[12];

	// Check if buffer is Number first
	if( dataLen == 0 || !IS_NUMBER(dataBuf[0]) )
		return FALSE;

	numLen = 0;
	for ( idx = 0; idx < dataLen ; idx++)
	{
		if( dataBuf[idx]== ' ' )
		{
			continue;
		}else if( !IS_NUMBER(dataBuf[idx]) )
		{
			break;
		}else if( numLen == 10 )
		{
			return FALSE;
		}
		numString[numLen++] = dataBuf[idx];
	}
	numString[numLen] = 0x0;

	if( idxSearch )
		*idxSearch += idx;

	*rtnInt = atoi( (const char *)numString );
	return TRUE;
}

u16 NumString2Short(u8* str,u16 Len)
{
	u32 t;
	u16	idx;
	u16 var=0;
	
	// Check valid
	if( Len == 0)
		return FALSE;

	//strupr(str);
	StringToUper(str);

	for (idx = 0; idx < Len; idx++)
	{
		if (str[idx] >= '0' && str[idx] <= '9')
		{
			t = str[idx] -'0';
		}
		else
		{
			return FALSE;
		}

		var<<=4;
		var|=t;
	}
	return var;
}

void USART3ReceiveTimeoutTimerCallback(u8 Status)
{
	USART3_RX_NUM = TRUE;
}

void USART2ReceiveTimeoutTimerCallback(u8 Status)
{
	USART2_RX_NUM = TRUE;
}

void USART1ReceiveTimeoutTimerCallback(u8 Status)
{
	USART1_RX_NUM = TRUE;
}

void PutStrToUart1Dbg(char *string, u16 slen)
{	
//  HAL_USART_Transmit(&huart1, (u8*)string, slen, USART_SEND_DATA_TIMEOUT);
		Usart_SendString(USART1,(u8*)string, slen);
}
void PutStrToUart2Dbg(char *string, u16 slen)
{	
//  HAL_USART_Transmit(&huart1, (u8*)string, slen, USART_SEND_DATA_TIMEOUT);
		Usart_SendString(USART2,(u8*)string, slen);
}
void PutStrToUart3Dbg(char *string, u16 slen)
{	
//  HAL_USART_Transmit(&huart1, (u8*)string, slen, USART_SEND_DATA_TIMEOUT);
		Usart_SendString(USART3,(u8*)string, slen);
}
void PutStrToUart2Modem(u8 *string, u16 slen)
{
	// Do not allowed to send new instructions 
	// when system go into firmware upgrade mode
	if(gMCUFirmwareUpgrade == TRUE)
  {
		return;
  }
	Usart_SendString(USART1,(u8*)string, slen);
	
	// Print Out
	DumpMem("MODEM>>>", string, slen, LogInfoCtl);
}

void Serial_PutByte( uint8_t param )
{
		uint8_t  string[2];
		string[0]=param;
		Usart_SendString(USART1,(u8*)string, 1);
}
/***************************
´®¿Ú·¢ËÍ×Ö·û´®
***************************/
void IAP_SerialSendStr(char *string)
{
		while(*string!='\0')
		{
			//USART_DataSend(USART2,(u8*)string, 1);
			Usart_SendString(USART1,(u8*)string, 1);
			string++;
		}
}
uint32_t u32delayno;
/***************************
´®¿Ú½ÓÊÕ×Ö·û´®
***************************/
HAL_StatusTypeDef IAP_SerialGetStr(USART_TypeDef *USARTx, uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
		uint32_t  u32Count;
    uint32_t  u32Exit = 0ul;
	  for (u32Count = 0ul; u32Count < Size; u32Count++)
    {
        u32delayno = 0ul;

        while (!(USARTx->STR & USART_FLAG_RBNE))   /* Check RX empty => failed */
        {
             //u32delayno++;
            if (u32delayno >= Timeout)
            {
							  u32Exit = 1ul;
                break;
            }
        }

        if (u32Exit == 1ul)
        {
            return  HAL_TIMEOUT;
        }
        else
        {
            *pData++ = ( uint8_t) (USART_DataReceive(USARTx)); /* Get Data from UART RX  */
        }
    }
		return  HAL_OK;
}


int Seria1DbgPrintf(u8 type, char *fmt, ...)
{
	if(type != FALSE)
	{
		int cnt;
		char string[MAX_PRINTF_STR_SIZE + 2] = {'\0'};
		va_list ap;
		va_start(ap,fmt);
		//cnt = vsprintf(string, fmt, ap);
		cnt = vsnprintf(string,MAX_PRINTF_STR_SIZE ,fmt, ap);
		if(cnt > 0)
		{
			//PutStrToUart1Dbg(string,strlen((char *)string));
			if(cnt < MAX_PRINTF_STR_SIZE)
				PutStrToUart3Dbg(string,cnt);
			else
				PutStrToUart3Dbg(string,MAX_PRINTF_STR_SIZE);
		}
		va_end(ap);
	  return (cnt);
	}
	return -1;
}

char pucMessage[MAX_PRINTF_STR_SIZE];
void DumpMem(char *Disp, unsigned char *pBuff, int size, u8 PrintFlag)
{
	#define DUMP_LINE_MAX 8
	int i, j;
	long Address = (int) pBuff;
	int line = 0;

	int iCnt;
	int iPosn = 0;
	int iMax = sizeof(pucMessage);
	
	memset(pucMessage,0,sizeof(pucMessage));
	Seria1DbgPrintf(PrintFlag,"\r\n %s: [%d]",Disp, size);

	for (i = 0; i < size;)
	{
		iPosn = 0;
		for (j = 0; ((i + j) < size) && (j < DUMP_LINE_MAX); j++) 
		{
			if (((i + j) % DUMP_LINE_MAX) == 0) 
			{
				iCnt = snprintf(&pucMessage[iPosn], (iMax - iPosn), "\r\n%04lx: ", (long) Address + j);
				iPosn += iCnt;
			}
			iCnt = snprintf(&pucMessage[iPosn], (iMax - iPosn), "%02x ", pBuff[i + j]);
			iPosn += iCnt;
		}
		for (; j < DUMP_LINE_MAX; j++) 
		{
			iCnt = snprintf(&pucMessage[iPosn], (iMax - iPosn), "   ");
			iPosn += iCnt;
		}
		iCnt = snprintf(&pucMessage[iPosn], (iMax - iPosn), "  ");
		iPosn += iCnt;
		for (j = 0; ((i + j) < size) && (j < DUMP_LINE_MAX); j++) 
		{
			iCnt = snprintf(&pucMessage[iPosn], (iMax - iPosn), "%c ", isprint((int) pBuff[i + j]) ? pBuff[i + j] : '.');
			iPosn += iCnt;
		}

		Seria1DbgPrintf(PrintFlag,pucMessage);

		i += DUMP_LINE_MAX;
		Address += DUMP_LINE_MAX;
		line++;
	}
	Seria1DbgPrintf(PrintFlag,"\r\n");
}

/*******************************************************************************
End Of The File
*******************************************************************************/
