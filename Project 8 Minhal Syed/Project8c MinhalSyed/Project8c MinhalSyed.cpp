// Project8c MinhalSyed.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<conio.h>

int main(void)
{
	int count,sub;				//Counters for 'for loops'
	int numerator[12];			//int array to hold numerators of fraction
	int denominator[12];		//int array to hold denominators of fraction
	float answer[12];			//Float array to hold percentage-decimal result
	char name1[]="\n\nYour precentages are following:";//String for headings
	
	printf("\nFINDING PERCENTAGES FROM FRACTIONS>>>");
	printf("\n\nYou will be prompted to enter three fractions.");
	for(count=0; count<3;count++)
	{
		printf("\n\nEnter fraction %d NUMERATOR and press ENTER:",count+1);
		scanf("%d",&numerator[count]);
		printf("\n\nEnter fraction %d DENOMINATOR and press ENTER:",count+1);
		scanf("%d",&denominator[count]);
		("cls");
	}//Note the use of count +1 as a 'print to screen' guide for the user

	for(count=0;count<3;count++)
	{		//Do dividion between elements of different arrays
		answer[count]=(float)numerator[count]/denominator[count];
			//Put the answer in yet another array of floats
	}
	("cls");
	printf("%s\n",name1);

	for(sub=0;sub<3;sub++)//Switched the counter onm the for loop for fun
			//Print the results to the screen
	{
		printf("\n\nThe percentage of the fraction %d/%d is:",numerator[sub],denominator[sub]);
		printf("\n\n%10.2f or %10.2f%\n",answer[sub],answer[sub]*100);
	}

	getch();
	return 0;
}
