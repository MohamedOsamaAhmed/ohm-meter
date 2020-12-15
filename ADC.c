/*
 *
 ADC.c

 *
 *  Created on: 14/12/2020
 *      Author: Mohamed Osama
 */

#include "Registers.h"
#include "types.h"
#include "macros.h"
void ADC_Init_polling(void)
{

	ADMUX = 0b01000000;
	ADCSRA = 0b11000111;

	setBit(ADCSRA,6);

}



u8 ADC_Get_Result_polling(u32 * result)
{
	u8 stutus = 0;
	if (getBit(ADCSRA,4))
	{
		* result = ADCREG;
		setBit(ADCSRA,4);
		setBit(ADCSRA,6);
		stutus = 1;
	}
	else
	{
		stutus = 0;
	}
	return stutus;
}








