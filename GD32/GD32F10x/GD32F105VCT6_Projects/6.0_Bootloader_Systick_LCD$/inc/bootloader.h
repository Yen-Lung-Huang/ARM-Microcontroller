/*!
    \file    main.h
    \brief   the header file of main


*/



#ifndef BOOTLOADER_H
#define BOOTLOADER_H

#include "gd32f10x.h"
#include "main.h"

#define FMC_PAGE_SIZE           ((uint16_t)0x800U)          //MM Originally ((uint16_t)0x400U)
#define FMC_WRITE_START_ADDR    ((uint32_t)0x08004000U)     //MM Originally ((uint32_t)0x08004000U)
#define FMC_WRITE_END_ADDR      ((uint32_t)0x08040000U)     //MM Originally ((uint32_t)0x08004800U)


/****************************NEW*******************************/

#define APP_START       ((unit32_t)0x08006000)		        // Origin + Bootloader size (16KB)
#define APP_SIZE        ((uint16_t)0x3B000)                 // Memory available for application code (236KB)
#define BOOTLDR_SIZE    ((uint16_t)0x4000)                  // Memory available for bootloader code (16KB)


typedef void (application_t)(void);                         // This function is currently unused                           

typedef struct
{
    uint32_t		stack_addr;     // Stack Pointer
    application_t*	func_p;         // Program Counter
} JumpStruct;



void bootloaderInit(void);                                  // This function is currently unused



/**************************************************************/

/* Function Prototypes */

/* Deinitialize all previously initialized before jumping to app */
void deinit_all(void);

/* erase fmc pages from FMC_WRITE_START_ADDR to FMC_WRITE_END_ADDR */
void fmc_erase_pages(void);
/* program fmc word by word from FMC_WRITE_START_ADDR to FMC_WRITE_END_ADDR */
void fmc_program(void);
/* check fmc erase result */
void fmc_erase_pages_check(void);
/* check fmc program result */
void fmc_program_check(void);

/* Jump to application start address +4?  */
void jumpToApp( void );




#endif

/* BOOTLOADER_H */


