/*
 * STM32_F103C6_USART_drivers.c
 *
 *  Created on: Sep 28, 2024
 *      Author: Mina Fathy
 */


#include "STM32_F103C6_USART_drivers.h"

/*
 * ================================================================
 * 							Generic Variables
 * ================================================================
 *
 * */
UART_PinConfig_t *GP_USART1_Config = NULL;
UART_PinConfig_t *GP_USART2_Config = NULL;
UART_PinConfig_t *GP_USART3_Config = NULL;

/*
 * ================================================================
 * 					API Functions Definition
 * ================================================================
 *
 * */

void MCAL_UART_Init(USART_TypedDef *UARTx, UART_PinConfig_t *UART_Config)
{

	uint32 pclk, BRR;

	//Save Config data & Enable Clock
	if(UARTx == USART1)
	{
		GP_USART1_Config = UART_Config;
		RCC_USART1_CLK_EN();
	}
	else if(UARTx == USART2)
	{
		GP_USART2_Config = UART_Config;
		RCC_USART2_CLK_EN();
	}
	else if(UARTx == USART3)
	{
		GP_USART3_Config = UART_Config;
		RCC_USART3_CLK_EN();
	}

	//Enable UART Module
	UARTx->CR1 = (1 << 13);  		//Bit 13 UE: USART enable

	//Enable TX and RX
	UARTx->CR1 |= UART_Config->Mode;

	//Payload width
	UARTx->CR1 |= UART_Config->Payload_Length;

	//Stop bits
	UARTx->CR2 |= UART_Config->StopBit;

	//Parity Mode
	UARTx->CR1 |= UART_Config->Parity;

	//Flow Control
	UARTx->CR3 |= UART_Config->Hw_FlowCtl;

	//Baud rate
	if(UARTx == USART1)
	{
		pclk = MCAL_RCC_GetPLCK1Freq();
	}
	else //(UARTx == USART2 or USART3)
	{
		pclk = MCAL_RCC_GetPLCK2Freq();
	}

	BRR = UART_BRR_Register(pclk, UART_Config->BaudRate);

	UARTx->BRR = BRR;

	//Enable/Disable Interrupt
	if(UART_Config->IRQ_Enable != USART_IRQ_Enable_NONE)
	{
		UARTx->CR1 |= UART_Config->IRQ_Enable;

		//Enable NVIC FOR UART IRQ
		if(UARTx == USART1)
			NVIC_IRQ37_USART1_Enable;

		else if(UARTx == USART2)
			NVIC_IRQ38_USART2_Enable;

		else if(UARTx == USART3)
			NVIC_IRQ39_USART3_Enable;
	}
}


void MCAL_UART_DeInit(USART_TypedDef *UARTx)
{
	//Disable Clk & Interrupt IRQ
	if(UARTx == USART1)
	{
		RCC_USART1_CLK_EN();
		NVIC_IRQ37_USART1_Disable;
	}
	else if(UARTx == USART2)
	{
		RCC_USART2_CLK_EN();
		NVIC_IRQ38_USART2_Disable;
	}
	else if(UARTx == USART3)
	{
		RCC_USART3_CLK_EN();
		NVIC_IRQ39_USART3_Disable;
	}
}

