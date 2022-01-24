/*!
    \file    readme.txt
    \brief   description of SPI tf card fatfs file operation example
    
    \version 2017-06-28, V1.0.0, adapted for GD32F105VC

*/



  This demo is based on the GD32F105VC MCU, it provides a description of how 
to use the SPI in master-to-multiple-slaves configuration to write and read in
TF card using FATFS. 

Features:
    USART0 is used to send notifications via COM port
    
    When App stats all LEDs flash twice
    When multiple slave configuration, SD cards are selected mannually by switching SD_CSx_LOW and SD_CSx_HIGH on file spi_sd.h
    (Buttons can also be set for card selection)
    After initialization App creates a text file in SD card using FATFS.
        If the file already exists, app does not overwrite it
        If there is an error, a notification will be shown on screen
    If not exists the file is written to SD card
    A compare function is used to validate data written has no errors. After succesfull validation a notification is shown

Pinout:

The pinout corresponds to GPIO default values for Alternate Function (AF) for SPIx peripherals:

Alternate Function(AF)

 SPI0:
 PA4 --> SPI0_NSS
 PA5 --> SPI0_SCK
 PA6 --> SPI0_MISO
 PA7 --> SPI0_MOSI
 
 SPI1:
 PB12 --> SPI1_NSS
 PB13 --> SPI1_SCK
 PB14 --> SPI1_MISO
 PB15 --> SPI1_MOSI
 
 SPI2: (Not used)
 
 When multiple (2) SD cards, 1 chip select PINs is required for each additional card.
 In this application the second CS are used as follows:
 
 When using SPI0:
 PC4 --> SPI0_NSS(second SD card))
 
 When using For SPI1:
 PB10 --> SPI0_NSS(second SD card))
 

For GD32105-EVALUATION board JP12 must be selecting SPIO
