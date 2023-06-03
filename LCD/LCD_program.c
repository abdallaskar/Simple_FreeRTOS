/*
 * Author     : Abdalla Mahmoud
 * Component  : LCD
 * Layer      : HAL
 * Version    : 1.0
 * Created on : Aug 26, 2021
 */


#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include  <util/delay.h>

#include "LCD_Config.h"


/*  LCD_voidSendCommond : send commend to LCD
 *  arguments       : commend
 *  return          : null
 */

void LCD_voidSendCommond(u8 Copy_u8Commond) {

	CLEAR_BIT(PORT_CONTROL, RS_PIN);  // RS -> 0
	CLEAR_BIT(PORT_CONTROL, RW_PIN);  // RW -> 0

	if (MODE == 8) {
		ASSIGN_REG(PORT_DATA, Copy_u8Commond);   // assign data to port data
	} else if (MODE == 4) {

		ASSIGN_REG(PORT_DATA, (Copy_u8Commond & 0xf0));  // send high nibble

		SET_BIT(PORT_CONTROL, EN_PIN);   //EN ->  1
		_delay_ms(1);
		CLEAR_BIT(PORT_CONTROL, EN_PIN); //EN ->  0
		_delay_ms(1);

		ASSIGN_REG(PORT_DATA, (Copy_u8Commond << 4));   // send low nibble
	}

	SET_BIT(PORT_CONTROL, EN_PIN);   //EN ->  1
	_delay_ms(1);
	CLEAR_BIT(PORT_CONTROL, EN_PIN);      //EN ->  0
	_delay_ms(1);

}

/*  LCD_SendChracter : send charter to LCD
 *  arguments        : unsigned Charter
 *  return           : null
 */
void LCD_voidSendChar(u8 Copy_u8Data) {

	SET_BIT(PORT_CONTROL, RS_PIN);    // RS -> 1
	CLEAR_BIT(PORT_CONTROL, RW_PIN);  // RW -> 0

	if (MODE == 8) {
		ASSIGN_REG(PORT_DATA, Copy_u8Data);    // Assigned charter to port data

	} else if (MODE == 4) {

		ASSIGN_REG(PORT_DATA, (Copy_u8Data & 0xf0));    // send high nibble

		SET_BIT(PORT_CONTROL, EN_PIN);        //EN ->  1
		_delay_ms(1);
		CLEAR_BIT(PORT_CONTROL, EN_PIN);      //EN ->  0
		_delay_ms(EN_PIN);

		ASSIGN_REG(PORT_DATA, (Copy_u8Data << 4));   // send low nibble
	}

	SET_BIT(PORTB, EN_PIN);               //EN ->  1
	_delay_ms(1);
	CLEAR_BIT(PORT_CONTROL, EN_PIN);      //EN ->  0
	_delay_ms(1);

}

void LCD_voidInit(void) {

	if (MODE == 8) {
		SET_REG(DDR_DATA);                       // port data as output
		ASSIGN_REG(DDR_CONTROL, 0b00000111);     // pins control as output
		_delay_ms(40);

		LCD_voidSendCommond(0x38);
		_delay_ms(1);
		LCD_voidSendCommond(0x0E);
		_delay_ms(1);
		LCD_voidSendCommond(0x01);

	} else if (MODE == 4) {
		ASSIGN_REG(DDR_DATA,0b11110000);                // pins data as output
		ASSIGN_REG(DDR_CONTROL, 0b00000111);            // pins control as output
		_delay_ms(40);

		LCD_voidSendCommond(0x33);
		_delay_ms(1);
		LCD_voidSendCommond(0x32);
		_delay_ms(1);
		LCD_voidSendCommond(0x28);
		_delay_ms(1);
		LCD_voidSendCommond(0x0E);
		_delay_ms(1);
		LCD_voidSendCommond(0x01);
	}

	_delay_ms(2);
	LCD_voidSendCommond(0x06);

}

/* LCD_PrintString : print string to LCD
 * arguments       : pointer to charter
 * return          : void
 */

void LCD_voidPrintString(char* Copy_pu8String){
	u16 u16Index = 0;
	while (Copy_pu8String[u16Index] != 0) {
		LCD_voidSendChar(Copy_pu8String[u16Index]);
		u16Index++;
	}

}


void LCD_voidSetCursorPostion(u8 Copy_u8Horizontal, u8 Copy_u8Verticale){
	u8 Local_u8Posit = 0x80;
	Copy_u8Horizontal %= 16;
	if (Copy_u8Horizontal >= 0 && Copy_u8Horizontal < 16) {
		if (Copy_u8Verticale == 0) {
			Local_u8Posit += Copy_u8Horizontal;
		}
		if (Copy_u8Verticale == 1) {

			Local_u8Posit += (Copy_u8Horizontal + 0x40);
		}

	}
	LCD_voidSendCommond(Local_u8Posit);
}

void LCD_voidPrintNumber(s32 Copy_s32Number){
	s32 arr[11] = { -1 };
	s32 digit = 0;
	int i = 0;
	s32 nu = 0;

	if (Copy_s32Number < 0) {
		arr[i++] = '-';         // keep negative
		Copy_s32Number *= -1;      // convert number to positive
		nu++;
	};

	while (Copy_s32Number != 0) {
		digit = Copy_s32Number % 10;
		arr[i++] = ('0' + digit);

		Copy_s32Number = Copy_s32Number / 10;
		nu++;
	}

	if (arr[0] == '-') {

		LCD_voidSendChar(arr[0]);
		for (int i = nu; i >= 1; --i) {

			if (arr[i] != -1) {

				LCD_voidSendChar(arr[i]);
			}
		}
	} else if (nu >= 1) {
		for (int i = nu - 1; i >= 0; --i) {

			if (arr[i] != -1) {

				LCD_voidSendChar(arr[i]);
			}
		}
	} else {
		LCD_voidSendChar('0');
	}

}

void LCD_voidSaveCustomCharater(u8 arr[], u8 Copy_u8Index){

	if (Copy_u8Index >= 0 && Copy_u8Index < 8) {
		LCD_voidSendCommond((0x40 + (Copy_u8Index * 8)));
		for (int i = 0; i < 8; ++i) {
			LCD_voidSendChar(arr[i]);
		}
		LCD_voidSendCommond(0x80);
	}

}
void LCD_voidClear(void) {
	LCD_voidSendCommond(0x01);
	_delay_ms(2);
}
