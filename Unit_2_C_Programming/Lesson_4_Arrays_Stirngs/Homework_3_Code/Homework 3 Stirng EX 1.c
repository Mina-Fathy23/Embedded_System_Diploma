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

	char letter, text[100000];
	int freq = 0;
	printf("Enter String: ");
	fflush(stdin); fflush(stdout);
	gets(text);

	printf("Enter a Character to find frequency: ");
	fflush(stdin); fflush(stdout);
	scanf("%c", &letter);
	getchar();

	tolower(letter);
	strlwr(text);

	for(int i = 0; i < strlen(text); i++)
	{
		if(text[i] == letter)
		{
			freq++;
		}
	}

	printf("Frequency of %c = %d", letter, freq);


}
