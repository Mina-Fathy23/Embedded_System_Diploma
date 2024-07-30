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
	printf("Enter Information of Students: \n\n");

	for(int i = 0; i < 10; i++)
	{
		char firstname[20];
		printf("For roll number %d \nEnter name: ", i+1);
		fflush(stdin); fflush(stdout);
		scanf("%s", firstname);
		strcpy(students[i].name, firstname);

		printf("Enter Mark: ");
		fflush(stdin); fflush(stdout);
		scanf("%f", &students[i].mark);

		printf("\n");

	}


	printf("Displaying Information \n\n");
	fflush(stdin); fflush(stdout);

	for(int i = 0; i < 10; i++)
	{
		printf("Information for roll number %d: \n", i+1);
		printf("Name of Student no.%d: %s\n", i+1, students[i].name);
		printf("Mark of Student no.%d: %0.2f\n", i+1, students[i].mark);
		printf(".\n.\n.\n");
	}

	printf("NOTE: For the sake of the snapshot the array only holds 2 student");
}
