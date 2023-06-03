/*
 * Author     : Abdalla Mahmoud
 * Component  : GIE
 * Layer      : MCAL
 * Version    : 1.0
 * Created on : Sep 5, 2021
 */

#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"

#include "GIE_private.h"


void GIE_voidEnableGlobleInterrupt(void){
	SET_BIT(SREG,7);

}
void GIE_voidDisableGlobleInterrupt(void){
	CLEAR_BIT(SREG,7);
}
