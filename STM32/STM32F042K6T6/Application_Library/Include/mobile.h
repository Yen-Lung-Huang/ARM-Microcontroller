/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef MOBILE_H
#define MOBILE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "servo.h"

void wheels_degree_set(float front_left, float front_right, float rear_left, float rear_right);
void wheels_speed_set(float left_speed, float right_speed);
void wheels_stop(void);
void mobile_pwm_stop(void);
void turn_set(bool turn);
void move(float speed);
void turn(float speed);

#ifdef __cplusplus
}
#endif

#endif /* MOBILE_H */

/*****END OF FILE*****/
