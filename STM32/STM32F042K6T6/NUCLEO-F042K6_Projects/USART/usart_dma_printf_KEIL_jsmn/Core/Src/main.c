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
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h> //printf function

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
  MX_TIM14_Init();
  MX_TIM16_Init();
  MX_TIM17_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */

	HAL_UARTEx_ReceiveToIdle_DMA(&huart2, RxBuf, RxBuf_SIZE);
	__HAL_DMA_DISABLE_IT(&hdma_usart2_rx, DMA_IT_HT);
	
	
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	printf("USART DMA Printf test\r\n");
	
	
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		
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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
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
}

/* USER CODE BEGIN 4 */
void json2servo(char *JSON_STRING, uint16_t token_size )
{
    jsmntok_t *tokens = malloc(sizeof(jsmntok_t)*token_size);
    jsmn_parser parser;
    jsmn_init(&parser);
    int token_num = jsmn_parse(&parser, JSON_STRING, strlen(JSON_STRING), tokens, sizeof(jsmntok_t)*token_size);
    
	  printf("\nJSON_STRING= %s\n",JSON_STRING);
    printf("strlen(JSON_STRING)= %d\n",strlen(JSON_STRING));
    printf("\nsizeof(jsmntok_t)*token_size= %d*%d = %d\n\n",sizeof(jsmntok_t),token_size,sizeof(jsmntok_t)*token_size);
	
    for (int i = 0; i < token_num; i++)
    {
        // printf("token<%.*s> ", tokens[i].end - tokens[i].start, JSON_STRING + tokens[i].start);
			  printf("\ntoken[%d].start= %d, token[%d].end-1= %d, end-start= %d\n",i,tokens[i].start,i,tokens[i].end-1,tokens[i].end-tokens[i].start);
        printf("%s\r\n\n",substr(JSON_STRING, tokens[i].start, tokens[i].end-1));
			
				printf("%s\r\n",substr(JSON_STRING, tokens[i].start, tokens[i].end-1));
				char *p = substr(JSON_STRING, 2, 6);
				printf("%s\r\n",p);
				if(p){free(p);}

        if (jsoneq(JSON_STRING, &tokens[i], "mode") == 0){
            if (tokens[i + 1].type != JSMN_STRING){
                continue; /* We expect groups to be an array of string */
            }
            char *mode = substr(JSON_STRING, tokens[i + 1].start, tokens[i + 1].end-1); //Desired variable
            printf("mode: ");// Do some stuff.
            if(!strcmp(mode,"nest")){
                printf("%s\n",mode); // Do some stuff.
            }
            else if(!strcmp(mode,"grab")){
                printf("%s\n",mode); // Do some stuff.
            }
            else if(!strcmp(mode,"collect")){
                printf("%s\n",mode); // Do some stuff.
            }

            i++; // to next key token.
        }
        else if (jsoneq(JSON_STRING, &tokens[i], "move") == 0){
            if (tokens[i + 1].type != JSMN_PRIMITIVE){
                continue; /* We expect groups to be an array of numeric */
            }
            float speed= atof(substr(JSON_STRING, tokens[i + 1].start, tokens[i + 1].end-1));  //Desired variable

            printf("move: %f\n", speed); // Do some stuff.
            //wheel_l=speed;
            //wheel_r=speed;

            i++; // to next key token.
        }
        else if (jsoneq(JSON_STRING, &tokens[i], "turn") == 0){
            if (tokens[i + 1].type != JSMN_PRIMITIVE){
                continue; /* We expect groups to be an array of numeric */
            }
            float speed= atof(substr(JSON_STRING, tokens[i + 1].start, tokens[i + 1].end-1));  //Desired variable

            printf("turn: %f\n", speed); // Do some stuff.

            i++; // to next key token.
        }
        else if (jsoneq(JSON_STRING, &tokens[i], "rc_servo") == 0){
            if (tokens[i + 1].type != JSMN_OBJECT){
                continue; /* We expect groups to be an array of json object */
            }
            printf("rc_servo: {");
            for (int j = 0; j < tokens[i + 1].size; j++)
            {
                if (tokens[i + j*2 + 2].type != JSMN_STRING){
                    continue; /* We expect groups to be an array of strings */
                }
                jsmntok_t *tok_key = &tokens[i + j*2 + 2];
                unsigned short int servo_num= atoi(substr(JSON_STRING, tok_key->start, tok_key->end-1));  //Desired variable

                jsmntok_t *tok_val = &tokens[i + j*2 + 3];
                unsigned short int pwm_val= atoi(substr(JSON_STRING, tok_val->start, tok_val->end-1));  //Desired variable

                printf("%d:%d", servo_num, pwm_val); // Do some stuff.
                if(j+1 < tokens[i + 1].size){
                    printf(", ");
                }
            }
            printf("}\n"); // Do some stuff.
            
            i += tokens[i + 1].size*2 + 1; // to next key token.
        }
        else if (jsoneq(JSON_STRING, &tokens[i], "adc") == 0){

            printf("adc..\n"); // Do some stuff.

            i++; // to next key token.
        }
        else if (jsoneq(JSON_STRING, &tokens[i], "rc_request") == 0){

            printf("rc_request..\n"); // Do some stuff.

            i++; // to next key token.
        }
        else if (tokens[i].type == JSMN_PRIMITIVE){
            short int step_val= atoi(substr(JSON_STRING, tokens[i].start, tokens[i].end-1));  //Desired variable

            printf("step_value= %d\n", step_val); // Do some stuff.
            i++; // to next key token.
        }
    }
}/* USER CODE END 4 */

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

