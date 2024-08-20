/*
 * main.c
 *
 *  Created on: Aug 19, 2024
 *      Author: Mina Fathy
 */



#include "lifo.h"


uint32 buffer1[5];

int main()
{
	int i, temp = 0;;
	LIFO_Buf_t uart_lifo, I2C_lifo;
	//static allocation
	LIFO_Init(&uart_lifo, buffer1, 5);
	//dynamic allocation
	uint32* buffer2 = (uint32*) malloc(5 * sizeof(uint32));
	LIFO_Init(&I2C_lifo, buffer2, 5);

	for(i = 0; i < 7; i++)
	{
		if(LIFO_Add_Item(&uart_lifo, i) == LIFO_no_error)
		printf("Uart_LIFO add : %d \n", i);
	}
	printf("\n");

	for(i = 0; i < 7; i++)
	{
		if(LIFO_Get_Item(&uart_lifo, (uint32*)&temp) == LIFO_no_error)
		printf("Uart_LIFO get : %d \n", temp);
	}




}
