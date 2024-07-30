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

struct Sdistance
{
	int feet;
	float inch;
};

int main(void) {

	struct Sdistance dis1, dis2, R;

	printf("Enter information for 1st distance \nEnter Feet: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &dis1.feet);

	printf("Enter Inch: ");
	fflush(stdin); fflush(stdout);
	scanf("%f", &dis1.inch);

	printf("\nEnter information for 2st distance \nEnter Feet: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &dis2.feet);

	printf("Enter Inch: ");
	fflush(stdin); fflush(stdout);
	scanf("%f", &dis2.inch);

	R.feet = dis1.feet + dis2.feet;
	R.inch = dis1.inch + dis2.inch;

	if(R.inch >= 12.0)
	{
		R.feet += (int)R.inch/12;
		R.inch -= ((int)R.inch/12)*12;
	}

	printf("Sum of Distances = %d'-%0.2f\"", R.feet, R.inch);

}
