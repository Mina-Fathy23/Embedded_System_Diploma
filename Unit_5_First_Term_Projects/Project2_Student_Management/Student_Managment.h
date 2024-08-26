/*
 * fifo.h
 *
 *  Created on: Aug 20, 2024
 *      Author: Mina Fathy
 */

#ifndef STUDENT_MANAGMENT_H_
#define STUDENT_MANAGMENT_H_

#include "Platform_Types.h"
#include "stdio.h"
#include "stdlib.h"
#include <string.h>

#define DPRINT(...) {fflush(stdin);\
					 fflush(stdout);\
					 printf(__VA_ARGS__);\
					 fflush(stdin);\
					 fflush(stdout);}

//USER Configuration
//select the element type (uint8, uint16, uint32, ...)
#define element_type Sinfo_t

//create buffer
#define width 55

typedef struct Sinfo {
	char fname[50];
	char lname[50];
	int roll;
	float gpa;
	int cid[5];
} Sinfo_t;

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
FIFO_status FIFO_init();
FIFO_status FIFO_enqueue(FIFO_buff_t* fifo_buf,element_type item);
FIFO_status FIFO_dequeue(FIFO_buff_t* fifo_buf,element_type* item);
FIFO_status FIFO_is_full(FIFO_buff_t* fifo_buf);
void FIFO_print(FIFO_buff_t* fifo_buf);

//Main Function
void add_student_file(FIFO_buff_t* fifo_buf);
void add_student_manually(FIFO_buff_t* fifo_buf);
void find_roll_number(FIFO_buff_t* fifo_buf);
void find_first_name(FIFO_buff_t* fifo_buf);
void find_c(FIFO_buff_t* fifo_buf);
void total_students(FIFO_buff_t* fifo_buf);
void delete_student(FIFO_buff_t* fifo_buf);
void update_student(FIFO_buff_t* fifo_buf);
void show_students(FIFO_buff_t* fifo_buf);

//Extra
char check_id(FIFO_buff_t* fifo_buf, int id);
void Buffer_info(FIFO_buff_t* fifo_buf);

#endif /* STUDENT_MANAGMENT_H_ */
