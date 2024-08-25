/*
 * main.c
 *
 *  Created on: Aug 24, 2024
 *      Author: Mina Fathy
 */


#include <stdint.h>
#include <stdio.h>
#include "Alarm_M.h"
#include "P_Sensor.h"
#include "Main_Algorithm.h"


int main (){

	GPIO_INITIALIZATION();
	PS_state = STATE(PS_GetingReading);
	AM_state = STATE(AM_alarm_off);
	MA_state = STATE(MA_GetSignal);
	while (1)
	{	
		PS_state();
		MA_state();
		AM_state();
		Delay(1000);
	}

}
