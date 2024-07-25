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

	char text[10000];
	int size = 0;
	printf("Enter the String: ");
	fflush(stdin); fflush(stdout);
	gets(text);

	for(int i = 0; text[i] != 0; i++)
	{
		size ++;
	}

	printf("Length of String: %d", size);

}
