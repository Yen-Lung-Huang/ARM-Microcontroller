<<<<<<< HEAD
/* ----------------------------------------------------------------------------
 *         ATMEL Microcontroller Software Support 
 * ----------------------------------------------------------------------------
 * Copyright (c) 2008, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */

#ifndef EEFC_H
#define EEFC_H

//------------------------------------------------------------------------------
//         Headers
//------------------------------------------------------------------------------

#include <board.h>

#ifdef BOARD_FLASH_EEFC

//------------------------------------------------------------------------------
//         Constants
//------------------------------------------------------------------------------

/// Number of GPNVMs available on each chip.
#if defined(at91sam7l64) || defined(at91sam7l128)

    #define EFC_NUM_GPNVMS          2

#elif defined(at91sam9xe128) || defined(at91sam9xe256) || defined(at91sam9xe512)

    #define EFC_NUM_GPNVMS          17
#endif

//------------------------------------------------------------------------------
//         Types
//------------------------------------------------------------------------------

// Needed when EEFC is integrated in MC.
#if !defined(AT91C_BASE_EFC) && defined(AT91C_BASE_MC)
typedef struct _AT91S_EFC {
	AT91_REG	 EFC_FMR; 	// EFC Flash Mode Register
	AT91_REG	 EFC_FCR; 	// EFC Flash Command Register
	AT91_REG	 EFC_FSR; 	// EFC Flash Status Register
	AT91_REG	 EFC_FRR; 	// EFC Flash Result Register
	AT91_REG	 EFC_FVR; 	// EFC Flash Version Register
} AT91S_EFC, *AT91PS_EFC;

#define AT91C_EFC_FRDY              AT91C_MC_FRDY
#define AT91C_EFC_FWS               AT91C_MC_FWS
#define AT91C_EFC_FWS_0WS           AT91C_MC_FWS_0WS
#define AT91C_EFC_FWS_1WS           AT91C_MC_FWS_1WS
#define AT91C_EFC_FWS_2WS           AT91C_MC_FWS_2WS
#define AT91C_EFC_FWS_3WS           AT91C_MC_FWS_3WS
#define AT91C_EFC_FCMD              AT91C_MC_FCMD
#define AT91C_EFC_FCMD_GETD         AT91C_MC_FCMD_GETD
#define AT91C_EFC_FCMD_WP           AT91C_MC_FCMD_WP  
#define AT91C_EFC_FCMD_WPL          AT91C_MC_FCMD_WPL 
#define AT91C_EFC_FCMD_EWP          AT91C_MC_FCMD_EWP 
#define AT91C_EFC_FCMD_EWPL         AT91C_MC_FCMD_EWPL
#define AT91C_EFC_FCMD_EA           AT91C_MC_FCMD_EA  
#define AT91C_EFC_FCMD_EPL          AT91C_MC_FCMD_EPL 
#define AT91C_EFC_FCMD_EPA          AT91C_MC_FCMD_EPA 
#define AT91C_EFC_FCMD_SLB          AT91C_MC_FCMD_SLB 
#define AT91C_EFC_FCMD_CLB          AT91C_MC_FCMD_CLB 
#define AT91C_EFC_FCMD_GLB          AT91C_MC_FCMD_GLB 
#define AT91C_EFC_FCMD_SFB          AT91C_MC_FCMD_SFB 
#define AT91C_EFC_FCMD_CFB          AT91C_MC_FCMD_CFB 
#define AT91C_EFC_FCMD_GFB          AT91C_MC_FCMD_GFB 
#define AT91C_EFC_FARG              AT91C_MC_FARG     
#define AT91C_EFC_FKEY              AT91C_MC_FKEY     
#define AT91C_EFC_FRDY_S            AT91C_MC_FRDY_S   
#define AT91C_EFC_FCMDE             AT91C_MC_FCMDE   
#define AT91C_EFC_LOCKE             AT91C_MC_LOCKE    
#define AT91C_EFC_FVALUE            AT91C_MC_FVALUE   

#define AT91C_BASE_EFC              (AT91_CAST(AT91PS_EFC) 	0xFFFFFF60)    

#endif //#if !defined(AT91C_BASE_EFC) && defined(AT91C_BASE_MC)

//------------------------------------------------------------------------------
//         Functions
//------------------------------------------------------------------------------

extern void EFC_EnableFrdyIt(void);

extern void EFC_DisableFrdyIt(void);

extern void EFC_TranslateAddress(
    unsigned int address,
    unsigned short *pPage,
    unsigned short *pOffset);

extern void EFC_ComputeAddress(
    unsigned short page,
    unsigned short offset,
    unsigned int *pAddress);

extern void EFC_StartCommand(
    unsigned char command,
    unsigned short argument);

extern unsigned char EFC_PerformCommand(
    unsigned char command,
    unsigned short argument);

extern unsigned int EFC_GetStatus(void);

extern unsigned int EFC_GetResult(void);

#endif //#ifdef BOARD_FLASH_EEFC
#endif //#ifndef EEFC_H

