#include "HC-SR04.h"

// Initialize data for three HC-SR04 sensors
HC_SR04_TypeDef hc_sr04[3] = {
  {GPIOD, GPIO_PIN_2, GPIOC, GPIO_PIN_10, 0, 0, 0, 0, 0.0f},
  {GPIOD, GPIO_PIN_2, GPIOC, GPIO_PIN_11, 0, 0, 0, 0, 0.0f},
  {GPIOD, GPIO_PIN_2, GPIOC, GPIO_PIN_12, 0, 0, 0, 0, 0.0f}
};


// Microsecond delay function
void delay_us(uint16_t us)
{
    __HAL_TIM_SET_COUNTER(&htim6, 0);
    while (__HAL_TIM_GET_COUNTER(&htim6) < us);
}


// 發送 Trig 信號並回傳距離
float HC_SR04_GetDistance(HC_SR04_TypeDef* sensor)
{
    // 送出 Trig 信號
    HAL_GPIO_WritePin(sensor->trig_port, sensor->trig_pin, GPIO_PIN_SET);
    delay_us(10);
    HAL_GPIO_WritePin(sensor->trig_port, sensor->trig_pin, GPIO_PIN_RESET);

    // 等待回波信號檢測完成
    while (!sensor->pulseDetected) {}

    // 重置脈衝檢測標誌
    sensor->pulseDetected = 0;

    return sensor->distance;
}


// 處理 HC-SR04 中斷
void HC_SR04_HandleInterrupt(uint16_t GPIO_Pin, HC_SR04_TypeDef* sensors, int num_sensors)
{
    for (int i = 0; i < num_sensors; i++) {
        HC_SR04_TypeDef* sensor = &sensors[i];
        if (GPIO_Pin == sensor->echo_pin)
        {
            if (HAL_GPIO_ReadPin(sensor->echo_port, sensor->echo_pin) == GPIO_PIN_SET)
            {
                // 脈衝開始
                sensor->pulseStart = __HAL_TIM_GET_COUNTER(&htim6);
                sensor->overflow_count = 0; // 重置溢出計數
            }
            else
            {
                // 脈衝結束
                sensor->pulseEnd = __HAL_TIM_GET_COUNTER(&htim6);
                uint32_t echo_duration;

                if (sensor->pulseEnd < sensor->pulseStart)
                {
                    // 處理計數器溢出
                    echo_duration = (0xFFFF - sensor->pulseStart) + sensor->pulseEnd + (sensor->overflow_count * 0xFFFF);
                }
                else
                {
                    echo_duration = sensor->pulseEnd - sensor->pulseStart;
                }

                sensor->distance = (echo_duration * 0.03432) / 2;
                sensor->pulseDetected = 1; // 設置脈衝檢測標誌
            }
        }
    }
}
