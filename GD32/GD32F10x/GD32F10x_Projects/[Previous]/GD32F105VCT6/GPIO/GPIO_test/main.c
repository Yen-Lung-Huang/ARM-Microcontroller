#include "gd32f10x.h"
#include "gd32f10x_rcu.h"
#include "gd32f10x_gpio.h"

#include <stdbool.h>
void delay(int a);

int main(void){
	// Enable clock for GPIOB
	rcu_periph_clock_enable(RCU_GPIOB);
	// Configure PA0 as in-floating input
	gpio_init(GPIOB,GPIO_MODE_IPD,GPIO_OSPEED_50MHZ,GPIO_PIN_14);
	// Enable clock for GPIOC
	rcu_periph_clock_enable(RCU_GPIOC);
	// Configure PC6 as push-pull output
	gpio_init(GPIOC,GPIO_MODE_OUT_PP,GPIO_OSPEED_50MHZ,GPIO_PIN_9);
	
	bool buttonState= true, booleanState= false; //true:按鈕最後已放,false:按鈕最後未放
	
  while (1)
 {
	 if (gpio_input_bit_get (GPIOB, GPIO_PIN_14) == true && buttonState == true) { //按鈕目前是按下的且按鈕最後是放開的
    buttonState = false; //按鈕最後狀態改為"不是放開"
    booleanState = !booleanState;
		gpio_bit_write(GPIOC, GPIO_PIN_9,booleanState);
		delay(20000);
  }
  else if (gpio_input_bit_get (GPIOB, GPIO_PIN_14) == false && buttonState == false) { //按鈕目前是放開的且按鈕最後是不是放開的
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
