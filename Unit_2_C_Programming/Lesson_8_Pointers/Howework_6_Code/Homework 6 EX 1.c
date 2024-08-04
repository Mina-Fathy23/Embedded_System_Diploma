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

	int m = 29;
	int* ab = &m;

	printf("Address of m : 0x%p\n", &m);
	printf("Value of m : %d\n", m);

	printf("Address of pointer ab : 0x%p\n", ab);
	printf("Content of pointer ab : %d\n", *ab);

	m = 34;

	printf("Address of pointer ab : 0x%p\n", ab);
	printf("Content of pointer ab : %d\n", *ab);

	*ab = 7;

	printf("Address of m : 0x%p\n", &m);
	printf("Value of m : %d\n", m);

}
