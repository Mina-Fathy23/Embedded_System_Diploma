/*
 * CA.c
 *
 *  Created on: Aug 21, 2024
 *      Author: Mina Fathy
 */

#include "CA.h"

//variables
static uint32 CA_speed = 0;
static uint32 CA_distance = 0;
static uint32 CA_threshold = 50;

//state Pointer to function
void (*CA_state)();

//signal coming from US_Sensor is implemented here, as CA is the destination
//Signal is the event that changes states
void US_Set_distance(int d)
{
	CA_distance = d;
	(CA_distance <= CA_threshold)? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving));
	DPRINT("US -------Distance = %d------> CA\n", CA_distance);
}

STATE_define(CA_waiting)
{
	//State_Name
	CA_state_id = CA_waiting;
	DPRINT("CA_Waiting State: distance = %d  Speed = %d \n", CA_distance, CA_speed);

	//State_Action
	CA_speed = 0;
	DC_Set_speed(CA_speed);
}

STATE_define(CA_driving)
{
	//State_Name
	CA_state_id = CA_driving;
	DPRINT("CA_Driving State: distance = %d  Speed = %d \n", CA_distance, CA_speed);

	//State_Action
	CA_speed = 30;
	DC_Set_speed(CA_speed);
}


