/**
  ******************************************************************************
 *
 * @file        Sample_TM00_Delay.c
 *
 * @brief       Delay time by TM00
 *
 * @par         Project
 *              MG32x02z
 * @version     V1.11
 * @date        2021/05/31
 * @author      Megawin Software Center
 * @copyright   Copyright (c) 2017 MegaWin Technology Co., Ltd.
 *              All rights reserved.
 *
 ******************************************************************************
* @par Disclaimer
 * The Demo software is provided "AS IS" without any warranty, either
 * expressed or implied, including, but not limited to, the implied warranties
 * of merchantability and fitness for a particular purpose. The author will
 * not be liable for any special, incidental, consequential or indirect
 * damages due to loss of data or any other reason.
 * These statements agree with the world wide and local dictated laws about
 * authorship and violence against these laws.
 *******************************************************************************
 *******************************************************************************
 */


/* Includes ------------------------------------------------------------------*/
#include "MG32x02z_TM_DRV.h"

/* Wizard menu ---------------------------------------------------------------*/
//*** <<< Use Configuration Wizard in Context Menu >>> ***

//  <h> Delay Period Setting 
//      <o0> Clock Prescaler (1~256)  <1-256>
//      <o1> Main Counter (1~256) <1-256>
//  </h>
#define Simple_Time_Prescaler       100
#define Simple_Time_MainCounter     120

//*** <<< end of configuration section >>>    ***

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Exported variables --------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
/* External vairables --------------------------------------------------------*/


/**
 *******************************************************************************
 * @brief	    Delay time until TOF happended
 * @details     1.initial & modify TimeBase parameter 
 *    \n        2.clear TOF flag
 *    \n        3.Start TM00 
 *    \n        4.until TOF flag event (polling)
 *    \n        5.Disable Timer
 * @note        if user wants to delay 1ms and CK_TM00_PR is 12MHz.
 *              The Total clocks is 12M*1ms = 12000.
 *              User can set "clock prescaler"=100 and "pulse width"=120 .               
 *******************************************************************************
 */
void Sample_TM00_Delay(void)
{  
    TM_TimeBaseInitTypeDef TM_TimeBase_InitStruct;
     

    // make sure :
	
    //===Set CSC init====
    //MG32x02z_CSC_Init.h(Configuration Wizard)
    //Select CK_HS source = CK_IHRCO
    //Select IHRCO = 12M
    //Select CK_MAIN Source = CK_HS
    //Configure PLL->Select APB Prescaler = CK_MAIN/1
    //Configure Peripheral On Mode Clock->TM00 = Enable
	
    // ----------------------------------------------------
    // 1.initial TimeBase structure 
    TM_TimeBaseStruct_Init(&TM_TimeBase_InitStruct);
    
    // modify parameter
    TM_TimeBase_InitStruct.TM_Period = Simple_Time_MainCounter - 1; 
    TM_TimeBase_InitStruct.TM_Prescaler = Simple_Time_Prescaler - 1;
    TM_TimeBase_InitStruct.TM_CounterMode = Cascade;
    
    TM_TimeBase_Init(TM00, &TM_TimeBase_InitStruct);
    
    // ----------------------------------------------------
    // 2.clear TOF flag
    TM_ClearFlag(TM00, TMx_TOF);
    
    // ----------------------------------------------------
    // 3.Start TM00 
    TM_Timer_Cmd(TM00, ENABLE);

    // ----------------------------------------------------
    // 4.until TOF flag event (polling)
    while(TM_GetSingleFlagStatus(TM00, TMx_TOF) == DRV_UnHappened);
    TM_ClearFlag(TM00, TMx_TOF);        // clear TOF flag
    
    // ----------------------------------------------------
    // 5.Disable Timer
	TM_Timer_Cmd(TM00, DISABLE);        // Stop TM00
    
    return;
}

