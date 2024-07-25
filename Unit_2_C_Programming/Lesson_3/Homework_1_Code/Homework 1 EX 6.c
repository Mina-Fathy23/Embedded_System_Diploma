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

	long int num1, num2, temp;
	printf("Enter 1st num: ");
	fflush(stdin); fflush(stdout);
	scanf("%li", &num1);

	printf("Enter 2st num: ");
	fflush(stdin); fflush(stdout);
	scanf("%li", &num2);

	temp = num1;
	num1 = num2;
	num2 = temp;

	printf("After swapping, value of a = %li\n", num1);
	printf("After swapping, value of b = %li\n", num2);


}
