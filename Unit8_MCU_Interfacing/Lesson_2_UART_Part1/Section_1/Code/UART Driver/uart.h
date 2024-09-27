/*
 * uart.h
 *
 *  Created on: Sep 25, 2024
 *      Author:	Mina Fathy
 */

#ifndef UART_DRIVER_UART_H_
#define UART_DRIVER_UART_H_


#include <avr/io.h>
#include <avr/iom32.h>
#include <util/delay.h>
#include "../LIB/Platform_Types.h"
#include "../LIB/Utils.h"

#define DefaultStop	'\r'



void UART_Init(void);

uint8 UART_Receive(void);
void UART_Send(uint8 data);

void UART_SendString(uint8 * str);
void UART_ReceiveString(uint8 * Buff);



#endif /* UART_DRIVER_UART_H_ */
