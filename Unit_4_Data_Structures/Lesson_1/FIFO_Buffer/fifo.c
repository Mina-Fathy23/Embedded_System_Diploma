/*
 * fifo.c
 *
 *  Created on: Aug 20, 2024
 *      Author: Mina Fathy
 */


#include "fifo.h"

//initializes FIFO Buffer by setting head & base & tail pointers , sets length and count
FIFO_status FIFO_init(FIFO_buff_t* fifo_buf,element_type* buff,uint32 length)
{
	//buffer is valid? used for memory allocation
	if(buff == NULL)
		return FIFO_NULL;

	fifo_buf->base = buff;
	fifo_buf->head = buff;
	fifo_buf->tail = buff;
	fifo_buf->length = length;
	fifo_buf->count = 0;

	return FIFO_no_error;
}

//add item to FIFO
FIFO_status FIFO_enqueue(FIFO_buff_t* fifo_buf,element_type item)
{
	//FIFO is initialized?
	if(!fifo_buf->base ||!fifo_buf->head || !fifo_buf->tail)
		return FIFO_NULL;

	//FIFO is full?
	if(FIFO_is_full(fifo_buf) == FIFO_full)
		return FIFO_full;

	*(fifo_buf->head) = item;

	//Circular FIFO
	if(fifo_buf->head == fifo_buf->base + (fifo_buf->length * sizeof(element_type)))
		fifo_buf->head = fifo_buf->base;
	else
		fifo_buf->head++;

	fifo_buf->count++;

	return FIFO_no_error;
}

//Pops items from FIFO
FIFO_status FIFO_dequeue(FIFO_buff_t* fifo_buf,element_type* item)
{
	//FIFO is initialized?
	if(!fifo_buf->base ||!fifo_buf->head || !fifo_buf->tail)
		return FIFO_NULL;

	//FIFO is empty?
	if(fifo_buf->head == fifo_buf->tail)
		return FIFO_empty;

	//item dequeue
	*item = *(fifo_buf->tail);

	//Circular FIFO
	if(fifo_buf->tail == fifo_buf->base + (fifo_buf->length * sizeof(element_type)))
		fifo_buf->tail = fifo_buf->base;
	else
		fifo_buf->tail++;

	fifo_buf->count--;

	return FIFO_no_error;
}

//Checks if FIFO is full
FIFO_status FIFO_is_full(FIFO_buff_t* fifo_buf)
{
	//FIFO is initialized?
	if(!fifo_buf->base ||!fifo_buf->head || !fifo_buf->tail)
		return FIFO_NULL;

	//FIFO is full?
	if(fifo_buf->count == fifo_buf->length)
		return FIFO_full;

	return FIFO_no_error;
}

//Prints all values in FIFO without changing its values
void FIFO_print(FIFO_buff_t* fifo_buf)
{
	element_type* temp;
	if(fifo_buf->count == 0)
	{
		printf("FIFO is empty");
	}
	else
	{
		temp = fifo_buf->tail;
		printf("\n ======FIFO_Print======\n");
		while(temp != fifo_buf->head)
		{
			printf("\t %X\n", *temp);
			temp++;
		}
		printf("========================\n");
	}
}
