#include "stm32f4xx_hal.h"
#include <string.h>

void UART_Config(void);
void DMA_Config(void);
void SysTick_Handler(void);
void DMA1_Stream5_IRQHandler(void);

static UART_HandleTypeDef myUARThandle;
static DMA_HandleTypeDef myDMA_Uart1Handle;

//static char txData[40] = "Hello from STM32F407ZGT6 Explorer\r\n";
static char rxData[40];

int main(void)
{
	// HAL_Initialise
	HAL_Init();
	// UART_Initialise
	UART_Config();
	// DMA_Initialise
	DMA_Config();
	
	HAL_UART_Receive_DMA(&myUARThandle, (uint8_t *)rxData, 20);
	
	while(1)
	{
		/*HAL_UART_Transmit(&myUARThandle, (uint8_t *)txData, strlen(txData),10);
		HAL_Delay(500);*/
	}
}

void UART_Config(void)
{
	__HAL_RCC_GPIOC_CLK_ENABLE(); //使能GPIOC時鐘
	__HAL_RCC_USART1_CLK_ENABLE(); //使能USART1時鐘
	
	GPIO_InitTypeDef myUartDef;
	myUartDef.Pin = GPIO_PIN_9 | GPIO_PIN_10;
	myUartDef.Mode = GPIO_MODE_AF_PP; //
	myUartDef.Pull = GPIO_PULLUP;
	myUartDef.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	myUartDef.Alternate = GPIO_AF7_USART1; //GPIOA復用為USART1
	HAL_GPIO_Init(GPIOA, &myUartDef);
	//UART Configuration
	myUARThandle.Instance = USART1;
	myUARThandle.Init.BaudRate = 115200;
	myUARThandle.Init.Mode = UART_MODE_TX_RX;
	myUARThandle.Init.WordLength = UART_WORDLENGTH_8B;
	myUARThandle.Init.StopBits = UART_STOPBITS_1;
	myUARThandle.Init.OverSampling = UART_OVERSAMPLING_16;
	HAL_UART_Init(&myUARThandle);
	
	//Systick interrupt enable
	HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);
	HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);
	HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

void SysTick_Handler(void)
{
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
}

void DMA_Config(void)
{
	__HAL_RCC_DMA1_CLK_ENABLE();
	myDMA_Uart1Handle.Instance = DMA1_Stream5;
	myDMA_Uart1Handle.Init.Channel = DMA_CHANNEL_4;
	myDMA_Uart1Handle.Init.Direction = DMA_PERIPH_TO_MEMORY;
	myDMA_Uart1Handle.Init.PeriphInc = DMA_PINC_DISABLE;
	myDMA_Uart1Handle.Init.MemInc = DMA_MINC_ENABLE;
	myDMA_Uart1Handle.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
	myDMA_Uart1Handle.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
	myDMA_Uart1Handle.Init.Mode = DMA_CIRCULAR;
	myDMA_Uart1Handle.Init.Priority = DMA_PRIORITY_LOW;
	myDMA_Uart1Handle.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
	HAL_DMA_Init(&myDMA_Uart1Handle);
	
	__HAL_LINKDMA(&myUARThandle, hdmarx, myDMA_Uart1Handle);
	
	//Enable DMA1 Stream 5 interrupt
	HAL_NVIC_SetPriority(DMA1_Stream5_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(DMA1_Stream5_IRQn);
}

void DMA1_Stream5_IRQHandler(void)
{
	HAL_DMA_IRQHandler(&myDMA_Uart1Handle);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	/* Prevent unused argument(s) compilation warning*/
	UNUSED(huart);
	/* NOTE: This function Should not be modified, when the callback is needed,
	the HAL_UART_TxCpltCallback could be implemented in the user file*/
	HAL_UART_Transmit(&myUARThandle, (uint8_t *)rxData, (unsigned short)strlen(rxData), 10);
}
