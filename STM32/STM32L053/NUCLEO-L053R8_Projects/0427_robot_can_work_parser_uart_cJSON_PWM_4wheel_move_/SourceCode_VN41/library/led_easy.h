/**
*@file: led_easy.h
*@brief: STM32F407 GPIOD Pin 12,13,14,15 user leds easy example hal driver
*/

#ifndef LED_EASY_H
#define LED_EASY_H 


#ifdef __cplusplus
extern "C" {
#endif


/**
*@note: In both .h and .c files, uncomment one of the examples below, which you want to get activated
*/
//#define Example_1 //typedef enum method is used
//#define Example_2 //tyedef enum and define methods are used
//#define Example_3	//typedef enum, typedef struct methods and are used
//#define Example_4 //tyedef enum and define methods are used. toggle feature is added in the function.
#define Example_1 //tyedef enum and define methods are used. toggle&toggle_delay feature is added in the function.
	
/*Includes-------------------------------------------------------*/
#include "stm32l0xx_hal.h"
	
/*---------------------------------------------------------------*/

#ifdef Example_1
/************************Example 1********************************/
/*Defines--------------------------------------------------------*/
typedef enum {
	off = 0,
  on,	
}	led_state_t;

typedef enum {
	D12 = 0,
	D13,
	D14,
	D15,
	All
} led_pin_t;

/*---------------------------------------------------------------*/

/*Private functions----------------------------------------------*/
/**
*@brief: ledx() function is for turning on&off GPIOD user Leds.
*@param: led_p is GPIOD pin number, led_s is GPIOD pin state; on or off.
*@retval: none
*/
void ledx(led_pin_t led_p, led_state_t led_s);

//void PWM_wild_control(motor_emun motor, uint8_  t pwm_value);
	
/*---------------------------------------------------------------*/
/*****************************************************************/
#endif //Example_1


#ifdef Example_2
/************************Example 2********************************/
/*Defines--------------------------------------------------------*/
#define led_D12              GPIO_PIN_12 //D12
#define led_D13              GPIO_PIN_13 //D13
#define led_D14              GPIO_PIN_14 //D14
#define led_D15              GPIO_PIN_15 //D15
#define led_D12_D13          GPIO_PIN_12|GPIO_PIN_13 //D12 + D13
#define led_D12_D14          GPIO_PIN_12|GPIO_PIN_14 //D12 + D14
#define led_D12_D15          GPIO_PIN_12|GPIO_PIN_15 //D12 + D15
#define led_D13_D14          GPIO_PIN_13|GPIO_PIN_14 //D13 + D14
#define led_D13_D15          GPIO_PIN_13|GPIO_PIN_15 //D13 + D15
#define led_D14_D15          GPIO_PIN_14|GPIO_PIN_15 //D14 + D15
#define led_D12_D13_D14      GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14 //D12 + D13 + D14
#define led_D12_D13_D15      GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_15 //D12 + D13 + D15
#define led_D12_D14_D15      GPIO_PIN_12|GPIO_PIN_14|GPIO_PIN_15 //D12 + D14 + D15
#define led_D13_D14_D15      GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15 //D13 + D14 + D15
#define led_All              GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15 //D12 + D13 + D14 + D15

typedef enum {
	off = 0,
  on	
}	led_state_t;

/*---------------------------------------------------------------*/

/*Private functions----------------------------------------------*/
/**
*@brief: ledx() function is for turning on&off GPIOD user Leds.
*@param: led_p is GPIOD pin number, led_s is GPIOD pin state; on or off.
*@retval: none
*/
void ledx(uint16_t led_p, led_state_t led_s);
	
/*---------------------------------------------------------------*/
/*****************************************************************/
#endif //Example_2


#ifdef Example_3
/************************Example 3********************************/
/*Defines--------------------------------------------------------*/
typedef enum {
	off = 0,
  on	
}	led_state_t;

typedef struct {
	uint16_t D12;
	uint16_t D13;
	uint16_t D14;
	uint16_t D15;
	uint16_t D12_D13;
  uint16_t D12_D14;
  uint16_t D12_D15;
  uint16_t D13_D14;
	uint16_t D13_D15;
	uint16_t D14_D15;
	uint16_t D12_D13_D14;
  uint16_t D12_D13_D15;
	uint16_t D12_D14_D15;
	uint16_t D13_D14_D15;
	uint16_t All;
} led_pin_t;

extern led_pin_t led; //extern is for preventing the multiply defined of "led" variable. 
                      //It means a variable or function can be accessed by other files.

/*---------------------------------------------------------------*/

/*Private functions----------------------------------------------*/
/**
*@brief: ledx() function is for turning on&off GPIOD user Leds.
*@param: led_p is GPIOD pin number, led_s is GPIOD pin state; on or off.
*@retval: none
*/
void ledx(uint16_t led_p, led_state_t led_s);
	
/*---------------------------------------------------------------*/
/*****************************************************************/
#endif //Example_3


#ifdef Example_4
/************************Example 4********************************/
/*Defines--------------------------------------------------------*/
#define led_D12              GPIO_PIN_12 //D12
#define led_D13              GPIO_PIN_13 //D13
#define led_D14              GPIO_PIN_14 //D14
#define led_D15              GPIO_PIN_15 //D15
#define led_D12_D13          GPIO_PIN_12|GPIO_PIN_13 //D12 + D13
#define led_D12_D14          GPIO_PIN_12|GPIO_PIN_14 //D12 + D14
#define led_D12_D15          GPIO_PIN_12|GPIO_PIN_15 //D12 + D15
#define led_D13_D14          GPIO_PIN_13|GPIO_PIN_14 //D13 + D14
#define led_D13_D15          GPIO_PIN_13|GPIO_PIN_15 //D13 + D15
#define led_D14_D15          GPIO_PIN_14|GPIO_PIN_15 //D14 + D15
#define led_D12_D13_D14      GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14 //D12 + D13 + D14
#define led_D12_D13_D15      GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_15 //D12 + D13 + D15
#define led_D12_D14_D15      GPIO_PIN_12|GPIO_PIN_14|GPIO_PIN_15 //D12 + D14 + D15
#define led_D13_D14_D15      GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15 //D13 + D14 + D15
#define led_All              GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15 //D12 + D13 + D14 + D15

typedef enum {
	off = 0,
  on,
  toggle	
}	led_state_t;

/*---------------------------------------------------------------*/

/*Private functions----------------------------------------------*/
/**
*@brief: ledx() function is for turning on&off GPIOD user Leds.
*@param: led_p is GPIOD pin number, led_s is GPIOD pin state; on, off and toggle.
*@retval: none
*/
void ledx(uint16_t led_p, led_state_t led_s);
	
/*---------------------------------------------------------------*/
/*****************************************************************/
#endif //Example_4


#ifdef Example_5
/************************Example 5********************************/
/*Defines--------------------------------------------------------*/
#define led_D12              GPIO_PIN_12 //D12
#define led_D13              GPIO_PIN_13 //D13
#define led_D14              GPIO_PIN_14 //D14
#define led_D15              GPIO_PIN_15 //D15
#define led_D12_D13          GPIO_PIN_12|GPIO_PIN_13 //D12 + D13
#define led_D12_D14          GPIO_PIN_12|GPIO_PIN_14 //D12 + D14
#define led_D12_D15          GPIO_PIN_12|GPIO_PIN_15 //D12 + D15
#define led_D13_D14          GPIO_PIN_13|GPIO_PIN_14 //D13 + D14
#define led_D13_D15          GPIO_PIN_13|GPIO_PIN_15 //D13 + D15
#define led_D14_D15          GPIO_PIN_14|GPIO_PIN_15 //D14 + D15
#define led_D12_D13_D14      GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14 //D12 + D13 + D14
#define led_D12_D13_D15      GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_15 //D12 + D13 + D15
#define led_D12_D14_D15      GPIO_PIN_12|GPIO_PIN_14|GPIO_PIN_15 //D12 + D14 + D15
#define led_D13_D14_D15      GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15 //D13 + D14 + D15
#define led_All              GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15 //D12 + D13 + D14 + D15

typedef enum {
	off = 0,
  on,
  toggle	
}	led_state_t;

/*---------------------------------------------------------------*/

/*Private functions----------------------------------------------*/
/**
*@brief: ledx() function is for turning on&off GPIOD user Leds.
*@param: led_p is GPIOD pin number, led_s is GPIOD pin state; on, off and toggle, toggle_delay is a delay for toggle process.
*@retval: none
*/
void ledx(uint16_t led_p, led_state_t led_s, uint32_t toggle_delay);
	
/*---------------------------------------------------------------*/
/*****************************************************************/
#endif //Example_5


#ifdef __cplusplus
}
#endif

#endif


/*************************END OF FILE*****************************/
