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

	char letter;
	printf("nter a character:  ");
	fflush(stdin); fflush(stdout);
	scanf("%c", &letter);
	getchar();

	printf("ASCII value of %c = %d", letter, letter);
}
