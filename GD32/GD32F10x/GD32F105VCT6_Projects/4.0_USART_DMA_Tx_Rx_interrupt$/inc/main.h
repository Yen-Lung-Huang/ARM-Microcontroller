/*!
    \file    main.c
    \brief   transmit/receive data using DMA interrupt
    
*/

#ifndef _MAIN_H
#define _MAIN_H

#include <stdio.h>
#include "gd32f10x.h"


  
#define USART0_DATA_ADDRESS      ((uint32_t)&USART_DATA(USART0))
#define USART1_DATA_ADDRESS      ((uint32_t)&USART_DATA(USART1))
#define ARRAYNUM(arr_nanme)      (uint32_t)(sizeof(arr_nanme) / sizeof(*(arr_nanme)))    // Not being used

__IO FlagStatus g_transfer_complete = RESET;

const uint16_t rx_buf_size = 2;
const uint16_t rx_buf_half = rx_buf_size/2;
const uint16_t rx_tot_size = 3516;
uint8_t rxbuffer[rx_buf_size];
uint8_t rxtotal [rx_tot_size]= {'\0'};

//uint8_t txbuffer[];

void dma_initialize(void);
void com_port_init(uint32_t com);
void nvic_config(void);
int fputc(int ch, FILE *f);








/* FUNCTION DEFINITIONS */


/*!
    \brief      configure COM port
    \param[in]  com: COM on the board
      \arg        EVAL_COM0: COM0 on the board
      \arg        EVAL_COM1: COM1 on the board
    \param[out] none
    \retval     none
*/
void com_port_init(uint32_t com)            //MM Adapted to not depend upon Evaluation board
{

    
    /* enable GPIO clock */
    rcu_periph_clock_enable(RCU_GPIOA);


    if(USART0 == com){
    /* enable USART clock */
    rcu_periph_clock_enable(RCU_USART0);        
    /* connect port to USARTx_Tx */
    gpio_init(GPIOA, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_9);           //MM GPIO_PIN_2 for COM1
    /* connect port to USARTx_Rx */
    gpio_init(GPIOA, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, GPIO_PIN_10);    //MM GPIO_PIN_3 for COM1
    }
    else if(USART1 == com){
    /* enable USART clock */
    rcu_periph_clock_enable(RCU_USART1);
    /* connect port to USARTx_Tx */
    gpio_init(GPIOA, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_2);           //MM GPIO_PIN_9 for COM0
    /* connect port to USARTx_Rx */
    gpio_init(GPIOA, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, GPIO_PIN_3);    //MM GPIO_PIN_10 for COM0        
        
    }
    /* USART configure */
    usart_deinit(com);
    usart_baudrate_set(com, 115200U);
    usart_word_length_set(com, USART_WL_8BIT);
    usart_stop_bit_set(com, USART_STB_1BIT);
    usart_parity_config(com, USART_PM_NONE);
    usart_hardware_flow_rts_config(com, USART_RTS_DISABLE);
    usart_hardware_flow_cts_config(com, USART_CTS_DISABLE);
    usart_receive_config(com, USART_RECEIVE_ENABLE);
    usart_transmit_config(com, USART_TRANSMIT_ENABLE);
    usart_enable(com);
}



/*!
    \brief      configure DMA interrupt
    \param[in]  none
    \param[out] none
    \retval     none
*/
void nvic_config(void)
{
//    nvic_irq_enable(DMA0_Channel3_IRQn, 0, 0);
    nvic_irq_enable(DMA0_Channel4_IRQn, 0, 1);
}

/* retarget the C library printf function to the USART */
int fputc(int ch, FILE *f)
{
    usart_data_transmit(USART0, (uint8_t)ch);
    while(RESET == usart_flag_get(USART0, USART_FLAG_TBE));
    return ch;
}




#endif /* _MAIN_H */


