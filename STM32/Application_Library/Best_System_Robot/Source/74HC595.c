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

//Set GPIO Pin
void gpio_pin_set(My_GPIO_TypeDef *gpio, GPIO_TypeDef *port, uint16_t pin)
{
    gpio->Port = port;
    gpio->Pin = pin;
}

// Send a byte to the 74HC595 structure
void HC595_SendByte(HC595 *hc595, uint8_t byte)
{
    HAL_GPIO_WritePin(hc595->LATCH.Port, hc595->LATCH.Pin, 0); 	 // Toggle latch
    for (int8_t i = 7; i >= 0; --i) {
        uint8_t bit = byte & (0x1 << i);             							 // Read bit
        HAL_GPIO_WritePin(hc595->CLOCK.Port, hc595->CLOCK.Pin, 0); // Toggle clock
        HAL_GPIO_WritePin(hc595->DATA.Port, hc595->DATA.Pin, bit); // Send bit
        HAL_GPIO_WritePin(hc595->CLOCK.Port, hc595->CLOCK.Pin, 1); // Toggle clock
        HAL_GPIO_WritePin(hc595->DATA.Port, hc595->DATA.Pin, bit); // Send bit(again for sure)
    }
    HAL_GPIO_WritePin(hc595->LATCH.Port, hc595->LATCH.Pin, 1);   // Toggle latch
    hc595->byte = byte; // Assign the input value to the byte value
}


// Define a function to set a specific bit of the output byte
void HC595_SendBit(HC595 *hc595, uint8_t bit, bool value)
{
    // Check the validity of the arguments
    if (hc595 == NULL) {
        return;    // Invalid pointer
    }
    if (bit > 7) {
        return;    // Invalid bit number
    }

    // Set or clear the bit according to the value
    if (value) { // Set the bit to 1
        hc595->byte = hc595->byte | (1 << bit); // Use bitwise OR to set the bit
    } else { // Set the bit to 0
        hc595->byte = hc595->byte & ~(1 << bit); // Use bitwise AND and NOT to clear the bit
    }

    // Send the byte to the HC595 structure
    HC595_SendByte(hc595, hc595->byte);
}

