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
#include "adc.h"
#include "i2c.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h> //printf function
#include <string.h>
#include <stdbool.h>
#include "servo.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
ServoTypeDef servo[12];
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
  MX_TIM2_Init();
  MX_TIM3_Init();
  MX_TIM14_Init();
  MX_TIM16_Init();
  MX_TIM17_Init();
  MX_USART2_UART_Init();
  MX_I2C1_Init();
  MX_ADC_Init();
  MX_TIM1_Init();
  /* USER CODE BEGIN 2 */
	
	/* Servo Motors Configuration--------------------------------------------------------*/
	servo[0 ] = servo_init(.timer=&htim2 , .channel=TIM_CHANNEL_2); // 0_Base
	servo[1 ] = servo_init(.timer=&htim2 , .channel=TIM_CHANNEL_4, .reverse=true); // 1_Shoulder#1
	servo[2 ] = servo_init(.timer=&htim2 , .channel=TIM_CHANNEL_1, .latch=true); // 2_Elbow
	servo[3 ] = servo_init(.timer=&htim3 , .channel=TIM_CHANNEL_1); // 3_Wrist
	servo[4 ] = servo_init(.timer=&htim3 , .channel=TIM_CHANNEL_2); // 4_End-effecter
	servo[5 ] = servo_init(.timer=&htim14, .channel=TIM_CHANNEL_1); // 5_Shoulder#2
	servo[6 ] = servo_init(.timer=&htim3 , .channel=TIM_CHANNEL_3); // 6_Wheel_FL
	servo[7 ] = servo_init(.timer=&htim17, .channel=TIM_CHANNEL_1, .complementary=true); // 7_Wheel_FR
	servo[8 ] = servo_init(.timer=&htim16, .channel=TIM_CHANNEL_1, .complementary=true); // 8_Wheel_RL
	servo[9 ] = servo_init(.timer=&htim3 , .channel=TIM_CHANNEL_4); // 9_Wheel_RR
	servo[10] = servo_init(.timer=&htim1 , .channel=TIM_CHANNEL_1); // 10_Wheel_Speed_L
	servo[11] = servo_init(.timer=&htim1 , .channel=TIM_CHANNEL_4); // 11_Wheel_Speed_R
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	
	uint32_t pwm_count = 25;
	uint32_t prev_tick=HAL_GetTick();
	uint32_t tick_count = 1;
	bool count_state = true;
	//const uint32_t tick_delay=700;
	//const uint32_t tick_delay=15;
	const uint32_t tick_delay=4;
	
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		
		//servo_pwm_set(&servo[selected_servo],servo[selected_servo].pwm_value);
		uint32_t temp_tick = HAL_GetTick()-prev_tick;
		
		if(temp_tick>=tick_delay*(tick_count) && temp_tick<tick_delay*(tick_count+1)){
			arm_pwm_set(pwm_count,pwm_count,pwm_count,pwm_count,pwm_count);
		}
		printf("pwm_count= %d, tick_count= %d, count_state= %d\n",pwm_count,tick_count,count_state);
		pwm_count+=count_state*2-1;
		tick_count ++;
		if(pwm_count==125 || pwm_count==25){
			prev_tick=HAL_GetTick();
			count_state=!count_state;
			tick_count = 1;
		}
		
		
//		if(temp_tick>=tick_delay*1 && temp_tick<tick_delay*2){
//			arm_pwm_set(25,25,25,25,25);
//		}
//		if(temp_tick>=tick_delay*2 && temp_tick<tick_delay*3){
//			arm_pwm_set(75,75,75,75,75);
//		}
//		if(temp_tick>=tick_delay*3 && temp_tick<tick_delay*4){
//			arm_pwm_set(125,125,125,125,125);
//		}
//		if(temp_tick>=tick_delay*4 && temp_tick<tick_delay*5){
//			arm_pwm_set(75,75,75,75,75);
//			prev_tick=HAL_GetTick();
//		}
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
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_HSI14
                              |RCC_OSCILLATORTYPE_HSI48;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSI48State = RCC_HSI48_ON;
  RCC_OscInitStruct.HSI14State = RCC_HSI14_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.HSI14CalibrationValue = 16;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI48;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL16;
  RCC_OscInitStruct.PLL.PREDIV = RCC_PREDIV_DIV16;
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

