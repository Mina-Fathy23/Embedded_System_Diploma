/*
 * keypad.c
 *
 *  Created on: Sep 12, 2024
 *      Author: Mina Fathy
 */

#include "keypad.h"


char keypad_character[4][4] = {
		{'7', '8', '9', '/'},
		{'4', '5', '6', 'X'},
		{'1', '2', '3', '-'},
		{'C', '0', '=', '+'}  };

/**================================================================
 * @Fn				- KEYPAD_Init
 * @breif			- Initializes Keypads' Port
 * @param [in]		- None
 * @retval			- None
 * Note				- None
 */
void KEYPAD_Init()
{
	/*	KEYPAD_DataDir &= ~((1 << R0) | (1 << R1) | (1 << R2) | (1 << R3));
	KEYPAD_DataDir |=  ((1 << C0) | (1 << C1) | (1 << C2) | (1 << C3));
	KEYPAD_PORT = 0xFF;
	 */

	GPIO_PinConfig_t PinCfg;


	PinCfg.GPIO_PinNumber = R0;
	PinCfg.GPIO_Mode = GPIO_MODE_INPUT_PD;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = R1;
	PinCfg.GPIO_Mode = GPIO_MODE_INPUT_PD;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = R2;
	PinCfg.GPIO_Mode = GPIO_MODE_INPUT_PD;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = R3;
	PinCfg.GPIO_Mode = GPIO_MODE_INPUT_PD;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);


	//=========================================================

	//Set C0 >> C3 as Output Push-Pull
	PinCfg.GPIO_PinNumber = C0;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = C1;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = C2;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = C3;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg);



}

/**================================================================
 * @Fn				- KEYPAD_GetChar
 * @breif			- Checks for the pressed button
 * @param [in]		- None
 * @retval			- the pressed button as ASCII Code char
 * Note				- None
 */
char KEYPAD_GetChar()
{
	vuint16_t keypad_C[4] = {C0, C1, C2, C3}; //columns
	vuint16_t keypad_R[4] = {R0, R1, R2, R3}; //rows of the keypad

	vuint8_t i, j;

	for(i = 0; i < 4; i++)
	{

		// Send a high to a particular column of the keypad
		MCAL_GPIO_WritePin(KEYPAD_PORT, keypad_C[i], GPIO_PIN_SET);

		for(j = 0; j < 4; j++)
		{
			if(MCAL_GPIO_ReadPin(KEYPAD_PORT, keypad_R[j])) // Check if is key is pressed
			{
				while(MCAL_GPIO_ReadPin(KEYPAD_PORT, keypad_R[j])) // Wait for the key to be released (Single pressed)
				{
					//Will Still pressed DO Noting
				}
				return keypad_character[j][i];
			}
		}
		wait(10);
		MCAL_GPIO_WritePin(KEYPAD_PORT, keypad_C[i], GPIO_PIN_RESET);//Return the column low again
	}
	return 'N';
}


