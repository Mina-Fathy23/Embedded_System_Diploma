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
#define PI 3.1415
#define area(r) (PI*r*r)

int main(void) {

	int radius;
	float area;
	printf("Enter the radius: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &radius);

	area = area(radius);

	printf("Area = %0.2f", area);


}
