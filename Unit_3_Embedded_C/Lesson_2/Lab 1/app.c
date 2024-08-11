#include "uart.h"

unsigned char string_buffer[100] = "learn-in-depth:Mina Fathy";
unsigned char const string_buffer2[100] = "learn-in-depth:Mina";

void main(void)
{
	Uart_Send_string(string_buffer);
}