// Project10 MinhalSyed.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<conio.h>

int main(void)
{
	void	printHeading	(void);
	int		mathCalc		(int);
	void	printEnding		(int);

	//Declare LOCAL variables for use in main
	int sum=0;
	int num1=2;

	//FUNCTION CALLS SECTION IN MAIN

	printHeading();//Calls function that prints heading to screen

	sum=mathCalc(num1);//Calls function that passes 'num1' to function, 
						//and prints endmessage to screen

	printEnding(sum);//Calls a function that passes 'sum' to function and prints end message to screen


	//In the FUNCTION CALLS, just the names of the variables being passed to the function areneeded
		
	getch();
	return 0;
}
void printHeading(void)//NO SEMI-COLON on function definitions
{
	printf("\nHere is a simple function program.");
	return;//No value returned
}//End function

int mathCalc(int num1)//num1 is value passed in from main
{
	int num2=2;	//These are local variables for use in the function only
	int answer=0;
	answer=num1+num2;
	return(answer);//Return 'answer' to main where it becomes 'sum'
}//End function

void printEnding(int sum)//Sum is passed in from main
{
	printf("\n\nThe sum of the numbers is %d.",sum);
	printf("\n\nPress ENTER to exit...");
	return;//Nothing returned
}//End function
