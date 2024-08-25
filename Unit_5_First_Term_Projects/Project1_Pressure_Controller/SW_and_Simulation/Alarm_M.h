/*
 * Alarm_M.h
 *
 *  Created on: Aug 24, 2024
 *      Author: Mina Fathy
 */

#ifndef AM_H_
#define AM_H_

#include "state.h"
#include "Platform_Types.h"
#include "stdio.h"
#include "stdlib.h"


//State Pointer declaration
extern void (*AM_state)();

enum {
	AM_alarm_off,
	AM_alarm_on,
	AM_waiting
}AM_state_id;

//Declare states functions PS
STATE_define(AM_alarm_off);
STATE_define(AM_alarm_on);
STATE_define(AM_waiting);


#endif /* AM_H_ */
