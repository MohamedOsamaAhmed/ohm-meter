#include "Registers.h"
#include "macros.h"
#include "DIO.h"

#include "Types.h"
void DIO_Vid_Set_Port_Direction(u8 portNumber,u8 value)
{
	switch(portNumber)
		{
		case 0:
			DDRA = value;
			break;
		case 1:
			DDRB = value;
			break;
		case 2:
			DDRC = value;
			break;
		case 3:
			DDRD = value;
			break;
		}

}

void DIO_Vid_Set_Port_Value(u8 portNumber,u8 value)
{
	switch(portNumber)
		{
		case 0:
			PORTA = value;
			break;
		case 1:
			PORTB = value;
			break;
		case 2:
			PORTC = value;
			break;
		case 3:
			PORTD = value;
			break;
		}

}



u8 DIO_u8_Read_Port_Value(u8 portNumber)
{
	u8 value ;
	switch (portNumber)
	{
	case 0:
		value = PINA;
		break;
	case 1:
		value = PINB;
		break;
	case 2:
		value = PINC;
		break;
	case 3:
		value = PIND;
		break;
	}
	return value;

}
void DIO_Vid_Set_Pin_Direcition(u8 portNumber, u8 pinNumber,u8 value)
{
	switch(portNumber)
		{
		case 0:
			if (value == 1)
				setBit(DDRA, pinNumber);
			else if ( value == 0)
				clearBit(DDRA , pinNumber);
			break;
		case 1:
			if (value == 1)
				setBit(DDRB, pinNumber);
			else if ( value == 0)
				clearBit(DDRB , pinNumber);
			break;
		case 2:
			if (value == 1)
				setBit(DDRC, pinNumber);
			else if ( value == 0)
				clearBit(DDRC , pinNumber);
			break;
		case 3:
			if (value == 1)
				setBit(DDRD, pinNumber);
			else if ( value == 0)
				clearBit(DDRD , pinNumber);
			break;
		}

}

void DIO_Vid_Set_Pin_Value(u8 portNumber, u8 pinNumber,u8 value)
{

	switch(portNumber)
		{
		case 0:
			if (value == 1)
				setBit(PORTA, pinNumber);
			else if ( value == 0)
				clearBit(PORTA , pinNumber);
			break;
		case 1:
			if (value == 1)
				setBit(PORTB, pinNumber);
			else if ( value == 0)
				clearBit(PORTB , pinNumber);
			break;
		case 2:
			if (value == 1)
				setBit(PORTC, pinNumber);
			else if ( value == 0)
				clearBit(PORTC , pinNumber);
			break;
		case 3:
			if (value == 1)
				setBit(PORTD, pinNumber);
			else if ( value == 0)
				clearBit(PORTD , pinNumber);
			break;
		}

}

u8 DIO_u8_Read_Pin_Value(u8 portNumber,u8 pinNumber)
{
	u8 value;
	switch(portNumber)
		{
		case 0:
			value = getBit(PINA,pinNumber);
			break;
		case 1:
			value = getBit(PINB,pinNumber);
			break;
		case 2:
			value = getBit(PINC,pinNumber);
			break;
		case 3:
			value = getBit(PIND,pinNumber);
			break;
		}
	return value;

}



