/*

 * this code for ohmmeter using ADC channel 0 to measure volt then using voltage
 * divider concept to measure resistance with minimum resolution 4.88mv
 *
 *  Created on: Dec 14, 2020
 *      Author: Mohamed Osama Ahmed
 */

#include "DIO.h"
#include "LCD.h"
#include "Types.h"
#include "ADC.h"
#include <util/delay.h>
#define R1 10000
#define VCC 5
int main()
{
	u32 adc_value = 0;
	u32 Runknown;
	f32 Runknown_volt = 0;
	LCD_Vid_Init();
	ADC_Init_polling();
	DIO_Vid_Set_Pin_Direcition(A,0,0);
	while (1)
	{
		if (ADC_Get_Result_polling(&adc_value))
		{

			LCD_Vid_Select_Position(0,0);
			// this number .00488281 is 5/1024
			Runknown_volt = adc_value * .00488281;
			// this is a form of the formula of voltage divider
			Runknown= ((R1*(Runknown_volt/5))/(1-(Runknown_volt/5)));
			LCD_Vid_Write_Number(Runknown);
			_delay_ms(500);
			LCD_Clear();

		}
	}

}
