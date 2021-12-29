/*!
    \file    bootloader.c
    \brief   Bootloader to make operations on flash memory and give control to main app

*/



#include "bootloader.h"



uint32_t *ptrd;
uint32_t address = 0x00;                              //MM Originally 0x00;
uint32_t data0   = 0xDDCCBBAA;                              //MM Originally 0x01234567U;



/* calculate the num of page to be programmed/erased */
uint32_t page_num = (FMC_WRITE_END_ADDR - FMC_WRITE_START_ADDR) / FMC_PAGE_SIZE;
/* calculate the num of page to be programmed/erased */
uint32_t word_num = ((FMC_WRITE_END_ADDR - FMC_WRITE_START_ADDR) >> 2);



/*!
    \brief      Deinitialize all peripherals and registers before jumping to app address 
    \param[in]  none
    \param[out] none
    \retval     none
*/
void deinit_all(){

    /* deinitialize the USART0 */
    usart_deinit(USART0);
    /* deinitialize the GPIOx ports | gpio_periph: GPIOx(x = A,B,C,D,E,F,G) */
    gpio_deinit(GPIOA); 
    gpio_deinit(GPIOB);
    gpio_deinit(GPIOC);
    gpio_deinit(GPIOE);
    /* deinitialize the EXTI */
    exti_deinit();
    /* disable NVIC interrupt requests */
    nvic_irq_disable(EXTI10_15_IRQn);
    nvic_irq_disable(EXTI0_IRQn);
    /* disable GPIOA clock */
    rcu_periph_clock_disable(RCU_GPIOA);
    /* disable GPIOB clock */
    rcu_periph_clock_disable(RCU_GPIOB);
    /* disable GPIOC clock */
    rcu_periph_clock_disable(RCU_GPIOC);
    /* disable GPIOC clock */
    rcu_periph_clock_disable(RCU_GPIOE);
    /* disable USART clock */
    rcu_periph_clock_disable(RCU_USART0);
    /* disable APB2 peripheral alternate function clock */
    rcu_periph_clock_disable(RCU_AF);

}


/*!
    \brief      erase fmc pages from FMC_WRITE_START_ADDR to FMC_WRITE_END_ADDR
    \param[in]  none
    \param[out] none
    \retval     none
*/
void fmc_erase_pages(void)
{
    uint32_t erase_counter;

    /* unlock the flash program/erase controller */
    fmc_unlock();

    /* clear all pending flags */
    fmc_flag_clear(FMC_FLAG_BANK0_END);
    fmc_flag_clear(FMC_FLAG_BANK0_WPERR);
    fmc_flag_clear(FMC_FLAG_BANK0_PGERR);
    
    /* erase the flash pages */
    for(erase_counter = 0; erase_counter < page_num; erase_counter++){
        fmc_page_erase(FMC_WRITE_START_ADDR + (FMC_PAGE_SIZE * erase_counter));
        fmc_flag_clear(FMC_FLAG_BANK0_END);
        fmc_flag_clear(FMC_FLAG_BANK0_WPERR);
        fmc_flag_clear(FMC_FLAG_BANK0_PGERR);
    }

    /* lock the main FMC after the erase operation */
    fmc_lock();
}

/*!
    \brief      program fmc word by word from FMC_WRITE_START_ADDR to FMC_WRITE_END_ADDR
    \param[in]  none
    \param[out] none
    \retval     none
*/
void fmc_program(void)
{
    /* unlock the flash program/erase controller */
    fmc_unlock();

    address = FMC_WRITE_START_ADDR;

    /* program flash */
    while(address < FMC_WRITE_END_ADDR){
        fmc_word_program(address, data0);
        address += 4;
        fmc_flag_clear(FMC_FLAG_BANK0_END);
        fmc_flag_clear(FMC_FLAG_BANK0_WPERR);
        fmc_flag_clear(FMC_FLAG_BANK0_PGERR); 
    }

    /* lock the main FMC after the program operation */
    fmc_lock();
}

/*!
    \brief      check fmc erase result
    \param[in]  none
    \param[out] none
    \retval     none
*/
void fmc_erase_pages_check(void)
{
    uint32_t i;

    ptrd = (uint32_t *)FMC_WRITE_START_ADDR;

    /* check flash whether has been erased */
    for(i = 0; i < word_num; i++){
        if(0xFFFFFFFF != (*ptrd)){
            LED_ON(Led2);
            break;
        }else{
            ptrd++;
        }
    }
}

/*!
    \brief      check fmc program result
    \param[in]  none
    \param[out] none
    \retval     none
*/
void fmc_program_check(void)
{
    uint32_t i;

    ptrd = (uint32_t *)FMC_WRITE_START_ADDR;

    /* check flash whether has been programmed */
    for(i = 0; i < word_num; i++){
        if((*ptrd) != data0){
            LED_ON(Led3);
            break;
        }else{
            ptrd++;
        }
    }
}


/*!
    \brief      Jump to application start address +4?
    \param[in]  none
    \param[out] none
    \retval     none
*/

void jumpToApp( void ){

    typedef void (*app_reset_handler)(void);

    app_reset_handler arh = (void*) (*(volatile uint32_t*)(0x08006000+4U));

    arh();    //call the app reset handler
        
}
