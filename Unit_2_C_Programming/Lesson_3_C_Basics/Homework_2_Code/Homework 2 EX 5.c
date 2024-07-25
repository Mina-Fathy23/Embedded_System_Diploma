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

	char letter;
	printf("Enter an alphabet: ");
	fflush(stdin); fflush(stdout);
	scanf("%c", &letter);
	getchar();

	if(((int)letter <= 122 && letter >= 97) || ((int)letter <= 90 && letter >= 65))
		printf("%c is an alphabet", letter);
	else
		printf("%c is not an alphabet", letter);
}
