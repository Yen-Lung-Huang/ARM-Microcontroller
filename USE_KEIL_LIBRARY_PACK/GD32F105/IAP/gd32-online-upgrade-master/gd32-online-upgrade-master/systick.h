/**
  ******************************************************************************
  * @brief   The header file of the SysTick configuration.
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SYS_TICK_H
#define __SYS_TICK_H

/* Exported functions ------------------------------------------------------- */
void SysTick_Configuration(void);
void Delay_1ms(uint32_t nTime);
void TimingDelay_Decrement(void);
void LED_Spark(void);

#endif

