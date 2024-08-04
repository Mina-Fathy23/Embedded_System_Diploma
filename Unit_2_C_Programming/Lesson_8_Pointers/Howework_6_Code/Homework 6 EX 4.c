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

	int i, n, arr[15], rev_arr[15];
	int *ptr_arr = arr, *ptr_rev_arr = rev_arr;

	printf("Input the number of elements to store in the array (max 15) : ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &n);

	printf("Input %d number of elements in the array :\n", n);

	for(i = 0; i < n; i++)
	{
		printf("element - %d : ", i+1);
		fflush(stdin); fflush(stdout);
		scanf("%d", ptr_arr);
		ptr_arr++;
	}

	i--;

	while(i >= 0)
	{
		ptr_arr--;
		*ptr_rev_arr = *ptr_arr;
		ptr_rev_arr ++;
		i --;
	}

	ptr_rev_arr = rev_arr;

	printf("\nReversed numbers: \n");
	for(i = 0; i < n; i++)
	{
		printf("element - %d : %d\n", n - i, *ptr_rev_arr);
		ptr_rev_arr++;
	}




}
