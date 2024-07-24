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

	long int number, sum;
	printf("Enter number: ");
	fflush(stdin); fflush(stdout);
	scanf("%li", &number);

	sum = number * (number+1) / 2;

	printf("Sum = %li", sum);


}
