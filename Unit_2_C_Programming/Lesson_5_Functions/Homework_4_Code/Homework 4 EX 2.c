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

unsigned long factorical(int x);

int main(void) {

	int x;
	printf("Enter a Positive Integer: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &x);

	printf("Factorial of %d = %lu", x, factorical(x));


}

unsigned long factorical(int x)
{
	unsigned long fac = 1;

	if(x == 1 || x == 0)
		return 1;
	else if(x > 1)
		fac *= x * factorical(x - 1);

	return fac;

}
