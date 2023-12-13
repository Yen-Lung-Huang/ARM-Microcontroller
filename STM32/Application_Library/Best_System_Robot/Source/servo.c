#include "servo.h"
//extern PWM_TypeDef servo[];

/* Math--------------------------------------------------------*/
float map(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

/* Servo Motors Configuration--------------------------------------------------------*/
PWM_TypeDef pwm_constructor(PWM_TypeDef pwm_struct)
{
	pwm_struct.complementary?
	HAL_TIMEx_PWMN_Start(pwm_struct.timer,pwm_struct.channel):
	HAL_TIM_PWM_Start(pwm_struct.timer,pwm_struct.channel);
	return pwm_struct;
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
uint16_t reverse_pwm(PWM_TypeDef* servo, uint16_t pwm_value)
{
	return servo->pwm_min + servo->pwm_max - pwm_value;
}

float reverse_physical(PWM_TypeDef* servo, float physical_value)
{
	return servo->physical_min + servo->physical_max - physical_value;
}

int pwm_set_func(PWM_TypeDef* servo, ...) {
  uint16_t pwm_value;
  bool limit;
  va_list args;
  va_start(args, servo); // 初始化可變參數列表
  pwm_value = (uint16_t)va_arg(args, int); // 獲取第一個可變參數，類型為int，然後轉換為uint16_t
  limit = (bool)va_arg(args, int); // 獲取第二個可變參數，類型為int，然後轉換為bool
  va_end(args); // 釋放可變參數列表
	const uint16_t duty_cycle_min = 20; // min: 18
	
	// 根據 limit 的值來決定是否執行限制 PWM 值的代碼
	if(limit == true){
		if(pwm_value < servo->pwm_min){
			pwm_value = servo->pwm_min;
		}
		else if(pwm_value > servo->pwm_max){
			pwm_value = servo->pwm_max;
		}
	}

	servo->pwm_value = pwm_value; // 儲存不被限制的 PWM 值
	
	uint16_t pwm_set_value = get_limit_pwm(servo); // 獲取實際使用的 PWM 值
	
	if(pwm_set_value < duty_cycle_min){
		pwm_set_value = duty_cycle_min;
	}
	
	*(timer_ch2ccr(servo->timer,servo->channel)) = pwm_set_value;
	if(servo->latch == true){
		//HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET); // for Relay
	}
	return pwm_value;
}

void pwm_physical_set(PWM_TypeDef* servo, float physical_value)
{
	uint16_t pwm_value=map(physical_value,servo->physical_min,servo->physical_max,servo->pwm_min,servo->pwm_max);
	pwm_set(servo,pwm_value);
	if(servo->latch == true && servo->pwm_value == 0){
		//HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET); // for Relay
	}
}

void all_pwm_stop(void)
{
	for(int i=0; i<=11; i++){
		//servo_pwm_set(&servo[i], 0, false);
	}
}


/* Servo Motor Returns Infomation--------------------------------------------------------*/

float get_pwm_physical(PWM_TypeDef* servo)
{
	return map(servo->pwm_value,servo->pwm_min,servo->pwm_max,servo->physical_min,servo->physical_max);
}

void pwm_stop(PWM_TypeDef* servo)
{
	pwm_set(servo, 0, false);
}


// 這個函數接收一個 servo 物件的指標，並回傳它的實際使用的 PWM 占空比
uint16_t get_limit_pwm(PWM_TypeDef* servo)
{
    uint16_t limit_pwm = servo->pwm_value; // 先將 pwm_value 複製給 limit_pwm
    if (servo->reverse == true) // 如果 reverse 為 true，則進行反轉的運算
    {
        limit_pwm = reverse_pwm(servo,limit_pwm);
    }
    if (servo->offset != 0) // 如果 offset 不為零，則加上 offset
    {
        limit_pwm = limit_pwm + servo->offset;
    }
    if(limit_pwm < servo->pwm_min){ // 如果 limit_pwm 小於 pwm_min，則設為 pwm_min
        limit_pwm = servo->pwm_min;
    }
    if(limit_pwm > servo->pwm_max){ // 如果 limit_pwm 大於 pwm_max，則設為 pwm_max
        limit_pwm = servo->pwm_max;
    }
    return limit_pwm; // 回傳 limit_pwm
}





