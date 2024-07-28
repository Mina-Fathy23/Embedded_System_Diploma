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

void prime(int x, int y);

int main(void) {

	int x, y;

	printf("Enter Two numbers (intervals)\nStart: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &x);

	printf("End:   ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &y);

	prime(x, y);

	return 0;

}

void prime(int x, int y)
{


	for(int i = x; i <=y; i++)
	{
		char flag = 0;
		if(i == 1)
			continue;
		else if(i == 2)
			printf("2 ");
		else
		{
			for(int j = 2; j <= i/2; j++)
			{
				if((i%j) == 0)
					flag ++;
			}

			if(flag == 0)
				printf("%d ", i);
		}
	}



}
