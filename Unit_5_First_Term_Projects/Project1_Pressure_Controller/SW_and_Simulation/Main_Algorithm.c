/*
 * Alarm_M.c
 *
 *  Created on: Aug 24, 2024
 *      Author: Mina Fathy
 */

#include "Main_Algorithm.h"

//State Pointer Definition
void (*MA_state)();

//variables
int MA_pressure = 0;
int MA_threshold = 20;

STATE_define(MA_GetSignal)
{
	//Set State ID
	MA_state_id = MA_GetSignal;

	//Action
	(MA_pressure > MA_threshold)? (MA_state = STATE(MA_High_Pressure)) : (MA_state = STATE(MA_GetSignal));
}

void Set_Pressure_Value(int pvalue)
{
	MA_pressure = pvalue;
}

STATE_define(MA_High_Pressure)
{
	//Set State ID
	MA_state_id = MA_High_Pressure;

	//Action
	High_pressure_detected();
	MA_state = STATE(MA_GetSignal);
}


