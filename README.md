# FreeRTOS Project
This project is a simple implementation of FreeRTOS (Real-Time Operating System) for microcontrollers. 
It demonstrates the usage of tasks and a binary semaphore to synchronize access to an LCD display.

## Project Structure
The project consists of the following files and directories:

LIB/STD_TYPES.h: Header file for standard types used in the project.
LIB/BIT_MATH.h: Header file for bit manipulation macros.
util/delay.h: Header file for delay functions.
FREERTOS/FreeRTOS.h: FreeRTOS library header file.
FREERTOS/task.h: FreeRTOS task management header file.
FREERTOS/semphr.h: FreeRTOS semaphore management header file.
DIO/DIO_interface.h: Header file for Digital I/O (DIO) interface.
LCD/LCD_interface.h: Header file for LCD interface.
GIE/GIE_interface.h: Header file for Global Interrupt Enable (GIE) interface.
EXTI/EXTI_interface.h: Header file for External Interrupt (EXTI) interface.
main.c: Main source file containing the application logic and tasks.

## Prerequisites
To compile and run this project, you will need the following:

AVR microcontroller.
AVR development board or custom hardware setup.
AVR compiler toolchain (e.g., AVR-GCC).
FreeRTOS library for AVR.

## Getting Started
To get started with this project, follow these steps:

Connect the AVR microcontroller to your development board or custom hardware setup.
Set up the necessary connections for the LCD display, external interrupt, and other peripherals as required.
Configure the AVR compiler toolchain and include the necessary libraries.
Compile and flash the main.c file to the AVR microcontroller.
Verify that the project is running correctly by observing the behavior of the LCD display and any connected buttons or switches.
Project Overview
This project demonstrates the usage of FreeRTOS to implement two tasks (Task and Task2) that share access to an LCD display.
The tasks are synchronized using a binary semaphore (LCD_SEM) to ensure exclusive access to the LCD resource.

## Usage
To use this project, follow these instructions:

Include the necessary libraries and header files in your AVR project.
Configure the AVR microcontroller and any required peripherals based on your hardware setup.
Create the voidinitSystem(void) function in your project and initialize the system peripherals as shown in the provided code.
Create your own tasks and functions based on the provided Task and Task2 functions.
Compile and flash the project to the AVR microcontroller.
Ensure that the necessary connections are in place for the LCD.
