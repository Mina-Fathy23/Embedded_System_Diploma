/*
 * main.c
 *
 *  Created on: Aug 21, 2024
 *      Author: Mina Fathy
 */


#include "CA.h"
#include "US.h"
#include "DC.h"

void setup()
{
	//init all the drivers
	//init IRQ ....
	//init HAL: US_Driver DC_Drvier
	//init Block
	US_init();
	DC_init();
	//set states pointers for each block
	US_state = STATE(US_Senor_Busy);
	CA_state = STATE(CA_waiting);
	DC_state = STATE(DC_Idle);
}


int main(void)
{
	vuint32_t delay;
	setup();

	while(1)
	{
		//call state for each Block
		US_state();
		CA_state();
		DC_state();
		//delay
		for(delay = 0; delay < 500; delay++);
	}
}
