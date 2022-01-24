#ifndef __MAIN_H
#define __MAIN_H


#include "gd32f10x.h"
#include "systick.h"
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
void led_flash(uint32_t times);
int fputc(int ch, FILE *f);





/* FUNCTION DEFINITIONS */



/*!
    \brief      configure different peripheral clocks
    \param[in]  none
    \param[out] none
    \retval     none
*/
void rcu_config(void)
{
    rcu_periph_clock_enable(RCU_GPIOA);
    rcu_periph_clock_enable(RCU_GPIOC);
    rcu_periph_clock_enable(RCU_GPIOE);
    rcu_periph_clock_enable(RCU_AF);
    rcu_periph_clock_enable(RCU_SPI0);

}



/*!
    \brief      initialize the LEDs
    \param[in]  none
    \param[out] none
    \retval     none
*/
void led_init(void)
{
	/* Requires rcu_config() previously */
   
    /* Configure LED GPIO port */
	gpio_init(GPIOC, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_0 | GPIO_PIN_2 );
	gpio_init(GPIOE, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_0 | GPIO_PIN_1 );
}


/*!
    \brief      configure COM port
    \param[in]  com: COM on the board
      \arg        EVAL_COM0: COM0 on the board
      \arg        EVAL_COM1: COM1 on the board
    \param[out] none
    \retval     none
*/
void com_port_init(uint32_t com)            //MM Adapted to not depend upon Evaluation board
{
    
    /* enable GPIO clock */
    rcu_periph_clock_enable(RCU_GPIOA);

    /* enable USART clock */
    rcu_periph_clock_enable(RCU_USART0);

    /* connect port to USARTx_Tx */
    gpio_init(GPIOA, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_9);   //MM GPIO_PIN_2 for COM1

    /* connect port to USARTx_Rx */
    gpio_init(GPIOA, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, GPIO_PIN_10);    //MM GPIO_PIN_3 for COM1

    /* USART configure */
    usart_deinit(com);
    usart_baudrate_set(com, 115200U);
    usart_word_length_set(com, USART_WL_8BIT);
    usart_stop_bit_set(com, USART_STB_1BIT);
    usart_parity_config(com, USART_PM_NONE);
    usart_hardware_flow_rts_config(com, USART_RTS_DISABLE);
    usart_hardware_flow_cts_config(com, USART_CTS_DISABLE);
    usart_receive_config(com, USART_RECEIVE_ENABLE);
    usart_transmit_config(com, USART_TRANSMIT_ENABLE);
    usart_enable(com);
}


/*!
    \brief      led flash
    \param[in]  times : specifies the delay time length, in milliseconds
    \param[out] none
    \retval     none
*/

void led_flash(uint32_t times)
{
    uint32_t i;
    for( i = 0 ; i < times ; i ++ ){
        /* insert 400 ms delay */
        delay_1ms(400);
        /* turn on LED */
        LED_ON(Led2);
        LED_ON(Led3);
        LED_ON(Led4);
        LED_ON(Led5);
        /* insert 400 ms delay */
        delay_1ms(400);
        /* turn off LED */
        LED_OFF(Led2);
        LED_OFF(Led3);
        LED_OFF(Led4);
        LED_OFF(Led5);
         
    }
}



/*
\brief          configure key
    \param[in]  key_num: specify the key to be configured
      \arg        KEY_TAMPER: tamper key
      \arg        KEY_WAKEUP: wakeup key
      \arg        KEY_USER: user key
    \param[in]  key_mode: specify button mode
      \arg        KEY_MODE_GPIO: key will be used as simple IO
      \arg        KEY_MODE_EXTI: key will be connected to EXTI line with interrupt
    \param[out] none
    \retval     none
*/

