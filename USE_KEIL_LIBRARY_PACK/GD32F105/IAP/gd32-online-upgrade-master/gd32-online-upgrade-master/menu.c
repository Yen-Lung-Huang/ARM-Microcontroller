/*******************************************************************************
* File Name          : menu.c
* Author             : lizhifei
* Description        : This file provides all the menu functions.

* History:
* 2021/02/03 : version V1.00
*******************************************************************************/
/* Includes ------------------------------------------------------------------*/

#include "main.h"

#include "systick.h"

#include "uart_driver.h"
#include "usart.h"
#include "ymodem.h"
#include "menu.h"
#include "flash.h"
#include "common.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
//uint32_t JumpAddress;
uint32_t FlashProtection = 0;
uint8_t aFileName[FILE_NAME_LENGTH];
extern __IO uint32_t MsCnt;


/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

void SerialDownload(void)
{
  uint8_t number[11] = {0};
  uint32_t size = 0;
  COM_StatusTypeDef result;

  Seria1DbgPrintf(LogInfoCtl,"Waiting for the file to be sent ... (press 'a' to abort)\n\r");
  result = Ymodem_Receive( &size );
  if (result == COM_OK)
  {
    Seria1DbgPrintf(LogInfoCtl,"\n\n\r Programming Completed Successfully!\n\r--------------------------------\r\n Name: ");
    Seria1DbgPrintf(LogInfoCtl,"%s",aFileName);
    Int2Str(number, size);
    Seria1DbgPrintf(LogInfoCtl,"\n\r Size: ");
    Seria1DbgPrintf(LogInfoCtl,"%d",number);
    Seria1DbgPrintf(LogInfoCtl," Bytes\r\n");
    Seria1DbgPrintf(LogInfoCtl,"-------------------\n");
		WriteIAPFlagToFlashMemory(0);//升级完成
    UserJumpToApplication();
  }
  else if (result == COM_LIMIT)
  {
    Seria1DbgPrintf(LogInfoCtl,"\n\n\rThe image size is higher than the allowed space memory!\n\r");
  }
  else if (result == COM_DATA)
  {
    Seria1DbgPrintf(LogInfoCtl,"\n\n\rVerification failed!\n\r");
  }
  else if (result == COM_ABORT)
  {
    Seria1DbgPrintf(LogInfoCtl,"\r\n\nAborted by user.\n\r");
  }
  else
  {
    Seria1DbgPrintf(LogInfoCtl,"\n\rFailed to receive the file!\n\r");
  }	
	//UserJumpToBackupApplication();
	
}

/*
  * @brief  Display the Main Menu on HyperTerminal
  * @param  None
  * @retval None
  */
void Main_Menu(void)
{

	Delay_1ms(500);
	FlashProtection=FlashMemoryOneByteRead(MCU_OTA_ADDRESS);
	
//	SerialDownload();
	if(FlashMemoryOneByteRead(MCU_OTA_ADDRESS)==1)  //开始OTA
	{
		
		Seria1DbgPrintf(LogInfoCtl,"\r\n Canature Bootloader");
		Seria1DbgPrintf(LogInfoCtl,"\r\n Author : lizhifei");
		Seria1DbgPrintf(LogInfoCtl,"\r\n Date : 2021-02-02");
		Seria1DbgPrintf(LogInfoCtl,"\r\n\r\n");
		Seria1DbgPrintf(LogInfoCtl,"\r\n MCU_OTA_ADDRESS : %d",FlashProtection);
		Seria1DbgPrintf(LogInfoCtl,"\r\n Start OTA\r\n");
		Delay_1ms(500);
		WriteIAPFlagToFlashMemory(0); //如果升级失败跳转到Backup APPlication

		while (1)
		{
			/* Download user application in the Flash */
			SerialDownload();
		}
	}
	else if(FlashMemoryOneByteRead(MCU_OTA_ADDRESS)==2)  //跳转到User APPlication
	{
//		Seria1DbgPrintf(LogInfoCtl,"\r\n Jump To Application\r\n");
		Delay_1ms(500);
		UserJumpToApplication();		
	}
	else //跳转到Backup APPlication
	{
		
//		Seria1DbgPrintf(LogInfoCtl,"\r\n Jump To Backup Application\r\n");
		Delay_1ms(500);
//		UserJumpToApplication();
		UserJumpToBackupApplication();
		NVIC_SystemReset();
	}
}
	

