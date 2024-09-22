/*
 * Seven_Segmant.h
 *
 *  Created on: Sep 17, 2024
 *      Author: Mina Fathy
 */

#ifndef SEVEN_SEGMANT_DRIVER_SEVEN_SEGMANT_H_
#define SEVEN_SEGMANT_DRIVER_SEVEN_SEGMANT_H_

#include "Platform_Types.h"
#include "Utils.h"
#include "STM32_F103C6_GPIO_drivers.h"
#include "STM32F103x6.h"

#define Seven_Seg_PORT	GPIOB //Pin 9 >> 15
#define Seven_Seg_SHIFT	9	  //Index of PIN Seven_Seg_A

#define Seven_Seg_A		GPIO_PIN_9
#define Seven_Seg_B		GPIO_PIN_10
#define Seven_Seg_C		GPIO_PIN_11
#define Seven_Seg_D		GPIO_PIN_12
#define Seven_Seg_E		GPIO_PIN_13
#define Seven_Seg_F		GPIO_PIN_14
#define Seven_Seg_G		GPIO_PIN_15


//@ref HEX_Numbers
#define ZERO 			0x01
#define ONE 			0x79
#define TWO 			0x24
#define THREE 			0x30
#define FOUR 			0x4C
#define FIVE 			0x12
#define SIX 			0x02
#define SEVEN	 		0x19
#define EIGHT 			0x00
#define NINE 			0x10

void Seven_Seg_Init();
void Seven_Seg_Write_Num(uint16 Num);

#endif /* SEVEN_SEGMANT_DRIVER_SEVEN_SEGMANT_H_ */
