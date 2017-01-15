// Project6b MinhalSyed.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<conio.h>

int main(void)
{
	int row,column;	//Counters for row and column
	int flag=0;		//Set'flag' for while loop condition
	int value;		//Result of multiplication

	printf("This is a program to print out the multiplication table.");
	printf("\nDo you wish to continue? Enter '1' for yes, '0' for no.");
	printf("\nPlease type in your choice and press ENTER:");
	scanf("%d",&flag);
	fflush(stdin);
	printf("\n");//Put a line between text and timetable printout

	while(flag==1)//During the time flag==1, do the process inside the curly brackets of the while loop-the 2 nested for loops

	{

		for(row=1;row<=12;row++)//This will loop 12 times
		{
			for(column=1;column<=12;column++)//This will loop 12 times for every 1 time in the outer loop
			
			{
				value=row*column;
				printf("%3d",value);
			}//End inner for loop
			printf("\n");
		}//End outer for loop
		flag=0;//Reset flag to prevent endless loop in while loop
	
	}//End while-if user enters 0 above, 'fall through'the while loop structure with no processing taking place inside of it

	printf("\n\nPress ENTER to exit...");
	
	getch();
	return 0;
}
