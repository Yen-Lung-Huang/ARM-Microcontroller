#include <gd32f10x.h>
#include "usart_config.h"
#include "at_command.h"

int main(void)
{
	USART1_init(115200U);	/* 初始化USART1 */
	USART1_transmit((uint8_t*) "USART1_transmit Test! \r\n");
  char str[USART1_BUF_LEN];
	
	while(1)
	{
		if(USART1_RX_NUM > 0){
			USART1_RX_NUM = 0;
			
			sprintf(str, "Receive: %s (length= %d)\r\n",USART1_RX_BUF,strlen((char*)USART1_RX_BUF));
			USART1_transmit((uint8_t*) str);
			
			sprintf(str, "Command: %s \r\n",at_command((char*)USART1_RX_BUF));
			USART1_transmit((uint8_t*) str);
		}

  }
}
