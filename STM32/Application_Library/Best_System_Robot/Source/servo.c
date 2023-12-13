#include "servo.h"
//extern ServoTypeDef servo[];

/* Math--------------------------------------------------------*/
float map(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

/* Servo Motors Configuration--------------------------------------------------------*/
ServoTypeDef servo_constructor(ServoTypeDef servo_struct)
{
	servo_struct.complementary?
	HAL_TIMEx_PWMN_Start(servo_struct.timer,servo_struct.channel):
	HAL_TIM_PWM_Start(servo_struct.timer,servo_struct.channel);
	return servo_struct;
}

volatile uint32_t* timer_ch2ccr(TIM_HandleTypeDef* timer, uint32_t channel)
{
	switch(channel){
		case TIM_CHANNEL_1:
			return &(timer->Instance->CCR1);
		case TIM_CHANNEL_2:
			return &(timer->Instance->CCR2);
		case TIM_CHANNEL_3:
			return &(timer->Instance->CCR3);
		case TIM_CHANNEL_4:
			return &(timer->Instance->CCR4);
	}
	return &(timer->Instance->CCR1); // A random return value for default, not nesseary.
}


/* Servo Motors Control--------------------------------------------------------*/
uint16_t reverse_pwm(ServoTypeDef* servo, uint16_t pwm_value)
{
	return servo->pwm_min + servo->pwm_max - pwm_value;
}

float reverse_physical(ServoTypeDef* servo, float physical_value)
{
	return servo->physical_min + servo->physical_max - physical_value;
}

void servo_pwm_set(ServoTypeDef* servo, uint16_t pwm_value)
{
	const uint16_t duty_cycle_min = 20; // min: 18
	
	if(pwm_value < servo->pwm_min){
		pwm_value = servo->pwm_min;
	}
	else if(pwm_value > servo->pwm_max){
		pwm_value = servo->pwm_max;
	}

	servo->pwm_value = pwm_value;
	servo->return_pwm = pwm_value;
	
	if(servo->reverse == true){
		pwm_value = reverse_pwm(servo,pwm_value);
	}
	
	if(servo->latch == true){
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_SET);
	}
	
	uint16_t pwm_set_value = pwm_value + /*(servo->reverse*-2+1)**/servo->offset;
	
	if(pwm_set_value < duty_cycle_min){
		pwm_set_value = duty_cycle_min;
	}
	
	*(timer_ch2ccr(servo->timer,servo->channel)) = pwm_set_value;
}

void servo_wild_set(ServoTypeDef* servo, uint16_t pwm_value)
{
	servo->pwm_value = pwm_value;
	*(timer_ch2ccr(servo->timer,servo->channel)) = pwm_value + servo->offset;
	if(servo->latch == true){
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);
	}
}

void servo_physical_set(ServoTypeDef* servo, float physical_value)
{
	uint16_t pwm_value=map(physical_value,servo->physical_min,servo->physical_max,servo->pwm_min,servo->pwm_max);
	servo_pwm_set(servo,pwm_value);
	if(servo->latch == true && servo->pwm_value == 0){
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);
	}
}

float servo_get_physical(ServoTypeDef* servo)
{
	return map(servo->pwm_value,servo->pwm_min,servo->pwm_max,servo->physical_min,servo->physical_max);
}

void servo_pwm_stop(ServoTypeDef* servo)
{
	servo_wild_set(servo, 0);
}

void all_pwm_stop(void)
{
	for(int i=0; i<=11; i++){
		//servo_wild_set(&servo[i], 0);
	}
}
