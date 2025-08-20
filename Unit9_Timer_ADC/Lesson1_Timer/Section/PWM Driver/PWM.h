/*
 * PWM.h
 *
 *  Created on: Aug 20, 2025
 *      Author:	Mina Fathy
 */

#ifndef PWM_DRIVER_PWM_H_
#define PWM_DRIVER_PWM_H_

//--------------------------------
//includes
//--------------------------------
#include "../Timer Driver/Timer.h"

//--------------------------------
//MACROS
//--------------------------------
#define TIMER0_MAX	255


//--------------------------------
//enums
//--------------------------------
typedef enum{
	TIMER0,
	TIMER1,
	TIMER2
}TIMERS;


//--------------------------------
//APIs
//--------------------------------
E_STATUS_t PWM_SetDutyCylce(uint8_t duty,TIMERS timer_num);


#endif /* PWM_DRIVER_PWM_H_ */
