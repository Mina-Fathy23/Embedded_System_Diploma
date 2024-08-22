/*
 * main.c
 *
 *  Created on: Aug 21, 2024
 *      Author: Mina Fathy
 */


#include "CA.h"

void setup()
{
	//init all the drivers
	//init IRQ ....
	//init HAL: US_Driver DC_Drvier
	//init Block
	//set states pointers for each block
	CA_state = STATE(CA_waiting);
}


int main(void)
{
	vuint32_t delay;
	setup();

	while(1)
	{
		//call state for each Block
		CA_state();
		//delay
		for(delay = 0; delay < 500; delay++);
	}
}
