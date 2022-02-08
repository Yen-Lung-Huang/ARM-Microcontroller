#include "stm32f10x.h"
#include <stdbool.h>
 
static GPIO_InitTypeDef GPIO_InitStruct;
void delay(int a);
 
int main(void)
{
	// Configure PB14 as in-floating input
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);// Enable clock for GPIOB
  GPIO_InitStruct.GPIO_Pin = GPIO_Pin_14;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;
  GPIO_Init(GPIOB, &GPIO_InitStruct);
	
  // Configure PC9 as push-pull output
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);// Enable clock for GPIOC
  GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(GPIOC, &GPIO_InitStruct);
	
	bool buttonState= true, booleanState= false; //true:按鈕最後已放,false:按鈕最後未放
	
  while (1)
 {
	 
	 if (GPIO_ReadInputDataBit (GPIOB, GPIO_Pin_14) == true && buttonState == true) { //按鈕目前是按下的且按鈕最後是放開的
    buttonState = false; //按鈕最後狀態改為"不是放開"
    booleanState = !booleanState;
		GPIO_WriteBit(GPIOC, GPIO_Pin_9,booleanState);
		delay(20000);
  }
  else if (GPIO_ReadInputDataBit (GPIOB, GPIO_Pin_14) == false && buttonState == false) { //按鈕目前是放開的且按鈕最後是不是放開的
    buttonState = true; //按鈕最後狀態改為"放開"
		delay(20000);
  }
 }
}

void delay (int a)
{
 volatile int i,j=0;
 for (i=0 ; i < a ; i++){
	 j++;
 }
 return;
}
