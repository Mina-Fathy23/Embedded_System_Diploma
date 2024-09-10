/*
 * main.c
 *
 *  Created on: Sep 7, 2024
 *      Author: EliteBook
 */

#include <avr/io.h>
#include <util/delay.h>
#include "Platform_Types.h"
#include <avr/iom32.h>
#include "Utils.h"

#define IO_Base 0x20

//GDPIO_Port B
//#define DDRB 		*((vuint8_t*)(IO_Base + 0x17))
//#define PORTB 	*((vuint8_t*)(IO_Base + 0x18))
//#define PINB		*((vuint8_t*)(IO_Base + 0x16))
//
////GDPIO_Port D
//#define DDRD 		*((vuint8_t*)(IO_Base + 0x11))
//#define PORTD 	*((vuint8_t*)(IO_Base + 0x12))
//#define PIND		*((vuint8_t*)(IO_Base + 0x10))

void GPIO_init()
{
	//Set PORTD PIN 0, 1, 2 as input High-Z
	ClearBit(DDRD, 0);
	ClearBit(DDRD, 1);
	ClearBit(DDRD, 2);

	//Set PortD Pin 4, 5, 6, 7 as output Pull Push
	SetBit(DDRD, 4);
	SetBit(DDRD, 5);
	SetBit(DDRD, 6);
	SetBit(DDRD, 7);
}


int main()
{
	GPIO_init();
	vuint8_t flag = 5;
	while(1)
	{
		//Push Button 0
		if(GetBit(PIND, 0) == 1)
		{
			//Turn Leds on from 1 -> 3
			SetBit(PORTD, 5);
			_delay_ms(500);
			SetBit(PORTD, 6);
			_delay_ms(500);
			SetBit(PORTD, 7);
			_delay_ms(500);

			//Turn the Leds off from 3 ->1
			ClearBit(PORTD, 7);
			_delay_ms(500);
			ClearBit(PORTD, 6);
			_delay_ms(500);
			ClearBit(PORTD, 5);
			_delay_ms(500);
		}

		//Push Button 1
		if(GetBit(PIND, 1) == 1)
		{
			_delay_ms(200);
			if(flag > 7)
			{
				flag = 5;
				ClearBit(PORTD, 7);
				ClearBit(PORTD, 6);
				ClearBit(PORTD, 5);
			}
			else
			{
				SetBit(PORTD, flag);
				flag++;
			}

			while(GetBit(PIND, 1) == 1); // single Press
		}

		//Push Button 2
		if(GetBit(PIND, 2) == 1)
		{
			SetBit(PORTD, 4);
			_delay_ms(1000);
			ClearBit(PORTD, 4);
		}

	}
	return 1;
}

