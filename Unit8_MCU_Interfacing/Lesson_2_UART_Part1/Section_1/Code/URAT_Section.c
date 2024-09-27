/*
 * URAT_Section.c
 *
 *  Created on: Sep 25, 2024
 *      Author:	Mina Fathy
 */

#include <avr/io.h>
#include <util/delay.h>
#include "../LIB/Platform_Types.h"
#include "../UART Driver/uart.h"
#include "../LCD Driver/LCD.h"


uint8 data;
uint8 str[100];

int main(void)
{
	LCD_INIT();
	UART_Init();

	uint8 x = 0;
	uint8 i = 9;


	LCD_WRITE_STRING("Sending: Mina");


	UART_SendString("Mina");

	while(1)
	{

		UART_ReceiveString(str);
		LCD_WRITE_STRING(str);
	}



return 0;
}
