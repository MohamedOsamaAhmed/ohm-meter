/*
 * Registers.h
 *
 *  Created on: Aug 17, 2019
 *      Author: Mohamed Osama
 */

#ifndef REGISTERS_H_
#define REGISTERS_H_

#define DDRA *((volatile u8 *)0x3A)
#define PORTA *((volatile u8 *)0x3B)
#define PINA *((volatile u8 *)0x39)


#define DDRB *((volatile u8 *)0x37)
#define PORTB *((volatile u8 *)0x38)
#define PINB *((volatile u8 *)0x36)


#define DDRC *((volatile u8 *)0x34)
#define PORTC *((volatile u8 *)0x35)
#define PINC *((volatile u8 *)0x33)


#define DDRD *((volatile u8 *)0x31)
#define PORTD *((volatile u8 *)0x32)
#define PIND *((volatile u8 *)0x30)

#define MCUCR *((volatile u8 *)0x55)

#define SREG *((volatile u8 *)0x5F)

#define GICR *((volatile u8 *)0x5B)

#define TCNT0 *((volatile u8 *)0x52)

#define OCR0 *((volatile u8 *)0x5C)


#define TIMSK *((volatile u8 *)0x59)
#define TCCR0 *((volatile u8 *)0x53)
#define TIFR *((volatile u8 *)0x58)


#define TCCR1A *((volatile u8 *)0x4F)
#define TCCR1B *((volatile u8 *)0x4E)
#define ICR1 *((volatile u16 *)0x46)
#define OCR1A *((volatile u16 *)0x4A)


// ADC
#define ADMUX *((volatile u8*) 0x27)
#define ADCSRA *((volatile u8*) 0x26)
#define ADCREG *((volatile u16*) 0x24)


// USART
#define UCSRA *((volatile u8*) 0x2B)
#define USCRB *((volatile u8*) 0x2A)
#define UCSRC *((volatile u8*) 0x40)
#define UBRRH *((volatile u8*) 0x40)
#define UBRRL *((volatile u8*) 0x29)
#define UDR *((volatile u8*) 0x2C)


// WATCH DOG

#define WDTCR *((volatile u8*) 0x41)



// SPI

#define SPCR *((volatile u8*) 0x2D)
#define SPSR *((volatile u8*) 0x2E)
#define SPDR *((volatile u8*) 0x2F)

// I2C
#define TWDR *((volatile u8*) 0x23)
#define TWAR *((volatile u8*) 0x22)
#define TWSR *((volatile u8*) 0x21)
#define TWBR *((volatile u8*) 0x20)
#define TWCR *((volatile u8*) 0x56)



#define TWINT 0b10000000
#define TWEN  0b00000100
#define TWEA  0b01000000
#define TWSTA 0b00100000
#define TWSTO 0b00010000


#endif /* REGISTERS_H_ */
