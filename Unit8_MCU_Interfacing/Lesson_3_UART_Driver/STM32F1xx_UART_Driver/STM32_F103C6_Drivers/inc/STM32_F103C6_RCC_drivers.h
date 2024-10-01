/*
 * STM32_F103C6_RCC_drivers.h
 *
 *  Created on: Sep 28, 2024
 *      Author: Mina Fathy
 */

#ifndef INC_STM32_F103C6_RCC_DRIVERS_H_
#define INC_STM32_F103C6_RCC_DRIVERS_H_

//----------------------------
//Includes
//----------------------------

#include "STM32F103x6.h"
#include "STM32_F103C6_GPIO_drivers.h"


//----------------------------
//Macros Configuration References
//---------------------------
#define HSI_RC_CLK		(uint32)8000000
#define HSE_CLK			(uint32)16000000
//todo Define PLLMul			//Defined by user



//----------------------------
//APIS
//---------------------------

uint32 MCAL_RCC_GetPLCK1Freq(void);
uint32 MCAL_RCC_GetPLCK2Freq(void);

uint32 MCAL_RCC_GetHCLKFreq(void);
uint32 MCAL_RCC_GetSYSCLKFreq(void);


#endif /* INC_STM32_F103C6_RCC_DRIVERS_H_ */
