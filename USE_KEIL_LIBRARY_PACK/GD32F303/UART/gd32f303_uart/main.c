#include "gd32f30x.h"
#include "systick.h"
#include "my_lib/my_board.h"
#include "uart.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define UART0_DMA
#define UART0_RX


#define DELAY_TIME 1000
int main(void)
{
	int t = 0;
	/* 配置系統時鐘 */
	systick_config();
	/* 初始化LED */
		led_init(2, 0);	// PC0
	/* 初始化USART0 */
	uart0_init(115200);
	
//	u1_printf("Hello world! ");
	u1_printf("Tx/Rx demo... \r\n");

    while(1)
	{
		if(UART0_RX_STAT > 0)
		{
			UART0_RX_STAT = 0;
			u1_printf("RECEIVE %d data:%s \r\n", UART0_RX_NUM, UART0_RX_BUF);
		}
		
		delay_1ms(10);
		t++;
		if(t % 200 == 0) 
			led_off(2, 0);/* turn off LED */
		else if(t % 200 == 100)
			led_on(2, 0);	/* turn on LED */
        
	}
}
//int main(void)
//{
//	/* 配置系統時鐘 */
//	systick_config();
//	/* 初始化LED */
//		led_init(2, 0);	// PC0
////		led_init(2, 2);	// PC2
//	/* 初始化USART0 */
//	uart0_init(115200);
//while(1)
//	{
//		/* 通過串口列印 Hello world! */
//		printf("Hello world! 123456789 \r\n");
//		
//        /* turn on LED */
//			led_on(2, 0);
//			delay_1ms(DELAY_TIME);
//		printf("Second!");
//        /* turn off LED */
//			led_off(2, 0);
//			delay_1ms(DELAY_TIME);
//    }
//}

