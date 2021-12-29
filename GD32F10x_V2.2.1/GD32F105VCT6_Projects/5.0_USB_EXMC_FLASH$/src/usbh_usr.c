/*!
    \file    usbh_usr.c
    \brief   user application layer for USBFS host-mode MSC class operation

    \version 2020-07-17, V3.0.0, firmware for GD32F10x
*/

/*
    Copyright (c) 2020, GigaDevice Semiconductor Inc.

    Redistribution and use in source and binary forms, with or without modification, 
are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice, this 
       list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright notice, 
       this list of conditions and the following disclaimer in the documentation 
       and/or other materials provided with the distribution.
    3. Neither the name of the copyright holder nor the names of its contributors 
       may be used to endorse or promote products derived from this software without 
       specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT 
NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR 
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY 
OF SUCH DAMAGE.
*/


#include "usbh_usr.h"
#include "ledsbut.h"


/*Nand Flash variables begin*/

#define BUFFER_SIZE                 (0x100U)        //MM Originally (0x100U)
#define NAND_HY_MAKERID             (0xC8U)         //MM Originally (0xADU)
#define NAND_HY_DEVICEID            (0xF1U)         //MM Originally (0xF1U)

nand_id_struct nand_id;
uint8_t txbuffer[BUFFER_SIZE], rxbuffer[BUFFER_SIZE];
__IO uint32_t writereadstatus = 0, status= 0;
uint32_t j = 0;
uint32_t k = 0;
uint32_t writereadaddr ;
uint16_t zone, block, page, pageoffset;

/*Nand Flash variables end*/



extern usb_core_driver usbh_core;
extern usbh_host usb_host;

FATFS fatfs;
FIL file;


uint8_t usbh_usr_application_state = USBH_USR_FS_INIT;

/*  points to the DEVICE_PROP structure of current device */
usbh_user_cb usr_cb =
{
    usbh_user_init,
    usbh_user_deinit,
    usbh_user_device_connected,
    usbh_user_device_reset,
    usbh_user_device_disconnected,
    usbh_user_over_current_detected,
    usbh_user_device_speed_detected,
    usbh_user_device_desc_available,
    usbh_user_device_address_assigned,
    usbh_user_configuration_descavailable,
    usbh_user_manufacturer_string,
    usbh_user_product_string,
    usbh_user_serialnum_string,
    usbh_user_enumeration_finish,
    usbh_user_userinput,
    usbh_usr_msc_application,
    usbh_user_device_not_supported,
    usbh_user_unrecovered_error
};




/*!
    \brief      user operation for host-mode initialization
    \param[in]  none
    \param[out] none
    \retval     none
*/
void usbh_user_init(void)
{
    static uint8_t startup = 0U;

    if (0U == startup) {
        startup = 1U;

        printf("USB host library started\r\n");

    }
}

/*!
    \brief      deinitialize user state and associated variables
    \param[in]  none
    \param[out] none
    \retval     none
*/
void usbh_user_deinit(void)
{
    usbh_usr_application_state = USBH_USR_FS_INIT;
}

/*!
    \brief      user operation for device attached
    \param[in]  none
    \param[out] none
    \retval     none
*/
void usbh_user_device_connected(void)
{
    printf("> Device Attached.\r\n");
}

/*!
    \brief      user operation when unrecovered error happens
    \param[in]  none
    \param[out] none
    \retval     none
*/
void usbh_user_unrecovered_error (void)
{
    printf("> Unrecovered error state .\r\n");
}

/*!
    \brief      user operation for device disconnect event
    \param[in]  none
    \param[out] none
    \retval     none
*/
void usbh_user_device_disconnected (void)
{
    printf("> Device Disconnected.\r\n");
}

/*!
    \brief      user operation for reset USB Device
    \param[in]  none
    \param[out] none
    \retval     none
*/
void usbh_user_device_reset(void)
{
    printf("> Reset the USB device.\r\n");
}

