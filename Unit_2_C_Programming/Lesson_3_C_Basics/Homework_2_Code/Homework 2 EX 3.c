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

	float a, b, c;
	printf("Enter 1st number: ");
	fflush(stdin); fflush(stdout);
	scanf("%f", &a);

	printf("Enter 2st number: ");
	fflush(stdin); fflush(stdout);
	scanf("%f", &b);

	printf("Enter 3st number: ");
	fflush(stdin); fflush(stdout);
	scanf("%f", &c);

	printf("Largest number: %f", ((c > ((a > b)? a : b)) ? c : ((a > b)? a : b)));
}
