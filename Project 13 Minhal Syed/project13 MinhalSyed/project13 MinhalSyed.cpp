// project13 MinhalSyed.cpp : Defines the entry point for the console application.
//

#include"stdafx.h"
#include<stdio.h>
#include<conio.h>
#include<string.h>

struct CD//Declare structure data type CD above main function
{
	int cdNumber;
	float price;
	char CDtitle[30];
	char song[20];
};//DONT FORGET THE SEMI COLON!

int main(void)
{
	struct CD record1;//Declare structure variables
	struct CD record2;

	//INITIALIZE MEMBER VARIABLES FOR RECORD 1//
	
	record1.cdNumber=101;
	record1.price=23.45;
	strcpy(record1.CDtitle,"Moon Rockets"); //String copy "Moon Rockets" to record1.CDtitle
	strcpy(record1.song,"Green Cheese");	//Ditto "Green Cheese"

	//Use the DOT operator to signify that variables belong to record2
	
	record2.cdNumber=102;
	record2.price=18.45;
	strcpy(record2.CDtitle,"Ear=Full");//String copy "Ear-Full" to record2.CDtitle
	strcpy(record2.song,"Decibel Gun");//Ditto strcpy
	
//Print record1 to the screem

	printf("\nHere is the CD information in record1...\n");

	printf("\nCD record number: %d",record1.cdNumber);//Dot operators
	printf("\n           Price: %.2f",record1.price);
	printf("\n        CD title: %s",record1.CDtitle);
	printf("\n      Song title: %s",record1.song);

	//Print record2 to the screem

	printf("\n\nHere is the CD information in record2...\n");

	printf("\nCD record number: %d",record2.cdNumber);//Dot operators
	printf("\n           Price: %.2f",record2.price);
	printf("\n        CD title: %s",record2.CDtitle);
	printf("\n      Song title: %s",record2.song);

	getch();
	return 0;
}