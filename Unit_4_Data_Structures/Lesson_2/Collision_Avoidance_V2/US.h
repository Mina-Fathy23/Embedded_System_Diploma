/*
 * US_Senor.h
 *
 *  Created on: Aug 21, 2024
 *      Author: Mina Fathy
 */

#ifndef US_H
#define US_H

#include "state.h"
#include "platfrom_Types.h"
#include "stdio.h"
#include "stdlib.h"

#define DPRINT(...) {fflush(stdin); \
					 fflush(stdout); \
					 printf(__VA_ARGS__); \
					 fflush(stdin); \
					 fflush(stdout);}

uint32 US_Get_distacne_random(uint32 l, uint32 r, uint32 count);

//state pointer Declaration
extern void (*US_state)();

//Define States
enum{
	US_Senor_Busy,
}US_state_id;

//Declare states functions US
STATE_define(US_Senor_Busy);

void US_init();

#endif /* US_H_ */
