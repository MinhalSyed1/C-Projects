// Project8 MinhalSyed.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<conio.h>

int main(void)
{
	int values[12]={12,13,14,15,16};//Int array 12 elements are reserved in memory

	int count;
	for(count=0;count<5;count++)
		printf("The value at element %2d is:%3d\n", count, values[count]);

	getch();
	return 0;
}
