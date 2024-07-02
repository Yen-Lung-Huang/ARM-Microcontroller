#include "servo.h"
//extern PWM_TypeDef servo[];

/* Math--------------------------------------------------------*/
float map(float x, float in_min, float in_max, float out_min, float out_max)
{
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

/* Servo Configuration--------------------------------------------------------*/
PWM_TypeDef pwm_constructor(PWM_TypeDef pwm_struct)
{
#if defined(__STM32L0xx_HAL_H)
    HAL_TIM_PWM_Start(pwm_struct.timer,pwm_struct.channel);
#elif defined(__STM32F4xx_HAL_H)
    pwm_struct.complementary?
    HAL_TIMEx_PWMN_Start(pwm_struct.timer,pwm_struct.channel):
    HAL_TIM_PWM_Start(pwm_struct.timer,pwm_struct.channel);
#endif
    return pwm_struct;
}


//Robot arm servos initialization.
PWM_TypeDef servo[3];
void servos_init(void)
{
    servo[S1] = pwm_constructor((PWM_TypeDef) {
        .timer=&htim21, .channel=TIM_CHANNEL_1, .pwm_min=26,\
                                 .pwm_max=123, .physical_min=-90, .physical_max=90, .offset=0,.pwm_value=0,\
                                          .reverse=false, .complementary=false, .latch=false
    });
    servo[S2] = pwm_constructor((PWM_TypeDef) {
        .timer=&htim21, .channel=TIM_CHANNEL_2, .pwm_min=26,\
                                 .pwm_max=115, .physical_min=0, .physical_max=180, .offset=0,.pwm_value=0,\
                                          .reverse=true, .complementary=false, .latch=false
    });

    servo[S3] = pwm_constructor((PWM_TypeDef) {
        .timer=&htim2, .channel=TIM_CHANNEL_4, .pwm_min=118-(40*(118-25)/180),\
                                .pwm_max=118, .physical_min=0, .physical_max=40, .offset=0,.pwm_value=0,\
                                         .reverse=true, .complementary=false, .latch=false
    });

    /*
    servo[S3] = pwm_constructor((PWM_TypeDef) { // MKS HBL575: pwm= 29~122, angle= 120°
        .timer=&htim2, .channel=TIM_CHANNEL_4, .pwm_min=29,\
                                .pwm_max=122-(60*(122-29)/120), .physical_min=0, .physical_max=60, .offset=0,.pwm_value=0,\
                                         .reverse=false, .complementary=false, .latch=false
    });
    */
}


volatile uint32_t* timer_ch2ccr(TIM_HandleTypeDef* timer, uint32_t channel)
{
    switch(channel) {
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


/* Servo Control--------------------------------------------------------*/
uint16_t reverse_pwm(PWM_TypeDef* servo, uint16_t pwm_value)
{
    return servo->pwm_min + servo->pwm_max - pwm_value;
}


float reverse_physical(PWM_TypeDef* servo, float physical_value)
{
    return servo->physical_min + servo->physical_max - physical_value;
}



// 定義一個宏，表示 PWM 的最小占空比
#define PWM_DUTY_CYCLE_MIN 20

void pwm_set(PWM_TypeDef* servo, uint16_t pwm_value, bool limit) // Set PWM value and limit if required
{
    // Save the unrestricted PWM value
    servo->pwm_value = pwm_value;

    // Apply limits if needed
    if (limit) {
        pwm_value = pwm_get_limit(servo);
    }

    // Set PWM output
    *(timer_ch2ccr(servo->timer, servo->channel)) = pwm_value;

    // Control relay if latch is true
    if (servo->latch) {
        // HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET); // for Relay
    }
}



// Define a function to set the PWM value according to the physical angle and the limit with fixed arguments
void pwm_physical_set(PWM_TypeDef *servo, float physical_value, bool limit)
{
    // Check the validity of the arguments
    if (servo == NULL) {
        return;    // Invalid pointer
    }

    // Apply reverse logic if necessary
    if (limit && servo->reverse) {
        physical_value = reverse_physical(servo, physical_value);
    }

    // Apply limits to the physical value
    if (limit) {
        if (physical_value < servo->physical_min) {
            physical_value = servo->physical_min;
        }
        if (physical_value > servo->physical_max) {
            physical_value = servo->physical_max;
        }
    }

    // Calculate the PWM value for the physical value
    uint16_t pwm_value = map(physical_value, servo->physical_min, servo->physical_max, servo->pwm_min, servo->pwm_max);

    // Set the PWM value
    pwm_set(servo, pwm_value, limit);
}

// Define a function to control the servo angle with fixed arguments
void servo_control(PWM_TypeDef *servo, float servo_input, bool mode, bool limit)
{
    // Check the validity of the arguments
    if (servo == NULL) {
        return;    // Invalid pointer
    }

    // Check the mode parameter
    if (mode == PWM) { // If the mode is PWM
        // Set the PWM value
        pwm_set(servo, (int)servo_input, limit);
    } else if (mode == ANGLE) { // If the mode is ANGLE
        // Set the PWM value according to the servo angle
        pwm_physical_set(servo, servo_input, limit);
    }
}


void pwm_stop(PWM_TypeDef* servo)
{
    pwm_set(servo, 0, false);
}

void all_pwm_stop(void)
{
    for(int i=S1; i<=S3; i++) {
        pwm_stop(&servo[i]);
    }
}


/* Servo Motor Returns Infomation--------------------------------------------------------*/

float pwm_get_physical(PWM_TypeDef* servo)
{
    return map(servo->pwm_value,servo->pwm_min,servo->pwm_max,servo->physical_min,servo->physical_max);
}


uint16_t pwm_get_limit(PWM_TypeDef* servo)
{
    uint16_t limit_pwm = servo->pwm_value;

    // Apply offset if necessary
    if (servo->offset != 0) {
        limit_pwm = limit_pwm + servo->offset;
    }
    // Enforce PWM limits
    if(limit_pwm < servo->pwm_min) {
        limit_pwm = servo->pwm_min;
    }
    if(limit_pwm > servo->pwm_max) {
        limit_pwm = servo->pwm_max;
    }
    return limit_pwm; // Return limited PWM value
}


