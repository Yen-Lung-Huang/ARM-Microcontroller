
# Overview

This directory contains a MPLAB-X demo project (XC8 compiler) for AVR128DA48 Curiosity Nano board equipped with AVR128DA48 microcontroller (128 KB Flash, 16 KB SRAM, 512 bytes EEPROM).  

The project comes as three different demos, selectable by a define in the main.c file. Each demo has its own main-***demo_name***.c file. Follow the instructions on the RTOS port documentation page for details about how to setup the target hardware, download and execute the demo application.

### Blinky Demo

**#define       mainSELECTED_APPLICATION	  0**

Blinky demos are intended for beginners. They normally create just two [tasks](https://www.freertos.org/a00015.html) that communicates with each other through a [queue](https://www.freertos.org/Embedded-RTOS-Queues.html). Their functionality is contained in a single C source file called **main_blinky.c**.

One of the tasks repeatedly sends a predefined value to the queue with 200 ms intervals, while the other task waits for messages to be available in the queue. Once a new message is available, it toggles on board LED if the value matches the expected value.


### Minimal Demo

**#define       mainSELECTED_APPLICATION	  1**

This demo includes a higher number of tasks than the **Blinky demo**, but the complexity is still fairly low. Whole functionality is included in the **main_minimal.c** file by using the following tasks:

 - integer math task (**Integer.c**)
 - register tasks to verify the context switch (**Regtest.c**)
 - polled queue tasks (**PollQ.c**)
 - serial communiation tasks (**Serial.c**)
 - check task that periodically checks the other tasks are operating without error.

This demo uses the **check** task to periodically inspect the standard demo tasks in order to ensure all the tasks are functioning as expected. The check task also toggles an LED to give a visual feedback of the system status. If the LED is toggling roughly every second, then the check task has not discovered any problems. If the LED stops toggling, then the check task has discovered a problem in one or more tasks.

To see the console output from serial communication tasks, serial port could be configured as: 
 - baud rate 9600
 - data 8-bit
 - parity none
 - stop bits 1-bit
 - flow control none

### Full Demo

**#define       mainSELECTED_APPLICATION	  2**

This demo is a comprehensive demonstration and test of a lot of FreeRTOS features, including direct task to task notifications, queues, semaphores, recursive semaphores, software timers, and more. The following tasks are created in **main_full.c** file:

 - register tasks to verify the context switch (**Regtest.c**)
 - semaphores task (**Semtest.c**)
 - direct task to task notification task (**TaskNotify.c**)
 - recursive semaphores task (**Regmutex.c**)
 - check task that periodically checks the other tasks are operating without error

The demo uses the **check** task to periodically inspect the standard demo tasks in order to ensure all the tasks are functioning as expected. The check task also toggles an LED to give a visual feedback of the system status. If the LED is toggling roughly every 3 seconds, then the check task has not discovered any problems. If the LED stops toggling, then the check task has discovered a problem in one or more tasks.

# Quick start

To run this demo on AVR128DA48 Curiosity Nano platform, the following steps are required:
 - install **MPLAB® X IDE**
 - install **MPLAB® XC8** compiler
 - open **AVR_ATMega4809_MPLAB.X** project file from current folder
 - select desired demo using **#define       mainSELECTED_APPLICATION** as explained in the previous section
 - build and debug the project


# References
  - [Atmega4809 Curiosity Nano platform](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/DM320115)
  - MPLAB® X IDE 5.40 or newer [(microchip.com/mplab/mplab-x-ide)](http://www.microchip.com/mplab/mplab-x-ide)
  - MPLAB® XC8 2.20 or a newer compiler [(microchip.com/mplab/compilers)](http://www.microchip.com/mplab/compilers)
  - [Atmega4809](https://www.microchip.com/wwwproducts/en/ATMEGA4809), [Atmega4808](https://www.microchip.com/wwwproducts/en/ATMEGA4808), [Atmega3208](https://www.microchip.com/wwwproducts/en/ATMEGA3208) and [Atmega3209](https://www.microchip.com/wwwproducts/en/ATMEGA3209) devices page
  
