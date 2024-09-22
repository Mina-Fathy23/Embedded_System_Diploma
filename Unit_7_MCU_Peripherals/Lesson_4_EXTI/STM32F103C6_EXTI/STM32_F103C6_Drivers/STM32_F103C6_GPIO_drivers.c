/*
 * STM32_F103C6_GPIO_drivers.c
 *
 *  Created on: Sep 16, 2024
 *      Author: Mina Fathy
 */
#include "STM32_F103C6_GPIO_drivers.h"

uint8 Get_CRLH_Position(uint16 Pin_Number)
{
	switch (Pin_Number)
	{
	case GPIO_PIN_0:  return 0;  break;
	case GPIO_PIN_1:  return 4;  break;
	case GPIO_PIN_2:  return 8;  break;
	case GPIO_PIN_3:  return 12; break;
	case GPIO_PIN_4:  return 16; break;
	case GPIO_PIN_5:  return 20; break;
	case GPIO_PIN_6:  return 24; break;
	case GPIO_PIN_7:  return 28; break;
	case GPIO_PIN_8:  return 0;  break;
	case GPIO_PIN_9:  return 4;  break;
	case GPIO_PIN_10: return 8;  break;
	case GPIO_PIN_11: return 12; break;
	case GPIO_PIN_12: return 16; break;
	case GPIO_PIN_13: return 20; break;
	case GPIO_PIN_14: return 24; break;
	case GPIO_PIN_15: return 28; break;
	default:		  return 0;  break;
	}
}


/**================================================================
 * @Fn				- MCAL_GPIO_Init
 * @breif			- Initializes GPIOx PinY according to specific parameters in PinConfig
 * @param [in]		- GPIOx: where x can be (A..G depending on device used) to select GPIO peripheral
 * @param [in]		- PinConfig: Pointer to GPIO_PinConfig_t structure that contains
 * 					  the configuration information for the specified GPIO Pin
 * @retval			- None
 * Note				- STM32F103C6 MCU has GPIO A, B, C, D, E Modules
 * 					  But LQFP48 Package has only GPIO A, B, Part of C/D as external PINs
 */
void MCAL_GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_PinConfig_t *PinConfig)
{
	//	Port configuration register low (GPIOx_CRL) Configure pins 0 >> 7
	//	Port configuration register High (GPIOx_CRL) Configure pins 8 >> 15
	vuint32_t *ConfigRegister = NULL;
	vuint8_t PIN_CNF_MODE;

	ConfigRegister = (PinConfig->GPIO_PinNumber < GPIO_PIN_8)? &GPIOx->CRL: &GPIOx->CRH;

	//clear CNFy[1:0] MODEy[1:0]
	(*ConfigRegister) &= ~(0xF << Get_CRLH_Position(PinConfig->GPIO_PinNumber));

	//If Pin is Output
	if( (PinConfig->GPIO_Mode == GPIO_MODE_OUTPUT_PP) || (PinConfig->GPIO_Mode == GPIO_MODE_OUTPUT_OD) || (PinConfig->GPIO_Mode == GPIO_MODE_OUTPUT_AF_PP) || (PinConfig->GPIO_Mode == GPIO_MODE_OUTPUT_AF_OD) )
	{
		//Set CNFy[1:0] MODEy[1:0]
		PIN_CNF_MODE = ( (((PinConfig->GPIO_Mode - 4) << 2) | (PinConfig->GPIO_Output_Speed)) & 0x0F );
	}

	//If Pin is Input
	else // Mode = 00: input Mode (reset value)
	{
		//Set CNFy[1:0] MODEy[1:0]
		if((PinConfig->GPIO_Mode == GPIO_MODE_INPUT_FLO) || (PinConfig->GPIO_Mode == GPIO_MODE_Analog))
		{
			PIN_CNF_MODE = (((PinConfig->GPIO_Mode << 2) | 0x0) & 0x0F);
		}
		else if(PinConfig->GPIO_Mode == GPIO_MODE_AF_INPUT) //Note: AF_INPUT is treated as Floating
		{
			PIN_CNF_MODE = (((GPIO_MODE_INPUT_FLO << 2) | 0x0) & 0x0F);
		}
		else //PU PD Input
		{
			PIN_CNF_MODE = (((PinConfig->GPIO_Mode << 2) | 0x0) & 0x0F);

			if(PinConfig->GPIO_Mode == GPIO_MODE_INPUT_PU)
			{
				//Table 20. Port bit configuration table PxODR -> 1
				GPIOx->ODR |= (1 << PinConfig->GPIO_PinNumber);
			}
			else //PULL down Input
			{
				//Table 20. Port bit configuration table PxODR -> 0
				GPIOx->ODR |= (0 << PinConfig->GPIO_PinNumber);
			}
		}
	}

	//Write on CLR or CRH
	(*ConfigRegister) |= ( PIN_CNF_MODE << Get_CRLH_Position(PinConfig->GPIO_PinNumber) );
}

