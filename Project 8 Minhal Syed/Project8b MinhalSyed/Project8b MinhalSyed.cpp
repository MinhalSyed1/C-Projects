// Project8b MinhalSyed.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<conio.h>

int main(void)
{

	int values[12], count;//Declare int array and count for 'for loop'
	for (count=0; count <3; count++)//User loads array with 3 int values
	{
		printf("Please enter an integer and press ENTER:");
		scanf("%d",&values[count]);
		printf("The value at element %2d is: %3d\n",count,values[count]);
			//Show current element values
	}
	for(count=0;count<3;count++)
		values[count]=values[count]*2;//Do math with the variables
		printf("\n\nThe new values overwrite the old element values.\n\n");

	for(count=0;count<3;count++)
		printf("The new value at element %2d is: %3d\n", count, values[count]);
	
	getch();
	return 0;
}
