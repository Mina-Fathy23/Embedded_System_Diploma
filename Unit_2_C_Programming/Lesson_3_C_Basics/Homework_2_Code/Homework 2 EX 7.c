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

	long long number;
	printf("Enter number: ");
	fflush(stdin); fflush(stdout);
	scanf("%lld", &number);

	if(number >= 0)
	{
		long long fact = 1;
		for(long long i = 2; i <= number; i++)
		{
			fact *= i;
		}
		printf("Factorial = %lld", fact);
	}
	else
	{
		printf("ERROR!!! Factorial of a negative number doesn't exist");
	}






}
