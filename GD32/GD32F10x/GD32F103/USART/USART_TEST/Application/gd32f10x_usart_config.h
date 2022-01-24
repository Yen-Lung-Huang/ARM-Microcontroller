/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef HEADER_CAPITAL_NAME_H
#define HEADER_CAPITAL_NAME_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include "gd32f10x.h"

#define USART0_DATA_ADDRESS      ((uint32_t)&USART_DATA(USART0))
#define USART1_DATA_ADDRESS      ((uint32_t)&USART_DATA(USART1))
#define ARRAYNUM(arr_nanme)      (uint32_t)(sizeof(arr_nanme) / sizeof(*(arr_nanme)))    // Not being used

__IO FlagStatus g_transfer_complete = RESET;






#ifdef __cplusplus
}
#endif

#endif /* HEADER_CAPITAL_NAME_H */

/*****END OF FILE*****/