/*!
    \brief      user operation for detecting device speed
    \param[in]  device_speed: device speed
    \param[out] none
    \retval     none
*/
void usbh_user_device_speed_detected(uint32_t device_speed)
{
    if (PORT_SPEED_HIGH == device_speed) {
        printf("> High speed device detected.\r\n");
    } else if(PORT_SPEED_FULL == device_speed) {
        printf("> Full speed device detected.\r\n");
    } else if(PORT_SPEED_LOW == device_speed) {
        printf("> Low speed device detected.\r\n");
    } else {
        printf("> Device Fault.\r\n");
    }
}

/*!
    \brief      user operation when device descriptor is available
    \param[in]  device_desc: device descriptor
    \param[out] none
    \retval     none
*/
void usbh_user_device_desc_available(void *device_desc)
{
    usb_desc_dev *pDevStr = device_desc;

    printf("VID: %04Xh\r\n", (uint32_t)pDevStr->idVendor);
    printf("PID: %04Xh\r\n", (uint32_t)pDevStr->idProduct);
}

/*!
    \brief      usb device is successfully assigned the address 
    \param[in]  none
    \param[out] none
    \retval     none
*/
void usbh_user_device_address_assigned(void)
{
}

/*!
    \brief      user operation when configuration descriptor is available
    \param[in]  cfg_desc: pointer to configuration descriptor
    \param[in]  itf_desc: pointer to interface descriptor
    \param[in]  ep_desc: pointer to endpoint descriptor
    \param[out] none
    \retval     none
*/
void usbh_user_configuration_descavailable(usb_desc_config *cfg_desc,
                                           usb_desc_itf *itf_desc,
                                           usb_desc_ep *ep_desc)
{
    usb_desc_itf *id = itf_desc;

    if (0x08U  == (*id).bInterfaceClass) {
        printf("> Mass storage device connected.\r\n");
    } else if (0x03U  == (*id).bInterfaceClass) {
        printf("> HID device connected.\r\n");
    }
}

/*!
    \brief      user operation when manufacturer string exists
    \param[in]  manufacturer_string: manufacturer string of usb device
    \param[out] none
    \retval     none
*/
void usbh_user_manufacturer_string(void *manufacturer_string)
{
    printf("Manufacturer: %s\r\n", (char *)manufacturer_string);
}

/*!
    \brief      user operation when product string exists
    \param[in]  product_string: product string of usb device
    \param[out] none
    \retval     none
*/
void usbh_user_product_string(void *product_string)
{
    printf("Product: %s\r\n", (char *)product_string);
}

/*!
    \brief      user operation when serialNum string exists
    \param[in]  serial_num_string: serialNum string of usb device
    \param[out] none
    \retval     none
*/
void usbh_user_serialnum_string(void *serial_num_string)
{
    printf("Serial Number: %s\r\n", (char *)serial_num_string);
}

/*!
    \brief      user response request is displayed to ask for application jump to class
    \param[in]  none
    \param[out] none
    \retval     none
*/
void usbh_user_enumeration_finish(void)
{
    printf("> Enumeration completed.\r\n");

}

/*!
    \brief      user operation when device is not supported
    \param[in]  none
    \param[out] none
    \retval     none
*/
void usbh_user_device_not_supported(void)
{
    printf("> Device not supported.\r\n");
}

/*!
    \brief      user action for application state entry
    \param[in]  none
    \param[out] none
    \retval     user response for user key
*/
usbh_user_status usbh_user_userinput(void)
{

    usbh_user_status usbh_usr_status = USBH_USER_RESP_OK;

    return usbh_usr_status;
}

/*!
    \brief      user operation for device over current detection event
    \param[in]  none
    \param[out] none
    \retval     none
*/
void usbh_user_over_current_detected (void)
{
    printf("> Overcurrent detected.\r\n");
}

