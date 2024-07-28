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
#include "string.h"

void reverse(char start_text[], int size, int index);

int main(void) {

	char text[1000];

	printf("Enter a Sentence: ");
	fflush(stdin); fflush(stdout);
	gets(text);

	int size = strlen(text);

	reverse(text, size, 0);


}

void reverse(char text[], int size, int index)
{

	if(index == size)
		return;

	char temp = text[index];
	reverse(text, size, ++index);

	printf("%c", temp);

}
