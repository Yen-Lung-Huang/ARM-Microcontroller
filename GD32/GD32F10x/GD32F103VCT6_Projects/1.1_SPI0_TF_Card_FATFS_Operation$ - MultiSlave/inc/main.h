#ifndef __MAIN_H
#define __MAIN_H


#include "gd32f10x.h"
#include "systick.h"
#include "spi_sd.h"
#include "ff.h"
#include "diskio.h"
#include <stdio.h>



typedef enum {
    Led2    =0,
    Led3    =1,
    Led4    =2,
    Led5    =3,
    AllLeds =4
}led_type;


typedef enum            // Redefining enum to skip evaluation board dependency
{
    WAKEUP = 0,
    TAMPER = 1,
    USER   = 2,
    AllBut = 3          
} key_type;

typedef enum            // Redefining enum to skip evaluation board dependency
{
    MODE_GPIO = 0,
    MODE_EXTI = 1
} key_mode;



/*FUNCTION PROTOTYPES*/

void rcu_config(void);
void led_init(void);
void LED_ON(led_type led);
void LED_OFF(led_type led);
void com_port_init(uint32_t com);
void button_init(key_type keynum, key_mode keymode);
uint8_t button_state_get(key_type key);
void display_init(void);
void led_flash(uint32_t times);
ErrStatus memory_compare(uint8_t* src, uint8_t* dst, uint16_t length);
int fputc(int ch, FILE *f);





#endif  /* __MAIN_H */

