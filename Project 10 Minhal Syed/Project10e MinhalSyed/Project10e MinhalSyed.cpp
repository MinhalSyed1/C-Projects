// Project10e MinhalSyed.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<conio.h>

float intrestPaid(void)//Declare Function
{

	float currentBalance, annualRate, intrest, newBalance; //Local variables
	
	printf("\nEnter Current Balance 000.00, and Press ENTER:");
	scanf("%f",&currentBalance);
	printf("\nEnter the Intrest Rate 0.0, and Press ENTER:");
	scanf("%f",&annualRate);

	intrest=currentBalance*((annualRate/100.0)/12.0);
	newBalance=currentBalance+intrest;

	printf("\n	Beginning	Intrest	Intrest	New");
	printf("\n	Balance		Rate	Payment	Balance");
	printf("\n	========	=======	=======	=========");
	printf("\n%10.2f%11.3f%10.2f%11.2f\n",
		currentBalance,annualRate,intrest,newBalance);

	return(intrest);//Return a float value to main
}//End function

void endProgram(void)
{
	printf("Processing is complete!");
	printf("Press ENTER to exit....");
}//end of Function

//Begin main function
int main(void)
{
	int i,numberClients; //Index, # of depositors
	float totalIntPaid=0.00;	//Intrest paid Counter
	float intrestPaid(void);	//Function prototypes
	void endProgram(void);

	printf("\nEnter the number of depositors to proess and press ENTER:");
	scanf("%2d",&numberClients);//Executed one time

	for(i=0;i<numberClients;i++)//Repeat numberClients times
		totalIntPaid=totalIntPaid+intrestPaid();//Function call

	printf("\nTotal Intrest Paid---->%8.2f\n",totalIntPaid);

	endProgram();//Function Call
	getch();
	return 0;
}//End main

	

