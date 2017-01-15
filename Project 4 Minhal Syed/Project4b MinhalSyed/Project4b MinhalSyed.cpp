// Project4b MinhalSyed.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<conio.h>

int main(void)
{

	int badOperator=0;
	char mathOp;
	float number1, number2, result;

	printf("Enter your 1st number and press ENTER:");
	scanf("%f",&number1);
	printf("\nEnter your 2nd number and press ENTER:");
	scanf("%f",&number2);
	fflush(stdin);//Fflush is very important here-clear keyboard clutter before entering a character type next
	
	printf("\nEnter a math operator sign from the keyboard ie.+,-,*,/.");
	printf("\nEnter your choice and press ENTER:");
	scanf("%c", &mathOp);
	
	if(mathOp=='*')	//If this is true, multiply the numbers
		result=number1*number2;
	else if(mathOp=='/') //If this is true, divide the numbers
		result=number1/number2;
	else if(mathOp=='+') //If this is true, add the numbers
		result=number1+number2;
	else if(mathOp=='-') //If this is true, subtract the numbers
		result=number1-number2;
	else //If none of the above are true then
		badOperator=1;//Otherwise the user has inputted an invalid entry for the math operator
	//You might think of else as the 'default condition which will come in handy later
	//End of nested else-if black...new if statement starts next line

	//Notice curly brackets surounding the if and else blocks of code. 
	//Failure to include them results in a "misplaced else or error message
	
	if(badOperator!=1)//If the math operator entered is a valuise one then
	{
		printf("\n%6.2f %c %6.2f is %6.2f\n",number1, mathOp, number2, result);
		printf("\nPress ENTER to exit.");
	}
	else //Math operator not valid
	{
		printf("\nYou have entered and invalid operator!\n");
		printf("\nYou'll have to start all over again! press ENTER to exit.");
	}

	getch();
	return 0;
}
