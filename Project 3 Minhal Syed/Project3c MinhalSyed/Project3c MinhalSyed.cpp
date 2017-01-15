// Project3b MinhalSyed.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<conio.h>

int main(void)
{
//You can use character strings to code headings for later use. 
//This keeps various parts of your programn in specific areas of your program

char projectTitle[]="\n\n\t\tBob Dawes, \tExercise 4-2, \tFebuary 3, 2002\n\n";
char CelciusHeading[]="\nCelcius";
char fahrenheitHeading[]="\nFahrenheit";

//Calculations etc. done here
//Then print titles to the screen in conjunction with display output
	printf(projectTitle);//Only the string name is needed in print function
	printf(CelciusHeading);
	printf(fahrenheitHeading);

	getch();
	return 0;
}
