// project13d MinhalSyed.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
/**************DECLARE STRUCTURE******************/

struct CD
{
	int cdNumber;
	float price;
	char CDtitle[30];
	char song[20];
};

//Headings Set up
			char heading[]="Radio Playlist Songs-CD Disc Record";

int main(void)
{
	struct CD disc[10]={101,10.95,"Burning Rocks","Charbaby",
						102,11.95,"Burnt Rocks","Burnbaby",
						103,12.95,"Smoldering Boulders","Smokebaby"};

	//3 of 10 array elements filled
	int sub2=0;

	//Declare Function Prototypes

	void PrintHeadings(void);
	int addDisc(int,struct CD disc[]);
	void record(int,struct CD disc[]);
	void exitProgram(void);

	//Call Functions

	PrintHeadings();			//Function to print title to screen

	sub2=addDisc(sub2,disc);	//Prints current records, and prompts user to add records to storage

	record(sub2,disc);			//Prints updated list of recors to screen

	exitProgram();				//Prints end message to screen

	getch();
	return 0;
}

//FUNCTIONS DEFINITIONS//

void PrintHeadings(void)
{
	printf(heading);
	return;
}//End Function

int addDisc(int sub2, struct CD disc[])
{
	int sub;
	printf("\n\nHere are the current total number of CD's");
	printf("\nCD#	Price			 CD Title			Song Title\n");
	//Current status of structure with 3 elements out of 10 loaded
	for(sub=0;sub<3;sub++)
	{
		printf("\n%d	%.2f%20s	%30s",disc[sub].CDtitle,disc[sub].song);

		sub2=sub2+1;
	}

	printf("\n\nPress Enter to continue...");
	getch();
	return(sub2);
}//End Function

void record(int sub2, struct CD disc[])
{
	int sub;
	int count;
	int counta=1;

	system("cls");
	printf("\nHow many CD's do you wish to add: ");
	scanf("%d",&count);

	for(sub=0;sub<count;sub++)
	{
		system("cls");
		printf("\n\nPlease enter the cd number # %d :",counta);
		scanf("%d",&disc[sub2].cdNumber);	//sub2 to avoid erasing
		printf("\nPlease enter the price:");//Previous Values in  struct
		scanf("%f",&disc[sub2].price);
		fflush(stdin);
		printf("\nPlease enter the CDtitle:");
		scanf("%30[^\n]",&disc[sub2].CDtitle);
		fflush(stdin);
		printf("\nPlease enter the song title:");
		scanf("%20[^\n]",disc[sub2].song);
		sub2++;
		counta++;
		fflush(stdin);
	}//end for loop
	printf("\n\nPress ENTER to continue...");
	getch();

	system("cls");

	printf("\nHere are the total number of CD's");
	printf("\nCD#	PRICE			CD Title		Song Title\n");
	fflush(stdin);
	for(sub=0;sub<sub2;sub++)
	{
		printf("\n%d	%.2f%20s	%30s",disc[sub].cdNumber, disc[sub].price,
								disc[sub].CDtitle,disc[sub].song);
	}//end for loop

	return;
}//End function

void exitProgram(void)
{
	printf("\n\nThis is the end of the program. Press enter to exit");
	return;
}//End of function 