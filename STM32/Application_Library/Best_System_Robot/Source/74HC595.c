/*
 * 74HC595.c
 *
 *  Created on: 2023/12/11
 *      Author: Yan Lung Huang
 *
 *	LATCH    - PA6 (General output PP)
 *  CLOCK    - PB5 (General output PP)
 *  DATA     - PA9 (General output PP)
 */

#include "74HC595.h"

// Send a byte to the 74HC595 structure
void HC595_SendByte(HC595 *hc595, uint8_t byte)
{
	HAL_GPIO_WritePin(hc595->LATCH_Port, hc595->LATCH_Pin, 0); 	 // Toggle latch
	for (int8_t i = 7; i >= 0; --i) {
		uint8_t bit = byte & (0x1 << i);             							 // Read bit
		HAL_GPIO_WritePin(hc595->CLOCK_Port, hc595->CLOCK_Pin, 0); // Toggle clock
		HAL_GPIO_WritePin(hc595->DATA_Port, hc595->DATA_Pin, bit); // Send bit
		HAL_GPIO_WritePin(hc595->CLOCK_Port, hc595->CLOCK_Pin, 1); // Toggle clock
		HAL_GPIO_WritePin(hc595->DATA_Port, hc595->DATA_Pin, bit); // Send bit(again for sure)
	}
	HAL_GPIO_WritePin(hc595->LATCH_Port, hc595->LATCH_Pin, 1);   // Toggle latch
}


