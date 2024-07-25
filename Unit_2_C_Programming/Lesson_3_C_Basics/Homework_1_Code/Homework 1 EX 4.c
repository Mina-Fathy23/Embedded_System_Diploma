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

	float num1, num2;
		printf("Enter 1st num: ");
		fflush(stdin); fflush(stdout);
		scanf("%f", &num1);

		printf("Enter 2st num: ");
		fflush(stdin); fflush(stdout);
		scanf("%f", &num2);

		printf("Sum: %f", (num1 * num2));
}
