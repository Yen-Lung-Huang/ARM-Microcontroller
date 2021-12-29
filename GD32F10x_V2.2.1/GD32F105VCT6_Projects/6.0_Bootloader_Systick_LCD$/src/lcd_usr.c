/*!
    \file    lcd_usr.c
    \brief   user application layer for USBFS host-mode MSC class operation

    \version 2020-07-17, V3.0.0, firmware for GD32F10x
*/




#include "lcd_usr.h"


const uint8_t MSG_HOST_HEADER[]      = "Bootloader v1.0";
const uint8_t MSG_HOST_FOOTER[]      = "Rebit Digital Co.; Ltd";


/*!
    \brief      user operation for host-mode initialization
    \param[in]  none
    \param[out] none
    \retval     none
*/
void lcd_user_init(void)
{

        gd_eval_lcd_init();

        lcd_log_init();

        lcd_log_header_set((uint8_t *)MSG_HOST_HEADER, 90U);

        lcd_log_footer_set((uint8_t *)MSG_HOST_FOOTER, 60U);

}





