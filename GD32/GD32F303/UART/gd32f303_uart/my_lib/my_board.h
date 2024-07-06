#ifndef MY_BOARD_H
#define MY_BOARD_H

#ifdef __cplusplus
 extern "C" {
#endif



//#include "gd32f30x.h"
#include "gd32f30x_gpio.h"              // GigaDevice::Device:GD32F30x_StdPeripherals:GPIO

void led_on(uint8_t port, uint8_t num);
void led_off(uint8_t port, uint8_t num);
void led_init(uint8_t port, uint8_t num);
void key_init(uint8_t port, uint8_t num);

static uint32_t pin[] = {	GPIO_PIN_0, GPIO_PIN_1, GPIO_PIN_2, GPIO_PIN_3, GPIO_PIN_4, GPIO_PIN_5, GPIO_PIN_6, 
													GPIO_PIN_7, GPIO_PIN_8, GPIO_PIN_9, GPIO_PIN_10, GPIO_PIN_11, GPIO_PIN_12, GPIO_PIN_13,
													GPIO_PIN_14, GPIO_PIN_15};
static uint32_t group[] = { GPIOA, GPIOB, GPIOC, GPIOD, GPIOE, GPIOF, GPIOG };
static rcu_periph_enum clock[] =	{ RCU_GPIOA, RCU_GPIOB, RCU_GPIOC, RCU_GPIOD, RCU_GPIOE, RCU_GPIOF, RCU_GPIOG };
static uint8_t KEY_IRQn[] = {EXTI0_IRQn, 									//WAKEUP_KEY_EXTI_IRQn, 
														 EXTI10_15_IRQn, 							//TAMPER_KEY_EXTI_IRQn,
														 EXTI5_9_IRQn, 								//USER_KEY1_EXTI_IRQn
														};

//GPIO_BOP(GPIOD) = GPIO_PIN_8;

void led_init(uint8_t port, uint8_t num){
		/* enable the led clock */
		rcu_periph_clock_enable(clock[port]);
		/* configure led GPIO port */ 
		gpio_init(group[port], GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, pin[num]);
		GPIO_BC(group[port]) = pin[num];
}

void led_on(uint8_t port, uint8_t num)
{
    GPIO_BOP(group[port]) = pin[num];
}

void led_off(uint8_t port, uint8_t num)
{
    GPIO_BC(group[port]) = pin[num];
}

void key_init(uint8_t port, uint8_t num)//, keymode_typedef_enum key_mode)
{
    /* enable the key clock */
    rcu_periph_clock_enable(clock[port]);
    rcu_periph_clock_enable(RCU_AF);

    /* configure button pin as input */
    gpio_init(group[port], GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, pin[num]);

//    if (key_mode == KEY_MODE_EXTI) {
        /* enable and set key EXTI interrupt to the lowest priority */
//        nvic_irq_enable(KEY_IRQn[port], 2U, 0U);

        /* connect key EXTI line to key GPIO pin */
//        gpio_exti_source_select(KEY_PORT_SOURCE[port], KEY_PIN_SOURCE[port]);

        /* configure key EXTI line */
//        exti_init(KEY_EXTI_LINE[port], EXTI_INTERRUPT, EXTI_TRIG_FALLING);
//        exti_interrupt_flag_clear(KEY_EXTI_LINE[port]);
//    }
}
#ifdef __cplusplus
}
#endif

#endif /* MY_BOARD_H */
