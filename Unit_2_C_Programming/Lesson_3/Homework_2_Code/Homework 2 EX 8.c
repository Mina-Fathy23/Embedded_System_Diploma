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

	char operation;
	float a, b, result;
	printf("Enter operator either + or - or * or / : ");
	fflush(stdin); fflush(stdout);
	scanf("%c", &operation);
	getchar();

	printf("Enter 1st Operand: ");
	fflush(stdin); fflush(stdout);
	scanf("%f", &a);

	printf("Enter 2st Operand: ");
	fflush(stdin); fflush(stdout);
	scanf("%f", &b);

	if(b == 0 && operation == '/')
	{
		printf("Can't divide by Zero");
	}
	else
	{
		switch(operation)
		{
		case '+':
			result = a + b;
			break;
		case '-':
			result = a - b;
			break;
		case '*':
			result = a * b;
			break;
		case '/':
			result = a / b;
			break;

		}

		printf("%f %c %f = %f", a, operation, b, result);

	}



}
