/*
 * DC.h
 *
 *  Created on: Aug 21, 2024
 *      Author: Mina Fathy
 */

#ifndef DC_H_
#define DC_H_

#include "state.h"
#include "platfrom_Types.h"
#include "stdio.h"
#include "stdlib.h"

#define DPRINT(...) {fflush(stdin); \
					 fflush(stdout); \
					 printf(__VA_ARGS__); \
					 fflush(stdin); \
					 fflush(stdout);}


//state pointer Declaration
extern void (*DC_state)();

//Define States
enum{
	DC_Idle,
	DC_Busy
}DC_state_id;

//Declare states functions DC
STATE_define(DC_Idle);
STATE_define(DC_Busy);

void DC_init();

#endif /* DC_H_ */
