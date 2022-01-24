#include <stdio.h>
#include "usart_config.h"

int main(void)
{
	USART1_init(115200U);	/* 初始化USART1 */
	USART1_transmit((uint8_t*) "USART1_transmit Test! \r\n");
  while(1)
	{
		if(USART1_RX_NUM > 0){
			USART1_RX_NUM = 0;

			char str[USART1_BUF_LEN];
			sprintf(str, "Receive: %s (length= %d)\r\n",USART1_RX_BUF,strlen((char*)USART1_RX_BUF));
			USART1_transmit((uint8_t*) str);
		}
  }
}
