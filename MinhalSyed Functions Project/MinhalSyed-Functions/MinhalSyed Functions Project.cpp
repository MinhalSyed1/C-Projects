/*******************************************************/
/*		Minhal Syed Functions Project				   */
/*													   */
/*	This program is basically a schedule planner       */
/*	that will help you organize your time table        */
/*	and tell you all the things you need to do         */
/*	while still allocating the amount of time you      */
/*	need to get the marks you desire.                  */
/*                                                     */
/*		By:			Minhal Syed						   */
/*		Run Date:	08/10/2015                         */
/*******************************************************/

#include "stdafx.h"
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include <ctype.h>
#include <time.h>
/**********************/
/*FUNCTION PROTOTYPES */
/**********************/
char programinformation (void);			// program info
int	 menuChoose			(void);			//Choice function
int	 chooseMark			(float[6]);		//Choose your mark
int day					(void);			//Enter in the day
int year				(void);			//Enter in the year
int month				(void);			//Enter in the month

int main(void)							//Main
{	
/************/
/*Variables */
/************/
int count;				//menu choice count
int counter;			//Counter for colour change
int a,b =0;				//Sets a and b as 0
int day1;				//day1 for day
int year1;				//year1 for year
int month1;				//month1 for month
int end;				//End
char time1[128];		//string to record time
char time2[128];		

//***********
//User Input
//***********

		
	//Colour Code as well as setting the title 			
	system("TITLE Minhal Syed - Functions Project");
	HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);  
	WORD wOldColorAttrs;                                                                                              
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;                                                             
	GetConsoleScreenBufferInfo(h, &csbiInfo); 
	wOldColorAttrs = csbiInfo.wAttributes;
    SetConsoleTextAttribute ( h,FOREGROUND_RED |FOREGROUND_INTENSITY );
	system("cls");

	
	//Counter that changes the colour of the text
		for(counter=0; counter<5; counter++)
{
			switch(counter)
{ 
				case 1: SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_BLUE |FOREGROUND_INTENSITY );
				
				break;

				case 2: SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_INTENSITY ); 
				
				break;

				case 3: SetConsoleTextAttribute ( h, FOREGROUND_GREEN |FOREGROUND_RED | FOREGROUND_INTENSITY );
					
				break;

				case 4:	SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
				
				break;

				case 5: SetConsoleTextAttribute ( h, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY );
					
				break;
}
		//message printed on screen
	printf("PPPPPP  RRRRRRR   OOOO     JJJJJJJ  EEEEEEE   CCCCCC  TTTTTTT\n");		
	printf("PP   P  RR    R  O    O       J     EEE       CC         T   \n");
	printf("PPPPPP  RRRRRRR O      O      J     EEEEEEE   CC         T   \n");
	printf("PP      RRR     O      O   J  J     EEE       CC         T   \n");
	printf("PP      RR RR    O    O    J  J     EEE       CC         T   \n");
	printf("PP      RR  RR    OOOO     JJJJ     EEEEEEE   CCCCCC     T   \n");


	//delay function 
	_strtime( time1 );
	 do
{
	_strtime( time2 ); 
	a=(strcmp(time2, time1));
	if (a!=0)
{
	b=b+1;
	_strtime(time1);
}
							
}	while(b!=1);//changing number 1 to higher number increases time lag
	b=0;
	a=0; 
	system("cls");
}


SetConsoleTextAttribute ( h, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY );
//Tittle of the Project 

printf("\t\t\tFunctions Project\n\t\t\tBy:Minhal Syed\n\t\t\tRun Date:08/10/2015"); 
SetConsoleTextAttribute ( h, BACKGROUND_BLUE | FOREGROUND_GREEN |FOREGROUND_INTENSITY );//Changing colour
//an array to determine the hours you need to study

float hoursStudied[6]={0.30,1,1.30,2,2.5,};

	programinformation();//Calling a function that will give program info
	
	//A switch statement between options 1 or 2
