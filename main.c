 /* Author     : Abdalla Mahmoud
 * Component  : FreeRTOS
 * Version    : 1.0
 * Created on : Jul 26, 2022
 */

//#include <avr/interrupt.h>
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "util/delay.h"

#include "FREERTOS/FreeRTOS.h"
#include "FREERTOS/task.h"
#include "FREERTOS/semphr.h"


#include "DIO/DIO_interface.h"
#include "LCD/LCD_interface.h"
#include "GIE/GIE_interface.h"
#include "EXTI/EXTI_interface.h"

void Task(void* Copy_Pvoid);
void Task2 (void* Copy_Pvoid);
void isr(void);

void voidinitSystem(void){
    DIO_voidSetPinDirection(3, 2, 0);
    DIO_voidSetPinValue(3, 2, 1);
    //DDRD &=0xfb;
    //PORTD |=0x04;

    EXTI_voidTriggerEdge(EXTI_INT0, FALLING_EDGE);
    EXTI_voidSetCallBack(EXTI_INT0, isr);
    EXTI_voidEnable(EXTI_INT0);
    GIE_voidDisableGlobleInterrupt();


   // MCUCR &=0xfc;
   // SET_BIT(GICR,6);
   // SET_BIT(SREG,7);

    LCD_voidInit();
}

 xSemaphoreHandle  LCD_SEM;


int main(){

	voidinitSystem();

	LCD_SEM =xSemaphoreCreateCounting(1,0);

	xTaskCreate(Task2,NULL,150, NULL, 2, NULL);
	xTaskCreate(Task,NULL,150, NULL, 2, NULL);
	vTaskStartScheduler();

	return 0;
}

//Fucation to task one
void Task (void* Copy_Pvoid){

	u8 ret;
	while(1){

       ret=xSemaphoreTake(LCD_SEM,portMAX_DELAY);


       if(ret==1){
		LCD_voidPrintString("Button Presed :D");
		_delay_ms(500);
		LCD_voidClear();

        }

    }
}
void Task2 (void* Copy_Pvoid){

	u8 ret;
	while(1){

        ret=xSemaphoreTake(LCD_SEM,portMAX_DELAY);


     if(ret==1){
		LCD_voidPrintString("Button Presed :G");
		_delay_ms(500);
		LCD_voidClear();
        }

    }
}

void isr(void){
    xSemaphoreGive(LCD_SEM);
}



