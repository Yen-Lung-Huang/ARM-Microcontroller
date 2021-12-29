/*!
    \file    main.c
    \brief   CRC calculate demo

    \version 2014-12-26, V1.0.0, firmware for GD32F10x
    \version 2017-06-20, V2.0.0, firmware for GD32F10x
    \version 2018-07-31, V2.1.0, firmware for GD32F10x
    \version 2020-09-30, V2.2.0, firmware for GD32F10x
*/

/*
    Copyright (c) 2020, GigaDevice Semiconductor Inc.

    Redistribution and use in source and binary forms, with or without modification, 
are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice, this 
       list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright notice, 
       this list of conditions and the following disclaimer in the documentation 
       and/or other materials provided with the distribution.
    3. Neither the name of the copyright holder nor the names of its contributors 
       may be used to endorse or promote products derived from this software without 
       specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT 
NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR 
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY 
OF SUCH DAMAGE.
*/

#include "gd32f10x.h"
#include "main.h"


uint32_t val = 0, valcrc1 = 0, valcrc2 = 0;
uint32_t val_data[] = {0x11223344, 0x55667788, 0x99aabbcc, 0xddeeffff};

/*!
    \brief      main function
    \param[in]  none
    \param[out] none
    \retval     none
*/
int main(void)
{
    val = (uint32_t)0xabcd1234;

    /* system clocks configuration */
    rcu_config();
    /* LED initialize */
    led_init();
	/* initialize USARTx */
    com_port_init(USART1);

    /* reset the CRC data register and calculate the CRC of the value */
    crc_data_register_reset();
    valcrc1 = crc_single_data_calculate(val);
    
    /* reset the CRC data register and calculate the CRC of the value group */
    crc_data_register_reset();
    valcrc2 = crc_block_data_calculate(val_data, sizeof(val_data)/sizeof(val_data[0]));
    
    printf("\r\nSingle data CRC: %X", valcrc1 );
    printf("\r\nBlock data CRC: %X", valcrc2 );    

    if(0xf7018a40 == valcrc1 && 0x85A317CB == valcrc2){
        LED_ON(Led2);
        LED_ON(Led3);
    }

    while (1){
    }
}


/*!
    \brief      configure the different system clocks
    \param[in]  none
    \param[out] none
    \retval     none
*/
void rcu_config(void)
{
    /* enable GPIOA clock */
    rcu_periph_clock_enable(RCU_GPIOA);
    rcu_periph_clock_enable(RCU_GPIOC);
    rcu_periph_clock_enable(RCU_GPIOE);
    /* enable USARTx clocks */
    rcu_periph_clock_enable(RCU_USART1);
    /* enable CRC clock */
    rcu_periph_clock_enable(RCU_CRC);

}


/*!
    \brief      initialize the LEDs
    \param[in]  none
    \param[out] none
    \retval     none
*/
void led_init(void)
{
	/* Requires rcu_config() previously */
   
    /* Configure LED GPIO port */
	gpio_init(GPIOC, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_0 | GPIO_PIN_2 );
	gpio_init(GPIOE, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_0 | GPIO_PIN_1 );
}



/*!
    \brief      configure COM port
    \param[in]  com: COM on the board
      \arg        EVAL_COM0: COM0 on the board
      \arg        EVAL_COM1: COM1 on the board
    \param[out] none
    \retval     none
*/
void com_port_init(uint32_t com)                                               //MM Adapted to not depend upon Evaluation board
{
    
	/* Requires rcu_config() previously */
    if (USART0 == com){

    /* connect port to USARTx_Tx */
    gpio_init(GPIOA, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_9);          //MM GPIO_PIN_9 for USART0 Tx
    /* connect port to USARTx_Rx */
    gpio_init(GPIOA, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, GPIO_PIN_10);   //MM GPIO_PIN_10 for USART0 Rx
    }
    else if (USART1 == com) {

    /* connect port to USARTx_Tx */
    gpio_init(GPIOA, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_2);          //MM GPIO_PIN_2 for USART1 Tx
    /* connect port to USARTx_Rx */
    gpio_init(GPIOA, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, GPIO_PIN_3);    //MM GPIO_PIN_3 for USART1 Rx
    }        
        
    /* USART common configuration */
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
\brief      Turn ON LEDs
\param[in]  LEDn: (Led2, Led3, Led4, Led5)
\param[out] none
\retval     none
*/
void LED_ON(led_type led){
    switch(led){
        case Led2:
         gpio_bit_set ( GPIOC, GPIO_PIN_0 );   
        break;
        case Led3:
         gpio_bit_set ( GPIOC, GPIO_PIN_2 );   
        break;
        case Led4:
         gpio_bit_set ( GPIOE, GPIO_PIN_0 );   
        break;
        case Led5:
         gpio_bit_set ( GPIOE, GPIO_PIN_1 );
        break;
        case AllLeds:
         gpio_bit_set ( GPIOC, GPIO_PIN_0 | GPIO_PIN_2 );
         gpio_bit_set ( GPIOE, GPIO_PIN_0 | GPIO_PIN_1);
        break;
       
    }
}


/*!
\brief      Turn OFF LEDs
\param[in]  LEDn: (Led2, Led3, Led4, Led5)
\param[out] none
\retval     none
*/
void LED_OFF(led_type led){
      switch(led){
        case Led2:
            gpio_bit_reset ( GPIOC, GPIO_PIN_0 );   
            break;
        case Led3:
            gpio_bit_reset ( GPIOC, GPIO_PIN_2 );   
            break;
        case Led4:
            gpio_bit_reset ( GPIOE, GPIO_PIN_0 );   
            break;
        case Led5:
            gpio_bit_reset ( GPIOE, GPIO_PIN_1 );
            break;  
        case AllLeds:
         gpio_bit_reset ( GPIOC, GPIO_PIN_0 | GPIO_PIN_2 );
         gpio_bit_reset ( GPIOE, GPIO_PIN_0 | GPIO_PIN_1);        
        break;
    }
}



/* retarget the C library printf function to the USART */
int fputc(int ch, FILE *f)
{
    usart_data_transmit(USART1, (uint8_t)ch);
    while(RESET == usart_flag_get(USART1, USART_FLAG_TBE));
    return ch;
}

