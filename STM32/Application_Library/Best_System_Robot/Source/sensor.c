#include "sensor.h"

/* Buttons--------------------------------------------------------*/

#define DEBOUNCE_DELAY 50 // Debounce delay time 50ms

bool debounce_flag = false;
uint32_t last_debounce_time = 0;


// Main loop or timer interrupt service routine
void CheckButtonState(void)
{
    uint32_t current_time = HAL_GetTick();
    // Check whether the bounce time has been reached
    if(debounce_flag && (current_time - last_debounce_time) >= DEBOUNCE_DELAY) {
        // Read button pin state
        if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_RESET) {
            ms_motor_control(&motor_shield_v1, MS_V1, M1, 0);
        }
        debounce_flag = false; // Reset debounce flag
    }
}


// Interrupt Service Routine
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if(GPIO_Pin == GPIO_PIN_13) {
        uint32_t current_time = HAL_GetTick();
        if(!debounce_flag) {
            last_debounce_time = current_time;
            debounce_flag = true;
        }
    }
    
    // Check if the echo_pin of any HC-SR04 sensor triggered the interrupt
    HC_SR04_HandleInterrupt(GPIO_Pin, hc_sr04, 3);
}

