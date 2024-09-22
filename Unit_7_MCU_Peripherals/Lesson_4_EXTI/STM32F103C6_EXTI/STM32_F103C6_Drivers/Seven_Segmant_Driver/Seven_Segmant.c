/*
 * Seven_Segmant.c
 *
 *  Created on: Sep 17, 2024
 *      Author: Mina Fathy
 */

#include "Seven_Segmant.h"

vuint8_t Seven_Seg_DISPLAY[10] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};


/**================================================================
 * @Fn				- Seven_Seg_Init
 * @breif			- Initializes Keypads' Port
 * @param [in]		- None
 * @retval			- None
 * Note				- None
 */
void Seven_Seg_Init()
{
	GPIO_PinConfig_t PinCfg;
	//Set PIN B9 >> B15 Set as Output Pull-Push
	PinCfg.GPIO_PinNumber = Seven_Seg_A;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(Seven_Seg_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = Seven_Seg_B;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(Seven_Seg_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = Seven_Seg_C;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(Seven_Seg_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = Seven_Seg_D;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(Seven_Seg_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = Seven_Seg_E;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(Seven_Seg_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = Seven_Seg_F;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(Seven_Seg_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = Seven_Seg_G;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(Seven_Seg_PORT, &PinCfg);
}

/**================================================================
 * @Fn				- Seven_Seg_Write_Num
 * @breif			- Writes a Number on Seven Segment display
 * @param [in]		- Num: Specifies the Number code to be written according to @ref HEX_Numbers or Seven_Seg_DISPLAY array
 * @retval			- None
 * Note				- None
 */
void Seven_Seg_Write_Num(uint16 Num)
{
	MCAL_GPIO_WritePort(Seven_Seg_PORT, (Num << Seven_Seg_SHIFT));
}

