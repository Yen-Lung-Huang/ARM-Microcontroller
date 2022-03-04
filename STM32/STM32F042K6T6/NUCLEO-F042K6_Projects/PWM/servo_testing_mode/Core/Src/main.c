/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "dma.h"
#include "i2c.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h> //printf function
#include <string.h>
#include <stdbool.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

#ifdef __GNUC__
  /* With GCC, small printf (option LD Linker->Libraries->Small printf
     set to 'Yes') calls __io_putchar() */
  #define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
  #define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */
	
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
	
extern DMA_HandleTypeDef hdma_usart2_rx;
uint32_t last_time = 0;
uint32_t sub_last_time = 0;
bool rotate_dir;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

#define RxBuf_SIZE   128
#define MainBuf_SIZE RxBuf_SIZE
uint8_t RxBuf[RxBuf_SIZE]; 			// DMA receive buffer.
uint8_t MainBuf[MainBuf_SIZE];	// RX receive. 




/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  MX_TIM14_Init();
  MX_TIM16_Init();
  MX_TIM17_Init();
  MX_USART2_UART_Init();
  MX_I2C1_Init();
  /* USER CODE BEGIN 2 */

	HAL_UARTEx_ReceiveToIdle_DMA(&huart2, RxBuf, RxBuf_SIZE);
	__HAL_DMA_DISABLE_IT(&hdma_usart2_rx, DMA_IT_HT);

	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_4);
	HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim14,TIM_CHANNEL_1);
	
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	printf("uart servo test\r\n");
		htim2.Instance ->CCR1 = 75;
		htim2.Instance ->CCR4 = 75;
		htim3.Instance ->CCR1 = 75;
		htim3.Instance ->CCR2 = 75;
		htim14.Instance->CCR1 = 75;
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		
		
		
		
		
		
		// Duty Cycle= 0.5ms/(1/50Hz), rotate angle= -90°
//		htim2.Instance ->CCR1 = 25;
//		htim2.Instance ->CCR4 = 25;
//		htim3.Instance ->CCR1 = 25;
//		htim3.Instance ->CCR2 = 25;
//		htim14.Instance->CCR1 = 25;
//	  HAL_Delay(1000); 
//		// Duty Cycle= 1.5ms/(1/50Hz), rotate angle= 0°
//		htim2.Instance ->CCR1 = 75;
//		htim2.Instance ->CCR4 = 75;
//		htim3.Instance ->CCR1 = 75;
//		htim3.Instance ->CCR2 = 75;
//		htim14.Instance->CCR1 = 75;
//	  HAL_Delay(1000); 
//		// Duty Cycle= 2.5ms/(1/50Hz), rotate angle= 90°
//		htim2.Instance ->CCR1 = 125;
//		htim2.Instance ->CCR4 = 125;
//		htim3.Instance ->CCR1 = 125;
//		htim3.Instance ->CCR2 = 125;
//		htim14.Instance->CCR1 = 125;
//	  HAL_Delay(1000); 
		
  }
	
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL6;
  RCC_OscInitStruct.PLL.PREDIV = RCC_PREDIV_DIV1;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_I2C1;
  PeriphClkInit.I2c1ClockSelection = RCC_I2C1CLKSOURCE_HSI;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

PUTCHAR_PROTOTYPE
{
  /* Place your implementation of fputc here */
  /* e.g. write a character to the EVAL_COM1 and Loop until the end of transmission */
  HAL_UART_Transmit(&huart2, (uint8_t *)&ch, 1, 0xFFFF);
  return ch;
}

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size) 
{
		if(huart->Instance == USART2){
			uint16_t rx_buf_len = strlen((const char*)RxBuf);
			memset(MainBuf, '\0', MainBuf_SIZE);
			memcpy ((uint8_t *)MainBuf, (uint8_t *)RxBuf, rx_buf_len);  // copy data in that remaining space
			memset(RxBuf, '\0', rx_buf_len);
			
			/* start the DMA again */
			HAL_UARTEx_ReceiveToIdle_DMA(&huart2, (uint8_t *) RxBuf, RxBuf_SIZE);
			__HAL_DMA_DISABLE_IT(&hdma_usart2_rx, DMA_IT_HT);
			
			/* Do some stuff */
			printf("%s\r\n",MainBuf);
		}
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
	if(GPIO_Pin == GPIO_PIN_3 && HAL_GetTick()-last_time >= 100){
		last_time = HAL_GetTick();
		if( HAL_GetTick()-sub_last_time >= 300){
			last_time = HAL_GetTick();
			sub_last_time = HAL_GetTick();
			if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_4)==false){
					rotate_dir = true;
				}
			else if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_4)==true){
				rotate_dir = false;
			}
		}
		printf("counter %s 1\r\n",rotate_dir?"+":"-");
	}
	if(GPIO_Pin == GPIO_PIN_0){
		printf("PA0\r\n");
	}
	if(GPIO_Pin == GPIO_PIN_8){
		printf("PA8\r\n");
	}
	if(GPIO_Pin == GPIO_PIN_9){
		printf("PA9\r\n");
	}
	if(GPIO_Pin == GPIO_PIN_10){
		printf("PA10\r\n");
	}
	if(GPIO_Pin == GPIO_PIN_11){
		printf("PA11\r\n");
	}
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