/*!
    \brief      demo application for mass storage
    \param[in]  none
    \param[out] none
    \retval     status
*/
int usbh_usr_msc_application(void)
{
    FRESULT res;
    msc_lun info;
//    uint8_t WriteTextBuff[256];
    uint16_t bytesWritten, bytesToWrite;

    switch(usbh_usr_application_state){
    case USBH_USR_FS_INIT:
        /* initializes the file system*/
        if (FR_OK != f_mount(&fatfs, "0:/", 0)) {
            printf("> Cannot initialize File System.\r\n");

            return(-1);
        }

        printf("> File System initialized.\r\n");
        if (USBH_OK == usbh_msc_lun_info_get(&usb_host, 0U, &info))
        {
            printf("> Disk capacity: %ud Bytes.\r\n", info.capacity.block_nbr * info.capacity.block_size);
        }

        usbh_usr_application_state = USBH_USR_FS_READLIST;
        break;

    case USBH_USR_FS_READLIST:

        usbh_usr_application_state = USBH_USR_FS_WRITEFILE;
        break;

    case USBH_USR_FS_WRITEFILE:
        usb_mdelay(100U);

				printf("                                  \r\n");
				printf("\r\nPress User Key to copy flash content\r\n"); 

        /*key b3 in polling*/
        while ((usbh_core.host.connect_status) && \
                (SET == button_state_get (USER))) {
            toggle_leds();
        }

        
        if (usbh_core.host.connect_status){              //MM Adding this consider USB being disconnected while waiting for wakeup button
        printf("> Reading external flash memory memory ...\r\n");

        /* register work area for logical drives */
        f_mount(&fatfs, "0:/", 1);

        if (FR_OK == f_open(&file, "0:FlashContent.txt", FA_CREATE_ALWAYS | FA_WRITE)) {
            
            
//*****************************************************************************************************************

    /* read NAND ID */
    nand_read_id(&nand_id);

    printf("read NAND ID");
    /* print NAND ID */
    printf("\r\nNand flash ID:0x%X 0x%X 0x%X 0x%X\r\n",nand_id.maker_id,nand_id.device_id,
                                               nand_id.third_id,nand_id.fourth_id);

    if((NAND_HY_MAKERID == nand_id.maker_id) && (NAND_HY_DEVICEID == nand_id.device_id))
    {
        /* set the read and write the address */
        zone = 0;
        block = 10;
        page = 0;
        pageoffset = 1200;      //MM Originally 1100;
        writereadaddr = ((zone * NAND_ZONE_SIZE + block) * NAND_BLOCK_SIZE + page) 
                        * NAND_PAGE_SIZE + pageoffset;

        /* whether address cross-border */
        if((writereadaddr + BUFFER_SIZE ) > NAND_MAX_ADDRESS)
        {
            printf("\r\naddress cross-border");

            /* failure, light on LED5 */
            LED_ON(Led5);
            while(1);
        }

        /* read data from nand flash */
        status = nand_read(writereadaddr, rxbuffer, BUFFER_SIZE);
        if(NAND_OK == status)
        {
            printf("\r\nread data successfully!");
        }
        else
        {
            printf("\r\nread data failure!\n\r");

            /* failure, light on LED5 */
            LED_ON(Led5);
            while(1);
        }


    }
    else
    {
        printf("\n\rread NAND ID failure!\n\r");
        
        /* failure, light on LED5 */
        LED_ON(Led5);
        while(1);
    }
    
    
//*************************************************************************************************
           
            
            /* write buffer to file */
            bytesToWrite = BUFFER_SIZE; //sizeof(rxbuffer); 
            res = f_write (&file, rxbuffer, bytesToWrite, (void *)&bytesWritten);
            /* EOF or error */
            if ((0U == bytesWritten) || (FR_OK != res)) {
                printf("> FlashContent.txt CANNOT be writen.\r\n");
            } else {
                printf("> FlashContent.txt created in the disk.\r\n");
            }

            /* close file and file system */
            f_close(&file);
            f_mount(NULL, "0:/", 1); 
        } else {
            printf("> FlashContent.txt created in the disk.\r\n");
        }

        }   //MM Adding...

        usbh_usr_application_state = USBH_USR_FS_DEMOEND;
        printf("> Application has been closed.\r\n");
        break;

    case USBH_USR_FS_DEMOEND:
        break;

    default:
        break;
    }

    return(0);
}



