/*!
    \file    lcd_conf.h
    \brief   LCD driver configuration

    \version 2020-07-17, V3.0.0, firmware for GD32F10x
*/



#ifndef __LCD_CONF_H
#define __LCD_CONF_H

#include <stdio.h>


#define LCD_LOG_TEXT_COLOR            LCD_COLOR_WHITE
#define LCD_LOG_DEFAULT_COLOR         LCD_COLOR_WHITE

/* define the cache depth */
#define CACHE_SIZE                    100U

#define YWINDOW_MIN                   3U
#define YWINDOW_SIZE                  8U

#define LCD_HEADER_X                  210U  //MM Originally 0U
#define LCD_HEADER_Y                  0U

#define LCD_FLAG_WIDTH                30U
#define LCD_FLAG_HEIGHT               320U

#define LCD_FOOTER_X                  0U    //MM Originally 210U
#define LCD_FOOTER_Y                  0U

#define LCD_BODY_X                    0U    //MM New
#define LCD_BODY_Y                    0U    //MM New
#define LCD_BODY_WIDTH                210U  //MM New
#define LCD_BODY_HEIGHT               320U  //MM New

#define LCD_TEXT_ZONE_X               LCD_FLAG_WIDTH
#define LCD_TEXT_ZONE_Y               0
#define LCD_TEXT_ZONE_WIDTH           LCD_PIXEL_WIDTH - 2 * LCD_FLAG_WIDTH
#define LCD_TEXT_ZONE_HEIGHT          LCD_PIXEL_HEIGHT

#define LCD_TEXT_OFFSET               20U

#define LCD_HEADER_LINE               LCD_HEADER_X + LCD_TEXT_OFFSET
#define LCD_FOOTER_LINE               LCD_FOOTER_X + LCD_TEXT_OFFSET

//#define LCD_HINT_LINE0                180U        //MM Original
//#define LCD_HINT_LINE1                190U        //MM Original
//#define LCD_HINT_LINE2                210U        //MM Original


#define LCD_HINT_LINE0                200U
#define LCD_HINT_LINE1                185U
#define LCD_HINT_LINE2                170U
#define LCD_HINT_LINE3                155U
#define LCD_HINT_LINE4                140U
#define LCD_HINT_LINE5                125U
#define LCD_HINT_LINE6                110U
#define LCD_HINT_LINE7                95U
#define LCD_HINT_LINE8                80U
#define LCD_HINT_LINE9                65U




/* redirect the printf to the LCD */
#ifdef __GNUC__
    /* With GCC, small printf (option LD Linker->Libraries->Small printf
       set to 'Yes') calls __io_putchar() */
    #define LCD_LOG_PUTCHAR int __io_putchar(int ch)
#else
    #define LCD_LOG_PUTCHAR int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

#endif /* __LCD_CONF_H */
