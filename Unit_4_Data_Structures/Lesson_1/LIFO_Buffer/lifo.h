/*
 * lifo.h
 *
 *  Created on: Aug 19, 2024
 *      Author: Mina Fathy
 *
 *  !! Constrains !!
 *
 *  ALL DATA IN LIFO IS STORED AS UNSIGNED INTEGERS... CAN'T STORE BYTE BY BYTE
 */

#ifndef LIFO_H_
#define LIFO_H_


#include "Platform_Types.h"
#include "stdio.h"
#include "stdlib.h"


//type definitions

typedef struct LIFO_Buf {
	uint32 length;
	uint32 count;
	uint32* base;
	uint32* head;
}LIFO_Buf_t;

typedef enum {
	LIFO_no_error,
	LIFO_full,
	LIFO_empty,
	LIFO_NUll //LIFO doesn't exist

}LIFO_status;

//APIs
LIFO_status LIFO_Add_Item(LIFO_Buf_t* lifo_buf, uint32 item);
LIFO_status LIFO_Get_Item(LIFO_Buf_t* lifo_buf, uint32* item);
LIFO_status LIFO_Init(LIFO_Buf_t* lifo_buf, uint32* buf, uint32 length);

#endif /* LIFO_H_ */
