/*
 * Author     : Abdalla Mahmoud
 * Component  : DIO
 * Layer      : MCAL
 * Version    : 1.0
 * Created on : Aug 25, 2021
 */

#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"


#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"




void DIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction){
	if (Copy_u8Direction == 1) {
		switch (Copy_u8Port) {
		case 0:
			SET_BIT(DDRA, Copy_u8Pin);
			break;
		case 1:
			SET_BIT(DDRB, Copy_u8Pin);
			break;
		case 2:
			SET_BIT(DDRC, Copy_u8Pin);
			break;
		case 3:
			SET_BIT(DDRD, Copy_u8Pin);
			break;
		default :
			break;
		}
	} else {
		switch (Copy_u8Port) {
		case 0:
			CLEAR_BIT(DDRA, Copy_u8Pin);
			break;
		case 1:
			CLEAR_BIT(DDRB, Copy_u8Pin);
			break;
		case 2:
			CLEAR_BIT(DDRC, Copy_u8Pin);
			break;
		case 3:
			CLEAR_BIT(DDRD, Copy_u8Pin);
			break;
		}
	}
}

void DIO_voidSetPortDirection(u8 Copy_u8port, u8 Copy_u8direction){

	switch (Copy_u8port) {
	case 0:
		DDRA = Copy_u8direction;
		break;
	case 1:
		DDRB = Copy_u8direction;
		break;
	case 2:
		DDRC = Copy_u8direction;
		break;
	case 3:
		DDRD = Copy_u8direction;
		break;
	}
}

void DIO_voidSetPinValue(u8 Copy_u8port, u8 Copy_u8pin, u8 Copy_u8value) {
	if (Copy_u8value == 1) {
		switch (Copy_u8port) {
		case 0:
			SET_BIT(PORTA, Copy_u8pin);
			break;
		case 1:
			SET_BIT(PORTB, Copy_u8pin);
			break;
		case 2:
			SET_BIT(PORTC, Copy_u8pin);
			break;
		case 3:
			SET_BIT(PORTD, Copy_u8pin);
			break;
		}
	} else {
		switch (Copy_u8port) {
		case 0:
			CLEAR_BIT(PORTA, Copy_u8pin);
			break;
		case 1:
			CLEAR_BIT(PORTB, Copy_u8pin);
			break;
		case 2:
			CLEAR_BIT(PORTC, Copy_u8pin);
			break;
		case 3:
			CLEAR_BIT(PORTD, Copy_u8pin);
			break;
		}
	}
}

void DIO_voidSetPortValue(u8 Copy_u8port, u8 Copy_u8value ){
	switch (Copy_u8port) {
	case 0:
		PORTA = Copy_u8value;
		break;
	case 1:
		PORTB = Copy_u8value;
		break;
	case 2:
		PORTC = Copy_u8value;
		break;
	case 3:
		PORTD = Copy_u8value;
		break;
	}
}

void DIO_voidTogglePin(u8 Copy_u8port, u8 Copy_u8pin){
	switch (Copy_u8port) {
	case 0:{
		TOGGLE_BIT(PORTA, Copy_u8pin);
	}
		break;
	case 1:
		TOGGLE_BIT(PORTB, Copy_u8pin);
		break;
	case 2:
		TOGGLE_BIT(PORTC, Copy_u8pin);
		break;
	case 3:
		TOGGLE_BIT(PORTD, Copy_u8pin);
		break;
	}

}

u8 DIO_u8GetPinValue(u8 Copy_u8port, u8 Copy_u8pin) {
	u8 Local_u8pinValue = 0;
	switch (Copy_u8port) {
	case 0:
		Local_u8pinValue = GET_BIT(PINA, Copy_u8pin);
		break;
	case 1:
		Local_u8pinValue = GET_BIT(PINB, Copy_u8pin);
		break;
	case 2:
		Local_u8pinValue = GET_BIT(PINC, Copy_u8pin);
		break;
	case 3:
		Local_u8pinValue = GET_BIT(PIND, Copy_u8pin);
		break;
	}
	return Local_u8pinValue;
}

u8 DIO_u8GitPortValue(u8 Copy_u8port) {
	u8 Local_u8portValue = 0;
	switch (Copy_u8port) {
	case 0:
		Local_u8portValue = PINA;
		break;
	case 1:
		Local_u8portValue = PINB;
		break;
	case 2:
		Local_u8portValue = PINC;
		break;
	case 3:
		Local_u8portValue = PIND;
		break;
	}
	return Local_u8portValue;
}


