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


	//-----------Method 1-------------
/*  char letter = 'A';
	char* ptr = &letter;

	for(int i = 0; i < 26; i++)
		printf("%c ", *ptr +i);
*/


	//------------Method 2-----------
	char letters[26];
	char* ptr = letters;

	for(int i = 0; i < 26; i++)
	{
		*ptr = 'A' + i;
		ptr++;
	}

	ptr = letters;

	for(int i = 0; i < 26; i++)
	{
		printf("%c ", *ptr);
		ptr++;

	}

}
