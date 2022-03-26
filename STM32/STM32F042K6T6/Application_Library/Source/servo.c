#include "servo.h"
extern ServoTypeDef servo[];

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

void servos_init(ServoTypeDef servo[12])
{
	servo[0 ] = servo_init(.timer=&htim2 , .channel=TIM_CHANNEL_2);																											// 0 _Base
	servo[1 ] = servo_init(.timer=&htim2 , .channel=TIM_CHANNEL_4, .reverse=true);																			// 1 _Shoulder   _L
	servo[2 ] = servo_init(.timer=&htim2 , .channel=TIM_CHANNEL_1, .latch=true);																				// 2 _Elbow
	servo[3 ] = servo_init(.timer=&htim3 , .channel=TIM_CHANNEL_1); 																										// 3 _Wrist
	servo[4 ] = servo_init(.timer=&htim3 , .channel=TIM_CHANNEL_2); 																										// 4 _End-effecter
	servo[5 ] = servo_init(.timer=&htim14, .channel=TIM_CHANNEL_1, .offset=3); 																					// 5 _Shoulder   _R
	servo[6 ] = servo_init(.timer=&htim1 , .channel=TIM_CHANNEL_2, .offset=-21); 																				// 6 _Wheel_Front_L
	servo[7 ] = servo_init(.timer=&htim1 , .channel=TIM_CHANNEL_3, .offset=8, .reverse=true);														// 7 _Wheel_Front_R
	servo[8 ] = servo_init(.timer=&htim3 , .channel=TIM_CHANNEL_3, .offset=3, .reverse=true);														// 8 _Wheel_Rear _L
	servo[9 ] = servo_init(.timer=&htim3 , .channel=TIM_CHANNEL_4, .offset=-16); 																				// 9 _Wheel_Rear _R
	servo[10] = servo_init(.timer=&htim1 , .channel=TIM_CHANNEL_1, .physical_min=-1, .physical_max=1); 									// 10_Wheel_Speed_L
	servo[11] = servo_init(.timer=&htim1 , .channel=TIM_CHANNEL_4, .physical_min=-1, .physical_max=1, .reverse=true); 	// 11_Wheel_Speed_R
	
//	for(int i=0; i<=11; i++){
//		servo_pwm_set(&servo[i], servo[i].pwm_value);
//	}
//	HAL_Delay(1200);
//	all_pwm_stop();
}

/* Servo Motors Control--------------------------------------------------------*/
uint16_t reverse_pwm(ServoTypeDef* servo, uint16_t pwm_value)
{
	return servo->pwm_max - (pwm_value - servo->pwm_min);
}

float reverse_physical(ServoTypeDef* servo, float physical_value)
{
	return servo->physical_max - (physical_value - servo->physical_min);
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
	
	uint16_t pwm_set_value = pwm_value + servo->offset;
	
	if(pwm_set_value < duty_cycle_min){
		pwm_set_value = duty_cycle_min;
	}
	
	*(timer_ch2ccr(servo->timer,servo->channel)) = pwm_set_value;
}

void servo_wild_set(ServoTypeDef* servo, uint16_t pwm_value)
{
	servo->pwm_value = pwm_value;
	*(timer_ch2ccr(servo->timer,servo->channel)) = pwm_value + servo->offset;
}

void servo_physical_set(ServoTypeDef* servo, float physical_value)
{
	uint16_t pwm_value=map(physical_value,servo->physical_min,servo->physical_max,servo->pwm_min,servo->pwm_max);
	servo_pwm_set(servo,pwm_value);
}

float servo_get_degree(ServoTypeDef* servo)
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
		servo_wild_set(&servo[i], 0);
	}
}
