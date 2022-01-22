

/**
 ******************************************************************************
 *
 * @file        MG32x02z_ChipInit.c
 * @brief       The demo ChipInit C file.
 *
 * @par         Project
 *              MG32x02z
 * @version     V1.18
 * @date        2022/01/11
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
#include "MG32x02z_ChipInit.h"
#include "MG32x02z.h"

/* Wizard menu ---------------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Exported variables --------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
/* External vairables --------------------------------------------------------*/

/*
 *******************************************************************************
 * @brief	    Chip initial.  
 * @details     Run the chip initialization wizard and enable module interrupts/
 *              priorities. 
 * @return      None
 *******************************************************************************
 */
void ChipInit(void)
{
    
    
    // ============= Module ConfigurWizard Table    =============
    
    // PW ConfigerWizard Table
    #ifdef MG32x02z_ConfigerWizard_PW
        PW_Init();
    #endif
    
    // CSC ConfigerWizard Table
    #ifdef MG32x02z_ConfigerWizard_CSC
        CSC_Init((uint32_t *) &CSC_InitConfig);
    #endif
    
    // RST ConfigerWizard Table
    #ifdef MG32x02z_ConfigerWizard_RST
        RST_Init();
    #endif
    
    // GPIO ConfigerWizard Table
    #ifdef MG32x02z_ConfigerWizard_GPIO
        GPIO_Init();
    #endif
    
    // TM ConfigerWizard Table
    #ifdef MG32x02z_ConfigerWizard_TM
        TM_Init();
    #endif
    
    // EXIC ConfigerWizard Table
    #ifdef MG32x02z_ConfigerWizard_EXIC
        EXIC_Init();
    #endif
        
    // EMB ConfigerWizard Table
    #ifdef MG32x02z_ConfigerWizard_EMB
        EMB_Initial();
    #endif
    
    // MEM ConfigerWizard Table
    #ifdef MG32x02z_ConfigerWizard_MEM
        MEM_Init();
    #endif
    
    // GPL ConfigerWizard Table
    #ifdef MG32x02z_ConfigerWizard_GPL
        GPL_Init();
    #endif
    
    // URT ConfigerWizard Table
    #ifdef MG32x02z_ConfigerWizard_URT
        URT_Init();
    #endif
    
    // ADC ConfigerWizard Table
    #ifdef MG32x02z_ConfigerWizard_ADC
        ADC_Init();
    #endif
    
    // DAC ConfigerWizard Table
    #ifdef MG32x02z_ConfigerWizard_DAC
        DAC_Init();
    #endif
    
    // CMP ConfigerWizard Table
    #ifdef MG32x02z_ConfigerWizard_CMP
        CMP_ACx_Init();
    #endif
    
    // APB ConfigerWizard Table
    #ifdef MG32x02z_ConfigerWizard_APB
        APB_Init();
    #endif
    
    // APX CCL ConfigerWizard Table
    #ifdef MG32x02z_ConfigerWizard_APX_CCL
        APX_CCL_Init();
    #endif
        
    // RTC ConfigerWizard Table
    #ifdef MG32x02z_ConfigerWizard_RTC
        RTC_Init();
    #endif
        
    // ============= Enable NVIC interrupt (Control by IRQ_Handler) =============
    // WWDT : Config interrupt priority
    #if defined(MG32x02z_WWDT_IRQ_)
        NVIC_EnableIRQ(WWDT_IRQn); 
        // IRQ priority configuration
        #if defined(MG32x02z_WWDT_IRQ_Priority0)
            NVIC_SetPriority(WWDT_IRQn, 0x0);
        #elif defined(MG32x02z_WWDT_IRQ_Priority1)
            NVIC_SetPriority(WWDT_IRQn, 0x1);
        #elif defined(MG32x02z_WWDT_IRQ_Priority2)
            NVIC_SetPriority(WWDT_IRQn, 0x2);
        #elif defined(MG32x02z_WWDT_IRQ_Priority3)
            NVIC_SetPriority(WWDT_IRQn, 0x3);
        #endif
    #endif
    
    // SYS : Config interrupt priority
    #if defined(MG32x02z_SYS_IRQ_)
        NVIC_EnableIRQ(SYS_IRQn); 
        // IRQ priority configuration
        #if defined(MG32x02z_SYS_IRQ_Priority0)
            NVIC_SetPriority(SYS_IRQn, 0x0);
        #elif defined(MG32x02z_SYS_IRQ_Priority1)
            NVIC_SetPriority(SYS_IRQn, 0x1);
        #elif defined(MG32x02z_SYS_IRQ_Priority2)
            NVIC_SetPriority(SYS_IRQn, 0x2);
        #elif defined(MG32x02z_SYS_IRQ_Priority3)
            NVIC_SetPriority(SYS_IRQn, 0x3);
        #else
            NVIC_SetPriority(SYS_IRQn, 0x0);
        #endif
    #endif
    
    // EXINT0 : Config interrupt priority
    #if defined(MG32x02z_EXINT0_IRQ_)
        NVIC_EnableIRQ(EXINT0_IRQn); 
        // IRQ priority configuration
        #if defined(MG32x02z_EXINT0_IRQ_Priority0)
            NVIC_SetPriority(EXINT0_IRQn, 0x0);
        #elif defined(MG32x02z_EXINT0_IRQ_Priority1)
            NVIC_SetPriority(EXINT0_IRQn, 0x1);
        #elif defined(MG32x02z_EXINT0_IRQ_Priority2)
            NVIC_SetPriority(EXINT0_IRQn, 0x2);
        #elif defined(MG32x02z_EXINT0_IRQ_Priority3)
            NVIC_SetPriority(EXINT0_IRQn, 0x3);
        #endif
    #endif
    
    // EXINT1 : Config interrupt priority
    #if defined(MG32x02z_EXINT1_IRQ_)
        NVIC_EnableIRQ(EXINT1_IRQn);
        // IRQ priority configuration
        #if defined(MG32x02z_EXINT1_IRQ_Priority0)
            NVIC_SetPriority(EXINT1_IRQn, 0x0);
        #elif defined(MG32x02z_EXINT1_IRQ_Priority1)
            NVIC_SetPriority(EXINT1_IRQn, 0x1);
        #elif defined(MG32x02z_EXINT1_IRQ_Priority2)
            NVIC_SetPriority(EXINT1_IRQn, 0x2);
        #elif defined(MG32x02z_EXINT1_IRQ_Priority3)
            NVIC_SetPriority(EXINT1_IRQn, 0x3);
        #endif
    #endif 
    
    // EXINT2 : Config interrupt priority
    #if defined(MG32x02z_EXINT2_IRQ_)
        NVIC_EnableIRQ(EXINT2_IRQn); 
        // IRQ priority configuration
        #if defined(MG32x02z_EXINT2_IRQ_Priority0)
            NVIC_SetPriority(EXINT2_IRQn, 0x0);
        #elif defined(MG32x02z_EXINT2_IRQ_Priority1)
            NVIC_SetPriority(EXINT2_IRQn, 0x1);
        #elif defined(MG32x02z_EXINT2_IRQ_Priority2)
            NVIC_SetPriority(EXINT2_IRQn, 0x2);
        #elif defined(MG32x02z_EXINT2_IRQ_Priority3)
            NVIC_SetPriority(EXINT2_IRQn, 0x3);
        #endif
    #endif
    
    // EXINT3 : Config interrupt priority
    #if defined(MG32x02z_EXINT3_IRQ_)
        NVIC_EnableIRQ(EXINT3_IRQn);
        // IRQ priority configuration
        #if defined(MG32x02z_EXINT3_IRQ_Priority0)
            NVIC_SetPriority(EXINT3_IRQn, 0x0);
        #elif defined(MG32x02z_EXINT3_IRQ_Priority1)
            NVIC_SetPriority(EXINT3_IRQn, 0x1);
        #elif defined(MG32x02z_EXINT3_IRQ_Priority2)
            NVIC_SetPriority(EXINT3_IRQn, 0x2);
        #elif defined(MG32x02z_EXINT3_IRQ_Priority3)
            NVIC_SetPriority(EXINT3_IRQn, 0x3);
        #endif
    #endif 
    
    // COMP : Config interrupt priority
    #if defined(MG32x02z_COMP_IRQ_)
        NVIC_EnableIRQ(COMP_IRQn);
        // IRQ priority configuration
        #if defined(MG32x02z_COMP_IRQ_Priority0)
            NVIC_SetPriority(COMP_IRQn, 0x0);
        #elif defined(MG32x02z_COMP_IRQ_Priority1)
            NVIC_SetPriority(COMP_IRQn, 0x1);
        #elif defined(MG32x02z_COMP_IRQ_Priority2)
            NVIC_SetPriority(COMP_IRQn, 0x2);
        #elif defined(MG32x02z_COMP_IRQ_Priority3)
            NVIC_SetPriority(COMP_IRQn, 0x3);
        #endif
    #endif 
    
    // DMA : Config interrupt priority
    #if defined(MG32x02z_DMA_IRQ_)
        NVIC_EnableIRQ(DMA_IRQn); 
        // IRQ priority configuration
        #if defined(MG32x02z_DMA_IRQ_Priority0)
            NVIC_SetPriority(DMA_IRQn, 0x0);
        #elif defined(MG32x02z_DMA_IRQ_Priority1)
            NVIC_SetPriority(DMA_IRQn, 0x1);
        #elif defined(MG32x02z_DMA_IRQ_Priority2)
            NVIC_SetPriority(DMA_IRQn, 0x2);
        #elif defined(MG32x02z_DMA_IRQ_Priority3)
            NVIC_SetPriority(DMA_IRQn, 0x3);
        #endif
    #endif
    
    // ADC : Config interrupt priority
    #if defined(MG32x02z_ADC_IRQ_) 
        NVIC_EnableIRQ(ADC_IRQn); 
        // IRQ priority configuration
        #if defined(MG32x02z_ADC_IRQ_Priority0)
            NVIC_SetPriority(ADC_IRQn, 0x0);
        #elif defined(MG32x02z_ADC_IRQ_Priority1)
            NVIC_SetPriority(ADC_IRQn, 0x1);
        #elif defined(MG32x02z_ADC_IRQ_Priority2)
            NVIC_SetPriority(ADC_IRQn, 0x2);
        #elif defined(MG32x02z_ADC_IRQ_Priority3)
            NVIC_SetPriority(ADC_IRQn, 0x3);
        #endif
    #endif
    
    // DAC : Config interrupt priority
    #if defined(MG32x02z_DAC_IRQ_)
        NVIC_EnableIRQ(DAC_IRQn);
        // IRQ priority configuration
        #if defined(MG32x02z_DAC_IRQ_Priority0)
            NVIC_SetPriority(DAC_IRQn, 0x0);
        #elif defined(MG32x02z_DAC_IRQ_Priority1)
            NVIC_SetPriority(DAC_IRQn, 0x1);
        #elif defined(MG32x02z_DAC_IRQ_Priority2)
            NVIC_SetPriority(DAC_IRQn, 0x2);
        #elif defined(MG32x02z_DAC_IRQ_Priority3)
            NVIC_SetPriority(DAC_IRQn, 0x3);
        #endif
    #endif
    
    // TM0x : Config interrupt priority
    #if defined(MG32x02z_TM0x_IRQ_)
        NVIC_EnableIRQ(TM0x_IRQn); 
        // IRQ priority configuration
        #if defined(MG32x02z_TM0x_IRQ_Priority0)
            NVIC_SetPriority(TM0x_IRQn, 0x0);
        #elif defined(MG32x02z_TM0x_IRQ_Priority1)
            NVIC_SetPriority(TM0x_IRQn, 0x1);
        #elif defined(MG32x02z_TM0x_IRQ_Priority2)
            NVIC_SetPriority(TM0x_IRQn, 0x2);
        #elif defined(MG32x02z_TM0x_IRQ_Priority3)
            NVIC_SetPriority(TM0x_IRQn, 0x3);
        #else
            NVIC_SetPriority(TM0x_IRQn, 0x0);
        #endif
    #endif
    
    // TM10 : Config interrupt priority
    #if defined(MG32x02z_TM10_IRQ_)
        NVIC_EnableIRQ(TM10_IRQn);
        // IRQ priority configuration
        #if defined(MG32x02z_TM10_IRQ_Priority0)
            NVIC_SetPriority(TM10_IRQn, 0x0);
        #elif defined(MG32x02z_TM10_IRQ_Priority1)
            NVIC_SetPriority(TM10_IRQn, 0x1);
        #elif defined(MG32x02z_TM10_IRQ_Priority2)
            NVIC_SetPriority(TM10_IRQn, 0x2);
        #elif defined(MG32x02z_TM10_IRQ_Priority3)
            NVIC_SetPriority(TM10_IRQn, 0x3);
        #endif
    #endif 
    
    // TM1x : Config interrupt priority
    #if defined(MG32x02z_TM1x_IRQ_)
        NVIC_EnableIRQ(TM1x_IRQn);
        // IRQ priority configuration
        #if defined(MG32x02z_TM1x_IRQ_Priority0)
            NVIC_SetPriority(TM1x_IRQn, 0x0);
        #elif defined(MG32x02z_TM1x_IRQ_Priority1)
            NVIC_SetPriority(TM1x_IRQn, 0x1);
        #elif defined(MG32x02z_TM1x_IRQ_Priority2)
            NVIC_SetPriority(TM1x_IRQn, 0x2);
        #elif defined(MG32x02z_TM1x_IRQ_Priority3)
            NVIC_SetPriority(TM1x_IRQn, 0x3);
        #endif
    #endif 
    
    // TM20 : Config interrupt priority
    #if defined(MG32x02z_TM20_IRQ_)
        NVIC_EnableIRQ(TM20_IRQn); 
        // IRQ priority configuration
        #if defined(MG32x02z_TM20_IRQ_Priority0)
            NVIC_SetPriority(TM20_IRQn, 0x0);
        #elif defined(MG32x02z_TM20_IRQ_Priority1)
            NVIC_SetPriority(TM20_IRQn, 0x1);
        #elif defined(MG32x02z_TM20_IRQ_Priority2)
            NVIC_SetPriority(TM20_IRQn, 0x2);
        #elif defined(MG32x02z_TM20_IRQ_Priority3)
            NVIC_SetPriority(TM20_IRQn, 0x3);
        #endif
    #endif
    
    // TM2x : Config interrupt priority
    #if defined(MG32x02z_TM2x_IRQ_)
        NVIC_EnableIRQ(TM2x_IRQn); 
        // IRQ priority configuration
        #if defined(MG32x02z_TM2x_IRQ_Priority0)
            NVIC_SetPriority(TM2x_IRQn, 0x0);
        #elif defined(MG32x02z_TM2x_IRQ_Priority1)
            NVIC_SetPriority(TM2x_IRQn, 0x1);
        #elif defined(MG32x02z_TM2x_IRQ_Priority2)
            NVIC_SetPriority(TM2x_IRQn, 0x2);
        #elif defined(MG32x02z_TM2x_IRQ_Priority3)
            NVIC_SetPriority(TM2x_IRQn, 0x3);
        #endif
    #endif
    
    // TM3x : Config interrupt priority
    #if defined(MG32x02z_TM3x_IRQ_)
        NVIC_EnableIRQ(TM3x_IRQn); 
        // IRQ priority configuration
        #if defined(MG32x02z_TM3x_IRQ_Priority0)
            NVIC_SetPriority(TM3x_IRQn, 0x0);
        #elif defined(MG32x02z_TM3x_IRQ_Priority1)
            NVIC_SetPriority(TM3x_IRQn, 0x1);
        #elif defined(MG32x02z_TM3x_IRQ_Priority2)
            NVIC_SetPriority(TM3x_IRQn, 0x2);
        #elif defined(MG32x02z_TM3x_IRQ_Priority3)
            NVIC_SetPriority(TM3x_IRQn, 0x3);
        #endif
    #endif
    
    // URT0 : Config interrupt priority
    #if defined(MG32x02z_URT0_IRQ_)
        NVIC_EnableIRQ(URT0_IRQn);
        // IRQ priority configuration
        #if defined(MG32x02z_URT0_IRQ_Priority0)
            NVIC_SetPriority(URT0_IRQn, 0x0);
        #elif defined(MG32x02z_URT0_IRQ_Priority1)
            NVIC_SetPriority(URT0_IRQn, 0x1);
        #elif defined(MG32x02z_URT0_IRQ_Priority2)
            NVIC_SetPriority(URT0_IRQn, 0x2);
        #elif defined(MG32x02z_URT0_IRQ_Priority3)
            NVIC_SetPriority(URT0_IRQn, 0x3);
        #endif
    #endif   
    
    // URT123 : Config interrupt priority
    #if defined(MG32x02z_URT123_IRQ_)
        NVIC_EnableIRQ(URT123_IRQn);
        // IRQ priority configuration
        #if defined(MG32x02z_URT123_IRQ_Priority0)
            NVIC_SetPriority(URT123_IRQn, 0x0);
        #elif defined(MG32x02z_URT123_IRQ_Priority1)
            NVIC_SetPriority(URT123_IRQn, 0x1);
        #elif defined(MG32x02z_URT123_IRQ_Priority2)
            NVIC_SetPriority(URT123_IRQn, 0x2);
        #elif defined(MG32x02z_URT123_IRQ_Priority3)
            NVIC_SetPriority(URT123_IRQn, 0x3);
        #else
            NVIC_SetPriority(URT123_IRQn, 0x0);
        #endif
    #endif 
    
    // URT4x : Config interrupt priority
    #if defined(MG32x02z_URT4x_IRQ_)
        NVIC_EnableIRQ(URT4x_IRQn);
        // IRQ priority configuration
        #if defined(MG32x02z_URT4x_IRQ_Priority0)
            NVIC_SetPriority(URT4x_IRQn, 0x0);
        #elif defined(MG32x02z_URT4x_IRQ_Priority1)
            NVIC_SetPriority(URT4x_IRQn, 0x1);
        #elif defined(MG32x02z_URT4x_IRQ_Priority2)
            NVIC_SetPriority(URT4x_IRQn, 0x2);
        #elif defined(MG32x02z_URT4x_IRQ_Priority3)
            NVIC_SetPriority(URT4x_IRQn, 0x3);
        #else
            NVIC_SetPriority(URT4x_IRQn, 0x0);
        #endif
    #endif     
    
    // SPI0 : Config interrupt priority
    #if defined(MG32x02z_SPI0_IRQ_)
        NVIC_EnableIRQ(SPI0_IRQn);
        // IRQ priority configuration
        #if defined(MG32x02z_SPI0_IRQ_Priority0)
            NVIC_SetPriority(SPI0_IRQn, 0x0);
        #elif defined(MG32x02z_SPI0_IRQ_Priority1)
            NVIC_SetPriority(SPI0_IRQn, 0x1);
        #elif defined(MG32x02z_SPI0_IRQ_Priority2)
            NVIC_SetPriority(SPI0_IRQn, 0x2);
        #elif defined(MG32x02z_SPI0_IRQ_Priority3)
            NVIC_SetPriority(SPI0_IRQn, 0x3);
        #endif
    #endif 
    
    // I2C0 : Config interrupt priority
    #if defined(MG32x02z_I2C0_IRQ_)
        NVIC_EnableIRQ(I2C0_IRQn);
        // IRQ priority configuration
        #if defined(MG32x02z_I2C0_IRQ_Priority0)
            NVIC_SetPriority(I2C0_IRQn, 0x0);
        #elif defined(MG32x02z_I2C0_IRQ_Priority1)
            NVIC_SetPriority(I2C0_IRQn, 0x1);
        #elif defined(MG32x02z_I2C0_IRQ_Priority2)
            NVIC_SetPriority(I2C0_IRQn, 0x2);
        #elif defined(MG32x02z_I2C0_IRQ_Priority3)
            NVIC_SetPriority(I2C0_IRQn, 0x3);
        #endif
    #endif 
    
    // I2Cx : Config interrupt priority
    #if defined(MG32x02z_I2Cx_IRQ_)
        NVIC_EnableIRQ(I2Cx_IRQn); 
        // IRQ priority configuration
        #if defined(MG32x02z_I2Cx_IRQ_Priority0)
            NVIC_SetPriority(I2Cx_IRQn, 0x0);
        #elif defined(MG32x02z_I2Cx_IRQ_Priority1)
            NVIC_SetPriority(I2Cx_IRQn, 0x1);
        #elif defined(MG32x02z_I2Cx_IRQ_Priority2)
            NVIC_SetPriority(I2Cx_IRQn, 0x2);
        #elif defined(MG32x02z_I2Cx_IRQ_Priority3)
            NVIC_SetPriority(I2Cx_IRQn, 0x3);
        #endif
    #endif  
    
    // USB : Config interrupt priority
	#if defined(MG32x02z_USB_IRQ_)
        NVIC_EnableIRQ(USB_IRQn);
        // IRQ priority configuration
        #if defined(MG32x02z_USB_IRQ_Priority0)
            NVIC_SetPriority(USB_IRQn, 0x0);
        #elif defined(MG32x02z_USB_IRQ_Priority1)
            NVIC_SetPriority(USB_IRQn, 0x1);
        #elif defined(MG32x02z_USB_IRQ_Priority2)
            NVIC_SetPriority(USB_IRQn, 0x2);
        #elif defined(MG32x02z_USB_IRQ_Priority3)
            NVIC_SetPriority(USB_IRQn, 0x3);
        #endif
    #endif 	
    
    // APX : Config interrupt priority
	#if defined(MG32x02z_APX_IRQ_)
        NVIC_EnableIRQ(APX_IRQn);
        // IRQ priority configuration
        #if defined(MG32x02z_APX_IRQ_Priority0)
            NVIC_SetPriority(APX_IRQn, 0x0);
        #elif defined(MG32x02z_APX_IRQ_Priority1)
            NVIC_SetPriority(APX_IRQn, 0x1);
        #elif defined(MG32x02z_APX_IRQ_Priority2)
            NVIC_SetPriority(APX_IRQn, 0x2);
        #elif defined(MG32x02z_APX_IRQ_Priority3)
            NVIC_SetPriority(APX_IRQn, 0x3);
        #endif
    #endif 
    
    // Systick: Only config IRQ priority
    #if defined(MG32x02z_SYSTICK_IRQ_Priority0)
        NVIC_SetPriority(SysTick_IRQn, 0x0);
    #elif defined(MG32x02z_SYSTICK_IRQ_Priority1)
        NVIC_SetPriority(SysTick_IRQn, 0x1);
    #elif defined(MG32x02z_SYSTICK_IRQ_Priority2)
        NVIC_SetPriority(SysTick_IRQn, 0x2);
    #elif defined(MG32x02z_SYSTICK_IRQ_Priority3)
        NVIC_SetPriority(SysTick_IRQn, 0x3);
    #endif
    
}