/*!
    \brief      toggle leds to shows user input state
    \param[in]  none
    \param[out] none
    \retval     none
*/


//MM Begins
//*************************************************************************************************


/*!
    \brief      initialize the LEDs
    \param[in]  none
    \param[out] none
    \retval     none
*/
void led_init(void)
{
	/* Enable the LED clock */
  	rcu_periph_clock_enable(RCU_GPIOC);
	rcu_periph_clock_enable(RCU_GPIOE);
    
    /* Configure LED GPIO port */
	gpio_init(GPIOC, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_0 | GPIO_PIN_2 );
	gpio_init(GPIOE, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_0 | GPIO_PIN_1 );
}





/*
\brief      configure key
    \param[in]  key_num: specify the key to be configured
      \arg        KEY_TAMPER: tamper key
      \arg        KEY_WAKEUP: wakeup key
      \arg        KEY_USER: user key
    \param[in]  key_mode: specify button mode
      \arg        KEY_MODE_GPIO: key will be used as simple IO
      \arg        KEY_MODE_EXTI: key will be connected to EXTI line with interrupt
    \param[out] none
    \retval     none
*/

void button_init(key_type key, key_mode keymode)
{

    if (key == WAKEUP){
    /* enable the key clock */
    rcu_periph_clock_enable(RCU_GPIOA); //MM WAKEUP_KEY_GPIO_CLK
    /* configure button pin as input */
    gpio_init(GPIOA, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, GPIO_PIN_0);
    }
    
    else if ( key == TAMPER){
    /* enable the key clock */
    rcu_periph_clock_enable(RCU_GPIOC); //MM TAMPER_KEY_GPIO_CLK
    /* configure button pin as input */
    gpio_init(GPIOC, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, GPIO_PIN_13);        
    }
    
    else if( key == USER){
    /* enable the key clock */
    rcu_periph_clock_enable(RCU_GPIOB); //MM USER_KEY_GPIO_CLK 
    /* configure button pin as input */
    gpio_init(GPIOB, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, GPIO_PIN_14);        
    }
    
    else if (key == AllBut) {
    /* enable all the key clocks */
    rcu_periph_clock_enable(RCU_GPIOA); //MM WAKEUP_KEY_GPIO_CLK
    rcu_periph_clock_enable(RCU_GPIOC); //MM TAMPER_KEY_GPIO_CLK         
    rcu_periph_clock_enable(RCU_GPIOB); //MM USER_KEY_GPIO_CLK 
    /* configure all button pins as input */
    gpio_init(GPIOA, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, GPIO_PIN_0);
    gpio_init(GPIOC, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, GPIO_PIN_13);
    gpio_init(GPIOB, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, GPIO_PIN_14);
        
    }

    rcu_periph_clock_enable(RCU_AF);    //MM APB2 peripheral alternate function clock

    if (keymode == MODE_EXTI) {
        
        if (key == WAKEUP){
        /* enable and set key EXTI interrupt to the lowest priority */
        nvic_irq_enable(EXTI0_IRQn, 2U, 0U);            //MM    WAKEUP_KEY_EXTI_IRQn
        /* connect key EXTI line to key GPIO pin */
        gpio_exti_source_select(GPIO_PORT_SOURCE_GPIOA, GPIO_PIN_SOURCE_0);   //MM    WAKEUP_KEY_EXTI_PORT_SOURCE & WAKEUP_KEY_EXTI_PIN_SOURCE
        /* configure key EXTI line */
        exti_init(EXTI_0, EXTI_INTERRUPT, EXTI_TRIG_FALLING);   //MM    WAKEUP_KEY_EXTI_LINE
        exti_interrupt_flag_clear(EXTI_0);            
        }
        
        else if ( key == TAMPER){
        /* enable and set key EXTI interrupt to the lowest priority */
        nvic_irq_enable(EXTI10_15_IRQn, 2U, 0U);        //MM    TAMPER_KEY_EXTI_IRQn and USER_KEY_EXTI_IRQn are the same
        /* connect key EXTI line to key GPIO pin */
        gpio_exti_source_select(GPIO_PORT_SOURCE_GPIOC, GPIO_PIN_SOURCE_13);   //MM   TAMPER_KEY_EXTI_PORT_SOURCE & TAMPER_KEY_EXTI_PIN_SOURCE
        /* configure key EXTI line */
        exti_init(EXTI_13, EXTI_INTERRUPT, EXTI_TRIG_FALLING);  //MM    TAMPER_KEY_EXTI_LINE            
        exti_interrupt_flag_clear(EXTI_14);            
        }
        
        else if( key == USER){
        /* enable and set key EXTI interrupt to the lowest priority */
        nvic_irq_enable(EXTI10_15_IRQn, 2U, 0U);        //MM    USER_KEY_EXTI_IRQn and TAMPER_KEY_EXTI_IRQn are the same
        /* connect key EXTI line to key GPIO pin */
        gpio_exti_source_select(GPIO_PORT_SOURCE_GPIOB, GPIO_PIN_SOURCE_14);   //MM   USER_KEY_EXTI_PORT_SOURCE & USER_KEY_EXTI_PIN_SOURCE
        /* configure key EXTI line */
        exti_init(EXTI_14, EXTI_INTERRUPT, EXTI_TRIG_FALLING);  //MM    USER_KEY_EXTI_LINE            
        exti_interrupt_flag_clear(EXTI_14);            
        }
        
        else if (key == AllBut){
            
        /* enable and set key EXTI interrupt to the lowest priority */
        nvic_irq_enable(EXTI0_IRQn, 2U, 0U);            //MM    WAKEUP_KEY_EXTI_IRQn
        nvic_irq_enable(EXTI10_15_IRQn, 2U, 0U);        //MM    USER_KEY_EXTI_IRQn and TAMPER_KEY_EXTI_IRQn are the same
        nvic_irq_enable(EXTI10_15_IRQn, 2U, 0U);        //MM    TAMPER_KEY_EXTI_IRQn and USER_KEY_EXTI_IRQn are the same

        /* connect key EXTI line to key GPIO pin */
        gpio_exti_source_select(GPIO_PORT_SOURCE_GPIOA, GPIO_PIN_SOURCE_0);   //MM    WAKEUP_KEY_EXTI_PORT_SOURCE & WAKEUP_KEY_EXTI_PIN_SOURCE
        gpio_exti_source_select(GPIO_PORT_SOURCE_GPIOB, GPIO_PIN_SOURCE_14);   //MM   USER_KEY_EXTI_PORT_SOURCE & USER_KEY_EXTI_PIN_SOURCE
        gpio_exti_source_select(GPIO_PORT_SOURCE_GPIOC, GPIO_PIN_SOURCE_13);   //MM   TAMPER_KEY_EXTI_PORT_SOURCE & TAMPER_KEY_EXTI_PIN_SOURCE        
        
        /* configure key EXTI line */
        exti_init(EXTI_0, EXTI_INTERRUPT, EXTI_TRIG_FALLING);   //MM    WAKEUP_KEY_EXTI_LINE
        exti_init(EXTI_14, EXTI_INTERRUPT, EXTI_TRIG_FALLING);  //MM    USER_KEY_EXTI_LINE
        exti_init(EXTI_13, EXTI_INTERRUPT, EXTI_TRIG_FALLING);  //MM    TAMPER_KEY_EXTI_LINE
        exti_interrupt_flag_clear(EXTI_0);
        exti_interrupt_flag_clear(EXTI_14);
        exti_interrupt_flag_clear(EXTI_14);            
            
        }

    }
}



