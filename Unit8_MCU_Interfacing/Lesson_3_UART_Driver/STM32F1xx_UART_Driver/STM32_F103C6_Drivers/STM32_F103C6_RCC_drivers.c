/*
 * STM32_F103C6_RCC_drivers.c
 *
 *  Created on: Sep 28, 2024
 *      Author: Mina Fathy
 */

#include "STM32_F103C6_RCC_drivers.h"


// Bits 10:8 PPRE1:  APB low-speed prescaler  (APB1)
// Bits 13:11 PPRE2: APB high-speed prescaler (APB2)
// Set and cleared by software to control the division factor of the APB clock
//(PCLK2) or (PCLK1).
// 0xx: HCLK not divided
// 100: HCLK divided by 2
// 101: HCLK divided by 4
// 110: HCLK divided by 8
// 111: HCLK divided by 16


const uint8 APB_PrescTable[8]  = {0, 0, 0, 0, 1, 2 ,3 ,4}; //Shift 1 right == division by 2

// Bits 7:4HPRE: AHB prescaler
// Set and cleared by software to control the division factor of the AHB clock.
// 0xxx: SYSCLK not divided
// 1000: SYSCLK divided by 2
// 1001: SYSCLK divided by 4
// 1010: SYSCLK divided by 8
// 1011: SYSCLK divided by 16
// 1100: SYSCLK divided by 64
// 1101: SYSCLK divided by 128
// 1110: SYSCLK divided by 256
// 1111: SYSCLK divided by 512

const uint8 AHB_PrescTable[16] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 6, 7, 8, 9};

uint32 MCAL_RCC_GetSYSCLKFreq(void)
{
//	 Bits 3:2 SWS: System clock switch status
//	 Set and cleared by hardware to indicate which clock source is used as system clock.
//	 00: HSI oscillator used as system clock
//	 01: HSE oscillator used as system clock
//	 10: PLL used as system clock

	switch((RCC->CFGR >> 2) & 0b11)
	{
	case 0:

		return HSI_RC_CLK;
		break;

	case 1:

		//Todo need to calculate it //HSE user should specify it
		return HSE_CLK;
		break;

	case 2:

		//Todo need to calculate it //PLLMul user should specify it
		return 16000000;
		break;
	}

	return HSI_RC_CLK;
}

uint32 MCAL_RCC_GetHCLKFreq(void)
{
	// Bits 7:4HPRE: AHB prescaler
	return (MCAL_RCC_GetSYSCLKFreq() >> AHB_PrescTable[(RCC->CFGR >> 4) & 0xF]);
}


uint32 MCAL_RCC_GetPLCK1Freq(void)
{
	// Bits 10:8 PPRE1:  APB low-speed prescaler  (APB1)
	return (MCAL_RCC_GetHCLKFreq() >> APB_PrescTable[(RCC->CFGR >> 8) & 0b111]);
}

uint32 MCAL_RCC_GetPLCK2Freq(void)
{
	// Bits 13:11 PPRE2: APB high-speed prescaler (APB2)
	return (MCAL_RCC_GetHCLKFreq() >> APB_PrescTable[(RCC->CFGR >> 11) & 0b111]);
}