//According to 9.1.11 GPIO configurations for device peripherals: Table 24. USARTs
void MCAL_UART_GPIO_Set_Pins(USART_TypedDef *UARTx)
{
	GPIO_PinConfig_t PinCfg;

	if(UARTx == USART1)
	{
		//PA9  		USART1_TX
		//PA10  	USART1_RX
		//PA11		USART1_CTS
		//PA12  	USART1_RTS

		PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP;
		PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
		PinCfg.GPIO_PinNumber = GPIO_PIN_9;
		MCAL_GPIO_Init(GPIOA, &PinCfg);

		PinCfg.GPIO_Mode = GPIO_MODE_INPUT_FLO;
		PinCfg.GPIO_PinNumber = GPIO_PIN_10;
		MCAL_GPIO_Init(GPIOA, &PinCfg);

		if(GP_USART1_Config->Hw_FlowCtl == USART_Hw_FlowCtl_CTS || GP_USART1_Config->Hw_FlowCtl == USART_Hw_FlowCtl_CTS_RTS)
		{
			PinCfg.GPIO_Mode = GPIO_MODE_INPUT_FLO;
			PinCfg.GPIO_PinNumber = GPIO_PIN_11;
			MCAL_GPIO_Init(GPIOA, &PinCfg);
		}

		if(GP_USART1_Config->Hw_FlowCtl == USART_Hw_FlowCtl_RTS || GP_USART1_Config->Hw_FlowCtl == USART_Hw_FlowCtl_CTS_RTS)
		{
			PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
			PinCfg.GPIO_PinNumber = GPIO_PIN_12;
			MCAL_GPIO_Init(GPIOA, &PinCfg);
		}

	}
	else if(UARTx == USART2)
	{
		//PA0-WKUP  	USART2_TX
		//PA1  			USART2_RX
		//PA12			USART2_CTS
		//PA13  		USART2_RTS

		PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP;
		PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
		PinCfg.GPIO_PinNumber = GPIO_PIN_0;
		MCAL_GPIO_Init(GPIOA, &PinCfg);

		PinCfg.GPIO_Mode = GPIO_MODE_INPUT_FLO;
		PinCfg.GPIO_PinNumber = GPIO_PIN_1;
		MCAL_GPIO_Init(GPIOA, &PinCfg);

		if(GP_USART2_Config->Hw_FlowCtl == USART_Hw_FlowCtl_CTS || GP_USART2_Config->Hw_FlowCtl == USART_Hw_FlowCtl_CTS_RTS)
		{
			PinCfg.GPIO_Mode = GPIO_MODE_INPUT_FLO;
			PinCfg.GPIO_PinNumber = GPIO_PIN_2;
			MCAL_GPIO_Init(GPIOA, &PinCfg);
		}

		if(GP_USART2_Config->Hw_FlowCtl == USART_Hw_FlowCtl_RTS || GP_USART2_Config->Hw_FlowCtl == USART_Hw_FlowCtl_CTS_RTS)
		{
			PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
			PinCfg.GPIO_PinNumber = GPIO_PIN_3;
			MCAL_GPIO_Init(GPIOA, &PinCfg);
		}
	}
	else if(UARTx == USART3)
	{
		//PB10  		USART2_TX
		//PB11 			USART2_RX
		//PB12			USART2_CTS
		//PB13	 		USART2_RTS

		PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP;
		PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
		PinCfg.GPIO_PinNumber = GPIO_PIN_10;
		MCAL_GPIO_Init(GPIOB, &PinCfg);

		PinCfg.GPIO_Mode = GPIO_MODE_INPUT_FLO;
		PinCfg.GPIO_PinNumber = GPIO_PIN_11;
		MCAL_GPIO_Init(GPIOB, &PinCfg);

		if(GP_USART3_Config->Hw_FlowCtl == USART_Hw_FlowCtl_CTS || GP_USART3_Config->Hw_FlowCtl == USART_Hw_FlowCtl_CTS_RTS)
		{
			PinCfg.GPIO_Mode = GPIO_MODE_INPUT_FLO;
			PinCfg.GPIO_PinNumber = GPIO_PIN_12;
			MCAL_GPIO_Init(GPIOB, &PinCfg);
		}

		if(GP_USART3_Config->Hw_FlowCtl == USART_Hw_FlowCtl_RTS || GP_USART3_Config->Hw_FlowCtl == USART_Hw_FlowCtl_CTS_RTS)
		{
			PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
			PinCfg.GPIO_PinNumber = GPIO_PIN_13;
			MCAL_GPIO_Init(GPIOB, &PinCfg);
		}
	}
}


void MCAL_UART_SendData(USART_TypedDef *UARTx, uint16 *pTxBuffer, enum Polling_mechnism PollingEN)
{
	//wait until TXE Flag is set in USART_SR
	if(PollingEN == enable)
	{
		while( ! (UARTx->SR & (1 << 7) ) );
	}

	//Note:
	//	When transmitting with the parity enabled (PCE bit set to 1 in the USART_CR1 register),
	//	the value written in the MSB (bit 7 or bit 8 depending on the data length) has no effect
	//	because it is replaced by the parity.
	//	 When receiving with the parity enabled, the value read in the MSB bit is the received parity
	//	bit.

	//check whether Pay load is set on 8Bit or 9Bit
	if(UARTx == USART1)
	{
		if(GP_USART1_Config->Payload_Length == USART_Payload_Length_9B)
			UARTx->DR = (*pTxBuffer & (uint16)0x1FF);

		else // USART_Payload_Length_8B)
			UARTx->DR = (*pTxBuffer & (uint8)0xFF);
	}
	else if(UARTx == USART2)
	{
		if(GP_USART2_Config->Payload_Length == USART_Payload_Length_9B)
			UARTx->DR = (*pTxBuffer & (uint16)0x1FF);

		else // USART_Payload_Length_8B)
			UARTx->DR = (*pTxBuffer & (uint8)0xFF);
	}
	else if(UARTx == USART3)
	{
		if(GP_USART3_Config->Payload_Length == USART_Payload_Length_9B)
			UARTx->DR = (*pTxBuffer & (uint16)0x1FF);

		else // USART_Payload_Length_8B)
			UARTx->DR = (*pTxBuffer & (uint8)0xFF);
	}

}

