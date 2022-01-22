

/**
 ******************************************************************************
 *
 * @file        main.C
 * @brief       MG32x02z demo main c Code. 
 *
 * @par         Project
 *              MG32x02z
 * @version     V1.01
 * @date        2021/05/31
 * @author      Megawin Software Center
 * @copyright   Copyright (c) 2017 MegaWin Technology Co., Ltd.
 *              All rights reserved.
 *
 ******************************************************************************* 
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
#include "MG32x02z_DRV.h"
#include "MG32x02z_ChipInit.h"

/* Wizard menu ---------------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#if defined(MG32_2ND)
    #define MG_EB_LED1SET  PIND(8)
    #define MG_EB_LED2SET  PIND(9)
    #define MG_EB_LED3SET  PIND(10)

    #define MG_EB_LED1     PD8
    #define MG_EB_LED2     PD9
    #define MG_EB_LED3     PD10
#endif
#if defined(MG32_1ST) || defined(MG32_3RD)
    #define MG_EB_LED1     PE13
    #define MG_EB_LED2     PE14
    #define MG_EB_LED3     PE15
    
    #define MG_EB_LED1SET  PINE(13)
    #define MG_EB_LED2SET  PINE(14)
    #define MG_EB_LED3SET  PINE(15)
#endif

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
void Sample_TM00_Delay(void);

/* Exported variables --------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
/* External vairables --------------------------------------------------------*/



int main()
{    
    uint16_t CNT;
    PIN_InitTypeDef        PINX_InitStruct;
    
    // ------------------------------------------------------------------------
    // chip initial (User can enable CSC, GPIO, TM, ADC, EXIC ... wizard)
    // ------------------------------------------------------------------------
    ChipInit();
        
    //============================================
    PINX_InitStruct.PINX_Mode               = PINX_Mode_PushPull_O;
    PINX_InitStruct.PINX_PUResistant        = PINX_PUResistant_Enable;
    PINX_InitStruct.PINX_Speed              = PINX_Speed_Low;
    PINX_InitStruct.PINX_OUTDrive           = PINX_OUTDrive_Level0;
    PINX_InitStruct.PINX_FilterDivider      = PINX_FilterDivider_Bypass;
    PINX_InitStruct.PINX_Inverse            = PINX_Inverse_Disable;
    PINX_InitStruct.PINX_Alternate_Function = 0;

    GPIO_PinMode_Config(MG_EB_LED1SET,&PINX_InitStruct);
    GPIO_PinMode_Config(MG_EB_LED2SET,&PINX_InitStruct);
    GPIO_PinMode_Config(MG_EB_LED3SET,&PINX_InitStruct);
    
    while(1)
    {
        //To do......
        
        MG_EB_LED1 = 0; MG_EB_LED2 = 1; MG_EB_LED3 = 1;
        for(CNT=0;CNT<500;CNT++)        // delay 0.5sec
            Sample_TM00_Delay();
            
        MG_EB_LED1 = 1; MG_EB_LED2 = 0; MG_EB_LED3 = 1;
        for(CNT=0;CNT<500;CNT++)        // delay 0.5sec
            Sample_TM00_Delay();
            
        MG_EB_LED1 = 1; MG_EB_LED2 = 1; MG_EB_LED3 = 0;
        for(CNT=0;CNT<500;CNT++)        // delay 0.5sec
            Sample_TM00_Delay();
    }
}




















