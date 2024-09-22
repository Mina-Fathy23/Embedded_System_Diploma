/*
 * keypad.h
 *
 *  Created on: Sep 12, 2024
 *      Author: Mina Fathy
 */

#ifndef KEYPAD_DRIVER_KEYPAD_H_
#define KEYPAD_DRIVER_KEYPAD_H_


#include "STM32_F103C6_GPIO_drivers.h"
#include "STM32F103x6.h"
#include "Utils.h"
#include "Platform_Types.h"

#define KEYPAD_PORT		GPIOB

#define R0 				GPIO_PIN_0
#define R1				GPIO_PIN_1
#define R2 				GPIO_PIN_3
#define R3 				GPIO_PIN_4
#define C0 				GPIO_PIN_5
#define C1 				GPIO_PIN_6
#define C2 				GPIO_PIN_7
#define C3 				GPIO_PIN_8

void KEYPAD_Init();
char KEYPAD_GetChar();

#endif /* KEYPAD_DRIVER_KEYPAD_H_ */
