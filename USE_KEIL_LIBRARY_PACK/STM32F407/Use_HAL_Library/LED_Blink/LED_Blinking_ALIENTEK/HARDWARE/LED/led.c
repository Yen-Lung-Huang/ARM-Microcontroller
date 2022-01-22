#include "led.h"
#include "stm32f4xx.h"


void LED_Init(void)
{

 RCC->AHB1ENR|= 1<<5;
	
	//PF9
 GPIOF->MODER &= ~(3<<2*9);
 GPIOF->MODER |= 1<<(2*9);
	
 GPIOF->OSPEEDR &= ~(3<<2*9);
 GPIOF->OSPEEDR |= 2<<(2*9);
	
 GPIOF->PUPDR &= ~(3<<2*9);
 GPIOF->PUPDR |=1<<(2*9);
	
	GPIOF->OTYPER &= ~(1<<9);
	GPIOF->OTYPER |=0<<9;
	
	GPIOF->ODR|= 1<<9;//1
	//GPIOF->ODR&=~(1<<9);//0
	//PF10-
	
	 GPIOF->MODER &= ~(3<<2*10);
 GPIOF->MODER |= 1<<(2*10);
	
 GPIOF->OSPEEDR &= ~(3<<2*10);
 GPIOF->OSPEEDR |= 2<<(2*10);
	
 GPIOF->PUPDR &= ~(3<<2*10);
 GPIOF->PUPDR |=1<<(2*10);
	
	GPIOF->OTYPER &= ~(1<<10);
	GPIOF->OTYPER |=0<<10;
	
	GPIOF->ODR|= 1<<10;
	


}

