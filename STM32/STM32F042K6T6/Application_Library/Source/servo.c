#include "servo.h"

ServoTypeDef servo_constructor(ServoTypeDef servo_struct)
{
	HAL_TIM_PWM_Start(servo_struct.timer,servo_struct.channel);
	return servo_struct;
}

void servo_pwm_set(ServoTypeDef* servo, unsigned int pwm_value)
{
	*(timer_ch2ccr(servo->timer,servo->channel)) = pwm_value;
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

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
	if(GPIO_Pin == GPIO_PIN_3 && HAL_GetTick()-last_time >= 100){
		last_time = HAL_GetTick();
		if( HAL_GetTick()-sub_last_time >= 300){
			last_time = HAL_GetTick();
			sub_last_time = HAL_GetTick();
			if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_4)==false){
					rotate_dir = true;
				}
			else if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_4)==true){
				rotate_dir = false;
			}
		}
		if(servo[selected_servo].pwm_value+rotate_dir*2-1 < servo[selected_servo].pwm_min || servo[selected_servo].pwm_value == 0)
			servo[selected_servo].pwm_value = servo[selected_servo].pwm_min;
		else if(servo[selected_servo].pwm_value+rotate_dir*2-1 > servo[selected_servo].pwm_max || servo[selected_servo].pwm_value == 65535)
			servo[selected_servo].pwm_value = servo[selected_servo].pwm_max;
		else
			servo[selected_servo].pwm_value += rotate_dir*2-1;
		
		printf("servo[%d]= %d\r\n",selected_servo,servo[selected_servo].pwm_value);
		
	}
	if(GPIO_Pin == GPIO_PIN_0){
		selected_servo = 1;
	}
	if(GPIO_Pin == GPIO_PIN_8){
		selected_servo = 2;
	}
	if(GPIO_Pin == GPIO_PIN_9){
		selected_servo = 3;
	}
	if(GPIO_Pin == GPIO_PIN_10){
		selected_servo = 4;
	}
	if(GPIO_Pin == GPIO_PIN_11){
		selected_servo = 5;
	}
	if(selected_servo!=selected_servo_prev){
		printf("servo[%d]= %d\r\n",selected_servo,servo[selected_servo].pwm_value);
		selected_servo_prev=selected_servo;
	}
}
