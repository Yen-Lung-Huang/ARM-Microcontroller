#include "stm32f4xx_hal.h"

void configureLEDpins(void);
void msDelay(uint32_t msTime);

int main(void)
{
	configureLEDpins();
	
	while(1)
	{
		HAL_GPIO_TogglePin(GPIOF,GPIO_PIN_9|GPIO_PIN_10);
		//msDelay(1000);
		HAL_Delay(1000);
	}
}

void configureLEDpins(void)
{
	__HAL_RCC_GPIOF_CLK_ENABLE();
	
	GPIO_InitTypeDef myLEDConfig;
	myLEDConfig.Mode = GPIO_MODE_OUTPUT_PP;
	myLEDConfig.Pin = GPIO_PIN_9|GPIO_PIN_10;
	
	HAL_GPIO_Init(GPIOF, &myLEDConfig);
}

void msDelay(uint32_t msTime)
{
	HAL_Delay(msTime);
	//for(uint32_t i=0; i<msTime*4000; i++);
}
