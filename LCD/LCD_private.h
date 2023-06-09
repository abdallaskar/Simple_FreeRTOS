/*
 * Author     : Abdalla Mahmoud
 * Component  : LCD
 * Layer      : HAL
 * Version    : 1.0
 * Created on : Aug 26, 2021
 */
#ifndef LCD_LCD_PRIVATE_H_
#define LCD_LCD_PRIVATE_H_



/* RIGISTER  A*/
#define PORTA   *((volatile u8*)0x3B)
#define DDRA    *((volatile u8*)0x3A)
#define PINA    *((volatile u8*)0x39)

/* RIGISTER  B*/
#define PORTB   *((volatile u8*)0x38)
#define DDRB    *((volatile u8*)0x37)
#define PINB    *((volatile u8*)0x36)

/* RIGISTER  C*/
#define PORTC  *((volatile u8*)0x35)
#define DDRC   *((volatile u8*)0x34)
#define PINC   *((volatile u8*)0x33)

/* RIGISTER  D*/
#define PORTD   *((volatile u8*)0x32)
#define DDRD    *((volatile u8*)0x31)
#define PIND    *((volatile u8*)0x30)





#endif /* LCD_LCD_PRIVATE_H_ */