/*!
    \brief      return the selected key state
    \param[in]  key: specify the key to be checked
      \arg        KEY_TAMPER: tamper key
      \arg        KEY_WAKEUP: wakeup key
      \arg        KEY_USER: user key
    \param[out] none
    \retval     the key's GPIO pin value
*/
uint8_t button_state_get(key_type key)
{
    if ( key == WAKEUP)    
    return gpio_input_bit_get(GPIOA, GPIO_PIN_0);
    if ( key == TAMPER)    
    return gpio_input_bit_get(GPIOC, GPIO_PIN_13);
    if ( key == USER)    
    return gpio_input_bit_get(GPIOB, GPIO_PIN_14);

    return 0;   //MM    Error argument

}



/*!
    \brief      toggle selected led
    \param[in]  lednum: specify the led to be toggled
      \arg        Led2
      \arg        Led3
      \arg        Led4
      \arg        Led5
    \param[out] none
    \retval     none
*/

void led_toggle(led_type led)           //MM    Use Ledn to select lED
{
   if( led == Led2){
       
      gpio_bit_write(GPIOC, GPIO_PIN_0, (bit_status)(1-gpio_input_bit_get(GPIOC, GPIO_PIN_0))); 
   }
   if(led == Led3){
       
      gpio_bit_write(GPIOC, GPIO_PIN_2, (bit_status)(1-gpio_input_bit_get(GPIOC, GPIO_PIN_2)));
   }
   if(led == Led4){
       
      gpio_bit_write(GPIOE, GPIO_PIN_0, (bit_status)(1-gpio_input_bit_get(GPIOE, GPIO_PIN_0)));
   }
   if(led == Led5){
       
      gpio_bit_write(GPIOE, GPIO_PIN_1, (bit_status)(1-gpio_input_bit_get(GPIOE, GPIO_PIN_1)));
   }
        


}




