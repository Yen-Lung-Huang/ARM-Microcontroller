#include "gd32f10x.h"
#include "uart_config.h"
	
static uint8_t string_array[256];

int main (void)
{
	/* 初始化USART1 */
	usart1_config(115200U);
	uart1_transmit((uint8_t*)"test");
	USART1_vsprintf("GO？%d\r\n",123);
	while(1){
		if(UART1_RX_STAT > 0){
			UART1_RX_STAT = 0;
			
			//uart1_transmit(UART1_RX_BUF);
			//sprintf((char*)string_array," (strlen= %d)\n",strlen((char*)UART1_RX_BUF));
			//uart1_transmit(string_array);
			
			USART1_vsprintf("%s (strlen= %d)\n",UART1_RX_BUF,strlen((char*)UART1_RX_BUF));
			//USART1_vsprintf("%s (strlen= %d)\n",UART1_RX_BUF,strlen((char*)UART1_RX_BUF));
			//USART1_vsprintf("(sizeof(UART1_RX_BUF)= %d)\n",sizeof(UART1_RX_BUF));
			
			//uart1_transmit();
			
		}
	}
}
