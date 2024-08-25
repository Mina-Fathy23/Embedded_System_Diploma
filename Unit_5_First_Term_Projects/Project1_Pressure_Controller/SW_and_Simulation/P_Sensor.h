/*
 * P_Sensor.h
 *
 *  Created on: Aug 24, 2024
 *      Author: Mina Fathy
 */

#ifndef PS_H_
#define PS_H_

#include "state.h"
#include "Platform_Types.h"
#include "stdio.h"
#include "stdlib.h"


//State Pointer declaration
extern void (*PS_state)();

enum {
	PS_GetingReading,
	PS_Waiting
}PS_state_id;

//Declare states functions PS
STATE_define(PS_GetingReading);
STATE_define(PS_Waiting);


#endif /* PS_H_ */
