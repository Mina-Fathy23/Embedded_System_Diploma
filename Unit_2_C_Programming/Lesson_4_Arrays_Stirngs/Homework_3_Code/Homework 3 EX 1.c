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

	float a[2][2];
	float b[2][2];
	float sum[2][2];

	printf("Enter the elements of 1st matrix\n");
	fflush(stdin); fflush(stdout);


	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			printf("Enter a%d%d: ", i, j);
			fflush(stdin); fflush(stdout);
			scanf("%d", &a[i][j]);
		}
	}

	for(int i = 0; i < 2; i++)
		{
			for(int j = 0; j < 2; j++)
			{
				printf("Enter b%d%d: ", i, j);
				fflush(stdin); fflush(stdout);
				scanf("%d", &b[i][j]);
			}
		}

	for(int i = 0; i < 2; i++)
		{
			for(int j = 0; j < 2; j++)
			{
				sum[i][j] = a[i][j] + b[i][j];
			}
		}

	printf("Sum of Matrix: \n");

	for(int i = 0; i < 2; i++)
		{
			for(int j = 0; j < 2; j++)
			{
				printf("%d \t ", sum[i][j]);
			}
			printf("\n");
		}


}
