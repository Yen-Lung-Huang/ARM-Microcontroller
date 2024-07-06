#include "gd32f10x_usart_config.h"

void usart_config(uint32_t usart_periph, uint32_t baudRate)
{
	switch(usart_periph){
		case USART0:
			usart_periph_enable[0] = true;
			rcu_periph_clock_enable(RCU_GPIOA); /* enable GPIO clock */
			rcu_periph_clock_enable(RCU_USART0); /* enable USART clock */
			gpio_init(GPIOA, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_9); /* connect port to USART0_TX */
			gpio_init(GPIOA, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, GPIO_PIN_10); /* connect port to USART0_RX */
			break;
		case USART1:
			usart_periph_enable[1] = true;
			rcu_periph_clock_enable(RCU_GPIOA); /* enable GPIO clock */
			rcu_periph_clock_enable(RCU_USART1); /* enable USART clock */
			gpio_init(GPIOA, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_2); /* connect port to USART1_TX */
			gpio_init(GPIOA, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, GPIO_PIN_3); /* connect port to USART1_RX */
			break;
		case USART2:
			usart_periph_enable[2] = true;
			rcu_periph_clock_enable(RCU_GPIOB); /* enable GPIO clock */
			rcu_periph_clock_enable(RCU_USART2); /* enable USART clock */
			gpio_init(GPIOB, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_10); /* connect port to USART2_TX */
			gpio_init(GPIOB, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, GPIO_PIN_11); /* connect port to USART2_RX */
			break;
	}
	
	/* USART configure */
	usart_deinit(usart_periph);
	usart_word_length_set(usart_periph, USART_WL_8BIT);
	usart_stop_bit_set(usart_periph, USART_STB_1BIT);
	usart_parity_config(usart_periph, USART_PM_NONE);
	usart_baudrate_set(usart_periph, baudRate);
	usart_receive_config(usart_periph, USART_RECEIVE_ENABLE);
	usart_transmit_config(usart_periph, USART_TRANSMIT_ENABLE);
	usart_enable(usart_periph);
}

/* retarget the C library printf function to the USART */
int fputc(int ch, FILE *f)
{
	if(usart_periph_enable[0] == true){
    usart_data_transmit(USART0, (uint8_t)ch);
		while(RESET == usart_flag_get(USART0, USART_FLAG_TBE)||RESET == usart_flag_get(USART0, USART_FLAG_TC));
	}
	if(usart_periph_enable[1] == true){
    usart_data_transmit(USART1, (uint8_t)ch);
		while(RESET == usart_flag_get(USART1, USART_FLAG_TBE)||RESET == usart_flag_get(USART1, USART_FLAG_TC));
	}
	if(usart_periph_enable[2] == true){
    usart_data_transmit(USART2, (uint8_t)ch);
		while(RESET == usart_flag_get(USART2, USART_FLAG_TBE)||RESET == usart_flag_get(USART2, USART_FLAG_TC));
	}
	return ch;
}

/*printf with the selected USART */
void printNum(unsigned long num, int base, uint32_t usart_periph)
{ 
	if (num == 0){ /* 遞迴結束條件*/
		return;
	}
	printNum(num / base, base, usart_periph); /* 繼續遞迴*/
	if(usart_periph == ALL)
		putchar("0123456789abcdef"[num % base]); /* 逆序打印結果*/
	else{
		usart_data_transmit(usart_periph, "0123456789abcdef"[num % base]);
		while(RESET == usart_flag_get(usart_periph, USART_FLAG_TBE)){};
	}
}

void printFloat(double f, uint32_t usart_periph)
{
	int temp;
	temp = (int)f; /* 先打印整數部分*/
	printNum(temp, 10, usart_periph);
	if(usart_periph == ALL)
		putchar('.'); /* 分隔點*/
	else{
		usart_data_transmit(usart_periph, '.');
		while(RESET == usart_flag_get(usart_periph, USART_FLAG_TBE)){};
	}
	f -= temp; /* 打印小數部分*/
	if (f == 0){ /* 浮點型數據至少六位精度*/
		for (temp = 0; temp < 6; temp++){
			if(usart_periph == ALL)
				putchar('0');
			else{
				usart_data_transmit(usart_periph, '0');
				while(RESET == usart_flag_get(usart_periph, USART_FLAG_TBE)){}; 
			}
		}
		return;
	}
	else{
		temp = (int)(f * 1000000);
		printNum(temp, 10, usart_periph);
	}
}

void print(uint32_t usart_periph, char *format, ...)
{
	va_list arg;
	char ch;
	char *str;
	va_start(arg, format);
	while ((ch = *format++) != '\0'){
		if(ch != '%'){
			if(usart_periph == ALL){
				putchar(ch);
			}
			else{
				usart_data_transmit(usart_periph, ch);
				while(RESET == usart_flag_get(usart_periph, USART_FLAG_TBE)){};
			}
			continue;
		}
		switch (*format != '\0' ? *format++ : '\0'){
			case 'd':
				printNum(*(int*)arg, 10, usart_periph);
				arg = (char *)arg + sizeof(format);
				break;
			case 'f':
				printFloat(*(double*)arg, usart_periph);
				arg = (char*)arg + sizeof(double); //為double型
				break;
			case 'c':
				if(usart_periph == ALL){
					char c = va_arg(arg, int);
					putchar(c);
				}
				else{
					char c = va_arg(arg, int);
					usart_data_transmit(usart_periph, c);
					while(RESET == usart_flag_get(usart_periph, USART_FLAG_TBE)){};
				}
				break;
			case 's':
				str = va_arg(arg, char*);
				while (*str != '\0'){
					if(usart_periph == ALL)
						putchar(*str++);
					else{
						usart_data_transmit(usart_periph, *str++);
						while(RESET == usart_flag_get(usart_periph, USART_FLAG_TBE));
					}
				}
				break;
		}
	}	
}
