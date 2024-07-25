/*
 ============================================================================
 Name        : Homework_1_EX_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	long int num;

	printf("Enter a integer: ");
	fflush(stdin); fflush(stdout);
	scanf("%li", &num);

	printf("You entered: %li", num);
}
