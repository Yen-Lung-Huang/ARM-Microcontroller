/******************************************************************************
 * @file     main.c
 * @version  V1.00
 * @brief    A project template for M031 MCU.
 *
 * Copyright (C) 2017 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/
#include <stdio.h>
#include "uart_driver.h"
#include "flash.h"
#include "common.h"
#include "menu.h"
#include "ymodem.h"
#include "usart.h"
#include "systick.h"


u8 LogInfoCtl = TRUE;

 pFunction JumpToApplication;
 uint32_t JumpAddress;


/*
 * This is a template project for M031 series MCU. Users could based on this project to create their
 * own application without worry about the IAR/Keil project settings.
 *
 * This template application uses external crystal as HCLK source and configures UART0 to print out
 * "Hello World", users may need to do extra system configuration based on their system design.
 */

int main()
{
		SysTick_Configuration();
		Usart2_Init(57600);
		Usart1_Init(115200);
		Usart3_Init(115200);
		Main_Menu ();
		while(1)
		{
			
		}
}

void UserJumpToApplication(void)
{
  /* Test if user code is programmed starting from address "APPLICATION_ADDRESS" */
  if (((*(__IO uint32_t*)APPLICATION_ADDRESS) & 0x2FFE0000 ) == 0x20000000)
  {
    /* Jump to user application */
    JumpAddress = *(__IO uint32_t*) (APPLICATION_ADDRESS + 4);
    JumpToApplication = (pFunction) JumpAddress;
    /* Initialize user application's Stack Pointer */
    __set_MSP(*(__IO uint32_t*) APPLICATION_ADDRESS);
    JumpToApplication();
  }  
}

void UserJumpToBackupApplication(void)
{
  /* Test if user code is programmed starting from address "APPLICATION_ADDRESS" */
  if (((*(__IO uint32_t*)BACKUP_APPLICATION_ADDRESS) & 0x2FFE0000 ) == 0x20000000)
  {
    /* Jump to user application */
    JumpAddress = *(__IO uint32_t*) (BACKUP_APPLICATION_ADDRESS + 4);
    JumpToApplication = (pFunction) JumpAddress;
    /* Initialize user application's Stack Pointer */
    __set_MSP(*(__IO uint32_t*) BACKUP_APPLICATION_ADDRESS);
    JumpToApplication();
  }  
}
/*** (C) COPYRIGHT 2017 Nuvoton Technology Corp. ***/
