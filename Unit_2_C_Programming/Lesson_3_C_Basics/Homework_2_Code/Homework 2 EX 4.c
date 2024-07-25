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

	float num;
	printf("Enter number: ");
	fflush(stdin); fflush(stdout);
	scanf("%f", &num);

	if(num == 0)
		printf("You Entered a Zero");
	else if(num > 0)
		printf("%f is Positive", num);
	else
		printf("%f is Negative", num);

}
