/*
 * Timer.h
 *
 *  Created on: Aug 18, 2025
 *      Author:	Mina Fathy
 */

#ifndef TIMER_DRIVER_TIMER_H_
#define TIMER_DRIVER_TIMER_H_

//--------------------------------
//includes
//--------------------------------
#include "avr/io.h"
#include "avr/interrupt.h"

#include "../LIB/Platform_Types.h"
#include "../LIB/Utils.h"


//--------------------------------
//Enums
//--------------------------------
typedef enum{
	NORMAL,
	CTC = 0x08,
	Phase_Correct_PWM = 0x40,
	Fast_PWM = 0x48

}TIMER0_MODE_t;

typedef enum{
	OC0_CTC_DISABLE,
	OC0_CTC_TOGGLE_ON_COMPARE = 0x10,
	OC0_CTC_CLEAR_ON_COMPARE = 0x20,
	OC0_CTC_SET_ON_COMPARE = 0x30
}TIMER0_CTC_OUTPUT_t;

typedef enum
{
	OC0_PWM_DISABLE,
	OC0_PWM_NON_INVERTING = 0x20,
	OC0_PWM_INVERTING = 0x30
}TIMER0_PWM_OUTPUT_t;

typedef enum{
	NO_CLK_SOURCE,
	NO_PRESCALING,
	PRESCALING_CLK8,
	PRESCALING_CLK16,
	PRESCALING_CLK64,
	PRESCALING_CLK256,
	PRESCALING_CLK1024,
	EXTERNAL_CLK_Falling,
	EXT_CLK_Rising
}TIMER0_CLOCK_t;

typedef enum{
	OCIE0_DISABLE,
	OCIE0_Enable = 0x02
}OCMIE0_t;

typedef enum{
	TOIE0_DISABLE,
	TOIE0_Enable = 0x01
}TOVFIE0_t;

//--------------------------------
//Structures
//--------------------------------
typedef struct {
	TIMER0_MODE_t 			Mode;
	TIMER0_CLOCK_t 			Clock;
	TIMER0_CTC_OUTPUT_t 	CTC_Output;
	TIMER0_PWM_OUTPUT_t 	PWM_Output;
	OCMIE0_t 				OCM_Interrupt;
	TOVFIE0_t 				OVF_Interrupt;
}ST_TIMER0_CONFIG_t;


//--------------------------------
//APIS
//--------------------------------
E_STATUS_t TIMER0_Init(ST_TIMER0_CONFIG_t* Config);
E_STATUS_t TIMER0_Stop(void);

E_STATUS_t TIMER0_GetCompareValue(uint8_t* pu8_TicksNumber);
E_STATUS_t TIMER0_SetCompareValue(uint8_t pu8_TicksNumber);

E_STATUS_t TIMER0_GetCounterValue(uint8_t* pu8_TicksNumber);
E_STATUS_t TIMER0_SetCounterValue(uint8_t pu8_TicksNumber);

E_STATUS_t TIMER0_GetOverflowValue(uint8_t* pu8_TicksNumber);
E_STATUS_t TIMER0_SetOverflowValue(uint8_t pu8_TicksNumber);

void TIMER0_CALLBACK_Overflow_INTERRUPT(PTR_VoidFunVoid_t callback);
void TIMER0_CALLBACK_CompareMatch_INTERRUPT(PTR_VoidFunVoid_t callback);


#endif /* TIMER_DRIVER_TIMER_H_ */
