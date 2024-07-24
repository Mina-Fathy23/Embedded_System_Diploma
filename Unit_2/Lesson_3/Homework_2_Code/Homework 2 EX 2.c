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

int main(void) {

	char letter;
	printf("Enter an alphabet: ");
	fflush(stdin); fflush(stdout);
	scanf("%c", &letter);
	getchar();

	switch(letter)
	{
		case 'a':
		case 'A':
		case 'o':
		case 'O':
		case 'u':
		case 'U':
		case 'i':
		case 'I':
		case 'E':
		case 'e':
			printf("%c is a vowel", letter);
			break;
		default:
			printf("%c is a consonant", letter);
			break;

	}

}