do
	{
	count=menuChoose();//Calling a function that will give you an option to choose
	switch(count)
	{
	
	case 1:
			printf("You have chosen to update the mark you wish to recieve.");
			chooseMark(hoursStudied);
			printf("\nPlease Press your name to repeat");
			printf("\nPlease Press '-1' to exit:");
			scanf("%d",&end);
			system("cls");
			
	break;

	case 2:
			printf("\nYou have chosen to update your schedule");
			day1=day();	//calling a function that is the day
			month1=month();//calling a function that is the month
			year1=year();//calling a function that is the year

			printf("\nThe information you have entered has beeen outputted to a text file.");
			printf("\nPlease Press your name to repeat:");
			printf("\nPlease Press '-1' to exit:");
			scanf("%d",&end);
			system("cls");

	break;	
	//default when the user enters something that is not one or two
	default:
	printf("Please enter either choice '1' or '2':");
	break;

}//End switch statement
}while(end!=-1);	

//Code for outputting into a text file
 FILE *fp;

   fp = fopen("output.txt", "w+");
   fprintf(fp, "%d,%d,%d\n",day1,month1,year1);
   fclose(fp);

	printf("Thank you for using the Program");
	getch();
	return 0;

}//End main

/************/
/*FUNCTIONS */
/************/

//The overview on how the program works
char programinformation(void)
{
	printf("\nThis program will allow you to enter in the events you have planned and it will schedule them for you.");
	printf("It will give you the option of entering the mark you wish to recieve");
	printf(" and it will print out your schedual on a text document.");
	printf("\n\nPress Enter to continue...");
	getch();
	system("cls");
	return 0;
}

int menuChoose(void)
{
	int row=0;
	int count;
	char name [20];//String Variable
	printf("\nEnter your name and press ENTER: ");
	gets(name);
	printf("\nWelcome %s.",name);
	printf("\nPlease choose '1'if you would like to update the mark you wish to recieve,"); 
	printf("\nChanging the time of your study sessions,"); 
	printf("\n\nOr '2' to enter in a important event into your Schedule.");
	printf("\n\nPlease enter in your choice and press Enter:");
	scanf("%d",&count);
	system("cls");//Clears the screen
	return (count);//Goes back to 'count' in main
}

//The array from above
int chooseMark(float hoursStudied[6])
{
int mark;
printf("\n\nPlease enter the mark you wish to recieve:");
scanf("%d",&mark);
if (mark <50)
	printf("\nYou should study %.2f hours a day",hoursStudied[0]);
else if ((mark>=60)&&(mark<=69))
	printf("\nYou should study %.2f hours each day",hoursStudied[1]);
else if ((mark>=70)&&(mark<=79))
	printf("\nYou should study %.2f hours each day",hoursStudied[2]);
else if ((mark>=80)&&(mark<=89))
	printf("\nYou should study %.2f hours each day",hoursStudied[3]);
else if ((mark>=90)&&(mark<=100))
	printf("\nSince you wish to have such a high mark you must work %.2f hours each day.",hoursStudied[4]);
return (mark);//Returns to mark
}


int month(void)
{	
int month;	 
printf("\n\nPlease enter the month the event is happening (1-12):");	
scanf("%d",&month);
fflush(stdin);
//if the user inpt doesnt fall between these two numbers, they will have to choose again
while((month<1)||(month>12))
{
	printf("Invalid choice menu");
	printf("\nEnter in another choice (1-12):");
	scanf("%d",&month);
}
return (month);//Return to month
}

int day (void)
{
int day;
printf("\n\nPlease enter the day the event is happening (1-31):");
scanf("%d",&day);
fflush(stdin);
//if the user inpt doesnt fall between these two numbers, they will have to choose again
while((day<1)||(day>31))
{
	printf("Invalid choice menu");
	printf("\nEnter in another choice (1-31):");
	scanf("%d",&day);
}
return (day);//Return to Day
}

int year (void)
{
int	year;
printf("\n\nPlease enter the year the event is happening:");
scanf("%d",&year);
fflush(stdin);
//if the user inpt doesnt fall between these two numbers, they will have to choose again
while((year<1)||(year>100000))
{
	printf("Invalid choice menu");
	printf("\nEnter in another choice:");
	scanf("%d",&year);
}
return(year);//Return to Year
}

