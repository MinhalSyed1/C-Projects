/*******************Description***********************/
/*													 */
/*		     Project 5 Bank Machine (loops)			 */
/*					ICS 4U1							 */
/*													 */
/*	This program will allow you to perform simple	 */
/*	deposits and withdraws from your bank. It		 */
/*	will let you see how much money you have in		 */
/*	your bank as well.								 */
/*													 */
/*				By:Minhal Syed						 */
/*				Run:14/09/2015						 */
/*****************************************************/

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main(void)
{
//************************//
//	Declaring Variables   //
//************************//
float deposit=0;
float withdraw=0;
float banked=0;
float amount=0;
float total=0;

int choice;
int choice2;
int userID = 123;
int pass;
int randNum;

char lastName[20];

bool repeat;


system("TITLE Minhal Syed - Bank Machine");
//*****************//
//	User Input     //
//*****************//

//Prompts user to input their bank pin
	printf("Please enter your 3 digit user ID and press ENTER\n(Hint: They are the first 3 numbers):");		
		scanf("%d",&pass);//Inputs and addresses integer value	
			if (pass == userID)
	
	{
		do
			{
				//Colour code
				system("cls");	 
				HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);WORD wOldColorAttrs;
				CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
				GetConsoleScreenBufferInfo(h, &csbiInfo);
				wOldColorAttrs = csbiInfo.wAttributes;
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_INTENSITY );


			   //Random number generator that will show the balance for every different user.                       
				randNum = (1 + (rand()%7000));

			
				printf("\n\t\t\tHello, Welcome to CAD Bank\n\n");
			
				printf("\nEnter your Last name and press ENTER:");
					scanf("%s",lastName);

				printf("\nWelcome to CAD Bank Mr.%s.",lastName);
			
				printf("\n\nThis is your balance:$%d", randNum);

				printf("\n\nPlease enter 1 to deposit, 2 to withdraw");
				printf("\nfrom your account then press ENTER:");
					scanf("%d",&choice);

//*******************//
//	Calculations	 //
//*******************//

	//Start of the switch statement
		switch(choice)
			{
			amount =0;
			//Option 1=true than it will do the following code below (Basically making deposits)
			case 1:
				do
				{  
					printf("\n\nEnter deposit(s) of this month (or enter 0 to quit):");
					scanf("%f",&deposit);
					amount+=deposit;
					}	while(deposit!=0);
				{
					printf("\nThe total if this month's deposit(s) is: $%.2f",amount);
					total=randNum+amount;

					printf("\n\nThe amount in your account after");
					printf("\nthis month's deposit(s) is:$%.2f\n",total);			
					}		
	
				break;
			
				amount =0;
			//Option 2= true than it will do the following code below (Basically making withdraws)	
			case 2:
				do
				{
			
					printf("\n\nEnter withdraw(s) of this month (or enter 0 to quit):");
					scanf("%f",&withdraw);
					amount+=withdraw;
					}	while(withdraw!=0);

	
					printf("\n\nThe total of this month's withdraw(s) is: $%.2f",amount);
					total=randNum-amount;

					printf("\n\nThe amount in your account after");
					printf("This month's withdraw(s) is: $%.2f",total);
					printf("\nPlease press ENTER to exit.\n");
	
					break;
					default:
					SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_INTENSITY );
					//If neither 1 or 2 are chosen it will send 
					printf("\n\nError, You have entered an Invalid character. Please enter either 1 or 2");
					break;
					
		
				}
		//Colour code
		SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_INTENSITY );

		//Asking the user if he wishes to perform another transaction
		printf("\n\nDo you wish to perform another transaction?");
		printf("\nPress 1 for yes and press 2 for no:");
		fflush(stdin);
		scanf("%d",&choice2);
		
		//Saying if user chooses 1 it will repeat and if they choose 2 it will end the program
		if(choice2 == 1)		
			repeat=true;


		if(choice2 == 2)
		{
			printf("\nThank you for using CAD Bank. Have a great day!");
			break;
		}
		
		
		}while(repeat = true);

}

//My project does run but their are a few glitches that I should have been able to fix if I had maybe 15 more minutes.

//**************//
//		End		//
//**************//

//If the 3 number pin is incorrect it will end the program and you will have to try again.
if(pass != userID)
printf("Password Incorrect..Access denied.");	
getch();
return 0;
}

