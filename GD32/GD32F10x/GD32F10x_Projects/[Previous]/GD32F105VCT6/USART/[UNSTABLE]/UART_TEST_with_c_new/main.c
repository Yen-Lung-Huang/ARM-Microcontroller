#include <gd32f10x.h>
#include <stdio.h>
#include "usart_config.h"


int main(void)
{
	//int t = 0;
	//systick_config();	/* 配置系统時鐘 */
	USART1_init(115200U);	/* 初始化USART1 */
	USART1_transmit((uint8_t*)"test \r\n");
	USART1_vsprintf("USART1_transmit Test! \r\n");
	
  while(1)
	{
		if(USART1_RX_NUM > 0){
			USART1_RX_NUM = 0;
			USART1_vsprintf("USART1_transmit Test! \r\n");
		}
  }
}
