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

	int size, num, position;
	printf("Enter Number of Elements: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &size);

	int arr[size];
	int new_arr[size + 1];

	for(int i = 0; i < size; i++)
	{
		arr[i] = i + 1;
		printf("%d  ", arr[i]);
	}


	printf("\nEnter the element to be inserted: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &num);

	printf("Enter the Location: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &position);

	int arr_index = 0;

	for(int i = 0; i < size + 1; i++)
	{
		if((i+1) == position)
		{
			new_arr[i] = num;
		}
		else
		{
			new_arr[i] = arr[arr_index];
			arr_index ++;
		}
	}

	for(int i = 0; i < size + 1; i++)
	{
		printf("%d  ", new_arr[i]);
	}

}
