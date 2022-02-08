#include <gd32f10x.h>
#include "usart_config.h"

int main(void)
{
	//int t = 0;
	//systick_config();	/* 配置系统時鐘 */
	usart1_config(115200U);	/* 初始化USART1 */
	//uart1_transmit((uint8_t*)"test \r\n");
	USART1_vsprintf("USART1_transmit Test! \r\n");
	
  while(1)
	{
		if(UART1_RX_STAT > 0){
			UART1_RX_STAT = 0;
			USART1_vsprintf("%s (strlen= %d)\n",UART1_RX_BUF,strlen((char*)UART1_RX_BUF));
			//USART1_vsprintf("%s (strlen= %d)\n","abc",123);
		}
  }
}
