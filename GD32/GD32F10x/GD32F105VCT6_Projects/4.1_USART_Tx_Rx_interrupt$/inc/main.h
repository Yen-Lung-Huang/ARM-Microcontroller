/*!
    \file    main.c
    \brief   transmit/receive data using DMA interrupt
    
*/

#ifndef _MAIN_H
#define _MAIN_H


#include "gd32f10x.h"
#include <stdio.h>


#define ARRAYNUM(arr_nanme)      (uint32_t)(sizeof(arr_nanme) / sizeof(*(arr_nanme)))
#define TRANSMIT_SIZE            (ARRAYNUM(txbuffer) - 1)

uint8_t txbuffer[] = "\n\rUSART interrupt test\n\r";
uint8_t rxbuffer[32];
uint8_t tx_size = TRANSMIT_SIZE;
uint8_t rx_size = 32;
__IO uint8_t txcount = 0; 
__IO uint16_t rxcount = 0; 



typedef enum {
    Led2    =0,
    Led3    =1,
    Led4    =2,
    Led5    =3,
    AllLeds =4
}led_type;


typedef enum            // Redefining enum to skip evaluation board dependency
{
    WAKEUP = 0,
    TAMPER = 1,
    USER   = 2,
    AllBut = 3          
} key_type;

typedef enum            // Redefining enum to skip evaluation board dependency
{
    MODE_GPIO = 0,
    MODE_EXTI = 1
} key_mode;



/*FUNCTION PROTOTYPES*/

void rcu_config(void);
void led_init(void);
void LED_ON(led_type led);
void LED_OFF(led_type led);
void com_port_init(uint32_t com);

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





/* retarget the C library printf function to the USART */
int fputc(int ch, FILE *f)
{
    usart_data_transmit(USART0, (uint8_t)ch);
    while(RESET == usart_flag_get(USART0, USART_FLAG_TBE));
    return ch;
}




#endif /* _MAIN_H */


