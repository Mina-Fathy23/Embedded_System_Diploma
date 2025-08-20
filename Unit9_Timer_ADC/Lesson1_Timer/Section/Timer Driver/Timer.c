/*
 * Timer.c
 *
 *  Created on: Aug 18, 2025
 *      Author:	Mina Fathy
 */

//--------------------------------
//Includes
//--------------------------------
#include "Timer.h"


//--------------------------------
//Global and Extern Variables
//--------------------------------
PTR_VoidFunVoid_t CALLBACK_OVF;
PTR_VoidFunVoid_t CALLBACK_CM;
uint8_t u8_TOVNumber;
ST_TIMER0_CONFIG_t* TIMER0_Config;

//--------------------------------
//APIs IMPLEMENTATION
//--------------------------------
E_STATUS_t TIMER0_Init(ST_TIMER0_CONFIG_t* Config)
{
	E_STATUS_t u8_Result = E_ERR;
	if(NULL_PTR == Config)
	{
		u8_Result = E_ERR;
	}
	else
	{
		TIMER0_Config = Config;
		//Initializing Mode of Operation
		if(NORMAL == TIMER0_Config->Mode || CTC == TIMER0_Config->Mode || Phase_Correct_PWM == TIMER0_Config->Mode || Fast_PWM == TIMER0_Config->Mode)
		{
			TCCR0 &= ~((1<<WGM00)|(1<<WGM01));
			TCCR0 |= TIMER0_Config->Mode;
			u8_Result = E_OK;
		}
		else
		{
			u8_Result = E_ERR;
		}

		//Initializing Clk soruce
		if(NO_CLK_SOURCE <= TIMER0_Config->Clock && EXT_CLK_Rising >= TIMER0_Config->Clock)
		{
			TCCR0 &= ~((1<<CS02)|(1<<CS01)|(1<<CS00));
			TCCR0 |= TIMER0_Config->Clock;
			u8_Result = E_OK;
		}
		else
		{
			u8_Result = E_ERR;
		}

		//Initializing Output mode
		if(CTC == TIMER0_Config->Mode)
		{
			TCCR0 &= ~((1<<COM01)|(1<<COM00));
			//CTC Output mode
			if(OC0_CTC_DISABLE <= TIMER0_Config->CTC_Output && OC0_CTC_TOGGLE_ON_COMPARE >= TIMER0_Config->CTC_Output)
			{
				TCCR0 |= TIMER0_Config->CTC_Output;
				u8_Result = E_OK;
			}
			else
			{
				u8_Result = E_ERR;
			}
		}//PWM Output Mode
		else if(Phase_Correct_PWM == TIMER0_Config->Mode || Fast_PWM == TIMER0_Config->Mode)
		{
			if(OC0_PWM_DISABLE == TIMER0_Config->PWM_Output || OC0_PWM_INVERTING == TIMER0_Config->PWM_Output || OC0_PWM_NON_INVERTING == TIMER0_Config->PWM_Output)
			{
				TCCR0 |= TIMER0_Config->PWM_Output;
				u8_Result = E_OK;
			}
			else
			{
				u8_Result = E_ERR;
			}
		}

		//Initializing Interrupts;
		if(OCIE0_DISABLE == TIMER0_Config->OCM_Interrupt || OCIE0_Enable == TIMER0_Config->OCM_Interrupt)
		{
			TIMSK |= TIMER0_Config->OCM_Interrupt;
			u8_Result = E_OK;
		}
		else
		{
			u8_Result = E_ERR;
		}

		if(TOIE0_DISABLE == TIMER0_Config->OVF_Interrupt || TOIE0_Enable== TIMER0_Config->OVF_Interrupt)
		{
			TIMSK |= TIMER0_Config->OVF_Interrupt;
			u8_Result = E_OK;
		}
		else
		{
			u8_Result = E_ERR;
		}
	}
	return u8_Result;
}
E_STATUS_t TIMER0_Stop(void)
{
	E_STATUS_t u8_Result = E_OK;
	TIMSK |= NO_CLK_SOURCE;
	return u8_Result;
}

E_STATUS_t TIMER0_GetCompareValue(uint8_t* pu8_TicksNumber)
{
	E_STATUS_t u8_Result = E_OK;
	*pu8_TicksNumber = OCR0;
	return u8_Result;
}
E_STATUS_t TIMER0_SetCompareValue(uint8_t pu8_TicksNumber)
{
	E_STATUS_t u8_Result = E_OK;
	OCR0 = pu8_TicksNumber;
	return u8_Result;
}

E_STATUS_t TIMER0_GetCounterValue(uint8_t* pu8_TicksNumber)
{
	E_STATUS_t u8_Result = E_OK;
	*pu8_TicksNumber = TCNT0;
	return u8_Result;
}
E_STATUS_t TIMER0_SetCounterValue(uint8_t pu8_TicksNumber)
{
	E_STATUS_t u8_Result = E_OK;
	TCNT0 = pu8_TicksNumber;
	return u8_Result;
}

E_STATUS_t TIMER0_GetOverflowValue(uint8_t* pu8_TicksNumber)
{
	E_STATUS_t u8_Result = E_OK;
	*pu8_TicksNumber = u8_TOVNumber;
	return u8_Result;
}
E_STATUS_t TIMER0_SetOverflowValue(uint8_t pu8_TicksNumber)
{
	E_STATUS_t u8_Result = E_OK;
	u8_TOVNumber = pu8_TicksNumber;
	return u8_Result;
}

void TIMER0_CALLBACK_Overflow_INTERRUPT(PTR_VoidFunVoid_t callback)
{
	CALLBACK_OVF = callback;
}
void TIMER0_CALLBACK_CompareMatch_INTERRUPT(PTR_VoidFunVoid_t callback)
{
	CALLBACK_CM = callback;
}

ISR(TIMER0_COMP_vect)
{
	CALLBACK_CM();
}

ISR(TIMER0_OVF_vect)
{
	u8_TOVNumber++;
	CALLBACK_OVF();
}
