#include <stdio.h>
#include <stdlib.h>
#include <gd32f10x_gpio.h>
#include <stdbool.h>
#include <time.h>
#include "systick.h"

int main() {
	systick_config();   //工程師寫的功能應用
	rcu_periph_clock_enable(RCU_GPIOE);    // GD 本身的庫
	rcu_periph_clock_enable(RCU_GPIOB);
	gpio_init(GPIOE,GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ,GPIO_PIN_2);
	//gpio_init(GPIOE,GPIO_MODE_IPD, GPIO_OSPEED_50MHZ,GPIO_PIN_3);
	gpio_init(GPIOB,GPIO_MODE_IPD, GPIO_OSPEED_50MHZ,GPIO_PIN_14);
	bool signal, buttonstate = true;
	int counter = 0;
	while (true) {
		delay_1ms(50);
		signal = gpio_input_bit_get(GPIOB,GPIO_PIN_14);
		//gpio_bit_write(GPIOE,GPIO_PIN_2,ledlight);   // buttonstate 是不是 放開的
		if (signal == true && buttonstate == true) {
			//ledlight = !ledlight;
			counter++;
			buttonstate = false;
			for (int i = 0; i < 1000000; i++);
		}
		else if (signal == false && buttonstate == false) buttonstate = true;
		delay_1ms(1);
		switch (counter) {
			case 0: gpio_bit_write(GPIOE,GPIO_PIN_2, 0); break;
			case 1: gpio_bit_write(GPIOE,GPIO_PIN_2, 1 ); break;
			case 2: while(1){
									gpio_bit_write(GPIOE,GPIO_PIN_2, 1);
									delay_1ms(250);
									gpio_bit_write(GPIOE,GPIO_PIN_2, 0);
									delay_1ms(250);
									if ((signal = gpio_input_bit_get(GPIOB,GPIO_PIN_14)) == 1) {
									counter = 0;
									break;
									}
							}
		}
	}
}
