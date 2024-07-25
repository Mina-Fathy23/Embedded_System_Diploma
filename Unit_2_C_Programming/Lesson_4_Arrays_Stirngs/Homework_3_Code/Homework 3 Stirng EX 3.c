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
#include <string.h>

int main(void) {

	char text[10000];
	printf("Enter the String: ");
	fflush(stdin); fflush(stdout);
	gets(text);

	int len = strlen(text);

	for(int i = 0; i < len/2; i++)
	{
		char temp = text[i];
		text[i] = text[(len-1) - i];
		text[(len-1) - i] = temp;
	}

	printf("Reverse string is: %s", text);



}
