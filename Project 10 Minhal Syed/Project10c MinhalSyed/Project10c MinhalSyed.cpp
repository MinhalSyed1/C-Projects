// Project10c MinhalSyed.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<conio.h>
int sum;
int main(void)
{
//Declare function PROTOTYPES
	void header (void);		//Returns no value,passes no value
	void square	(int);		//Returns no value,passes in an int
	void ending(void);		//Returns no value, passes in no value
//Declare local variables
	int count;

//FUNCTION CALLS
	header();	//This CALLS the function named header, nothing passed in

	for(count=0;count<7;count++)
		square(count);	//This CALLS the square function 7 times 
						//name of variable being passed in is in brackets
	
	ending();			//This CALLS the ending function nothing passed in

	getch();
	return 0;
}
//Function definitions

void header (void)
{
	int sum=0;//Initialize global variable here just to show it workds
	printf("This is the header for the squares program.\n\n");
	return;
}
void square (int count)
{
	int numSquare;//Numsquare is particular to square() and must be declared as a variable
	numSquare=count*count;
	sum=sum+numSquare;	//Use global variable here
	printf("The square of %d is %d\n",count,numSquare);
	return;
}
void ending (void)
{
	printf("\nThe sum of the squares is %d\n",sum);
	printf("\nPress Enter to exit...");
	return;
}