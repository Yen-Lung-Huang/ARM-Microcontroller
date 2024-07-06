#include "gd32f10x.h"
#include "gd32f10x_it.h"
#include <stdbool.h>

#include "systick.h"


int main(void)
{	
	systick_config();
	
	rcu_periph_clock_enable(RCU_GPIOA); // Enable GPIOA clock for PA0 button.
	rcu_periph_clock_enable(RCU_GPIOC); // Enable GPIOC clock for PC0 LED.
	
	rcu_periph_clock_enable(RCU_GPIOE); // Enable GPIOC clock for PE LED.
	
	gpio_init(GPIOA, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, GPIO_PIN_0); // Set PA0 as input GPIO for button.
	gpio_init(GPIOC, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_0); // Set PC0 as output GPIO for LED.
	gpio_init(GPIOC, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_2); // Set PC2 as output GPIO for LED.
	
	//rcu_periph_clock_enable(RCU_AF);
	nvic_irq_enable(EXTI0_IRQn, 1, 0); // enable and set key EXTI interrupt priority
	gpio_exti_source_select(GPIO_PORT_SOURCE_GPIOA, GPIO_PIN_SOURCE_0); // connect key EXTI line to key GPIO pin
	/* configure key EXTI line */
	exti_init(EXTI_0, EXTI_INTERRUPT, EXTI_TRIG_FALLING);
  exti_interrupt_flag_clear(EXTI_0);
	
//	gpio_bit_set(GPIOC,GPIO_PIN_2);
//	delay_1ms(400);
//	gpio_bit_reset(GPIOC,GPIO_PIN_2);
//	delay_1ms(400);
	
	while(1){
	gpio_bit_set(GPIOC,GPIO_PIN_2);
	delay_1ms(400);
	gpio_bit_reset(GPIOC,GPIO_PIN_2);
	delay_1ms(400);
		
	}
}