void MCAL_UART_WAIT_TC(USART_TypedDef *UARTx)
{
	//Wait until TC Flag is SET
	while( ! (UARTx->SR & (1 << 6) ) );
}


void MCAL_UART_RecieveData(USART_TypedDef *UARTx, uint16 *pTxBuffer, enum Polling_mechnism PollingEN)
{
	//Wait until Data is Received
	if(PollingEN == enable)
		while(! (UARTx->SR & (1 << 5) ));


	//check whether Payload is set on 8Bit or 9Bit
	if(UARTx == USART1)
	{
		if(GP_USART1_Config->Payload_Length == USART_Payload_Length_9B)
		{

			if(GP_USART1_Config->Parity == USART_Parity_NONE)
			{
				//No Parity so all 9 bits are considered Data
				*( (uint16*)pTxBuffer ) = UARTx->DR;
			}
			else
			{
				//Parity is Used, so only first 8 bits are considered Data and MSB is Parity
				*( (uint16*)pTxBuffer ) = (UARTx->DR & (uint8)0xFF);
			}
		}
		else // USART_Payload_Length_8B)
		{
			if(GP_USART1_Config->Parity == USART_Parity_NONE)
			{
				//No Parity so all 8 bits are considered Data
				*( (uint16*)pTxBuffer ) = (UARTx->DR & (uint8)0xFF);
			}
			else
			{
				//Parity is Used, so only first 7 bits are considered Data and MSB is Parity
				*( (uint16*)pTxBuffer ) = (UARTx->DR & (uint8)0x7F);
			}
		}
	}
	else if(UARTx == USART2)
	{
		if(GP_USART2_Config->Payload_Length == USART_Payload_Length_9B)
		{

			if(GP_USART2_Config->Parity == USART_Parity_NONE)
			{
				//No Parity so all 9 bits are considered Data
				*( (uint16*)pTxBuffer ) = UARTx->DR;
			}
			else
			{
				//Parity is Used, so only first 8 bits are considered Data and MSB is Parity
				*( (uint16*)pTxBuffer ) = (UARTx->DR & (uint8)0xFF);
			}
		}
		else // USART_Payload_Length_8B)
		{
			if(GP_USART2_Config->Parity == USART_Parity_NONE)
			{
				//No Parity so all 8 bits are considered Data
				*( (uint16*)pTxBuffer ) = (UARTx->DR & (uint8)0xFF);
			}
			else
			{
				//Parity is Used, so only first 7 bits are considered Data and MSB is Parity
				*( (uint16*)pTxBuffer ) = (UARTx->DR & (uint8)0x7F);
			}
		}
	}
	else if(UARTx == USART3)
	{
		if(GP_USART3_Config->Payload_Length == USART_Payload_Length_9B)
		{

			if(GP_USART3_Config->Parity == USART_Parity_NONE)
			{
				//No Parity so all 9 bits are considered Data
				*( (uint16*)pTxBuffer ) = UARTx->DR;
			}
			else
			{
				//Parity is Used, so only first 8 bits are considered Data and MSB is Parity
				*( (uint16*)pTxBuffer ) = (UARTx->DR & (uint8)0xFF);
			}
		}
		else // USART_Payload_Length_8B)
		{
			if(GP_USART3_Config->Parity == USART_Parity_NONE)
			{
				//No Parity so all 8 bits are considered Data
				*( (uint16*)pTxBuffer ) = (UARTx->DR & (uint8)0xFF);
			}
			else
			{
				//Parity is Used, so only first 7 bits are considered Data and MSB is Parity
				*( (uint16*)pTxBuffer ) = (UARTx->DR & (uint8)0x7F);
			}
		}
	}
}

//ISR
void USART1_IRQHandler(void)
{
	GP_USART1_Config->P_IRQ_CallBack();
}

void USART2_IRQHandler(void)
{
	GP_USART2_Config->P_IRQ_CallBack();
}

void USART3_IRQHandler(void)
{
	GP_USART3_Config->P_IRQ_CallBack();
}

