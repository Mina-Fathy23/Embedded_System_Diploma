/*
 * MainA.h
 *
 *  Created on: Aug 24, 2024
 *      Author: Mina Fathy
 */

#ifndef MA_H_
#define MA_H_

#include "state.h"
#include "Platform_Types.h"
#include "stdio.h"
#include "stdlib.h"


//State Pointer declaration
extern void (*MA_state)();

enum {
	MA_GetSignal,
	MA_High_Pressure
}MA_state_id;

//Declare states functions PS
STATE_define(MA_GetSignal);
STATE_define(MA_High_Pressure);


#endif /* MA_H_ */
