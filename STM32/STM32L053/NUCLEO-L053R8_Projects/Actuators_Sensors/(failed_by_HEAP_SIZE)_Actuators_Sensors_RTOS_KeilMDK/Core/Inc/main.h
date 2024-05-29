/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
extern UART_HandleTypeDef huart2;
extern DMA_HandleTypeDef hdma_usart2_rx;
/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
#define RxBuf_SIZE 256
#define MainBuf_SIZE RxBuf_SIZE
/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */
extern uint8_t RxBuf[RxBuf_SIZE]; 		// DMA receive buffer.
extern uint8_t MainBuf[MainBuf_SIZE];	// RX receive. 
/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define SW_Middle_Bracket_Pin GPIO_PIN_13
#define SW_Middle_Bracket_GPIO_Port GPIOC
#define SW_Middle_Bracket_EXTI_IRQn EXTI4_15_IRQn
#define SW_Right_Pin GPIO_PIN_0
#define SW_Right_GPIO_Port GPIOC
#define SW_Left_Pin GPIO_PIN_1
#define SW_Left_GPIO_Port GPIOC
#define M4_Encoder_A_Pin GPIO_PIN_2
#define M4_Encoder_A_GPIO_Port GPIOC
#define M4_Encoder_B_Pin GPIO_PIN_3
#define M4_Encoder_B_GPIO_Port GPIOC
#define M4_EN_Pin GPIO_PIN_0
#define M4_EN_GPIO_Port GPIOA
#define M1_EN_Pin GPIO_PIN_1
#define M1_EN_GPIO_Port GPIOA
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define SW_Middle_Up_Pin GPIO_PIN_4
#define SW_Middle_Up_GPIO_Port GPIOA
#define Rollers__Relay_Pin GPIO_PIN_5
#define Rollers__Relay_GPIO_Port GPIOA
#define DIR_LATCH_Pin GPIO_PIN_6
#define DIR_LATCH_GPIO_Port GPIOA
#define M1_ENA7_Pin GPIO_PIN_7
#define M1_ENA7_GPIO_Port GPIOA
#define M2_A_Pin GPIO_PIN_4
#define M2_A_GPIO_Port GPIOC
#define M3_B_Pin GPIO_PIN_5
#define M3_B_GPIO_Port GPIOC
#define SW_Middle_Down_Pin GPIO_PIN_0
#define SW_Middle_Down_GPIO_Port GPIOB
#define M1_A_Pin GPIO_PIN_1
#define M1_A_GPIO_Port GPIOB
#define M1_B_Pin GPIO_PIN_2
#define M1_B_GPIO_Port GPIOB
#define M3_EN_Pin GPIO_PIN_10
#define M3_EN_GPIO_Port GPIOB
#define S3_PWM_Pin GPIO_PIN_11
#define S3_PWM_GPIO_Port GPIOB
#define M4_A_Pin GPIO_PIN_12
#define M4_A_GPIO_Port GPIOB
#define S1_PWM_Pin GPIO_PIN_13
#define S1_PWM_GPIO_Port GPIOB
#define S2_PWM_Pin GPIO_PIN_14
#define S2_PWM_GPIO_Port GPIOB
#define M2_B_Pin GPIO_PIN_15
#define M2_B_GPIO_Port GPIOB
#define M3_ENC6_Pin GPIO_PIN_6
#define M3_ENC6_GPIO_Port GPIOC
#define M2_EN_Pin GPIO_PIN_7
#define M2_EN_GPIO_Port GPIOC
#define HC_SR04_All_Trig_Pin GPIO_PIN_8
#define HC_SR04_All_Trig_GPIO_Port GPIOC
#define HC_SR04_Middle_Echo_Pin GPIO_PIN_9
#define HC_SR04_Middle_Echo_GPIO_Port GPIOC
#define DIR_EN_Pin GPIO_PIN_8
#define DIR_EN_GPIO_Port GPIOA
#define DIR_SER_Pin GPIO_PIN_9
#define DIR_SER_GPIO_Port GPIOA
#define SW_Revolver_Right_Pin GPIO_PIN_10
#define SW_Revolver_Right_GPIO_Port GPIOA
#define M4_B_Pin GPIO_PIN_11
#define M4_B_GPIO_Port GPIOA
#define M3_A_Pin GPIO_PIN_12
#define M3_A_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define M3_Encoder_A_Pin GPIO_PIN_15
#define M3_Encoder_A_GPIO_Port GPIOA
#define M2_Encoder_A_Pin GPIO_PIN_10
#define M2_Encoder_A_GPIO_Port GPIOC
#define M1_Encoder_A_Pin GPIO_PIN_11
#define M1_Encoder_A_GPIO_Port GPIOC
#define M2_Encoder_B_Pin GPIO_PIN_12
#define M2_Encoder_B_GPIO_Port GPIOC
#define M1_Encoder_B_Pin GPIO_PIN_2
#define M1_Encoder_B_GPIO_Port GPIOD
#define M2_ENB3_Pin GPIO_PIN_3
#define M2_ENB3_GPIO_Port GPIOB
#define M4_ENB4_Pin GPIO_PIN_4
#define M4_ENB4_GPIO_Port GPIOB
#define DIR_CLK_Pin GPIO_PIN_5
#define DIR_CLK_GPIO_Port GPIOB
#define SW_Revolver_Left_Pin GPIO_PIN_6
#define SW_Revolver_Left_GPIO_Port GPIOB
#define M3_Encoder_B_Pin GPIO_PIN_7
#define M3_Encoder_B_GPIO_Port GPIOB
#define HC_SR04_Left_Echo_Pin GPIO_PIN_8
#define HC_SR04_Left_Echo_GPIO_Port GPIOB
#define HC_SR04_Right_Echo_Pin GPIO_PIN_9
#define HC_SR04_Right_Echo_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
