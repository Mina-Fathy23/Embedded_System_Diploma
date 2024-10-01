/*
 * STM32_F103C6_GPIO_drivers.c
 *
 *  Created on: Sep 18, 2024
 *      Author: Mina Fathy
 */

#include "STM32_F103C6_EXTI_drivers.h"


/*
 * ================================================================
 * 							Generic Variables
 * ================================================================
 *
 * */

void(* GP_IRQ_CallBack[16])(void);

/*
 * ================================================================
 * 							Generic Macros
 * ================================================================
 *
 * */

#define AFIO_GPIO_EXTI_Mapping(x)	((x == GPIOA)? 0:\
									 (x == GPIOB)? 1:\
									 (x == GPIOC)? 2:\
									 (x == GPIOD)? 3:0)

/*
 * ================================================================
 * 					Generic Functions Definition
 * ================================================================
 *
 * */

void Enable_NVIC(uint16 IRQ)
{
	switch(IRQ)
	{
	case 0:
		NVIC_IRQ6_EXTI0_Enable;
		break;
	case 1:
		NVIC_IRQ7_EXTI1_Enable;
		break;
	case 2:
		NVIC_IRQ8_EXTI2_Enable;
		break;
	case 3:
		NVIC_IRQ9_EXTI3_Enable;
		break;
	case 4:
		NVIC_IRQ10_EXTI4_Enable;
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_IRQ23_EXTI5_9_Enable;
		break;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		NVIC_IRQ40_EXTI10_15_Enable;
		break;

	}
}


void Disable_NVIC(uint16 IRQ)
{
	switch(IRQ)
	{
	case 0:
		NVIC_IRQ6_EXTI0_Disable;
		break;
	case 1:
		NVIC_IRQ7_EXTI1_Disable;
		break;
	case 2:
		NVIC_IRQ8_EXTI2_Disable;
		break;
	case 3:
		NVIC_IRQ9_EXTI3_Disable;
		break;
	case 4:
		NVIC_IRQ10_EXTI4_Disable;
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_IRQ23_EXTI5_9_Disable;
		break;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		NVIC_IRQ40_EXTI10_15_Disable;
		break;

	}
}


/**================================================================
 * @Fn				- MCAL_EXTI_GPIO_Upadte
 * @breif			- Initializes EXTI From GPIOx PinY abd specify the MASK/Trigger Condition and IRQ CallBack
 * @param [in]		- EXTI_Config: set by @ref EXTI_define, @ref EXTI_Trigger_define, @ref EXTI_IRQ_define
 * @retval			- None
 * Note				- STM32F103C6 MCU has GPIO A, B, C, D, E Modules
 * 					  But LQFP48 Package has only GPIO A, B, Part of C/D as external PINs
 * 					- Mandatory to enable RCC Clock of AFIO and the corresponding GPIO
 */
