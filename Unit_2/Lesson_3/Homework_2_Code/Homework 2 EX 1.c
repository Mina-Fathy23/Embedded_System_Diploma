/*
 ============================================================================
 Name        : Homework.c
 Author      : Mina Fathy
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void){

	long int num;
	printf("Enter an integer you want to check : ");
	fflush(stdin); fflush(stdout);
	scanf("%li", &num);

	if((num%2) == 0)
	{
		printf("%li is even", num);
	}
	else
	{
		printf("%li is odd", num);
	}
}
