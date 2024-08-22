/*
 * US_Senor.c
 *
 *  Created on: Aug 21, 2024
 *      Author: Mina Fathy
 */

#include "US.h"

//variables
static uint32 US_distance = 0;

//state Pointer to function
void (*US_state)();

void US_init()
{
	//init US_Senor Driver
	DPRINT("US Sensor Init.....Done\n");
}

STATE_define(US_Senor_Busy)
{
	//State_Name
	US_state_id = US_Senor_Busy;

	//State_Action
	US_distance = US_Get_distacne_random(45, 55, 1);
	DPRINT("US_Senor_Busy State: distance = %d\n", US_distance);
	US_Set_distance(US_distance);

	//jump to next state according to algorithm
	US_state = STATE(US_Senor_Busy);
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