void MCAL_EXTI_GPIO_Upadte(EXTI_PinConfig_t *EXTI_Config)
{
	//1- Configure GPIO to be AF input -> Floating Input
	GPIO_PinConfig_t PinCfg;

	PinCfg.GPIO_Mode = GPIO_MODE_AF_INPUT;
	PinCfg.GPIO_PinNumber = EXTI_Config->EXTI_PIN.GPIO_PIN;
	MCAL_GPIO_Init(EXTI_Config->EXTI_PIN.GPIO_PORT, &PinCfg);

	//=================================================================

	//2- Set AF MUX to be EXTI line with PORTx
	uint8 index 	= EXTI_Config->EXTI_PIN.EXTI_InputLineNumber / 4; // 0 -> 3
	uint8 position  = (EXTI_Config->EXTI_PIN.EXTI_InputLineNumber % 4) * 4;
	uint8 value		= AFIO_GPIO_EXTI_Mapping(EXTI_Config->EXTI_PIN.GPIO_PORT) & 0xF;

	//Clearing & Setting Intended half word
	AFIO->EXTICR[index] &= ~(0xF << position);
	AFIO->EXTICR[index] |= (value << position);

	//=================================================================

	//3- open Clock for EXTI
	//3- Set Interrupt Trigger
	EXTI->RTSR &= ~(1 << EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	EXTI->FTSR &= ~(1 << EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);

	if(EXTI_Config->Trigger_Case == EXTI_Trigger_RISING)
	{
		EXTI->RTSR |= (1 << EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	}
	else if(EXTI_Config->Trigger_Case == EXTI_Trigger_FALLING)
	{
		EXTI->FTSR |= (1 << EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	}
	else // EXTI_Trigger_RisingAndFalling
	{
		EXTI->RTSR |= (1 << EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
		EXTI->FTSR |= (1 << EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	}

	//=================================================================

	//4-Set Pointer to Interrupt Handler CallBack
	GP_IRQ_CallBack[EXTI_Config->EXTI_PIN.EXTI_InputLineNumber] = EXTI_Config->P_IRQ_CallBack;


	//=================================================================

	//5- Enable/Disable IRQ (Set NVIC Mask & Set Interrupt Mask)
	if(EXTI_Config->IRQ_EN == EXTI_IRQ_Enable)
	{
		EXTI->IMR |= (1 << EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
		Enable_NVIC(EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	}
	else //(EXTI_Config->IRQ_EN == EXTI_IRQ_Disable)
	{
		EXTI->IMR |= (0 << EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
		Disable_NVIC(EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	}
}

/*
 * ================================================================
 * 					APIs Functions Definition
 * ================================================================
 *
 * */


/**================================================================
 * @Fn				- MCAL_EXTI_GPIO_Init
 * @breif			- Initializes EXTI From GPIOx PinY abd specify the MASK/Trigger Condition and IRQ CallBack
 * @param [in]		- EXTI_Config: set by @ref EXTI_define, @ref EXTI_Trigger_define, @ref EXTI_IRQ_define
 * @retval			- None
 * Note				- STM32F103C6 MCU has GPIO A, B, C, D, E Modules
 * 					  But LQFP48 Package has only GPIO A, B, Part of C/D as external PINs
 * 					- Mandatory to enable RCC Clock of AFIO and the corresponding GPIO
 */
void MCAL_EXTI_GPIO_Init(EXTI_PinConfig_t *EXTI_Config)
{
	MCAL_EXTI_GPIO_Upadte(EXTI_Config);
}

/**================================================================
 * @Fn				- MCAL_EXTI_GPIO_DeInit
 * @breif			- Reset EXTI Register and NVIC corresponding IRQ MASK
 * @param [in]		- None
 * @retval			- None
 * Note				-
 */
void MCAL_EXTI_GPIO_DeInit(void)
{
	EXTI->IMR 	=  0x00000000;
	EXTI->EMR 	=  0x00000000;
	EXTI->RTSR 	=  0x00000000;
	EXTI->FTSR 	=  0x00000000;
	EXTI->SWIER =  0x00000000;

	//cleared by writing a ‘1’ into the bit.
	EXTI->PR	=  0xFFFFFFFF;

	//Disable EXTI IRQ from NVIC
	NVIC_IRQ6_EXTI0_Disable		;
	NVIC_IRQ7_EXTI1_Disable		;
	NVIC_IRQ8_EXTI2_Disable		;
	NVIC_IRQ9_EXTI3_Disable		;
	NVIC_IRQ10_EXTI4_Disable	;
	NVIC_IRQ23_EXTI5_9_Disable	;
	NVIC_IRQ40_EXTI10_15_Disable;
}


/*
 * ================================================================
 * 					ISR Functions Definition
 * ================================================================
 *
 * */


void EXTI0_IRQHandler(void)
{
	//	This bit is cleared by writing a ‘1’ into the bit.
	EXTI->PR |= (1 << 0);
	GP_IRQ_CallBack[0]();
}

void EXTI1_IRQHandler(void)
{
	//	This bit is cleared by writing a ‘1’ into the bit.
	EXTI->PR |= (1 << 1);
	GP_IRQ_CallBack[1]();
}

void EXTI2_IRQHandler(void)
{
	//	This bit is cleared by writing a ‘1’ into the bit.
	EXTI->PR |= (1 << 2);
	GP_IRQ_CallBack[2]();
}

void EXTI3_IRQHandler(void)
{
	//	This bit is cleared by writing a ‘1’ into the bit.
	EXTI->PR |= (1 << 3);
	GP_IRQ_CallBack[3]();
}

void EXTI4_IRQHandler(void)
{
	//	This bit is cleared by writing a ‘1’ into the bit.
	EXTI->PR |= (1 << 4);
	GP_IRQ_CallBack[4]();
}

void EXTI9_5_IRQHandler(void)
{
		 if(EXTI->PR & (1 << 5))	{	EXTI->PR |= (1 << 5)	;GP_IRQ_CallBack[5]();	}
	else if(EXTI->PR & (1 << 6))	{	EXTI->PR |= (1 << 6)	;GP_IRQ_CallBack[6]();	}
	else if(EXTI->PR & (1 << 7))	{	EXTI->PR |= (1 << 7)	;GP_IRQ_CallBack[7]();	}
	else if(EXTI->PR & (1 << 8))	{	EXTI->PR |= (1 << 8)	;GP_IRQ_CallBack[8]();	}
	else if(EXTI->PR & (1 << 9))	{	EXTI->PR |= (1 << 9)	;GP_IRQ_CallBack[9]();	}

}

void EXTI15_10_IRQHandler(void)
{
		 if(EXTI->PR & (1 << 10))	{	EXTI->PR |= (1 << 10)	;GP_IRQ_CallBack[10]();	}
	else if(EXTI->PR & (1 << 11))	{	EXTI->PR |= (1 << 11)	;GP_IRQ_CallBack[11]();	}
	else if(EXTI->PR & (1 << 12))	{	EXTI->PR |= (1 << 12)	;GP_IRQ_CallBack[12]();	}
	else if(EXTI->PR & (1 << 13))	{	EXTI->PR |= (1 << 13)	;GP_IRQ_CallBack[13]();	}
	else if(EXTI->PR & (1 << 14))	{	EXTI->PR |= (1 << 14)	;GP_IRQ_CallBack[14]();	}
	else if(EXTI->PR & (1 << 15))	{	EXTI->PR |= (1 << 15)	;GP_IRQ_CallBack[15]();	}
}



