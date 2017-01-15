// Project8d MinhalSyed.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<conio.h>


int main(void)
{
//String array is initialized with 7 memory addresses, each can hold 20 characters 
//not to be confused with multidimensional array
	char daysofWeek[7][20]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
	float moneySpent[7]={2.70,450.35,0.00,2.37,5.00,6.73,110.00};
	int row;
	
	printf("These are the cost per days of the week\n\n");
	for(row=0;row<7;row++)
		printf("%s\	t%5.2f\n",daysofWeek[row],moneySpent[row]);
	
	getch();
	return 0;
}
