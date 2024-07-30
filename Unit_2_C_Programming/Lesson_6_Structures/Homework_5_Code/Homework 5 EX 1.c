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
#include <string.h>

struct Sstudent
{
	char name[20];
	unsigned int roll;
	float mark;
};

int main(void) {

	struct Sstudent students[10];
	unsigned int num;
	printf("Enter Number of Students (max number: 10) : ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &num);

	printf("Enter Information of Students: \n");

	for(int i = 0; i < num; i++)
	{
		char firstname[20];
		printf("Enter Name of Student no.%d: ", i+1);
		fflush(stdin); fflush(stdout);
		scanf("%s", firstname);
		strcpy(students[i].name, firstname);

		printf("Enter roll number of Student no.%d: ", i+1);
		fflush(stdin); fflush(stdout);
		scanf("%d",  &students[i].roll);

		printf("Enter mark of Student no.%d: ", i+1);
		fflush(stdin); fflush(stdout);
		scanf("%f", &students[i].mark);

		printf("\n");

	}


	printf("Displaying Information \n");
	fflush(stdin); fflush(stdout);

	for(int i = 0; i < num; i++)
	{
		printf("Name of Student no.%d: %s\n", i+1, students[i].name);
		printf("Roll number of Student no.%d: %d\n", i+1, students[i].roll);
		printf("Mark of Student no.%d: %0.2f\n\n", i+1, students[i].mark);
	}

}
