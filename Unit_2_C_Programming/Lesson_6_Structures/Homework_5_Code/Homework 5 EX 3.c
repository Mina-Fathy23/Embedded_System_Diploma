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


struct Scomplex
{
	float real;
	float img;
};

struct Scomplex add(struct Scomplex a, struct Scomplex b);

int main(void) {

	struct Scomplex V1, V2, R;

	printf("Enter information for 1st Complex num \nEnter Real and Imaginary respectivly: ");
	fflush(stdin); fflush(stdout);
	scanf("%f %f", &V1.real, &V1.img);

	printf("\nEnter information for 2nd Complex num \nEnter Real and Imaginary respectivly: ");
	fflush(stdin); fflush(stdout);
	scanf("%f %f", &V2.real, &V2.img);

	R = add(V1, V2);


	printf("\nSum = %0.1f + %0.1f i", R.real, R.img);

}

struct Scomplex add(struct Scomplex a, struct Scomplex b)
{
	struct Scomplex result;

	result.real = a.real + b.real;
	result.img = a.img + b.img;
	return result;
}
