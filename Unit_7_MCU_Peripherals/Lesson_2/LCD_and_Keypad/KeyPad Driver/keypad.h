/*
 * keypad.h
 *
 *  Created on: Sep 12, 2024
 *      Author: Mina Fathy
 */

#ifndef KEYPAD_DRIVER_KEYPAD_H_
#define KEYPAD_DRIVER_KEYPAD_H_

#define F_CPU 1000000UL

#include "../LIB/Utils.h"
#include "../LIB/Platform_Types.h"
#include "avr/io.h"
#include "util/delay.h"

#define KEYPAD_PORT		PORTD
#define KEYPAD_DataDir	DDRD
#define KEYPAD_PIN		PIND

#define R0 				0
#define R1				1
#define R2 				2
#define R3 				3
#define C0 				4
#define C1 				5
#define C2 				6
#define C3 				7

void KEYPAD_Init();
char KEYPAD_GetChar();

#endif /* KEYPAD_DRIVER_KEYPAD_H_ */
