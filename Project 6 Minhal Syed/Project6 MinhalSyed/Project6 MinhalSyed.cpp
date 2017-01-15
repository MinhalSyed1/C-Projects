// Project6 MinhalSyed.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<conio.h>


int main(void)
{

	int times, number;

//Line A	
		for(times=0;times<2;times++)//Outer for loop controls how many times the inner "for loop" goes
		{

//Line B
			for(number=1;number<=5;number++)//Inner for loop processes for as many yimes as you tell it to
			{//Starts inner for loop
				
				printf("\nThe number is %d:",number);
//Line C
			
			}//End inner for loop
			
			printf("\n");//Creastes space between cycles of outputs
//Line D
	
		}//End outer for loop	
	
	
	getch();
	return 0;
}//End main
