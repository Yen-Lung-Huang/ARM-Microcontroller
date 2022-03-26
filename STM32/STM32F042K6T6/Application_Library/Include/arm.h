/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef ARM_H
#define ARM_H

#ifdef __cplusplus
extern "C" {
#endif

#include "servo.h"

void arm_pwm_set(uint16_t pwm_dest[5]);
void arm_set(uint16_t pwm_0, uint16_t pwm_1, uint16_t pwm_2, uint16_t pwm_3, uint16_t pwm_4);
void arm_pwm_stop(void);
void shoulder_set(uint16_t pwm_value);

#ifdef __cplusplus
}
#endif

#endif /* ARM_H */

/*****END OF FILE*****/
