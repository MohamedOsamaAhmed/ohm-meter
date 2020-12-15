/*
 * LCD.c

 *
 *  Created on: Aug 23, 2019
 *      Author: Mohamed Osama
 */
#include "LCD.h"
#include "LCD_cfg.h"
#include <util/delay.h>
#include "DIO.h"
#include "Registers.h"
#include "macros.h"
#include "Types.h"


void LCD_Vid_Write_Data(u8 data)
{

	DIO_Vid_Set_Pin_Value(LCD_controlPort,RS,1);
	DIO_Vid_Set_Pin_Value(LCD_controlPort,RW,0);
// #ifdef LCD_8bit
	DIO_Vid_Set_Port_Value(LCD_dataPort,data);
	DIO_Vid_Set_Pin_Value(LCD_controlPort,E,1);
	_delay_ms(1);
	DIO_Vid_Set_Pin_Value(LCD_controlPort,E,0);
	_delay_ms(1);
/*
 * #endif

#ifdef LCD_4bit
	DIO_Vid_Set_Port_Value(LCD_dataPort,data);
	DIO_Vid_Set_Pin_Value(LCD_controlPort,E,1);
	_delay_ms(1);
	DIO_Vid_Set_Pin_Value(LCD_controlPort,E,0);
	DIO_Vid_Set_Port_Value(LCD_dataPort,(( data << 4)& 0xF0));
	DIO_Vid_Set_Pin_Value(LCD_controlPort,E,1);
	_delay_ms(1);
	DIO_Vid_Set_Pin_Value(LCD_controlPort,E,0);

#endif
*/


}
void LCD_Vid_Write_Command(u8 command)
{

	DIO_Vid_Set_Pin_Value(LCD_controlPort,RS,0);
	DIO_Vid_Set_Pin_Value(LCD_controlPort,RW,0);
	//#ifdef LCD_8bit
	DIO_Vid_Set_Port_Value(LCD_dataPort,command);
	_delay_ms(1);
	DIO_Vid_Set_Pin_Value(LCD_controlPort,E,1);
	_delay_ms(1);
	DIO_Vid_Set_Pin_Value(LCD_controlPort,E,0);
	_delay_ms(1);
	//#endif

/*	#ifdef LCD_4bit
	DIO_Vid_Set_Port_Value(LCD_dataPort,command);
	DIO_Vid_Set_Pin_Value(LCD_controlPort,E,1);
	_delay_ms(1);
	DIO_Vid_Set_Pin_Value(LCD_controlPort,E,0);


	DIO_Vid_Set_Port_Value(LCD_dataPort,((command << 4) & 0xF0));
	DIO_Vid_Set_Pin_Value(LCD_controlPort,E,1);
	_delay_ms(1);
	DIO_Vid_Set_Pin_Value(LCD_controlPort,E,0);
	#endif
	*/

}
void LCD_Vid_Init(void)
{
	DIO_Vid_Set_Port_Direction(LCD_dataPort,0xff);
	DIO_Vid_Set_Pin_Direcition(LCD_controlPort,RS,1);
	DIO_Vid_Set_Pin_Direcition(LCD_controlPort,RW,1);
	DIO_Vid_Set_Pin_Direcition(LCD_controlPort,E,1);


	_delay_ms(50);
	//#ifdef LCD_8bit
	LCD_Vid_Write_Command(0b00111000);
/*	#endif
	#ifdef LCD_4bit
	LCD_Vid_Write_Command(0b00101000);
	#endif
	*/
	_delay_ms(1);
	LCD_Vid_Write_Command(0b00001100);
	_delay_ms(2);
	LCD_Vid_Write_Command(0b00000001);

}

void LCD_Vid_Write_String(u8 *ptr)
{
	u8 i = 0;
	while (ptr[i] != 0)
	{
		LCD_Vid_Write_Data(ptr[i]);
		i++;

	}




}

void LCD_Vid_Write_Number(u32 number)
{
	u32
	reversed_Number = 1;
	/*if (number < 0)
	{

		LCD_Vid_Write_Data('-');
		number *= -1;


	}*/
	if (number == 0)
		{
			LCD_Vid_Write_Data('0');
		}
		while (number != 0)
		{
			reversed_Number = ((reversed_Number * 10) + (number % 10));
			number /= 10;

		}
		while (reversed_Number != 1)
		{
			LCD_Vid_Write_Data((reversed_Number % 10) + '0');
			reversed_Number /= 10;

		}

}
/*
 * 0 -> 39
 * 64 -> 103
 * */

void LCD_Vid_Select_Position(u8 row,u8 column)
{
	if (row == 0)
	{


		LCD_Vid_Write_Command(128+column);


	}
	else if(row == 1)
	{


		LCD_Vid_Write_Command(128+64+column);

	}

}

void LCD_Clear(void)
{

	LCD_Vid_Write_Command(0b00000001);
	_delay_ms(2);

}







