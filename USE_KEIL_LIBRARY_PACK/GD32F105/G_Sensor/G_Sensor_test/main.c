#include <gd32f10x.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265358979323846

int main(void)
{
	rcu_periph_clock_enable(RCU_GPIOA);
	gpio_init(GPIOC, GPIO_MODE_AIN, GPIO_OSPEED_50MHZ, GPIO_PIN_3);
	
}

void ADC_Init(void)
{
    
}