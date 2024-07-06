/**
*@file: lead_easy.c
*@brief: STM32F407 GPIOD Pin 12,13,14,15 user leds easy example hal driver
*/

/**
*@note: In both .h and .c files, uncomment one of the examples below, which you want to get activated
*/
//#define Example_1 
//#define Example_2 
//#define Example_3
//#define Example_4	
#define Example_1

/*Includes---------------------------------------------------------*/
#include "led_easy.h"

/*-----------------------------------------------------------------*/

#ifdef Example_1
/************************Example 1**********************************/
/*Private functions----------------------------------------------*/
/**
*@brief: ledx() function is for turning on&off GPIOD user Leds.
*@param: led_p is GPIOD pin number, led_s is GPIOD pin state; on or off.
*@retval: none
*/
void ledx(led_pin_t led_p, led_state_t led_s){
	
	uint16_t gpio_pin;
	GPIO_PinState pin_state;
		
	if(led_p == D12)
		gpio_pin = GPIO_PIN_12;
	else if(led_p == D13)
		gpio_pin = GPIO_PIN_13;
	else if(led_p == D14)
		gpio_pin = GPIO_PIN_14;
	else if(led_p == D15)
		gpio_pin = GPIO_PIN_15;
	else if(led_p == All)
		gpio_pin = GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
		
	if(led_s == on) 
		pin_state = GPIO_PIN_SET;
	else if(led_s == off) 
		pin_state = GPIO_PIN_RESET;
	
	HAL_GPIO_WritePin(GPIOD, gpio_pin, pin_state); 
	
}

/*-----------------------------------------------------------------*/
/*******************************************************************/
#endif //Example_1


#ifdef Example_2
/************************Example 2**********************************/
/*Private functions------------------------------------------------*/
/**
*@brief: ledx() function is for turning on&off GPIOD user Leds.
*@param: led_p is GPIOD pin number, led_s is GPIOD pin state; on or off.
*@retval: none
*/
void ledx(uint16_t led_p, led_state_t led_s){
	
	GPIO_PinState pin_state;
	
	if(led_s == on) pin_state = GPIO_PIN_SET;
	else if(led_s == off) pin_state = GPIO_PIN_RESET;
	
	HAL_GPIO_WritePin(GPIOD, led_p, pin_state); 
	
}

/*-----------------------------------------------------------------*/
/*******************************************************************/
#endif //Example_2


#ifdef Example_3
/************************Example 3**********************************/
/*Private functions------------------------------------------------*/
/**
*@brief: ledx() function is for turning on&off GPIOD user Leds.
*@param: led_p is GPIOD pin number, led_s is GPIOD pin state; on or off.
*@retval: none
*/
void ledx(uint16_t led_p, led_state_t led_s){
		
	static GPIO_PinState pin_state; //static means a variable or function can't be accessed by other files.
	
	led.D12 = 2;
	led.D13 = 3;
	led.D14 = 4;
	led.D15 = 5;
	led.D12_D13 = 23;
	led.D12_D14 = 24;
	led.D12_D15 = 25;
	led.D13_D14 = 34;
	led.D13_D15 = 35;
	led.D14_D15 = 45;
	led.D12_D13_D14 = 234;
	led.D12_D13_D15 = 235;
	led.D12_D14_D15 = 245;
	led.D13_D14_D15 = 345;
	led.All = 2345;
	
	if(led_p == 2) led_p = GPIO_PIN_12;
	else if(led_p == 3) led_p = GPIO_PIN_13;
	else if(led_p == 4) led_p = GPIO_PIN_14;
	else if(led_p == 5) led_p = GPIO_PIN_15;
	else if(led_p == 23) led_p = GPIO_PIN_12|GPIO_PIN_13;
	else if(led_p == 24) led_p = GPIO_PIN_12|GPIO_PIN_14;
	else if(led_p == 25) led_p = GPIO_PIN_12|GPIO_PIN_15;
	else if(led_p == 34) led_p = GPIO_PIN_13|GPIO_PIN_14;
	else if(led_p == 35) led_p = GPIO_PIN_13|GPIO_PIN_15;
	else if(led_p == 45) led_p = GPIO_PIN_14|GPIO_PIN_15;
	else if(led_p == 234) led_p = GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14;
	else if(led_p == 235) led_p = GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_15;
	else if(led_p == 245) led_p = GPIO_PIN_12|GPIO_PIN_14|GPIO_PIN_15;
	else if(led_p == 345) led_p = GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
	else if(led_p == 2345) led_p = GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
	
	if(led_s == on) pin_state = GPIO_PIN_SET;
	else if(led_s == off) pin_state = GPIO_PIN_RESET;
	
	HAL_GPIO_WritePin(GPIOD, led_p, pin_state); 
	
}

/*-----------------------------------------------------------------*/
/*******************************************************************/
#endif //Example_3


#ifdef Example_4
/************************Example 4**********************************/
/*Private functions------------------------------------------------*/
/**
*@brief: ledx() function is for turning on&off GPIOD user Leds.
*@param: led_p is GPIOD pin number, led_s is GPIOD pin state; on or off.
*@retval: none
*/
void ledx(uint16_t led_p, led_state_t led_s){
	
	static GPIO_PinState pin_state;
	static int led_s_indeks = 0;
	
	if(led_s != toggle) led_s_indeks = 0;
  else led_s_indeks = 1;	
	
	switch(led_s_indeks){	
		case 0:
			
			if(led_s == on) pin_state = GPIO_PIN_SET;
	    else if(led_s == off) pin_state = GPIO_PIN_RESET;
		  
		  HAL_GPIO_WritePin(GPIOD, led_p, pin_state);	
			break;
		
		case 1:
			
			HAL_GPIO_TogglePin(GPIOD, led_p);
			break;
	}
	
}

/*-----------------------------------------------------------------*/
/*******************************************************************/
#endif //Example_4


#ifdef Example_5
/************************Example 5**********************************/
/*Private functions------------------------------------------------*/
/**
*@brief: ledx() function is for turning on&off GPIOD user Leds.
*@param: led_p is GPIOD pin number, led_s is GPIOD pin state; on or off.
*@retval: none
*/
void ledx(uint16_t led_p, led_state_t led_s, uint32_t toggle_delay){
	
	static GPIO_PinState pin_state;
	static int led_s_indeks = 0;
	
	//for on-off processes except for toggle, the toggle_delay must be "0".
	if(((led_s == on) || (led_s == off)) && toggle_delay == 0) led_s_indeks = 1;
  else if(led_s == toggle) led_s_indeks = 2;
  else led_s_indeks = 0;	
	
	switch(led_s_indeks){	
		case 1:
			
			if(led_s == on) pin_state = GPIO_PIN_SET;
	    else if(led_s == off) pin_state = GPIO_PIN_RESET;
		  
		  HAL_GPIO_WritePin(GPIOD, led_p, pin_state);	
			break;
		
		case 2:
				  
			HAL_GPIO_TogglePin(GPIOD, led_p);
		  HAL_Delay(toggle_delay);
			break;
	}
	
}

/*-----------------------------------------------------------------*/
/*******************************************************************/
#endif //Example_5

/*************************END OF FILE*******************************/
