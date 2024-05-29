#include "HC-SR04.h"

// Initialize data for three HC-SR04 sensors
HC_SR04_TypeDef hc_sr04[3] = {
    {GPIOD, GPIO_PIN_2, GPIOC, GPIO_PIN_10, 0.0f, false, false, 0, 0, 0, 0},
    {GPIOD, GPIO_PIN_2, GPIOC, GPIO_PIN_11, 0.0f, false, false, 0, 0, 0, 0},
    {GPIOD, GPIO_PIN_2, GPIOC, GPIO_PIN_12, 0.0f, false, false, 0, 0, 0, 0}
};

// Microsecond delay function
void delay_us(uint16_t us)
{
    __HAL_TIM_SET_COUNTER(&htim6, 0);
    while (__HAL_TIM_GET_COUNTER(&htim6) < us);
}

// Trigger measurement and return distance
float HC_SR04_GetDistance(HC_SR04_TypeDef* hc_sr04)
{
    // Clear TRIG pin
    HAL_GPIO_WritePin(hc_sr04->trig_port, hc_sr04->trig_pin, GPIO_PIN_RESET);
    delay_us(2); // Wait for 2 microseconds

    // Send a pulse
    HAL_GPIO_WritePin(hc_sr04->trig_port, hc_sr04->trig_pin, GPIO_PIN_SET);
    delay_us(10); // Wait for 10 microseconds
    HAL_GPIO_WritePin(hc_sr04->trig_port, hc_sr04->trig_pin, GPIO_PIN_RESET);

    // Wait for pulse detection to complete or until echo_duration exceeds a maximum value
    const uint32_t max_duration = 50000; // Maximum duration in microseconds
    uint32_t start_time = __HAL_TIM_GET_COUNTER(&htim6);
    while (!hc_sr04->pulseDetected && (__HAL_TIM_GET_COUNTER(&htim6) - start_time) < max_duration)
    {
        // Optionally, add a small delay here to prevent a tight spin loop
        delay_us(10); // Added delay to allow processing of echo
    }
    
    if (!hc_sr04->pulseDetected)
    {
        // Handle timeout situation
        return -1.0f; // Return an error value or handle as appropriate
    }

    // Use the pre-calculated echo_duration for distance calculation
    hc_sr04->distance = (hc_sr04->echo_duration * 0.03432) / 2;

    hc_sr04->pulseDetected = false; // Reset detection flag
    return hc_sr04->distance;
}


// HC-SR04 interrupt handling subroutine
void HC_SR04_HandleInterrupt(HC_SR04_TypeDef* hc_sr04)
{
    static uint32_t last_capture = 0; // Static variable to store the last capture time
    uint32_t current_capture = __HAL_TIM_GET_COUNTER(&htim6);

    if (HAL_GPIO_ReadPin(hc_sr04->echo_port, hc_sr04->echo_pin) == GPIO_PIN_SET)
    {
        if (!hc_sr04->waiting_for_end) // Only update pulseStart if we're not already waiting for a pulse end
        {
            // Pulse start
            hc_sr04->pulseStart = current_capture;
            hc_sr04->overflow_count = 0; // Reset overflow count
            last_capture = current_capture; // Update the last capture time
            hc_sr04->waiting_for_end = true; // Now we're waiting for a pulse end
          
            printf("pulseStart= %u\n", hc_sr04->pulseStart);
        }
    }
    else
    {
        if (hc_sr04->waiting_for_end) // Only update pulseEnd if we were waiting for it
        {
            // Pulse end
            hc_sr04->pulseEnd = current_capture;
            hc_sr04->pulseDetected = true; // Set pulse detection flag
            hc_sr04->waiting_for_end = false; // Reset the flag as we've detected a pulse end
          
            printf("pulseEnd= %u\n", hc_sr04->pulseEnd);

            // Calculate echo duration immediately to avoid repeated computation
            if (hc_sr04->pulseEnd < last_capture)
            {
                // Handle timer overflow
                hc_sr04->echo_duration = (0xFFFF - last_capture) + hc_sr04->pulseEnd + (hc_sr04->overflow_count * 0xFFFF);
            }
            else
            {
                hc_sr04->echo_duration = hc_sr04->pulseEnd - last_capture;
            }
            printf("echo_duration= %u\n\n", hc_sr04->echo_duration);
        }
    }
}