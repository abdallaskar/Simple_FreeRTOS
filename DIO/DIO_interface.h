/*
 * Author     : Abdalla Mahmoud
 * Component  : DIO
 * Layer      : MCAL
 * Version    : 1.0
 * Created on : Aug 25, 2021
 */


#ifndef DIO_DIO_INTERFACE_H_
#define DIO_DIO_INTERFACE_H_


#include "../LIB/STD_TYPES.h"



/* Define number of port */

	#define  DIO_PORTA   0
	#define  DIO_PORTB   1
	#define  DIO_PORTC   2
	#define  DIO_PORTD   3

/* define number of pins */

	#define   PIN0  0
	#define   PIN1  1
	#define   PIN2  2
	#define   PIN3  3
	#define   PIN4  4
	#define   PIN5  5
	#define   PIN6  6
	#define   PIN7  7

/* Define direction value */
	#define  OUTPUT  1
	#define  INPUT   0

/* Define pin value */
	#define  HIGH  1
	#define  LOW   0

/* Prototype of function */

void DIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction);
void DIO_voidSetPortDirection(u8 Copy_u8port, u8 Copy_u8direction);
void DIO_voidSetPinValue(u8 Copy_u8port, u8 Copy_u8pin, u8 Copy_u8value);
void DIO_voidSetPortValue(u8 Copy_u8port, u8 Copy_u8value);
void DIO_voidTogglePin(u8 Copy_u8port, u8 Copy_u8pin);
u8 DIO_u8GetPinValue(u8 Copy_u8port, u8 Copy_u8pin);
u8 DIO_u8GitPortValue(u8 Copy_u8port);

#endif /* DIO_DIO_INTERFACE_H_ */
