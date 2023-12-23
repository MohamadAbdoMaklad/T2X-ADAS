################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC.c \
../DIO_Program.c \
../LCD_Program.c \
../ServoMotor_Program.c \
../TMR0_Program.c \
../Timer1.c \
../UART0_program.c \
../icu.c \
../main.c \
../ultrasonic.c 

OBJS += \
./ADC.o \
./DIO_Program.o \
./LCD_Program.o \
./ServoMotor_Program.o \
./TMR0_Program.o \
./Timer1.o \
./UART0_program.o \
./icu.o \
./main.o \
./ultrasonic.o 

C_DEPS += \
./ADC.d \
./DIO_Program.d \
./LCD_Program.d \
./ServoMotor_Program.d \
./TMR0_Program.d \
./Timer1.d \
./UART0_program.d \
./icu.d \
./main.d \
./ultrasonic.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega128 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


