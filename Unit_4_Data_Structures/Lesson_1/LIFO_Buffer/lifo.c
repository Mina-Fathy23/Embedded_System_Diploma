/*
 * lifo.c
 *
 *  Created on: Aug 19, 2024
 *      Author: Mina Fathy
 */

#include "lifo.h"

//APIs
LIFO_status LIFO_Add_Item(LIFO_Buf_t* lifo_buf, uint32 item)
{
	//checking if the LIFO is valid
	if(!lifo_buf->base || !lifo_buf->head)
		return LIFO_NUll;

	//checking if the LIFO is full
	if(lifo_buf->count == lifo_buf->length)
		return LIFO_full;

	//filling the LIFO
	//1.add the new item
	*(lifo_buf->head) = item;

	//2.increment the head pointer
	lifo_buf->head++;

	//3.increment the counter by one
	lifo_buf->count++;
	return LIFO_no_error;
}

LIFO_status LIFO_Get_Item(LIFO_Buf_t* lifo_buf, uint32* item)
{
	//checking if the LIFO is valid
	if(!lifo_buf->base || !lifo_buf->head)
		return LIFO_NUll;

	//checking if the LIFO is empty
	if(lifo_buf->count == 0)
		return LIFO_empty;

	//getting value from LIFO
	//1.decrementing the head pointer
	lifo_buf->head--;

	//2.returning the value
	*item = *(lifo_buf->head);

	//3.decrementing the LIFO counter by one
	lifo_buf->count--;
	return LIFO_no_error;
}

LIFO_status LIFO_Init(LIFO_Buf_t * lifo_buf, uint32* buf, uint32 length)
{
	//checking if the LIFO is valid
	if(buf == NULL)
		return LIFO_NUll;

	//initializing the base & head with the starting address of the passed array
	lifo_buf->base = buf;
	lifo_buf->head = buf;
	//initializing the length with the no. of elements of array
	lifo_buf->length = length;

	lifo_buf->count = 0;
	return LIFO_no_error;

}
