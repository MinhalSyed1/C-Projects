// Project2 MinhalSyed.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream.h>
#include<conio.h>

//Begin main function
int main(void)
{

//Function Prototypes 
	void printHeading(void);
	void printBottles(int);
	void printEndMessage(void);

	for(int i=99; i>1;i--)
	{
		printBottles (i);
	}//end for loop

	printEndMessage();
	getch();
	return 0;
}//End main

void printHeading()
{
	cout<<"This program will print out the lyrics to the song"<<endl;
	cout<<"99 BOTTLES OF BEER. Minimally, thus program is required"<<endl;
	cout<<"To use a FOR loop but will also make us of"<<endl;
	cout<<"Functions and headers."<<endl;
	return;
}//End function

void printBottles (int i)
{
	if(i==1)
	{
		cout<<endl<<endl<<i<<" Bottle of beer on the wall.";
		cout<<endl<<i<<" Bottle of beer.";
		cout<<endl<<(i-1)<<" Take one down and pass it around";
		cout<<endl<<(i-1)<<" bottles of beer on the wall.";
	}

	else
		cout<<endl<<endl<<i<<" Bottles of beer on the wall.";
		cout<<endl<<endl<<i<<" Bottles of beer on the wall.";
		cout<<endl<<i<<" Bottles of Beer.";
		cout<<endl<<"Take one down and pass it around.";

		if((i-1)==1)
			cout<<endl<<(i-1)<<" Bottle of Beer on the wall.";
}
void printEndMessage()
{
	cout<<"\n\nProgram Complete. Song ended.";
	cout<<"\nPlease press ENTER to end program.";
	return;
}//end function
		










