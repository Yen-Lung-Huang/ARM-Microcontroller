#include "led.h"
 
 
void LED_Init(void)
{
	//使能GPIOF組時鐘
	RCC_AHB1ENR |= (1<<5);   //對位置1
 
	//設置GPIO口的模式
	GPIOF_MODER &= ~(1<<19); //對位清0
	GPIOF_MODER |=  (1<<18); //對位置1
	
	//設置輸出模式為推挽模式
	GPIOF_OTYPER  &= ~(1<<9); //對位清0
	
	//設置速度50MHZ
	GPIOF_OSPEEDR |=  (1<<19);
	GPIOF_OSPEEDR &= ~(1<<18);
	
	//設置為上拉模式
	GPIOF_PUPDR &= ~(1<<19); //對位清0
	GPIOF_PUPDR |=  (1<<18); //對位置1
}
