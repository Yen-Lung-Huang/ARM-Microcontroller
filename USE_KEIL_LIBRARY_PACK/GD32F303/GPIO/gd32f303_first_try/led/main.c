/*!
    \file  main.c
    \brief running led

    \version 2017-02-10, V1.0.0, firmware for GD32F30x
    \version 2018-10-10, V1.1.0, firmware for GD32F30x
    \version 2018-12-25, V2.0.0, firmware for GD32F30x
*/

/*
    Copyright (c) 2018, GigaDevice Semiconductor Inc.

    All rights reserved.

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


#define DELAY_TIME 300
#include "my_board.h"
#include "systick.h"
#include <stdio.h>

/*!
    \brief      main function
    \param[in]  none
    \param[out] none
    \retval     none
*/
int main(void)
{
    systick_config();
    gd_eval_led_init(LED2);
    gd_eval_led_init(LED3);
    gd_eval_led_init(LED4);
    gd_eval_led_init(LED1);
		for(uint8_t cnt=8; cnt<16; cnt++){	
			led_init(3, cnt);	// PD8~16
		}	
		led_init(2, 0);	// PC0
		led_init(2, 2);	// PC2
		led_init(4, 0);	// PE0
		led_init(4, 1);	// PE1
				led_on(2, 0);
				delay_1ms(DELAY_TIME);
				led_on(2, 2);
				delay_1ms(DELAY_TIME);
				led_on(4, 0);
				delay_1ms(DELAY_TIME);
				led_on(4, 1);
				delay_1ms(DELAY_TIME);
		led_off(2, 0);
		delay_1ms(DELAY_TIME);
		led_off(2, 2);
		delay_1ms(DELAY_TIME);
		led_off(4, 0);
		delay_1ms(DELAY_TIME);
		led_off(4, 1);
		delay_1ms(DELAY_TIME);
    while(1){

			
        /* turn on led2, turn off led5 */
        gd_eval_led_on(LED1);
        gd_eval_led_off(LED4);
        delay_1ms(DELAY_TIME);
        /* turn on led3, turn off led2 */
        gd_eval_led_on(LED2);
        gd_eval_led_off(LED1);
        delay_1ms(DELAY_TIME);
        /* turn on led4, turn off led3 */
        gd_eval_led_on(LED3);
        gd_eval_led_off(LED2);
        delay_1ms(DELAY_TIME);
        /* turn on led5, turn off led4 */
        gd_eval_led_on(LED4);
        gd_eval_led_off(LED3);
        delay_1ms(DELAY_TIME);
			
				for(uint8_t cnt=8; cnt<16; cnt++){
					led_on(3, cnt);
					delay_1ms(100);
					led_off(3, cnt);
				}
    }
}
