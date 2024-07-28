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

unsigned long int power(int x, int pow);

int main(void) {

	unsigned int x, pow;
	printf("Enter base number: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &x);

	printf("Enter the power number(postive integer): ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &pow);

	unsigned long int result = power(x, pow);

	printf("%d^%d = %li", x, pow, result);

	}

unsigned long int power(int x, int pow)
{
	long long result = 1;
	if(pow == 0)
		return 1;
	else
		result *= x *power(x, pow - 1);

	return result;
}
