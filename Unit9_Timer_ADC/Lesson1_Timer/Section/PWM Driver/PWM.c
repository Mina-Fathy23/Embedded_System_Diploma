/*
 * PWM.c
 *
 *  Created on: Aug 20, 2025
 *      Author:	Mina Fathy
 */

//--------------------------------
//Inlcudes
//--------------------------------
#include "PWM.h"

//--------------------------------
//Global and Extern Variables
//--------------------------------
extern ST_TIMER0_CONFIG_t* TIMER0_Config;
//todo extern ST_TIMER0_CONFIG_t* TIMER1_Config;
//todo extern ST_TIMER0_CONFIG_t* TIMER2_Config;

uint8_t compare_value;


//--------------------------------
//APIs IMPLEMENTATION
//--------------------------------
E_STATUS_t PWM_SetDutyCylce(uint8_t duty,TIMERS timer_num)
{
	E_STATUS_t u8_Result = E_ERR;
	SetBit(DDRB, PIN3);
	if(NULL_PTR == TIMER0_Config)
	{
		u8_Result = E_ERR;
	}
	else
	{
		switch(timer_num)
		{
		case TIMER0:
			if(OC0_PWM_DISABLE == TIMER0_Config->PWM_Output)
			{
				u8_Result = E_ERR;
			}
			else
			{
				if(Phase_Correct_PWM == TIMER0_Config->Mode || Fast_PWM == TIMER0_Config ->Mode)
				{
					if(OC0_PWM_INVERTING == TIMER0_Config->PWM_Output)
					{
						compare_value = TIMER0_MAX - ((duty * TIMER0_MAX) / 100);
						TIMER0_SetCompareValue(compare_value);
						u8_Result = E_OK;
					}
					else if(OC0_PWM_NON_INVERTING == TIMER0_Config->PWM_Output)
					{
						compare_value = ((duty * TIMER0_MAX) / 100);
						TIMER0_SetCompareValue(compare_value);
						u8_Result = E_OK;
					}
					else
					{
						u8_Result = E_ERR;
					}

				}
				else
				{
					u8_Result = E_ERR;
				}
			}
			break;
		case TIMER1: u8_Result = E_OK; break;  //todo
		case TIMER2: u8_Result = E_OK; break;  //todo
		default: u8_Result = E_ERR; break;
		}
	}

	return  u8_Result;
}
