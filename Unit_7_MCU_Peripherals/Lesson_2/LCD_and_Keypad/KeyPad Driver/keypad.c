/*
 * keypad.c
 *
 *  Created on: Sep 12, 2024
 *      Author: Mina Fathy
 */

#include "keypad.h"

vuint8_t keypad_R[4] = {R0, R1, R2, R3};
vuint8_t keypad_C[4] = {C0, C1, C2, C3};
char keypad_character[4][4] = {
		{'7', '8', '9', '/'},
		{'4', '5', '6', 'X'},
		{'1', '2', '3', '-'},
		{'C', '0', '=', '+'}  };

void KEYPAD_Init()
{
	KEYPAD_DataDir &= ~((1 << R0) | (1 << R1) | (1 << R2) | (1 << R3));
	KEYPAD_DataDir |=  ((1 << C0) | (1 << C1) | (1 << C2) | (1 << C3));
	KEYPAD_PORT = 0xFF;
}

char KEYPAD_GetChar()
{
	vuint8_t i, j;
	for(i = 0; i < 4; i++)
	{
		KEYPAD_PORT |= ((1 << keypad_C[0]) | (1 << keypad_C[1]) |(1 << keypad_C[2]) | (1 << keypad_C[3]));
		ClearBit(KEYPAD_PORT, keypad_C[i]);
		for(j = 0; j < 4; j++)
		{
			if(!GetBit(KEYPAD_PIN, keypad_R[j]))
			{
				while(!GetBit(KEYPAD_PIN, keypad_R[j]))
				{
					//Will Still pressed DO Noting
				}
				return keypad_character[j][i];
			}
		}
	}
	return 'N';
}


