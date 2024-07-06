#include "gd32f10x.h"
#include <stdbool.h>

int main(void)
{
	bool buttonState = true; // true: The button has been released. false: The button has been pressed.
	bool ledState = false; // true: LED on. false: LED off. 
	
	rcu_periph_clock_enable(RCU_GPIOA); // Enable GPIOA clock for PA0 button.
	rcu_periph_clock_enable(RCU_GPIOC); // Enable GPIOA clock for PC0 LED.
	gpio_init(GPIOA, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, GPIO_PIN_0); // Set PA0 as input GPIO for button.
	gpio_init(GPIOC, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_0); // Set PC0 as output GPIO for LED.
	
	while(1){
		if(buttonState == true && !(bool)gpio_input_bit_get(GPIOA,GPIO_PIN_0) == true){
			ledState = !ledState;
			gpio_bit_write(GPIOC,GPIO_PIN_0,(FlagStatus)ledState);
			buttonState = false;
		}
		else if(buttonState == false && !(bool)gpio_input_bit_get(GPIOA,GPIO_PIN_0) == false){
			buttonState = true;
		}
	}
}
