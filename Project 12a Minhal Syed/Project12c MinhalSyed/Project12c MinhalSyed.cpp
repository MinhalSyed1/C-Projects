// Project12c MinhalSyed.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<conio.h>


int main(void)
{

	FILE*outputFile;//Set pointer to file memory location
	char nameString[3][25];
	float firstBill[3];
	float secondBill[3];
	int count;
	
	//Use the 'fopen' function to open the file on the e drive to write
	outputFile=fopen("E:numbers.txt","w");//Open for writing

	for(count=1;count<3;count++)
	{
		printf("\nEnter the name of the client:");
		scanf("%[^\n]",nameString[count]);
		fflush(stdin);

		printf("\nEnter amount of first bill:");
		scanf("%f",&firstBill[count]);
		printf("\nEnter amount of second bill:");
		scanf("%f",&secondBill[count]);
		fflush(stdin);
	}

	printf("\nPlease wait while processing takes place...");


	for(count=1;count<3;count++)//Print array to text file
		fprintf(outputFile,"%s\t%5.2f\t%5.2f\n",nameString[count],firstBill[count],secondBill[count]);

	fclose(outputFile);//close the file

	for(count=1;count<3;count++)//Print Arrays to the screen
		printf("\n%s\t%5.2f\t%5.2f\n",nameString[count],firstBill[count],secondBill[count]);
	
	getch();
	return 0;
}
