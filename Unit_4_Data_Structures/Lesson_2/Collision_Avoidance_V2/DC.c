/*
 * DC.c
 *
 *  Created on: Aug 21, 2024
 *      Author: Mina Fathy
 */

#include "DC.h"

//variables
static uint32 DC_speed = 0;

//state Pointer to function
void (*DC_state)();

void DC_init()
{
	//init DC_Motor Driver
	DPRINT("\nDC Motor Init.....Done\n");
}

//signal coming from CA is implemented here, as DC is the destination
//Signal is the event that changes states
void DC_Set_speed(int s)
{
	DC_speed= s;
	DPRINT("CA -------Speed = %d------> DC\n", DC_speed);
	DC_state = STATE(DC_Busy);
}

STATE_define(DC_Idle)
{
	//State_Name
	DC_state_id = DC_Idle;

	//State_Action
	//CALL DC motor to make speed = DC_speed
	DPRINT("DC_Idle State: Speed = %d \n", DC_speed);

	//jump to next state according to algorithm
	DC_state = STATE(DC_Idle);
}

STATE_define(DC_Busy)
{
	//State_Name
	DC_state_id = DC_Busy;

	//State_Action
	//CALL DC Motor to change speed to = DC_Speed
	DPRINT("DC_Busy State: Speed = %d \n", DC_speed);

	//jump to next state according to algorithm
	DC_state = STATE(DC_Idle);
}


