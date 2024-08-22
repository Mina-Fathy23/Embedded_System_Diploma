/*
 * state.h
 *
 *  Created on: Aug 22, 2024
 *      Author: EliteBook
 */

#ifndef STATE_H_
#define STATE_H_

//Automatic STATE Function generation

#define STATE_define(_stateFUN_) void ST_##_stateFUN_()
#define STATE(_stateFUN_) ST_##_stateFUN_

//State Connection
void US_Set_distance(int d);
void DC_Set_speed(int s);


#endif /* STATE_H_ */