/**================================================================
 * @Fn				- MCAL_GPIO_DeInit
 * @breif			- Resets All GPIOx Registers
 * @param [in]		- GPIOx: where x can be (A..G depending on device used) to select GPIO peripheral
 * @retval			- None
 * Note				- None
 */
void MCAL_GPIO_DeInit(GPIO_TypeDef *GPIOx)
{
	/*	//Manual Reset of GPIOx
	GPIOx->CRL  = 0x44444444;
	GPIOx->CRH  = 0x44444444;
//	GPIOx->IDR  = (Read Only);
	GPIOx->ODR  = 0x00000000;
	GPIOx->BSRR = 0x00000000;
	GPIOx->BRR  = 0x00000000;
	GPIOx->LCKR = 0x00000000;*/

	//Reset Using Reset Controller (if available)
	//APB@ peripheral reset register (RCC_APB2RSTR)
	if(GPIOx == GPIOA){ SetBit(RCC->APB2RSTR, 2); ClearBit(RCC->APB2RSTR, 2);}		//IO Port A Reset
	else if(GPIOx == GPIOB){ SetBit(RCC->APB2RSTR, 3); ClearBit(RCC->APB2RSTR, 3);}		//IO Port B Reset
	else if(GPIOx == GPIOC){ SetBit(RCC->APB2RSTR, 4); ClearBit(RCC->APB2RSTR, 4);}		//IO Port C Reset
	else if(GPIOx == GPIOD){ SetBit(RCC->APB2RSTR, 5); ClearBit(RCC->APB2RSTR, 5);}		//IO Port D Reset
	else if(GPIOx == GPIOE){ SetBit(RCC->APB2RSTR, 6); ClearBit(RCC->APB2RSTR, 6);}		//IO Port E Reset
}

/**================================================================
 * @Fn				- MCAL_GPIO_ReadPin
 * @breif			- Reads Specific Bit
 * @param [in]		- GPIOx: where x can be (A..G depending on device used) to select GPIO peripheral
 * @param [in]		- PinNumber: Specifies the Pin Number according to @ref GPIO_PIN_define
 * @retval			- the input pin value (two value based on @ref GPIO_PIN_state)
 * Note				- None
 */
uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint16_t PinNumber)
{
	uint8 BitStatus;
	if(((GPIOx->IDR) & PinNumber) != (uint32)GPIO_PIN_RESET)
	{
		BitStatus = GPIO_PIN_SET;
	}
	else // IDR = 0
	{
		BitStatus = GPIO_PIN_RESET;
	}
	return BitStatus;
}

/**================================================================
 * @Fn				- MCAL_GPIO_ReadPort
 * @breif			- Reads Specific Bit
 * @param [in]		- GPIOx: where x can be (A..G depending on device used) to select GPIO peripheral
 * @retval			- the input Port value
 * Note				- None
 */
uint16_t MCAL_GPIO_ReadPort(GPIO_TypeDef *GPIOx)
{
	uint16 PortStatus;
	PortStatus = (uint16)(GPIOx->IDR & GPIO_PIN_All);
	return PortStatus;
}

/**================================================================
 * @Fn				- MCAL_GPIO_WritePin
 * @breif			- Writes value on Specific Pin
 * @param [in]		- GPIOx: where x can be (A..G depending on device used) to select GPIO peripheral
 * @param [in]		- PinNumber: Specifies the Pin Number according to @ref GPIO_PIN_define
 * @param [in]		- Value: the value to write on Pin
 * @retval			- None
 * Note				- None
 */
void MCAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t PinNumber, uint8_t Value)
{
	if(Value != GPIO_PIN_RESET)
	{
		//Writing on ODR Directly
		//GPIOx->ODR |= PinNumber;

		/*//Writing on BSRR to not do OR Operation
			BRy: Port x Reset bit y (y= 0 .. 15)
		 	These bits are write-only and can be accessed in Word mode only.
			0: No action on the corresponding ODRx bit
		 	1: Reset the corresponding ODRx bit
		 	Note: If both BSx and BRx are set, BSx has priority.*/
		GPIOx->BSRR = (uint32)PinNumber;
	}
	else
	{
		//Writing on ODR Directly
		//ClearBit(GPIOx->ODR, PinNumber);

		/*//Writing on BRR to not do OR Operation (Write to clear)
			BRy: Port x Reset bit y (y= 0 .. 15)
		 	These bits are write-only and can be accessed in Word mode only.
			0: No action on the corresponding ODRx bit
		 	1: Reset the corresponding ODRx bit*/
		GPIOx->BRR = (uint32)PinNumber;
	}
}

/**================================================================
 * @Fn				- MCAL_GPIO_WritePort
 * @breif			- Writes value on Specific Port
 * @param [in]		- GPIOx: where x can be (A..G depending on device used) to select GPIO peripheral
 * @param [in]		- Value: the value to write on Pin
 * @retval			- None
 * Note				- None
 */
void MCAL_GPIO_WritePort(GPIO_TypeDef *GPIOx, uint16_t Value)
{
	GPIOx->ODR = (uint32)Value;
}

/**================================================================
 * @Fn				- MCAL_GPIO_TogglePin
 * @breif			- Toggles value on Specific Pin
 * @param [in]		- GPIOx: where x can be (A..G depending on device used) to select GPIO peripheral
 * @param [in]		- PinNumber: Specifies the Pin Number according to @ref GPIO_PINS_define
 * @retval			- None
 * Note				- None
 */
void MCAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint16_t PinNumber)
{
	GPIOx->ODR ^=  PinNumber;
}

/**================================================================
 * @Fn				- MCAL_GPIO_LockPin
 * @breif			- Locks value on Specific Pin
 * @param [in]		- GPIOx: where x can be (A..G depending on device used) to select GPIO peripheral
 * @param [in]		- PinNumber: Specifies the Pin Number according to @ref GPIO_PIN_define
 * @retval			- OK if pin Config is locked or Error if pin not locked
 * 					  (OK & ERROR are defined at @ref GPIO_RETRUN_LOCK
 * Note				- None
 */
uint8_t MCAL_GPIO_LockPin(GPIO_TypeDef *GPIOx, uint16_t PinNumber)
{

	/*Bit 16 LCKK[16]: Lock key
	 	 This bit can be read anytime. It can only be modified using the Lock Key Writing Sequence.
		 0: Port configuration lock key not active
	 	 1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset.

	 	 LOCK key writing sequence:
	 	 Write 1
	 	 Write 0
	 	 Write 1
	 	 Read 0
	 	 Read 1 (this read is optional but confirms that the lock is active)
	 	 Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.
	 	 Any error in the lock sequence will abort the lock.

	 Bits 15:0 LCKy: Port x Lock bit y (y= 0 .. 15)
	 	 These bits are read write but can only be written when the LCKK bit is 0.
		 0: Port configuration not locked
		 1: Port configuration locked.*/

	//SET LCKK[16]
	vuint32_t temp = 1 << 16;

	//SET LCKy
	temp |= PinNumber;

	//LOCK Sequence
	//	Write 1
	GPIOx->LCKR = temp;
	//	Write 0
	GPIOx->LCKR = PinNumber;
	//	Write 1
	GPIOx->LCKR = temp;
	//	Read 0
	temp = GPIOx->LCKR;
	//	Read 1 (this read is optional but confirms that the lock is active)
	if((uint32)(GPIOx->LCKR & (1 << 16)))
	{
		return GPIO_RETRUN_LOCK_Enable;
	}
	else
	{
		return GPIO_RETRUN_LOCK_ERORR;
	}
}
