// Project12b MinhalSyed.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<conio.h>

int main(void)
{
	FILE*outputFile;	//Set pointer to file memory location
	char nameString[3][25]={"Bill Smith","Bob Warns","Julia Ramone"};
	float firstBill[3]={23.45,56.67,83.56};//Declare arrays of values
	float secondBill[3]={14.56,23.90,53.20};
	float thirdBill[3]={2.30,56.78,102.40};
	int count;

	//Use the 'fopen' function to open the file on the a: drive to write
		outputFile=fopen("E//:numbers1.txt","w");//open for writing to file on a

		for(count=0;count<3;count++)
		{
			//print to screen
			printf("%s\t%5.2f%5.2f %5.2f\n",nameString[count],firstBill[count],secondBill[count],thirdBill[count]);
			
			//print to file
			fprintf(outputFile,"%s\t%5.2f%5.2f%5.2f\n",nameString[count],firstBill[count],secondBill[count],thirdBill[count]);
		}
		fclose(outputFile);	
	getch();
	return 0;
}