=======
/* ----------------------------------------------------------------------------
 *         ATMEL Microcontroller Software Support 
 * ----------------------------------------------------------------------------
 * Copyright (c) 2008, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */

#ifndef EEFC_H
#define EEFC_H

//------------------------------------------------------------------------------
//         Headers
//------------------------------------------------------------------------------

#include <board.h>

#ifdef BOARD_FLASH_EEFC

//------------------------------------------------------------------------------
//         Constants
//------------------------------------------------------------------------------

/// Number of GPNVMs available on each chip.
#if defined(at91sam7l64) || defined(at91sam7l128)

    #define EFC_NUM_GPNVMS          2

#elif defined(at91sam9xe128) || defined(at91sam9xe256) || defined(at91sam9xe512)

    #define EFC_NUM_GPNVMS          17
#endif

//------------------------------------------------------------------------------
//         Types
//------------------------------------------------------------------------------

// Needed when EEFC is integrated in MC.
#if !defined(AT91C_BASE_EFC) && defined(AT91C_BASE_MC)
typedef struct _AT91S_EFC {
	AT91_REG	 EFC_FMR; 	// EFC Flash Mode Register
	AT91_REG	 EFC_FCR; 	// EFC Flash Command Register
	AT91_REG	 EFC_FSR; 	// EFC Flash Status Register
	AT91_REG	 EFC_FRR; 	// EFC Flash Result Register
	AT91_REG	 EFC_FVR; 	// EFC Flash Version Register
} AT91S_EFC, *AT91PS_EFC;

#define AT91C_EFC_FRDY              AT91C_MC_FRDY
#define AT91C_EFC_FWS               AT91C_MC_FWS
#define AT91C_EFC_FWS_0WS           AT91C_MC_FWS_0WS
#define AT91C_EFC_FWS_1WS           AT91C_MC_FWS_1WS
#define AT91C_EFC_FWS_2WS           AT91C_MC_FWS_2WS
#define AT91C_EFC_FWS_3WS           AT91C_MC_FWS_3WS
#define AT91C_EFC_FCMD              AT91C_MC_FCMD
#define AT91C_EFC_FCMD_GETD         AT91C_MC_FCMD_GETD
#define AT91C_EFC_FCMD_WP           AT91C_MC_FCMD_WP  
#define AT91C_EFC_FCMD_WPL          AT91C_MC_FCMD_WPL 
#define AT91C_EFC_FCMD_EWP          AT91C_MC_FCMD_EWP 
#define AT91C_EFC_FCMD_EWPL         AT91C_MC_FCMD_EWPL
#define AT91C_EFC_FCMD_EA           AT91C_MC_FCMD_EA  
#define AT91C_EFC_FCMD_EPL          AT91C_MC_FCMD_EPL 
#define AT91C_EFC_FCMD_EPA          AT91C_MC_FCMD_EPA 
#define AT91C_EFC_FCMD_SLB          AT91C_MC_FCMD_SLB 
#define AT91C_EFC_FCMD_CLB          AT91C_MC_FCMD_CLB 
#define AT91C_EFC_FCMD_GLB          AT91C_MC_FCMD_GLB 
#define AT91C_EFC_FCMD_SFB          AT91C_MC_FCMD_SFB 
#define AT91C_EFC_FCMD_CFB          AT91C_MC_FCMD_CFB 
#define AT91C_EFC_FCMD_GFB          AT91C_MC_FCMD_GFB 
#define AT91C_EFC_FARG              AT91C_MC_FARG     
#define AT91C_EFC_FKEY              AT91C_MC_FKEY     
#define AT91C_EFC_FRDY_S            AT91C_MC_FRDY_S   
#define AT91C_EFC_FCMDE             AT91C_MC_FCMDE   
#define AT91C_EFC_LOCKE             AT91C_MC_LOCKE    
#define AT91C_EFC_FVALUE            AT91C_MC_FVALUE   

#define AT91C_BASE_EFC              (AT91_CAST(AT91PS_EFC) 	0xFFFFFF60)    

#endif //#if !defined(AT91C_BASE_EFC) && defined(AT91C_BASE_MC)

//------------------------------------------------------------------------------
//         Functions
//------------------------------------------------------------------------------

extern void EFC_EnableFrdyIt(void);

extern void EFC_DisableFrdyIt(void);

extern void EFC_TranslateAddress(
    unsigned int address,
    unsigned short *pPage,
    unsigned short *pOffset);

extern void EFC_ComputeAddress(
    unsigned short page,
    unsigned short offset,
    unsigned int *pAddress);

extern void EFC_StartCommand(
    unsigned char command,
    unsigned short argument);

extern unsigned char EFC_PerformCommand(
    unsigned char command,
    unsigned short argument);

extern unsigned int EFC_GetStatus(void);

extern unsigned int EFC_GetResult(void);

#endif //#ifdef BOARD_FLASH_EEFC
#endif //#ifndef EEFC_H

>>>>>>> 16c66438 (Upload from PC.)
