################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FREERTOS/croutine.c \
../FREERTOS/list.c \
../FREERTOS/port.c \
../FREERTOS/queue.c \
../FREERTOS/tasks.c \
../FREERTOS/timers.c 

OBJS += \
./FREERTOS/croutine.o \
./FREERTOS/list.o \
./FREERTOS/port.o \
./FREERTOS/queue.o \
./FREERTOS/tasks.o \
./FREERTOS/timers.o 

C_DEPS += \
./FREERTOS/croutine.d \
./FREERTOS/list.d \
./FREERTOS/port.d \
./FREERTOS/queue.d \
./FREERTOS/tasks.d \
./FREERTOS/timers.d 


# Each subdirectory must supply rules for building sources it contributes
FREERTOS/%.o: ../FREERTOS/%.c FREERTOS/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


