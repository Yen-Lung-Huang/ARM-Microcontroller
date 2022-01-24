#include "gd32f10x.h"
#include "gd32f10x_rcu.h"
#include "gd32f10x_gpio.h"

#include <stdbool.h>
void delay(int a);

int main(void){
	// Enable clock for GPIOA
	rcu_periph_clock_enable(RCU_GPIOA);
	// Configure PA0 as in-floating input
	gpio_init(GPIOA,GPIO_MODE_IPD,GPIO_OSPEED_50MHZ,GPIO_PIN_0);
	// Enable clock for GPIOC
	rcu_periph_clock_enable(RCU_GPIOC);
	// Configure PC6 as push-pull output
	gpio_init(GPIOC,GPIO_MODE_OUT_PP,GPIO_OSPEED_50MHZ,GPIO_PIN_6);
	
	bool buttonState= true, booleanState= false; //true:按鈕最後已放,false:按鈕最後未放
	
  while (1)
 {
	 if (gpio_input_bit_get (GPIOA, GPIO_PIN_0) == true && buttonState == true) { //按鈕目前是按下的且按鈕最後是放開的
    buttonState = false; //按鈕最後狀態改為"不是放開"
    booleanState = !booleanState;
		gpio_bit_write(GPIOC, GPIO_PIN_6,booleanState);
  }
  else if (gpio_input_bit_get (GPIOA, GPIO_PIN_0) == false && buttonState == false) { //按鈕目前是放開的且按鈕最後是不是放開的
    buttonState = true; //按鈕最後狀態改為"放開"
  }
 }
}
