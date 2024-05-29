/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef SENSOR_H
#define SENSOR_H

#ifdef __cplusplus
extern "C" {
#endif

/* Include */
#include "main.h"
#include "motor_shield_v1.h"
#include "HC-SR04.h"

// Declare the global objects with extern keyword


/* FUNCTION (Prototype) DEFINITIONS */
void CheckButtonState(void);
//void measureDistance(hc_sr04* sensor);


#ifdef __cplusplus
}
#endif

#endif /* SENSOR_H */

/*****END OF FILE*****/
