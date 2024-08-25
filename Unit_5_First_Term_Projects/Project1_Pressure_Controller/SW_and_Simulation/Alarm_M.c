/*
 * Alarm_M.c
 *
 *  Created on: Aug 24, 2024
 *      Author: Mina Fathy
 */

#include "Alarm_M.h"

void (*AM_state)();

//variables

STATE_define(AM_alarm_off)
{
	//Set State ID
	AM_state_id = AM_alarm_off;

	//Action
	Set_Alarm_actuator(1);
	Delay(1000);
}

void High_pressure_detected()
{
	AM_state = STATE(AM_alarm_on);
}


STATE_define(AM_alarm_on)
{
	//Set State ID
	AM_state_id = AM_alarm_on;

	//Action
	Set_Alarm_actuator(0);
	Delay(1000);
	AM_state = STATE(AM_waiting);
}

STATE_define(AM_waiting)
{
	//Set State ID
	AM_state_id = AM_waiting;

	//Action
	Delay(1000000);
	AM_state = STATE(AM_alarm_off);
}
