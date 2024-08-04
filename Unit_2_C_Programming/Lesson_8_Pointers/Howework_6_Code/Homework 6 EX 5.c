/*
 ============================================================================
 Name        : Homework.c
 Author      : Mina Fathy Labib
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct Sdata
{
	char name[20];
	int id;
};


int main(void) {

	struct Sdata student1 = {"Mina", 1001};
	struct Sdata student2 = {"Alex", 1002};
	struct Sdata student3 = {"Andrew", 1003};

	struct Sdata (*arr[]) = {&student1, &student2, &student3};

	struct Sdata (*(*ptr_arr)[3]) = &arr;

	printf("Printing Data of each student: \n");

	for(int i = 0; i < 3; i++)
	{
		printf("Student %d name: %s\n", i+1, (*(*ptr_arr + i))->name);
		printf("Student %d ID: %d\n", i+1, (*(*ptr_arr + i))->id);

	}



}
