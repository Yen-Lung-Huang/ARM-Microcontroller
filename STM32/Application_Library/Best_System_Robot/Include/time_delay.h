/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef TIME_DELAY_H
#define TIME_DELAY_H

#ifdef __cplusplus
extern "C" {
#endif

/* Include */
#include "main.h"

/* FUNCTION (Prototype) DEFINITIONS */
void delay_us_init(void);
void delay_us_t(uint32_t Delay);
void delay_us_optimize(void);
void delay_us(uint32_t Delay);


#ifdef __cplusplus
}
#endif

#endif /* TIME_DELAY_H */

/*****END OF FILE*****/
