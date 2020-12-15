/*
 * macros.h
 *
 *  Created on: Aug 3, 2019
 *      Author: Mohamed Osama
 */


#ifndef MACROS_H_
#define MACROS_H_

#define setBit(reg,bit) reg |=(1<<bit)
#define clearBit(reg,bit) reg &= ~(1<<bit)
#define toogleBit(reg,bit) reg ^=(1<<bit)
#define getBit(reg,bit) ((reg>>bit)&1)

#endif /* MACROS_H_ */
