/*
 * Author     : Abdalla Mahmoud
 * Component  : LCD
 * Layer      : HAL
 * Version    : 1.0
 * Created on : Aug 26, 2021
 */

#ifndef LCD_LCD_INTERFACE_H_
#define LCD_LCD_INTERFACE_H_

#include "../LIB/STD_TYPES.h"


void LCD_voidInit(void);
void LCD_voidSendCommond(u8 Copy_u8Commond);
void LCD_voidSendChar(u8 Copy_u8Data);
void LCD_voidPrintString(char* Copy_pu8String);
void LCD_voidPrintNumber(s32 Copy_s32Number) ;
void LCD_voidSaveCustomCharater(u8 arr[], u8 Copy_u8Index);
void LCD_voidSetCursorPostion(u8 Copy_u8Horizontal, u8 Copy_u8Verticale) ;
void LCD_voidClear(void);


#endif /* LCD_LCD_INTERFACE_H_ */
