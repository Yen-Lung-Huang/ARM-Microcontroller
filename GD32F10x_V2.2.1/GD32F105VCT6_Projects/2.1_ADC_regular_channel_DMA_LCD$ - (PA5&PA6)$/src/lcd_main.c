/*!
    \file    main.c
    \brief   this file realizes the MSC host

    \version 2020-07-17, V3.0.0, firmware for GD32F10x
*/




#include "lcd_usr.h"


/*!
    \brief      main routine
    \param[in]  none
    \param[out] none
    \retval     none
*/
int main(void)
{   
    uint32_t id = 10270335;
    uint8_t Voltage[] = "5";
    uint8_t Luminosity[] = "100";
    
    lcd_user_init();
    
    LCD_ErrLog("> No errors detected.\r\n");
    LCD_DevInformation("VID: %u\r\n", id);
    lcd_text_color_set(LCD_COLOR_YELLOW);
    lcd_vertical_string_display(LCD_HINT_LINE0, 0,  (uint8_t *)"Potentiometer:");
    lcd_vertical_string_display(LCD_HINT_LINE5, 0, (uint8_t *)"Photoresistor:");
    lcd_text_color_set(LCD_COLOR_WHITE);
    lcd_vertical_string_display(LCD_HINT_LINE0, 120, (uint8_t *)Voltage);  
    lcd_vertical_string_display(LCD_HINT_LINE5, 120, (uint8_t *)Luminosity);

    while (1) {

    }
}
