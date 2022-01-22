#include "gd32103c_start.h"

void user_key_init(void)
{
	// Enable clock for GPIOA
	rcu_periph_clock_enable(RCU_GPIOA);
	// Configure PA0 as in-floating input
	gpio_init(GPIOA,GPIO_MODE_IPD,GPIO_OSPEED_50MHZ,GPIO_PIN_0);
}

void led_init(void)
{
	// Enable clock for GPIOC
	rcu_periph_clock_enable(RCU_GPIOC);
	// Configure PC6 as push-pull output
	gpio_init(GPIOC,GPIO_MODE_OUT_PP,GPIO_OSPEED_50MHZ,GPIO_PIN_6);
}

bool user_key(void) // Read the state of the user_key(PA0).
{
	return gpio_input_bit_get (GPIOA, GPIO_PIN_0);
}

void led(bool status) //Set LED2(PC2) on/off.
{
	gpio_bit_write(GPIOC, GPIO_PIN_6, status);
}
