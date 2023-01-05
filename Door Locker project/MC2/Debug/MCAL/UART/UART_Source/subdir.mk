################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/UART/UART_Source/UART_Program.c 

OBJS += \
./MCAL/UART/UART_Source/UART_Program.o 

C_DEPS += \
./MCAL/UART/UART_Source/UART_Program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/UART/UART_Source/%.o: ../MCAL/UART/UART_Source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


