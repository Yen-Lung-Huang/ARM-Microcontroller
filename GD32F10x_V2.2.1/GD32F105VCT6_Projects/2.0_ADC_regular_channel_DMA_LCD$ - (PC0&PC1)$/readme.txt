/*!
    \file    readme.txt
    \brief   description of the ADC regular channel with DMA

 
/*

This demo is adapted to GD32F105VCT6 MCU, it shows how to set the ADC to 
convert analog signal to digital data through DMA. 

The ADC is configured in continuous mode

PC0&PC1 are chosen as analog input pin.

As the ADC conversion begins by software, the converted data from ADC_RDATA register 
to SRAM begins continuously. 

Voltage on the pins can be changed, and check if the values match the converted data
through the watch window.

The analog input pin should configured to AIN mode. 

We can watch array adc_value[] values on display.

Channels 10 and 11 are use to convert the data

Information on display is raw data, not being processed. So, physical variables such as Voltage or 
Luminosity are not calculated because of absence of datasheet for used sensors.

Any sensor can be used and a function to calculate the physical variables involved must be added
to provide meaningful data
