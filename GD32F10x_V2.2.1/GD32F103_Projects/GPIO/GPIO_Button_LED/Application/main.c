/* <GPIO test>
		Function:
		PA0 input Low, PC2 output Low to light LED;
		PA0 input High, PC2 output High turn off LED
*/

#include "gd32103c_start.h"

int main(void)
{
	user_key_init(); // Enable GPIOA clock and set PA0 as in-floating input
	led_init(); // Enable GPIOC clock and set PC6 as push-pull output
	
	while(1){
		led(user_key());
		/* The same as:
		   gpio_bit_write(GPIOC, GPIO_PIN_6, gpio_input_bit_get (GPIOA, GPIO_PIN_0));
		*/
	}
}
