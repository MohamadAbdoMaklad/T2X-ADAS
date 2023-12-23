################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/GPIO_program.c \
../Src/L298_program.c \
../Src/NVIC_program.c \
../Src/PORT_config.c \
../Src/PORT_program.c \
../Src/RCC_program.c \
../Src/SYSTICK_program.c \
../Src/TMR1_program.c \
../Src/UART_program.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/GPIO_program.o \
./Src/L298_program.o \
./Src/NVIC_program.o \
./Src/PORT_config.o \
./Src/PORT_program.o \
./Src/RCC_program.o \
./Src/SYSTICK_program.o \
./Src/TMR1_program.o \
./Src/UART_program.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/GPIO_program.d \
./Src/L298_program.d \
./Src/NVIC_program.d \
./Src/PORT_config.d \
./Src/PORT_program.d \
./Src/RCC_program.d \
./Src/SYSTICK_program.d \
./Src/TMR1_program.d \
./Src/UART_program.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/GPIO_program.d ./Src/GPIO_program.o ./Src/GPIO_program.su ./Src/L298_program.d ./Src/L298_program.o ./Src/L298_program.su ./Src/NVIC_program.d ./Src/NVIC_program.o ./Src/NVIC_program.su ./Src/PORT_config.d ./Src/PORT_config.o ./Src/PORT_config.su ./Src/PORT_program.d ./Src/PORT_program.o ./Src/PORT_program.su ./Src/RCC_program.d ./Src/RCC_program.o ./Src/RCC_program.su ./Src/SYSTICK_program.d ./Src/SYSTICK_program.o ./Src/SYSTICK_program.su ./Src/TMR1_program.d ./Src/TMR1_program.o ./Src/TMR1_program.su ./Src/UART_program.d ./Src/UART_program.o ./Src/UART_program.su ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

