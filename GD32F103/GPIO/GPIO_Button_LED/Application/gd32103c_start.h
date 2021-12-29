/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef GD32F103C_START_H
#define GD32F103C_START_H

#ifdef __cplusplus
extern "C" {
#endif

#include "gd32f10x_rcu.h"
#include "gd32f10x_gpio.h"
#include <stdbool.h>

extern void led_init(void);
extern void user_key_init(void);
extern bool user_key(void);
extern void led(bool status);


#ifdef __cplusplus
}
#endif

#endif /* GD32F103C_START_H */

/*****END OF FILE*****/
