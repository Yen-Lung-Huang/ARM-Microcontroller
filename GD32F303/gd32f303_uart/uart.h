#ifndef __USART_H
#define __USART_H

#include <stdio.h>
#include <string.h>	
#include <stdarg.h>
#include "gd32f30x.h"
#include "systick.h"
#define UART0_DMA
#define UART0_RX

/* 串口0初始化，參數為串列傳輸速率 */
void uart0_init(uint32_t bound);
/* 自訂UART0 printf 函數 */
void u1_printf(char* fmt,...);

#ifdef UART0_RX
/* 接收緩存 */
extern uint8_t UART0_RX_BUF[]; 		/* 雙接收緩衝區 */
extern uint8_t UART0_RX_STAT;		/* 接受狀態 0x01:已接收到資料  0x03:接收緩衝區半滿  0x07:接收緩衝區全滿 */
extern uint32_t UART0_RX_NUM;		/* 接收到的資料個數 */
#endif

#endif

