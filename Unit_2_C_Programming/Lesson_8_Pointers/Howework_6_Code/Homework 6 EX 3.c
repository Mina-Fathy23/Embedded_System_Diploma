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

	char str[30];
	char rvstr[30];
	char *strptr = str;
	char *rvstrptr = rvstr;

	printf("Enter String: ");
	fflush(stdin); fflush(stdout);
	gets(str);

	int size = strlen(str);
	strptr += size;
	while(size > 0)
	{
		strptr--;
		*rvstrptr = *strptr;
		rvstrptr++;
		size--;
	}

	printf("%s", rvstr);



}
