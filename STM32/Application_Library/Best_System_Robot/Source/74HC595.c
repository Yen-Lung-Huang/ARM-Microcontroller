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

void HC595_SendByte(uint8_t byte)
{
	uint16_t clock_timeout = 10000;
	uint16_t latch_timeout = 1000;
	
	for (int8_t i = 7; i >= 0; --i) {
		uint8_t bit = byte & (0x1 << i);             // Read bit
		HAL_GPIO_WritePin(DATA_Port, DATA_Pin, bit); // Send bit
		
		// Toggle clock
		HAL_GPIO_WritePin(CLOCK_Port, CLOCK_Pin, 1);
		while(clock_timeout--);
		HAL_GPIO_WritePin(CLOCK_Port, CLOCK_Pin, 0);
	}

	// Toggle latch
	HAL_GPIO_WritePin(LATCH_Port, LATCH_Pin, 1);
	while (latch_timeout--);
	HAL_GPIO_WritePin(LATCH_Port, LATCH_Pin, 0);
}

