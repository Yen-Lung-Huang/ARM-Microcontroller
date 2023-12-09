/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    usart.c
  * @brief   This file provides code for the configuration
  *          of the USART instances.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#include "usart.h"

/* USER CODE BEGIN 0 */
int fputc(int ch, FILE *f){  // already include stdio.h in .h, ""for printf function"" 
	HAL_UART_Transmit(&huart2, (uint8_t *)&ch, 1, 0xFFFF);  
	return ch;
}

uint8_t RxBuf[RxBuf_SIZE]; 			// DMA receive buffer.
uint8_t MainBuf[MainBuf_SIZE];	// RX receive.

uint16_t oldPos = 0;
uint16_t newPos = 0;

int isOK = 1;
/* USER CODE END 0 */

UART_HandleTypeDef huart2;
DMA_HandleTypeDef hdma_usart2_rx;

/* USART2 init function */

void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

void HAL_UART_MspInit(UART_HandleTypeDef* uartHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(uartHandle->Instance==USART2)
  {
  /* USER CODE BEGIN USART2_MspInit 0 */

  /* USER CODE END USART2_MspInit 0 */
    /* USART2 clock enable */
    __HAL_RCC_USART2_CLK_ENABLE();

    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**USART2 GPIO Configuration
    PA2     ------> USART2_TX
    PA3     ------> USART2_RX
    */
    GPIO_InitStruct.Pin = USART_TX_Pin|USART_RX_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF4_USART2;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* USART2 DMA Init */
    /* USART2_RX Init */
    hdma_usart2_rx.Instance = DMA1_Channel6;
    hdma_usart2_rx.Init.Request = DMA_REQUEST_4;
    hdma_usart2_rx.Init.Direction = DMA_PERIPH_TO_MEMORY;
    hdma_usart2_rx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_usart2_rx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_usart2_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_usart2_rx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    hdma_usart2_rx.Init.Mode = DMA_NORMAL;
    hdma_usart2_rx.Init.Priority = DMA_PRIORITY_LOW;
    if (HAL_DMA_Init(&hdma_usart2_rx) != HAL_OK)
    {
      Error_Handler();
    }

    __HAL_LINKDMA(uartHandle,hdmarx,hdma_usart2_rx);

    /* USART2 interrupt Init */
    HAL_NVIC_SetPriority(USART2_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(USART2_IRQn);
  /* USER CODE BEGIN USART2_MspInit 1 */

  /* USER CODE END USART2_MspInit 1 */
  }
}

void HAL_UART_MspDeInit(UART_HandleTypeDef* uartHandle)
{

  if(uartHandle->Instance==USART2)
  {
  /* USER CODE BEGIN USART2_MspDeInit 0 */

  /* USER CODE END USART2_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USART2_CLK_DISABLE();

    /**USART2 GPIO Configuration
    PA2     ------> USART2_TX
    PA3     ------> USART2_RX
    */
    HAL_GPIO_DeInit(GPIOA, USART_TX_Pin|USART_RX_Pin);

    /* USART2 DMA DeInit */
    HAL_DMA_DeInit(uartHandle->hdmarx);

    /* USART2 interrupt Deinit */
    HAL_NVIC_DisableIRQ(USART2_IRQn);
  /* USER CODE BEGIN USART2_MspDeInit 1 */

  /* USER CODE END USART2_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */

////	original video tuorial "v.1"	//// 0330_Can work!
//void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
//{
//	if (huart->Instance == USART2)
//	{
//		memcpy(MainBuf, RxBuf, Size);
//		HAL_UARTEx_ReceiveToIdle_DMA(&huart2, RxBuf, RxBuf_SIZE);
//		
//		__HAL_DMA_DISABLE_IT(&hdma_usart2_rx, DMA_IT_HT);

//	}

//}

////	original video tuorial "v.2"	//// 0330_Can work!
//void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
//{
//	if (huart->Instance == USART2)
//	{
//		oldPos = newPos;  // Update the last position before copying new data

//		/* If the data in large and it is about to exceed the buffer size, we have to route it to the start of the buffer
//		 * This is to maintain the circular buffer
//		 * The old data in the main buffer will be overlapped
//		 */
//		if (oldPos+Size > MainBuf_SIZE)  // If the current position + new data size is greater than the main buffer
//		{
//			uint16_t datatocopy = MainBuf_SIZE-oldPos;  // find out how much space is left in the main buffer
//			memcpy ((uint8_t *)MainBuf+oldPos, RxBuf, datatocopy);  // copy data in that remaining space

//			oldPos = 0;  // point to the start of the buffer
//			memcpy ((uint8_t *)MainBuf, (uint8_t *)RxBuf+datatocopy, (Size-datatocopy));  // copy the remaining data
//			newPos = (Size-datatocopy);  // update the position
//		}

//		/* if the current position + new data size is less than the main buffer
//		 * we will simply copy the data into the buffer and update the position
//		 */
//		else
//		{
//			memcpy ((uint8_t *)MainBuf+oldPos, RxBuf, Size);
//			newPos = Size+oldPos;
//		}


//		/* start the DMA again */
//		HAL_UARTEx_ReceiveToIdle_DMA(&huart2, (uint8_t *) RxBuf, RxBuf_SIZE);
//		__HAL_DMA_DISABLE_IT(&hdma_usart2_rx, DMA_IT_HT);

//	}
//}

bool json_action(char *JSON_STRING, uint16_t token_size)
{
		cJSON *root = cJSON_ParseWithLength(JSON_STRING, token_size);
    if(root == NULL){
        // printf("invalid JSON\r\n"); // Print for debug.
        return false;
    }
		
		for (cJSON *token = root->child;token != NULL;token = token->next){
			
			if(!strcmp(token->string,"rc_servo")){
            cJSON *json_obj = cJSON_GetObjectItem(root, "rc_servo");
            if(json_obj!=NULL){
                if(cJSON_IsObject(json_obj) == false){
                    continue;
                }
									printf("%s:",token->string); // Print for debug.
									printf("{\n"); // Print for debug.
								
                for(cJSON *obj_token = json_obj->child; obj_token!= NULL; obj_token=obj_token->next){
									
                    uint8_t servo_num= atoi(obj_token->string); // Desired variable
									
										printf(">>servo_num:%d",servo_num); // Print for debug.
									
                    if(/*servo_num>=0 &&*/ servo_num<=11){
                      uint8_t pwm_val= obj_token->valueint;
											
											printf(">>pwm_val:%d\n",pwm_val); // Print for debug.
											
											if(pwm_val>=0 && pwm_val<=255){
												TIM2->CCR1 = pwm_val;
												printf("CCR1<-%d",pwm_val);
											}
											//servo_pwm_set(&servo[servo_num],pwm_val);
											
											if(servo_num==1||servo_num==5){
												//servo_pwm_set(&servo[servo_num],pwm_val);
												//servo_wild_set(&servo[servo_num],pwm_val);
												//servo_pwm_set(&servo[servo_num],map(pwm_val,0,100,servo[servo_num].pwm_min,servo[servo_num].pwm_max));
												//shoulder_set(pwm_val);
												//shoulder_set(map(pwm_val,0,100,servo[servo_num].pwm_min,servo[servo_num].pwm_max));
												////shoulder_set(map(pwm_val,0,100,servo[servo_num].physical_min,servo[servo_num].physical_max));
											}
											else{
												//servo_pwm_set(&servo[servo_num],pwm_val);
												////servo_pwm_set(&servo[servo_num],map(pwm_val,0,100,servo[servo_num].pwm_min,servo[servo_num].pwm_max));
											}
										
											// printf("%d:%d",servo_num,servo[servo_num].pwm_value); // Print for debug.
											// printf("(degree=%g, %d%%)",servo_get_physical(&servo[servo_num]),(int)map(servo[servo_num].pwm_value,servo[servo_num].pwm_min,servo[servo_num].pwm_max,0,100)); // Print for debug.
											
											if(obj_token->next!= NULL){
													// printf(", "); // Print for debug.
											}
                    }
                }
                // printf("}\r\n"); // Print for debug.
            }
        }
		}
		cJSON_Delete(root);
		return 1;
}

////	 Yan Long junior student's code	//// 0330_Can work!
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
			//printf("MainBuf:%s\r\n\n\n",MainBuf);
			//ParseStrDemo((char*)MainBuf);
			json_action((char*)MainBuf, sizeof(char)*MainBuf_SIZE);
		}
}



//// CSDN example ////
void ParseStrDemo(char* strArr)
{
		//char strArr[] = "{\"name\":\"Andy\",\"age\":20}";
		cJSON *str_json, *str_name, *str_age;
 
    printf("strArr[]:%s \r\n",strArr);
 
    str_json = cJSON_Parse(strArr);   //??JSON????,??JSON??????
    if (!str_json)
    {
        printf("JSON_script_error:%s \r\n", cJSON_GetErrorPtr()); //??json??????
    }
    else
    {
        printf("JSON_script_correct:%s \r\n",cJSON_Print(str_json) );
        str_name = cJSON_GetObjectItem(str_json, "name"); //??name????????
        if (str_name->type == cJSON_String)
        {
            printf("name:%s \r\n", str_name->valuestring);
        }
        str_age = cJSON_GetObjectItem(str_json, "age");   //??age????????
        if(str_age->type==cJSON_Number)
        {
            printf("edge:%d \r\n", str_age->valueint);
        }
        cJSON_Delete(str_json);    //????
    }
}
/* USER CODE END 1 */
