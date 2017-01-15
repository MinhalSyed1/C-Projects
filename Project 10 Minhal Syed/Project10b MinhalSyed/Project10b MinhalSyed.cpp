// Project10b MinhalSyed.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<conio.h>

int main(void)
{
	void printHeading(void);	//Returns no value, passes in no value
	int addNumbers(int,int);	//Returns an int, passes in 2 ints
	int squareNumber(int);		//Returns an int, passes in an int
	void printAnswer(int);		
	void printEnding(void);		//No value returned, nothing pased in

	//Declare local variables
		int num1=4, num2=5, num3, sum;

		//FUNCTION CALLS

		printHeading();	//Calls a function that prints heading to the screen
		sum=addNumbers(num1,num2);//Calls a function that adds 2 numbers,
					//returns a value to main neamed 'sum' as denoted in PROTOTYPE
					//AND CALL structure
		num3=squareNumber(sum);//Calls a function that squares the sum
					//Sends 'sum' to the function, returns value to the main called 'num3'
		printAnswer(num2);//Calls a function that prints answer to screen
		printEnding();//Calls a function that prints end message to screen
			
	getch();
	return 0;
}//End main function



//FUNCTION DEFINITIONS SECTION

void printHeading (void)	//Must match PROTOTYPE above, otherwise error!
{							//NO SEMI-COLON after function definition header!
	printf("\nThs is a program that does small calculations.");
	return;//As the function returns nothing, return; is not really needed, 
		   //but is good form. The function will 'Pass through' the curly
}//End function


int addNumbers(int num1,int num2)
//Return an int, function name, num1,num2 passed into function from main
{
	//declare variable for use JUST WITHIN THIS FUNCTION
	int answer;
	answer=num1*num2;
		return(answer);//Returned to main, where it becomes sum
}//End function

int squareNumber (int sum)//Int returned, function name, int passed in
{
	//declare variable for use only within function
	int square;
	square=sum*sum;
		return(square);//Returned to main, where it becomes num3
}//End function


void printAnswer(int num3)
{
	printf("\n\nThe square of the sum is %d.",num3);
	return;
}//End function

void printEnding(void)
{
	printf("\n\nPress ENTER to exit...");
	return;
}//End function


