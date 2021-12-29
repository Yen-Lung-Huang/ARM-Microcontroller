/*!
    \file    readme.txt
    \brief   description of the Bootloader v1.0


*/


This bootloader has been developed for GD32F105VC MCUs, however it might be easily adapted to work with 
any ARM based MCU.

In erasing operation, a comparison between flash memory and 0xffffffff is done to 
check whether the flash memory has been correctly erased. If the result is wrong, 
LED2 will be on.

  In programming operation, a comparison between flash memory and target data is 
done to check whether the flash memory has been correctly programmed. If the result 
is wrong, LED3 will be on.
 
  If all the three operations are successful, LED4 will be on.
