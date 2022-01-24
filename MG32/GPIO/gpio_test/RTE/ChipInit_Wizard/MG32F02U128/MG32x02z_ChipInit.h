
/**
 ******************************************************************************
 *
 * @file        MG32x02z_ChipInit.H
 *
 * @brief       By the file select you want to function initial.
 *   
 * @par         Project
 *              MG32x02z
 * @version     V1.12
 * @date        2021/07/28
 * @author      Megawin Software Center
 * @copyright   Copyright (c) 2017 MegaWin Technology Co., Ltd.
 *              All rights reserved.
 *
 ******************************************************************************
 * @par 		Disclaimer 
 *		The Demo software is provided "AS IS"  without any warranty, either 
 *		expressed or implied, including, but not limited to, the implied warranties 
 *		of merchantability and fitness for a particular purpose.  The author will 
 *		not be liable for any special, incidental, consequential or indirect 
 *		damages due to loss of data or any other reason. 
 *		These statements agree with the world wide and local dictated laws about 
 *		authorship and violence against these laws. 
 ******************************************************************************
 ******************************************************************************
 */

#ifndef _MG32x02z_ChipInit_H
 
#define _MG32x02z_ChipInit_H

/* Includes ------------------------------------------------------------------*/
#include "RTE_Components.h"         // From Keil "Manage Run-Time Enviroment' setting
//
#ifdef MG32x02z_ConfigerWizard_PW   // "Manage Run-Time Enviroment" enable PW wizard
    #include "MG32x02z_PW_Init.h"   // include "MG32x02z_PW_Init.h" file
#endif

#ifdef MG32x02z_ConfigerWizard_RST  // "Manage Run-Time Enviroment" enable RST wizard
    #include "MG32x02z_RST_Init.h"  // include "MG32x02z_RST_Init.h" file
#endif

#ifdef MG32x02z_ConfigerWizard_GPIO // "Manage Run-Time Enviroment" enable GPIO wizard
    #include "MG32x02z_GPIO_Init.h" // include "MG32x02z_GPIO_Init.h" file
#endif

#ifdef MG32x02z_ConfigerWizard_CSC  // "Manage Run-Time Enviroment" enable CSC wizard
    #include "MG32x02z_CSC_Init.h"  // include "MG32x02z_CSC_Init.h" file
#endif

#ifdef MG32x02z_ConfigerWizard_EXIC // "Manage Run-Time Enviroment" enable EXIC wizard
    #include "MG32x02z_EXIC_Init.h" // include "MG32x02z_EXIC_Init.h" file
#endif

#ifdef MG32x02z_ConfigerWizard_GPL  // "Manage Run-Time Enviroment" enable GPL wizard
    #include "MG32x02z_GPL_Init.h"  // include "MG32x02z_GPL_Init.h" file
#endif

#ifdef MG32x02z_ConfigerWizard_MEM  // "Manage Run-Time Enviroment" enable MEM wizard
    #include "MG32x02z_MEM_Init.h"  // include "MG32x02z_MEM_Init.h" file
#endif

#ifdef MG32x02z_ConfigerWizard_EMB  // "Manage Run-Time Enviroment" enable EMB wizard
    #include "MG32x02z_EMB_Init.h"  // include "MG32x02z_EMB_Init.h" file
#endif

#ifdef MG32x02z_ConfigerWizard_URT  // "Manage Run-Time Enviroment" enable URT wizard
    #include "MG32x02z_URT_Init.h"  // include "MG32x02z_URT_Init.h" file
#endif

#ifdef MG32x02z_ConfigerWizard_TM   // "Manage Run-Time Enviroment" enable TM wizard
    #include "MG32x02z_TM_Init.h"   // include "MG32x02z_TM_Init.h" file
#endif

#ifdef MG32x02z_ConfigerWizard_ADC  // "Manage Run-Time Enviroment" enable ADC wizard
    #include "MG32x02z_ADC_Init.h"  // include "MG32x02z_ADC_Init.h" file
#endif

#ifdef MG32x02z_ConfigerWizard_DAC  // "Manage Run-Time Enviroment" enable DAC wizard
    #include "MG32x02z_DAC_Init.h"  // include "MG32x02z_DAC_Init.h" file
#endif

#ifdef MG32x02z_ConfigerWizard_CMP  // "Manage Run-Time Enviroment" enable CMP wizard
    #include "MG32x02z_CMP_Init.h"  // include "MG32x02z_CMP_Init.h" file
#endif

#ifdef MG32x02z_ConfigerWizard_APB  // "Manage Run-Time Enviroment" enable APB wizard
    #include "MG32x02z_APB_Init.h"  // include "MG32x02z_APB_Init.h" file
#endif

#ifdef MG32x02z_ConfigerWizard_APX_CCL    // "Manage Run-Time Enviroment" enable APX CCL wizard
    #include "MG32x02z_CCL_Init.h"  // include "MG32x02z_CCL_Init.h" file
#endif

#ifdef MG32x02z_ConfigerWizard_RTC  // "Manage Run-Time Enviroment" enable RTC wizard
    #include "MG32x02z_RTC_Init.h"  // include "MG32x02z_CCL_Init.h" file
#endif

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Exported variables --------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
/**
 * @name    Function announce
 * @brief   Chip Initial routine	
 */ 
///@{
void ChipInit(void);
///@}

/* External vairables --------------------------------------------------------*/


#endif
