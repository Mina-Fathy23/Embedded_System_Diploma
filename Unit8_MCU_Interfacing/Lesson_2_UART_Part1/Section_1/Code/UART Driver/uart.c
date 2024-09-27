/*
 * uart.c
 *
 *  Created on: Sep 25, 2024
 *      Author:	Mina Fathy
 */


#include "../UART Driver/uart.h"



static uint8 *TX_str;
static uint8 flag_send = 1;

void UART_Init(void)
{
	//frame
	//No parity (reset value)

	//Set Character size to 8 bits
	UCSRC |= (1 << 1);
	UCSRC |= (1 << 2);
	UCSRB &= ~(1 << 2);


	//Set buad rate to 9600 and Normal mode
	UBRRL = 51;
	UCSRA &= ~(1 << 1);

	//Enable TX and RX
	UCSRB |= (1 << 3);
	UCSRB |= (1 << 4);
}

void UART_Send(uint8 data)
{
	while(!GetBit(UCSRA, UDRE)); //Do nothing while Buffer in Full (contains unsent data)
	UDR = data;
}

uint8 UART_Receive(void)
{
	while(!GetBit(UCSRA, RXC)); //Do nothing while Buffer contains unread data
	return UDR;
}

void UART_SendString(uint8 * str)
{
	uint8 i;
	for(i = 0; str[i] != '\0'; i++)
	{
		UART_Send(str[i]);
	}
	UART_Send(DefaultStop);
}

void UART_ReceiveString(uint8 * Buff)
{
	uint8 i = 0;
	Buff[i] = UART_Receive();
	while(Buff[i] != DefaultStop)
	{
		i++;
		Buff[i] = UART_Receive();
	}

	Buff[i] = '\0';
}


