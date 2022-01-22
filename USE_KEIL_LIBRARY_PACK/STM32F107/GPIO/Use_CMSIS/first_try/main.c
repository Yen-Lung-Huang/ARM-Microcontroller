#include<stm32f407xx.h>
//#include "stm32f4xx.h"

#include "led.h"
 
void delay_ms(int ms)
{
	int i,j;
	for(i=0; i<ms; i++)
		for(j=0; j<1000000;j++);
}


int main(void)
{
	LED_Init();//初始化LED
	
	while(1)
	{
		delay_ms(1000);//延時1秒
		GPIOF_BSRR |= (1<<9);   //對位置1 關閉LED
		delay_ms(1000);
		GPIOF_BSRR |= (1<<25); //對位清0 點亮LED
	}
	
	return 0;
	
}
