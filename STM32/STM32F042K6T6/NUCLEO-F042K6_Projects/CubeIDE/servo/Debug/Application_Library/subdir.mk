################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application_Library/jsmn.c \
../Application_Library/servo.c 

OBJS += \
./Application_Library/jsmn.o \
./Application_Library/servo.o 

C_DEPS += \
./Application_Library/jsmn.d \
./Application_Library/servo.d 


# Each subdirectory must supply rules for building sources it contributes
Application_Library/%.o Application_Library/%.su: ../Application_Library/%.c Application_Library/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F042x6 -c -I../Core/Inc -I../../../../Application_Library/Include -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Application_Library

clean-Application_Library:
	-$(RM) ./Application_Library/jsmn.d ./Application_Library/jsmn.o ./Application_Library/jsmn.su ./Application_Library/servo.d ./Application_Library/servo.o ./Application_Library/servo.su

.PHONY: clean-Application_Library

