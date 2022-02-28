/*
	In [Options for Target...] > [Target]:
	☑ Use default compiler version 5
	☑ Use MicroLIB
*/

#include "gd32f10x_usart_config.h"

int main(void)
{
	int i = 1;
	usart_config(USART0,115200);
	printf("%d%c%s\r\n",i++,'.'," USART printf example");

	usart_config(USART1,9600);
	printf("%d%c%s%f\r\n",i++,'.'," 你好 ", 0.125);
	
	print(USART0, "%d%c%s%f\r\n",i++, '.', " USART0 str test ", 3.14);
	print(USART1, "%d%c%s%f\r\n",i++, '.', " USART1 str test ", 3.1415926);
	print(ALL, "%d%c%s%f\r\n",i++, '.', " ALL str test ", 2.7182818284);
	
	printf("%d%s%c%f",i++,". ", 102, 5/3.);
	printf(", ALL print test by \"printf\".\r\n");
	
	print(ALL, "ALL print test1 by \"print\".\r\n");
	print(ALL, "ALL print test2 by \"print\".\r\n");
	printf("ALL print test by \"printf\". -- test finish\r\n");
}
