/*
 * fifo.h
 *
 *  Created on: Aug 20, 2024
 *      Author: Mina Fathy
 */

#ifndef FIFO_H_
#define FIFO_H_

#include "Platform_Types.h"
#include "stdio.h"

//USER Configuration
//select the element type (uint8, uint16, uint32, ...)
#define element_type uint8

//create buffer 1
#define width 5
element_type buffer[width];

typedef struct {
	uint32 count;
	uint32 length;
	element_type* base;
	element_type* head;
	element_type* tail;
} FIFO_buff_t;

typedef enum {
	FIFO_no_error,
	FIFO_full,
	FIFO_empty,
	FIFO_NULL
}FIFO_status;

//FIFO APIs
FIFO_status FIFO_init(FIFO_buff_t* fifo_buf,element_type* buff,uint32 length);
FIFO_status FIFO_enqueue(FIFO_buff_t* fifo_buf,element_type item);
FIFO_status FIFO_dequeue(FIFO_buff_t* fifo_buf,element_type* item);
FIFO_status FIFO_is_full(FIFO_buff_t* fifo_buf);
void FIFO_print(FIFO_buff_t* fifo_buf);

#endif /* FIFO_H_ */
