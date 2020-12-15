/*
 * LCD.h
 *
 *  Created on: Aug 23, 2019
 *      Author: Mohamed Osama
 */

#ifndef LCD_H_
#define LCD_H_
#include "Types.h"
void LCD_Vid_Write_Data(u8 );
void LCD_Vid_Write_Command(u8 );
void LCD_Vid_Init(void);
void LCD_Vid_Write_String(u8 *);
void LCD_Vid_Write_Number(u32 );
void LCD_Vid_Select_Position(u8 ,u8 );
void LCD_Clear(void);

#endif /* LCD_H_ */
