/*
 ============================================================================
 Name        : Homework.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	long int a, b;
	printf("Enter 1st a: ");
	fflush(stdin); fflush(stdout);
	scanf("%li", &a);

	printf("Enter 2st b: ");
	fflush(stdin); fflush(stdout);
	scanf("%li", &b);

	a = a + b; // sum
	b = a - b; // sum - b = a
	a = a - b; // sum - b (has value of a) = b (original value)

	printf("After swapping, value of a = %li\n", a);
	printf("After swapping, value of b = %li\n", b);
}
