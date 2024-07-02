#include "timing_delays.h"

// Microsecond delay function
void delay_us(uint16_t us)
{
    __HAL_TIM_SET_COUNTER(&htim6, 0);
    while (__HAL_TIM_GET_COUNTER(&htim6) < us);
}


/* Non-blocking wait function---------------------------------------*/

void NonBlockingDelay_Start(NonBlockingDelay_TypeDef* self, uint32_t duration) {
    self->start_time = HAL_GetTick();
    self->delay = duration;
}

bool NonBlockingDelay_IsExpired(NonBlockingDelay_TypeDef* self) {
    return (HAL_GetTick() - self->start_time) >= self->delay;
}

NonBlockingDelay_TypeDef CreateNonBlockingDelay() {
    NonBlockingDelay_TypeDef nbd_obj;
    nbd_obj.start_time = 0;
    nbd_obj.delay = 0;
    nbd_obj.Start = NonBlockingDelay_Start;
    nbd_obj.IsExpired = NonBlockingDelay_IsExpired;
    return nbd_obj;
}