/*
 * DIO.h
 *
 *  Created on: Aug 17, 2019
 *      Author: Mohamed Osama
 */
#include "Types.h"
#ifndef DIO_H_
#define DIO_H_


#define A 0
#define a 0

#define B 1
#define b 1

#define C 2
#define c 2

#define D 3
#define d 3

#define input 0
#define INPUT 0

#define output 255
#define output 255

#define outputport 255
#define OUTPUTPORT 255

#define outputpin 1
#define OUTPUTpint 1

void DIO_Vid_Set_Port_Direction(u8 portNumber,u8 value);
void DIO_Vid_Set_Port_Value(u8 portNumber,u8 value);
u8 DIO_u8_Read_Port_Value(u8 portNumber);
u8 DIO_u8_Read_Pin_Value(u8 portNumber,u8 pinNumber);
void DIO_Vid_Set_Pin_Value(u8 portNumber, u8 pinNumber,u8 value);
void DIO_Vid_Set_Pin_Direcition(u8 portNumber, u8 pinNumber,u8 value);

#endif /* DIO_H_ */
