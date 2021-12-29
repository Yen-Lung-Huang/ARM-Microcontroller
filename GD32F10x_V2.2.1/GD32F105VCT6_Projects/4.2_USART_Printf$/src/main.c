/*!
    \file    main.c
    \brief   USART printf demo

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


#include "main.h"



/*!
    \brief      main function
    \param[in]  none
    \param[out] none
    \retval     none
*/
int main(void)
{

    /* enable peripheral */
    rcu_config();
    /* initialize the LEDs */
    led_init();
    
    /* configure systick */
    systick_config();
    
    /* flash the LEDs for 1 time */
    led_flash(2);
    
    /* configure USART0 */
    com_port_init(USART0);
    
    /* configure TAMPER key */
    button_init(TAMPER, MODE_GPIO);
    
    /* output a message on hyperterminal using printf function */
    printf("\r\n USART printf example: please press the Tamper key \r\n");
    
    /* wait for completion of USART transmission */
    while(RESET == usart_flag_get(USART0 ,USART_FLAG_TC)){
    }
    while(1){
        /* check if the tamper key is pressed */
        if(RESET == button_state_get(TAMPER)){
            delay_1ms(50);
            if(RESET == button_state_get(TAMPER)){
                delay_1ms(50);
                if(RESET == button_state_get(TAMPER)){
                    /* turn on LED3 */
                    LED_ON(Led3);
                    /* output a message on hyperterminal using printf function */
                    printf("\r\n USART printf example \r\n");
                    /* wait for completion of USART transmission */
                    while(RESET == usart_flag_get(USART0, USART_FLAG_TC)){
                    }
                }else{
                    /* turn off LED3 */
                    LED_OFF(Led3);
                }
            }else{
                /* turn off LED3 */
                LED_OFF(Led3);
            }
        }else{
            /* turn off LED3 */
            LED_OFF(Led3);
        }
    }
}

