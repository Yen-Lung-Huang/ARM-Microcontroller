/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef TIMING_DELAYS_H
#define TIMING_DELAYS_H

#ifdef __cplusplus
extern "C" {
#endif

/* Include */
#include <stdbool.h>
#include "tim.h"

// Define the non-blocking wait structure
typedef struct NonBlockingDelay_TypeDef NonBlockingDelay_TypeDef;
struct NonBlockingDelay_TypeDef {
    uint32_t start_time;
    uint32_t delay;
    void (*Start)(NonBlockingDelay_TypeDef* self, uint32_t duration);
    bool (*IsExpired)(NonBlockingDelay_TypeDef* self);
};

/* FUNCTION (Prototype) DEFINITIONS */
void delay_us(uint16_t us);
void NonBlockingDelay_Start(NonBlockingDelay_TypeDef* self, uint32_t duration);
bool NonBlockingDelay_IsExpired(NonBlockingDelay_TypeDef* self);
NonBlockingDelay_TypeDef CreateNonBlockingDelay();


#ifdef __cplusplus
}
#endif

#endif /* TIMING_DELAYS_H */

/*****END OF FILE*****/
