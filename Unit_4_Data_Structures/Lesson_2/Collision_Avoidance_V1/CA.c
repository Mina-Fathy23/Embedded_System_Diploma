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

STATE_define(CA_waiting)
{
	//State_Name
	CA_state_id = CA_waiting;

	//State_Action
	CA_speed = 0;
	//DC_Motor(speed)

	//Event_Check
	CA_distance = US_Get_distacne_random(45, 55, 1);
	(CA_distance <= CA_threshold)? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving));
	DPRINT("CA_Waiting State: distance = %d  Speed = %d \n", CA_distance, CA_speed);
}

STATE_define(CA_driving)
{
	//State_Name
	CA_state_id = CA_driving;

	//State_Action
	CA_speed = 30;
	//DC_Motor(speed)

	//Event_Check
	CA_distance = US_Get_distacne_random(45, 55, 1);
	(CA_distance <= CA_threshold)? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving));
	DPRINT("CA_Driving State: distance = %d  Speed = %d \n", CA_distance, CA_speed);
}

//generates random distance for testing
uint32 US_Get_distacne_random(uint32 l, uint32 r, uint32 count)
{
	uint32 i;
	for(i = 0; i < count; i++)
	{
		uint32 rand_num = (rand() % (r - l + 1)) + l;
		return rand_num;
	}
	return 1;

}
