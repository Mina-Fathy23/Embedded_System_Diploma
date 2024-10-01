/*
 * STM32_F103C6_USART_drivers.h
 *
 *  Created on: Sep 28, 2024
 *      Author: Mina Fathy
 */

#ifndef INC_STM32_F103C6_USART_DRIVERS_H_
#define INC_STM32_F103C6_USART_DRIVERS_H_

//----------------------------
//Includes
//----------------------------
#include "STM32F103x6.h"
#include "STM32_F103C6_GPIO_drivers.h"
#include "STM32_F103C6_RCC_drivers.h"



//----------------------------
//User type definitions (structures)
//----------------------------

typedef struct
{
	uint8 	Mode;					//Specifies the USART TX/RX Enable/Disable
									//This Parameter must be passed on @ref USART_MODE_Define

	uint32 BaudRate;				//Specifies The Baud rate
									//This Parameter must be passed on @ref USART_BaudRate_Define

	uint8 Payload_Length;			//Specifies the size of data payload
									//This Parameter must be passed on @ref USART_Payload_Length_Define

	uint8 Parity;					//Specifies the Parity characteristics of Frame
									//This Parameter must be passed on @ref USART_Parity_Define

	uint8 StopBit;					//Specifies the Size of Stop bit of Frame
									//This Parameter must be passed on @ref USART_StopBit_Define

	uint8 Hw_FlowCtl;				//Specifies the CTS/RTS Enable/Disable
									//This Parameter must be passed on @ref USART_Hw_FlowCtl_Define

	uint8 IRQ_Enable;				//Enable/Disable UART IRQ TX/RX
									//This Parameter must be passed on @ref USART_IRQ_Enable_Define
									//Two or Three Parameters can be chosen

	void(* P_IRQ_CallBack)(void);

}UART_PinConfig_t;

enum Polling_mechnism {
	enable,
	disable
};


//----------------------------
//Macros Configuration References
//---------------------------

//@ref USART_MODE_Define
#define USART_MODE_TX					(uint32)(1 << 3)	// Bit 3 TE: Transmitter enable
#define USART_MODE_RX					(uint32)(1 << 2)	// Bit 2 RE: Receiver enable
#define USART_MODE_TX_RX				(uint32)((1 << 3) | (1 << 2))


//@ref USART_BaudRate_Define
#define USART_BaudRate_2400				2400
#define USART_BaudRate_9600				9600
#define USART_BaudRate_19200			19200
#define USART_BaudRate_57600			57600
#define USART_BaudRate_115200			115200
#define USART_BaudRate_230400			230400
#define USART_BaudRate_460800			460800
#define USART_BaudRate_921600			921600
#define USART_BaudRate_2250000			2250000
#define USART_BaudRate_4500000			4500000


//@ref USART_Payload_Length_Define
#define USART_Payload_Length_8B			(uint32)(0 << 12)
#define USART_Payload_Length_9B			(uint32)(1 << 12)


//@ref USART_Parity_Define
#define USART_Parity_NONE				(uint32)( 0 << 10)
#define USART_Parity_EVEN				(uint32)( 1 << 10)
#define USART_Parity_ODD				(uint32)((1 << 10) | (1 << 9))


//@ref USART_StopBit_Define
#define USART_StopBit_1					(uint32)(0)
#define USART_StopBit_half				(uint32)(0b01 << 12) //Note: The 0.5 Stop bit is not available for UART4 & UART5.
#define USART_StopBit_1_half			(uint32)(0b11 << 12) //Note: The 1.5 Stop bit is not available for UART4 & UART5.
#define USART_StopBit_2					(uint32)(0b10 << 12)


//@ref USART_Hw_FlowCtl_Define
#define USART_Hw_FlowCtl_NONE			(uint32)( 0)
#define USART_Hw_FlowCtl_CTS			(uint32)( 1 << 9)	//Bit 9 CTSE: CTS enable
#define USART_Hw_FlowCtl_RTS			(uint32)( 1 << 8)	//Bit 8 RTSE: RTS enable
#define USART_Hw_FlowCtl_CTS_RTS		(uint32)((1 << 9) | (1 << 8))


//@ref USART_IRQ_Enable_Define
#define USART_IRQ_Enable_NONE		(uint32)(0)
#define USART_IRQ_Enable_TXEIE		(uint32)(1 << 7)	//Transmit data register empty
#define USART_IRQ_Enable_TCIE		(uint32)(1 << 6)	//Transmission complete
#define USART_IRQ_Enable_RXNEIE		(uint32)(1 << 5)	//Received data ready to be read and Overrun error detected
#define USART_IRQ_Enable_PEIE		(uint32)(1 << 8)	//Parity error


//===============================================
//Baud Rate Calculations
//===============================================

//USARTDIV = fclk/ (16 * Baudrate)
// USARTDIV_MUL100=
// uint32((100 *fclk) / (16 * Baudrate) == (25 *fclk)/ (4* Baudrate))
// DIV_Mantissa_MUL100 = Integer Part (USARTDIV  )  * 100
// DIV_Mantissa= Integer Part (USARTDIV  )
// DIV_Fraction= (( USARTDIV_MUL100-DIV_Mantissa_MUL100 ) * 16 ) / 100

#define USARTDIV(_PCLK_, _BAUD_)			(uint32_t)(_PCLK_/(16 * _BAUD_ ))
#define USARTDIV_MUL100(_PCLK_, _BAUD_)		(uint32_t)( (25 * _PCLK_) / (4 * _BAUD_ ))
#define Mantissa_MUL100(_PCLK_, _BAUD_)		(uint32_t)(USARTDIV(_PCLK_, _BAUD_) * 100)
#define Mantissa(_PCLK_, _BAUD_)			(uint32_t)USARTDIV(_PCLK_, _BAUD_)
#define DIV_Fraction(_PCLK_, _BAUD_)		(uint32_t)(((USARTDIV_MUL100(_PCLK_, _BAUD_) - Mantissa_MUL100(_PCLK_, _BAUD_)) * 16) / 100)
#define UART_BRR_Register(_PCLK_, _BAUD_)	(( Mantissa(_PCLK_, _BAUD_) ) << 4) | ((DIV_Fraction(_PCLK_, _BAUD_)) &0xF )


//===============================================
// APIs Supported by "MCAL GPIO DRIVER"
//===============================================

void MCAL_UART_Init(USART_TypedDef *UARTx, UART_PinConfig_t *UART_Config);
void MCAL_UART_DeInit(USART_TypedDef *UARTx);

void MCAL_UART_GPIO_Set_Pins(USART_TypedDef *UARTx);

void MCAL_UART_SendData(USART_TypedDef *UARTx, uint16 *pTxBuffer, enum Polling_mechnism PollingEN);
void MCAL_UART_RecieveData(USART_TypedDef *UARTx, uint16 *pTxBuffer, enum Polling_mechnism PollingEN);

void MCAL_UART_WAIT_TC(USART_TypedDef *UARTx);

//todo MCAL_USART_LIN_Init()		//LIN
//todo MCAL_USART_Init()			//Synchronous
//todo MCAL_USART_DMA_Init()		//Multibuffer Communication

#endif /* INC_STM32_F103C6_USART_DRIVERS_H_ */
