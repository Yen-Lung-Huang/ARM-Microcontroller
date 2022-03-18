#include "servo.h"
extern ServoTypeDef servo[12];

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

uint16_t reverse_pwm(ServoTypeDef* servo, uint16_t pwm_value)
{
	return servo->pwm_max - (pwm_value - servo->pwm_min);
}

void servo_pwm_set(ServoTypeDef* servo, uint16_t pwm_value)
{
	if(pwm_value < servo->pwm_min){
		pwm_value = servo->pwm_min;
	}
	else if(pwm_value > servo->pwm_max){
		pwm_value = servo->pwm_max;
	}
	if(servo->reverse == true){
		pwm_value = reverse_pwm(servo,pwm_value);
	}
	*(timer_ch2ccr(servo->timer,servo->channel)) = pwm_value;
	servo->pwm_value = pwm_value;
	servo->return_pwm = pwm_value;
}

void servo_wild_set(ServoTypeDef* servo, uint16_t pwm_value)
{
	if(pwm_value >= servo->pwm_min && pwm_value <= servo->pwm_max){
		servo_pwm_set(servo, reverse_pwm(servo,pwm_value));
	}
	else{
		*(timer_ch2ccr(servo->timer,servo->channel)) = pwm_value;
		servo->pwm_value = pwm_value;
	}
}

void arm_pwm_set(uint16_t pwm_0, uint16_t pwm_1, uint16_t pwm_2, uint16_t pwm_3, uint16_t pwm_4)
{
	uint16_t pwm_value[]={pwm_0, pwm_1, pwm_2, pwm_3, pwm_4};
	for(int i=0;i<=4;i++){
		servo_pwm_set(&servo[i],pwm_value[i]);
		if(i==1){
			servo_pwm_set(&servo[5],pwm_value[i]);
		}
	}
}
