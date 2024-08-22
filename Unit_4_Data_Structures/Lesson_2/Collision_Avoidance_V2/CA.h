/*
 * CA.h
 *
 *  Created on: Aug 21, 2024
 *      Author: Mina Fathy
 */

#ifndef CA_H_
#define CA_H_

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
extern void (*CA_state)();

//Define States
enum{
	CA_waiting,
	CA_driving
}CA_state_id;

//Declare states functions CA
STATE_define(CA_waiting);
STATE_define(CA_driving);


#endif /* CA_H_ */
