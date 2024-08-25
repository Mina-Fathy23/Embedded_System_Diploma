/*
 * state.h
 *
 *  Created on: Aug 24, 2024
 *      Author: EliteBook
 */

#ifndef STATE_H_
#define STATE_H_

#include"driver.h"

//Automatic STATE Function generation

#define STATE_define(_stateFUN_) void ST_##_stateFUN_()
#define STATE(_stateFUN_) ST_##_stateFUN_

//State Connection
void Set_Pressure_Value(int pvalue);
void High_pressure_detected(void);
//set alarm and Stop alarm are in driver.h

#endif /* STATE_H_ */
