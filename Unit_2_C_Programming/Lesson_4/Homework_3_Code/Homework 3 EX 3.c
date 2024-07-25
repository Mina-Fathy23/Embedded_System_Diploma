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

	int row, col;
	printf("Enter Number of Rows: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &row);

	printf("Enter Number of columns: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &col);

	float arr[row][col];
	float trans_arr[col][row];

	printf("Enter element of the Matrix\n");

	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			printf("Enter element a%d%d: ", (i+1), (j+1));
			fflush(stdin); fflush(stdout);
			scanf("%f", &arr[i][j]);

			trans_arr[j][i] = arr[i][j];
		}
	}

	printf("Entered Matrix\n");

	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			printf("%0.2f\t", arr[i][j]);
		}
		printf("\n");
	}

	printf("Transpose of Matrix\n");

	for(int i = 0; i < col; i++)
	{
		for(int j = 0; j < row; j++)
		{
			printf("%0.2f\t", trans_arr[i][j]);
		}
		printf("\n");
	}




}
