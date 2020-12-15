/*
 * ADC.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed Osama
 */

#ifndef ADC_H_
#define ADC_H_
#include "types.h"

void ADC_Init_polling(void);
u8 ADC_Get_Result_polling(u32 *);
u8 ADC_Get_Result_interrupt(u32 *);
void ADC_Init_interrupt(void);

#endif /* ADC_H_ */
