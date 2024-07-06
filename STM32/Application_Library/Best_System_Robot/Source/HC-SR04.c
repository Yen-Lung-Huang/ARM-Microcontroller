#include "HC-SR04.h"

// Initialize data for three HC-SR04 sensors
HC_SR04_TypeDef hc_sr04[3] = {
    {GPIOD, GPIO_PIN_2, GPIOC, GPIO_PIN_10, 0, 0, 0, 0, 0.0f},
    {GPIOD, GPIO_PIN_2, GPIOC, GPIO_PIN_11, 0, 0, 0, 0, 0.0f},
    {GPIOD, GPIO_PIN_2, GPIOC, GPIO_PIN_12, 0, 0, 0, 0, 0.0f}
};



// Send Trig signal and return distance
float HC_SR04_GetDistance(HC_SR04_TypeDef* sensor)
{
    uint32_t startTick = HAL_GetTick();

    // Send Trig signal
    HAL_GPIO_WritePin(sensor->trig_port, sensor->trig_pin, GPIO_PIN_SET);
    delay_us(10);
    HAL_GPIO_WritePin(sensor->trig_port, sensor->trig_pin, GPIO_PIN_RESET);

    // Wait for echo signal to be detected
    while (!sensor->pulseDetected) {
        // Return an error value or appropriate value to indicate timeout
        if ((HAL_GetTick() - startTick) >= 100) {
            sensor->distance = -1;
            break;
        }
    }
    // Reset the pulse detection flag
    sensor->pulseDetected = 0;
    return sensor->distance;
}


// Handle HC-SR04 interrupt
void HC_SR04_HandleInterrupt(uint16_t GPIO_Pin, HC_SR04_TypeDef* sensors, int num_sensors)
{
    for (int i = 0; i < num_sensors; i++) {
        HC_SR04_TypeDef* sensor = &sensors[i];
        if (GPIO_Pin == sensor->echo_pin) {
            if (HAL_GPIO_ReadPin(sensor->echo_port, sensor->echo_pin) == GPIO_PIN_SET) {
                // Pulse start
                sensor->pulseStart = __HAL_TIM_GET_COUNTER(&htim6);
                sensor->overflow_count = 0; // Reset overflow count
            } else {
                // Pulse end
                sensor->pulseEnd = __HAL_TIM_GET_COUNTER(&htim6);
                uint32_t echo_duration;

                if (sensor->pulseEnd < sensor->pulseStart) {
                    // Handle counter overflow
                    echo_duration = (0xFFFF - sensor->pulseStart) + sensor->pulseEnd + (sensor->overflow_count * 0xFFFF);
                } else {
                    echo_duration = sensor->pulseEnd - sensor->pulseStart;
                }

                sensor->distance = (echo_duration * 0.03432) / 2;
                sensor->pulseDetected = 1; // Set pulse detection flag
            }
        }
    }
}
