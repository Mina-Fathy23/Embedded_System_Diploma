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

	int size, num;
	printf("Enter Number of Elements: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &size);

	int arr[size];

	for(int i = 0; i < size; i++)
	{
		arr[i] = (i + 1) + (i+1)*10;
		printf("%d  ", arr[i]);
	}

	printf("\nEnter The element to search for: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &num);

	for(int i = 0; i < size; i++)
	{
		if(num == arr[i])
		{
			printf("Number found at the location %d", (i+1));
			break;
		}
		else if(i == size - 1)
		{
			printf("Number was not found");
		}
	}


}
