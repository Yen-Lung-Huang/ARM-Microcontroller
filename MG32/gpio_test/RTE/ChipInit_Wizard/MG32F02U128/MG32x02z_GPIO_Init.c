


/**
 ******************************************************************************
 *
 * @file        MG32x02z_GPIO_Init.c
 * @brief       The GPIO Init C file.
 *
 * @par         Project
 *              MG32x02z
 * @version     V1.10
 * @date        2018/01/30
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



#include "MG32x02z__Common_DRV.h"
#include "MG32x02z_GPIO_DRV.h"
#include "MG32x02z_GPIO_Init.h"

    
/**
 *******************************************************************************
 * @brief	    To initial GPIO.
 * @details     
 * @return      
 * @exception   No
 * @note
 * @par         Example
 * @code
 * @endcode
 *******************************************************************************
 */
void GPIO_Init(void)
{
    uint32_t data_size = ((sizeof(GPIO_CFG))/4 - 1)/2;
    uint32_t i;
    
    
    for(i=0;i<data_size;i++)
    {
       *((volatile uint32_t*)((uint32_t)GPIO_CFG[i*2])) = GPIO_CFG[i*2+1];  
    }
}









