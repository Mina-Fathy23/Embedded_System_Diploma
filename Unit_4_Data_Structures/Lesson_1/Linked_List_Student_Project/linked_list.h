/*
 * linked_list.h
 *
 *  Created on: Aug 20, 2024
 *      Author: Mina Fathy
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#define DPRINT(...) {fflush(stdin); \
					 fflush(stdout); \
					 printf(__VA_ARGS__); \
					 fflush(stdin); \
					 fflush(stdout);}


#include "Platform_Types.h"
#include "stdio.h"
#include "stdlib.h"

typedef struct Sdata{

	char 	name[40];
	uint32 	id;
	float 	height;
} Sdata_t;

typedef struct SStudent {

	Sdata_t 	student;
	struct SStudent* p_NextStudent;

} SStudent_t;

//APIs
//Student project main functions
void Linked_Add_Student(void);
void Linked_Fill_Record(SStudent_t* NewStudent);
int Linked_Delete_Student(void);
void Linked_View_Students(void);
void Linked_Delete_All(void);

//Extra assignment functions
int Linked_Get_Nth(void);
int Linked_Find_Length(SStudent_t* head);
int Linked_Value_from_end(void);
void Linked_Middle(void);
void Linked_Reverse_list(void);



#endif /* LINKED_LIST_H_ */