void button_init(key_type key, key_mode keymode)
{

    if (key == WAKEUP){
    /* enable the key clock */
	/* Requires rcu_config() previously */                                     //MM WAKEUP_KEY_GPIO_CLK
    /* configure button pin as input */
    gpio_init(GPIOA, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, GPIO_PIN_0);
    }
    
    else if ( key == TAMPER){
    /* enable the key clock */
	/* Requires rcu_config() previously */                                        //MM TAMPER_KEY_GPIO_CLK
    /* configure button pin as input */
    gpio_init(GPIOC, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, GPIO_PIN_13);        
    }
    
    else if( key == USER){
    /* enable the key clock */
	/* Requires rcu_config() previously */                                        //MM USER_KEY_GPIO_CLK 
    /* configure button pin as input */
    gpio_init(GPIOB, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, GPIO_PIN_14);        
    }
    
    else if (key == AllBut) {
    /* enable all the key clocks */
	/* Requires rcu_config() previously */                                        //MM All the keys 
    /* configure all button pins as input */
    gpio_init(GPIOA, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, GPIO_PIN_0);
    gpio_init(GPIOC, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, GPIO_PIN_13);
    gpio_init(GPIOB, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, GPIO_PIN_14);
        
    }

	/* Requires rcu_config() previously */                                           //MM APB2 peripheral alternate function clock

    if (keymode == MODE_EXTI) {
        
        if (key == WAKEUP){
        /* enable and set key EXTI interrupt to the lowest priority */
        nvic_irq_enable(EXTI0_IRQn, 2U, 0U);                                   //MM    WAKEUP_KEY_EXTI_IRQn
        /* connect key EXTI line to key GPIO pin */
        gpio_exti_source_select(GPIO_PORT_SOURCE_GPIOA, GPIO_PIN_SOURCE_0);    //MM    WAKEUP_KEY_EXTI_PORT_SOURCE & WAKEUP_KEY_EXTI_PIN_SOURCE
        /* configure key EXTI line */
        exti_init(EXTI_0, EXTI_INTERRUPT, EXTI_TRIG_FALLING);                  //MM    WAKEUP_KEY_EXTI_LINE
        exti_interrupt_flag_clear(EXTI_0);            
        }
        
        else if ( key == TAMPER){
        /* enable and set key EXTI interrupt to the lowest priority */
        nvic_irq_enable(EXTI10_15_IRQn, 2U, 0U);                               //MM    TAMPER_KEY_EXTI_IRQn and USER_KEY_EXTI_IRQn are the same
        /* connect key EXTI line to key GPIO pin */
        gpio_exti_source_select(GPIO_PORT_SOURCE_GPIOC, GPIO_PIN_SOURCE_13);   //MM   TAMPER_KEY_EXTI_PORT_SOURCE & TAMPER_KEY_EXTI_PIN_SOURCE
        /* configure key EXTI line */
        exti_init(EXTI_13, EXTI_INTERRUPT, EXTI_TRIG_FALLING);                 //MM    TAMPER_KEY_EXTI_LINE            
        exti_interrupt_flag_clear(EXTI_14);            
        }
        
        else if( key == USER){
        /* enable and set key EXTI interrupt to the lowest priority */
        nvic_irq_enable(EXTI10_15_IRQn, 2U, 0U);                               //MM    USER_KEY_EXTI_IRQn and TAMPER_KEY_EXTI_IRQn are the same
        /* connect key EXTI line to key GPIO pin */
        gpio_exti_source_select(GPIO_PORT_SOURCE_GPIOB, GPIO_PIN_SOURCE_14);   //MM   USER_KEY_EXTI_PORT_SOURCE & USER_KEY_EXTI_PIN_SOURCE
        /* configure key EXTI line */
        exti_init(EXTI_14, EXTI_INTERRUPT, EXTI_TRIG_FALLING);                 //MM    USER_KEY_EXTI_LINE            
        exti_interrupt_flag_clear(EXTI_14);            
        }
        
        else if (key == AllBut){
            
        /* enable and set key EXTI interrupt to the lowest priority */
        nvic_irq_enable(EXTI0_IRQn, 2U, 0U);                                   //MM    WAKEUP_KEY_EXTI_IRQn
        nvic_irq_enable(EXTI10_15_IRQn, 2U, 0U);                               //MM    USER_KEY_EXTI_IRQn and TAMPER_KEY_EXTI_IRQn are the same
        nvic_irq_enable(EXTI10_15_IRQn, 2U, 0U);                               //MM    TAMPER_KEY_EXTI_IRQn and USER_KEY_EXTI_IRQn are the same

        /* connect key EXTI line to key GPIO pin */
        gpio_exti_source_select(GPIO_PORT_SOURCE_GPIOA, GPIO_PIN_SOURCE_0);    //MM    WAKEUP_KEY_EXTI_PORT_SOURCE & WAKEUP_KEY_EXTI_PIN_SOURCE
        gpio_exti_source_select(GPIO_PORT_SOURCE_GPIOB, GPIO_PIN_SOURCE_14);   //MM   USER_KEY_EXTI_PORT_SOURCE & USER_KEY_EXTI_PIN_SOURCE
        gpio_exti_source_select(GPIO_PORT_SOURCE_GPIOC, GPIO_PIN_SOURCE_13);   //MM   TAMPER_KEY_EXTI_PORT_SOURCE & TAMPER_KEY_EXTI_PIN_SOURCE        
        
        /* configure key EXTI line */
        exti_init(EXTI_0,  EXTI_INTERRUPT, EXTI_TRIG_FALLING);                 //MM    WAKEUP_KEY_EXTI_LINE
        exti_init(EXTI_14, EXTI_INTERRUPT, EXTI_TRIG_FALLING);                 //MM    USER_KEY_EXTI_LINE
        exti_init(EXTI_13, EXTI_INTERRUPT, EXTI_TRIG_FALLING);                 //MM    TAMPER_KEY_EXTI_LINE
        exti_interrupt_flag_clear(EXTI_0);
        exti_interrupt_flag_clear(EXTI_14);
        exti_interrupt_flag_clear(EXTI_14);            
            
        }

    }
}



