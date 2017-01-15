// Project2 MinhalSyed.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include<conio.h>
int main(void)
{

	 //Declare Variales
	float previousBalance, payments, annualIntRate,
			newBalance, monthEndBalance;
	
	int userID;

	//Prompt user for input

	printf("\nPlease enter your 3 digit user ID and press ENTER:");
	scanf("%d",&userID);//Inputs and addresses integer value

	printf("\nPlease enter Previous Balance and press ENTER:");
	scanf("%f",&previousBalance);//Inputs and adresses float value

	printf("\nPlease enter Payments Made and press ENTER:");
	scanf("%f",&payments);//Inputs and adresses float value


	//Flush keyboard storage buffer to lose digital garbage
	fflush(stdin);

	//Do calculations
	annualIntRate=.05/12;//Yearly 5% intrest/months

	newBalance=previousBalance-payments;
	
	newBalance=newBalance+(newBalance*annualIntRate);
	
	monthEndBalance=newBalance;

	//Print to screen

	printf("\nYour Name, title-CHARGE ACCOUNT, the date here");
	printf("\n\nUser ID is: %d", userID);//UserID is an integer value

	printf("\nMonth-End Balance: %7.2f", monthEndBalance);
	printf("\nThis is the end of this program!");
	printf("\n\nPress ENTER to exit...");

	getch();
	return 0;
}
