/*!
    \file    main.c
    \brief   USART hardware flow control demo
   
    \version 2014-12-26, V1.0.0, demo for GD32F10x
    \version 2017-06-30, V2.0.0, demo for GD32F10x
    \version 2021-04-30, V2.1.0, demo for GD32F10x
*/

/*
    Copyright (c) 2021, GigaDevice Semiconductor Inc.

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
#include "gd32f103b_eval.h"
#include "systick.h"

/* private define ------------------------------------------------------------*/
#define TxBufferSize   (countof(TxBuffer) - 1)
#define RxBufferSize   0xFF
#define countof(a)     (sizeof(a) / sizeof(*(a)))

/* private variables ---------------------------------------------------------*/
uint8_t TxBuffer[] = "\n\rUSART Hyperterminal Hardware Flow Control Example: USART - \
Hyperterminal communication using hardware flow control\n\r";
uint8_t RxBuffer[RxBufferSize];
uint8_t NbrOfDataToTransfer = TxBufferSize;
uint8_t TxCounter = 0;
uint8_t RxCounter = 0;

/* private function prototypes -----------------------------------------------*/
void led_flash(int times);

/*!
    \brief      main function
    \param[in]  none
    \param[out] none
    \retval     none
*/
int main(void)
{
    /* configure systick */
    systick_config();

    /* initialize the LEDs */
    gd_eval_led_init(LED2);
    gd_eval_led_init(LED3);
    gd_eval_led_init(LED4);
    gd_eval_led_init(LED5);

    /* LED flash for test */
    led_flash(1);

    /* enable USART1 clock */
    rcu_periph_clock_enable(RCU_GPIOD);
    rcu_periph_clock_enable(RCU_AF);
    rcu_periph_clock_enable(RCU_USART1);

    /* configure USART1 Tx, Rx, CTS and RTS remap pins */
    gpio_pin_remap_config(GPIO_USART1_REMAP, ENABLE);
    gpio_init(GPIOD, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_4);
    gpio_init(GPIOD, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_5);
    gpio_init(GPIOD, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, GPIO_PIN_3);
    gpio_init(GPIOD, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, GPIO_PIN_6);

    /* USART1 baudrate configuration */
    usart_baudrate_set(USART1, 115200);

    /* configure USART1 RTS and CTS */
    usart_hardware_flow_rts_config(USART1, USART_RTS_ENABLE);
    usart_hardware_flow_cts_config(USART1, USART_CTS_ENABLE);
    
    /* configure USART1 transmitter */
    usart_transmit_config(USART1, USART_TRANSMIT_ENABLE);
    
    /* configure USART1 receiver */
    usart_receive_config(USART1, USART_RECEIVE_ENABLE);
    
    /* enable USART1 */
    usart_enable(USART1);

    /* communication hyperterminal-USART1 using hardware flow control */
    /* send a buffer from USART to hyperterminal */
    while(NbrOfDataToTransfer--){
        usart_data_transmit(USART1, TxBuffer[TxCounter++]);
        while(usart_flag_get(USART1, USART_FLAG_TBE) == RESET);
    }

    /* receive a string (Max RxBufferSize bytes) from the Hyperterminal ended by '\r' (Enter key) */
    do{ 
        if((usart_flag_get(USART1, USART_FLAG_RBNE) != RESET) && (RxCounter < RxBufferSize)){
            RxBuffer[RxCounter] = usart_data_receive(USART1);
            RxCounter++;
        }   
    }while((RxBuffer[RxCounter - 1] != '\r') && (RxCounter != RxBufferSize));

    /* send the received string back to hyperterminal */
    TxCounter = 0;
    NbrOfDataToTransfer = RxCounter;
    while(NbrOfDataToTransfer--){
        usart_data_transmit(USART1, RxBuffer[TxCounter++]);
        while(usart_flag_get(USART1, USART_FLAG_TBE) == RESET);
    }

    while(1){
    }
}

/*!
    \brief      flash the LEDs for test
    \param[in]  times: times to flash the LEDs
    \param[out] none
    \retval     none
*/
void led_flash(int times)
{
    int i;
    for(i = 0; i < times; i++){
        /* turn on all LEDs */
        gd_eval_led_on(LED2);
        gd_eval_led_on(LED3);
        gd_eval_led_on(LED4);
        gd_eval_led_on(LED5);

        /* delay 250 ms */
        delay_1ms(250);

        /* turn off all LEDs */
        gd_eval_led_off(LED2);
        gd_eval_led_off(LED3);
        gd_eval_led_off(LED4);
        gd_eval_led_off(LED5);

        /* delay 250 ms */
        delay_1ms(250);
    }
}