/*!
    \brief      return the selected key state
    \param[in]  key: specify the key to be checked
      \arg        KEY_TAMPER: tamper key
      \arg        KEY_WAKEUP: wakeup key
      \arg        KEY_USER: user key
    \param[out] none
    \retval     the key's GPIO pin value
*/
uint8_t button_state_get(key_type key)
{
    if ( key == WAKEUP)    
    return gpio_input_bit_get(GPIOA, GPIO_PIN_0);
    if ( key == TAMPER)    
    return gpio_input_bit_get(GPIOC, GPIO_PIN_13);
    if ( key == USER)    
    return gpio_input_bit_get(GPIOB, GPIO_PIN_14);

    return 0;                                                                  //MM    Error argument

}




/*!
\brief      Turn ON LEDs
\param[in]  LEDn: (Led2, Led3, Led4, Led5)
\param[out] none
\retval     none
*/
void LED_ON(led_type led){
    switch(led){
        case Led2:
         gpio_bit_set ( GPIOC, GPIO_PIN_0 );   
        break;
        case Led3:
         gpio_bit_set ( GPIOC, GPIO_PIN_2 );   
        break;
        case Led4:
         gpio_bit_set ( GPIOE, GPIO_PIN_0 );   
        break;
        case Led5:
         gpio_bit_set ( GPIOE, GPIO_PIN_1 );
        break;
        case AllLeds:
         gpio_bit_set ( GPIOC, GPIO_PIN_0 | GPIO_PIN_2 );
         gpio_bit_set ( GPIOE, GPIO_PIN_0 | GPIO_PIN_1);
        break;
       
    }
}


/*!
\brief      Turn OFF LEDs
\param[in]  LEDn: (Led2, Led3, Led4, Led5)
\param[out] none
\retval     none
*/
void LED_OFF(led_type led){
      switch(led){
        case Led2:
            gpio_bit_reset ( GPIOC, GPIO_PIN_0 );   
            break;
        case Led3:
            gpio_bit_reset ( GPIOC, GPIO_PIN_2 );   
            break;
        case Led4:
            gpio_bit_reset ( GPIOE, GPIO_PIN_0 );   
            break;
        case Led5:
            gpio_bit_reset ( GPIOE, GPIO_PIN_1 );
            break;  
        case AllLeds:
         gpio_bit_reset ( GPIOC, GPIO_PIN_0 | GPIO_PIN_2 );
         gpio_bit_reset ( GPIOE, GPIO_PIN_0 | GPIO_PIN_1);        
        break;
    }
}


/* retarget the C library printf function to the USART */
int fputc(int ch, FILE *f)
{
    usart_data_transmit(USART0, (uint8_t)ch);
    while(RESET == usart_flag_get(USART0, USART_FLAG_TBE));
    return ch;
}




#endif  /* __MAIN_H */

