// Project10d MinhalSyed.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
//FUNCTION PROTOTYPES
	int  menuChoose(void);
	void loadHourlyArray(char[2][25],int[2][5]);
	void loadSalaryArray(char[2][25],int[2][5]);
	void printHourly(char[2][25],int[2][5]);
	void printSalary(char[2][25],int[2][5]);
	
//Declare Local Variables
	int count;
	
	char hName[2][25];//Char arrrays for last names
	char sName[2][25];
	int hHours[2][5];//Int arrays for hours worked for 5 days
	int sHours[2][5];
	
	count=menuChoose();//Call user menu function-user makes choice 1 or 2
	
	switch(count)
	{
	case 1:
			loadHourlyArray(hName,hHours);
			printHourly(hName,hHours);
	break;

	case 2:
			loadSalaryArray(sName,sHours);
			printSalary(sName,sHours);
	break;

	default:
		printf("\nYou have entered an invalid code.");
		printf("\nPress Enter to exit...");
		getch();
		exit(1);
	}//End switch statement

	printf("\nPress ENTER to exit.....");
	getch();
	return 0;
}//End main
//FUNCTION DEFINITIONS
int menuChoose (void) 
{
	int count;//Declaare local Variable
	printf("\n\nYou can update hourly or salary accounts.");
	printf("\n\nPlease enter '1' for hourly, '2' for salary.");
	printf("\nPlease enter your choice and press ENTER:");
	scanf("%d",&count);
	return(count);//Goes back to 'choice' in main
}//End function

void loadHourlyArray(char hName[2][25],int hHours[2][5])
	{
	int row, col;
	printf("\nYou will be entering hours for 2 hourly emplyees.");
	printf("\nPress enter to continue...");
	getch();

	for(row=0;row<2;row++)
	{
		system("cls");
		printf("\n\nEnter emplyees last name:");
		scanf("%s",hName[row]);

		for(col=0;col<5;col++)
		{
			printf("\nEnter hours for each day MON to FRI:");
			scanf("%d",&hHours[row][col]);
		}//End inner for loop
	}//End out for loop
	return;
}//End of Function

void loadSalaryArray(char sName[2][25],int sHours[2][5])
{
	int row,col;
	printf("\nYou will be entering hours for 2 salary employees");
	printf("\nPress Enter to continue...");
	getch();

	for(row=0;row<2;row++)
	{
		system("cls");
		printf("\n\nEnter employee's last name:");
		scanf("%s",sName[row]);
		for(col=0;col<5;col++)
		{
			printf("\nEnter hours for each day Mon to Fri:");
			scanf("%d",&sHours[row][col]);
		}//End inner for loop
	}//End outer for loop
	return;
}//End function

void printHourly(char hName[2][25],int hHours[2][5])
{
	int row;
	system("cls");
	printf("Hourly Printout\n");
	for(row=0;row<2;row++)
	{
		printf("\n%s \t%2d%2d%2d%2d%2d\n",hName[row],
				 hHours[row][0],hHours[row][1],hHours[row][2],hHours[row][3],
				 hHours[row][4]);
	}//End for loop
	return;
}//End of function

void printSalary(char sName[2][25], int sHours[2][5])
{
	int row;
	system("cls");
	printf("Salary Printouts\n");

	for(row=0;row<2;row++)
	{
		printf("\n%s \t%2d%2d%2d%2d%2d\n",sName[row],
				sHours[row][0],sHours[row][1],sHours[row][2],sHours[row][3],
				sHours[row][4]);
	}//End for loop
	return;
}//End of function

