<<<<<<< HEAD
/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only 
* intended for use with Renesas products. No other uses are authorized. This 
* software is owned by Renesas Electronics Corporation and is protected under 
* all applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING 
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT 
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE 
* AND NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS 
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE 
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR 
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE 
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software 
* and to discontinue the availability of this software.  By using this software, 
* you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2013 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : r_cg_cgc.c
* Version      : Applilet4 for RX64M V1.00.00.00 [02 Aug 2013]
* Device(s)    : R5F564MLHxFC
* Tool-Chain   : CCRX
* Description  : This file implements device driver for CGC module.
* Creation Date: 07/02/2014
***********************************************************************************************************************/

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_cgc.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_CGC_Create
* Description  : This function initializes the clock generator.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_CGC_Create(void)
{
    /* Set main clock control registers */
    SYSTEM.MOFCR.BYTE = _00_CGC_MAINOSC_RESONATOR | _00_CGC_MAINOSC_UNDER24M;	
    SYSTEM.MOSCWTCR.BYTE = _52_CGC_MOSCWTCR_VALUE;

    /* Set main clock operation */
    SYSTEM.MOSCCR.BIT.MOSTP = 0U;

    /* Wait for main clock oscillator wait counter overflow */
    while (1U != SYSTEM.OSCOVFSR.BIT.MOOVF);

    /* Set system clock */
    SYSTEM.SCKCR.LONG = _00000001_CGC_PCLKD_DIV_2 | _00000010_CGC_PCLKC_DIV_2 | _00000100_CGC_PCLKB_DIV_2 | 
                        _00001000_CGC_PCLKA_DIV_2 | _00010000_CGC_BCLK_DIV_2 | _01000000_CGC_ICLK_DIV_2 | 
                        _10000000_CGC_FCLK_DIV_2;

    /* Set PLL circuit */
    SYSTEM.PLLCR2.BIT.PLLEN = 0U;
    SYSTEM.PLLCR.BIT.PLLSRCSEL = 0U;
    SYSTEM.PLLCR.WORD = _0001_CGC_PLL_FREQ_DIV_2 | _1300_CGC_PLL_FREQ_MUL_10_0;

    /* Wait for PLL wait counter overflow */
    while (1U != SYSTEM.OSCOVFSR.BIT.PLOVF);


    /* Disable sub-clock */
    SYSTEM.SOSCCR.BIT.SOSTP = 1U;

    /* Wait for the register modification to complete */
    while (1U != SYSTEM.SOSCCR.BIT.SOSTP);

    /* Set LOCO */
    SYSTEM.LOCOCR.BIT.LCSTP = 0U;

    /* Set UCLK */
    SYSTEM.SCKCR2.WORD = _0020_CGC_UCLK_DIV_3;

    /* Set SDCLK */
    SYSTEM.SCKCR.BIT.PSTOP0 = 1U;

    /* Set clock source */
    SYSTEM.SCKCR3.WORD = _0400_CGC_CLOCKSOURCE_PLL;
}


/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
=======
/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only 
* intended for use with Renesas products. No other uses are authorized. This 
* software is owned by Renesas Electronics Corporation and is protected under 
* all applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING 
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT 
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE 
* AND NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS 
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE 
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR 
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE 
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software 
* and to discontinue the availability of this software.  By using this software, 
* you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2013 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : r_cg_cgc.c
* Version      : Applilet4 for RX64M V1.00.00.00 [02 Aug 2013]
* Device(s)    : R5F564MLHxFC
* Tool-Chain   : CCRX
* Description  : This file implements device driver for CGC module.
* Creation Date: 07/02/2014
***********************************************************************************************************************/

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_cgc.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_CGC_Create
* Description  : This function initializes the clock generator.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_CGC_Create(void)
{
    /* Set main clock control registers */
    SYSTEM.MOFCR.BYTE = _00_CGC_MAINOSC_RESONATOR | _00_CGC_MAINOSC_UNDER24M;	
    SYSTEM.MOSCWTCR.BYTE = _52_CGC_MOSCWTCR_VALUE;

    /* Set main clock operation */
    SYSTEM.MOSCCR.BIT.MOSTP = 0U;

    /* Wait for main clock oscillator wait counter overflow */
    while (1U != SYSTEM.OSCOVFSR.BIT.MOOVF);

    /* Set system clock */
    SYSTEM.SCKCR.LONG = _00000001_CGC_PCLKD_DIV_2 | _00000010_CGC_PCLKC_DIV_2 | _00000100_CGC_PCLKB_DIV_2 | 
                        _00001000_CGC_PCLKA_DIV_2 | _00010000_CGC_BCLK_DIV_2 | _01000000_CGC_ICLK_DIV_2 | 
                        _10000000_CGC_FCLK_DIV_2;

    /* Set PLL circuit */
    SYSTEM.PLLCR2.BIT.PLLEN = 0U;
    SYSTEM.PLLCR.BIT.PLLSRCSEL = 0U;
    SYSTEM.PLLCR.WORD = _0001_CGC_PLL_FREQ_DIV_2 | _1300_CGC_PLL_FREQ_MUL_10_0;

    /* Wait for PLL wait counter overflow */
    while (1U != SYSTEM.OSCOVFSR.BIT.PLOVF);


    /* Disable sub-clock */
    SYSTEM.SOSCCR.BIT.SOSTP = 1U;

    /* Wait for the register modification to complete */
    while (1U != SYSTEM.SOSCCR.BIT.SOSTP);

    /* Set LOCO */
    SYSTEM.LOCOCR.BIT.LCSTP = 0U;

    /* Set UCLK */
    SYSTEM.SCKCR2.WORD = _0020_CGC_UCLK_DIV_3;

    /* Set SDCLK */
    SYSTEM.SCKCR.BIT.PSTOP0 = 1U;

    /* Set clock source */
    SYSTEM.SCKCR3.WORD = _0400_CGC_CLOCKSOURCE_PLL;
}


/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
>>>>>>> 16c66438 (Upload from PC.)
