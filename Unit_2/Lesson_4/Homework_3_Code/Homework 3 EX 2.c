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

int main(void) {

	int size;
	float sum = 0;
	printf("Enter the number of data: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &size);


	float arr[size];

	for(int i = 0; i < size; i++)
	{
		printf("Enter number: ");
		fflush(stdin); fflush(stdout);
		scanf("%f", &arr[i]);
		sum += arr[i];
	}

	printf("Average = %0.2f", (sum / size));

}
