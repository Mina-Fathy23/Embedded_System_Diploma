/*
 * P_Sensor.c
 *
 *  Created on: Aug 24, 2024
 *      Author: Mina Fathy
 */
#include "P_Sensor.h"
void (*PS_state)();

//variable

STATE_define(PS_GetingReading)
{
	//Set State ID
	PS_state_id = PS_GetingReading;

	//Action
	Set_Pressure_Value((int)getPressureVal());

	//jump to next state according to algorithm
	PS_state = STATE(PS_Waiting);
}

STATE_define(PS_Waiting)
{
	//Set State ID
	PS_state_id = PS_Waiting;

	//Action
	Delay(100);
	PS_state = STATE(PS_GetingReading);
}