//*****************************************************************************
//MM Ends

static void toggle_leds(void)
{
    static uint32_t i;

    if (0x10000U == i++) {
        led_toggle(Led2);
        led_toggle(Led3);
        i = 0;
    }
}



/*!
\brief      Turn ON LEDs
\param[in]  LEDn: (Led2, Led3, Led4, Led5)
\param[out] none
\retval     none
*/
void LED_ON(led_type led){
    switch(led){
        case Led2:
         gpio_bit_set ( GPIOC, GPIO_PIN_0 );   
        break;
        case Led3:
         gpio_bit_set ( GPIOC, GPIO_PIN_2 );   
        break;
        case Led4:
         gpio_bit_set ( GPIOE, GPIO_PIN_0 );   
        break;
        case Led5:
         gpio_bit_set ( GPIOE, GPIO_PIN_1 );
        break;
        case AllLeds:
         gpio_bit_set ( GPIOC, GPIO_PIN_0 | GPIO_PIN_2 );
         gpio_bit_set ( GPIOE, GPIO_PIN_0 | GPIO_PIN_1);
        break;
       
    }
}


/*!
\brief      Turn OFF LEDs
\param[in]  LEDn: (Led2, Led3, Led4, Led5)
\param[out] none
\retval     none
*/
void LED_OFF(led_type led){
      switch(led){
        case Led2:
            gpio_bit_reset ( GPIOC, GPIO_PIN_0 );   
            break;
        case Led3:
            gpio_bit_reset ( GPIOC, GPIO_PIN_2 );   
            break;
        case Led4:
            gpio_bit_reset ( GPIOE, GPIO_PIN_0 );   
            break;
        case Led5:
            gpio_bit_reset ( GPIOE, GPIO_PIN_1 );
            break;  
        case AllLeds:
         gpio_bit_reset ( GPIOC, GPIO_PIN_0 | GPIO_PIN_2 );
         gpio_bit_reset ( GPIOE, GPIO_PIN_0 | GPIO_PIN_1);        
        break;
    }
}



/* retarget the C library printf function to the USART */
int fputc(int ch, FILE *f)
{
    usart_data_transmit(USART0, (uint8_t)ch);
    while(RESET == usart_flag_get(USART0, USART_FLAG_TBE));
    return ch;
}
