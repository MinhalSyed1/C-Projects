// project12h MinhalSyed.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main(void)
{
	FILE*salesFile;		//Pointer for sales file
	int row,col,count;	//counters for loops
	float array1[2][6];
	int arrayID[2];

	salesFile=fopen("E:sales1.txt","r");//open file

	//insert file check routine here
		while(!feof(salesFile))//load slaesFile into array 1 and arrayID until EOF
		{
			for(row=0;row<2;row++)
			{
				for(col=0;col<6;col++)
				{
					if(col==0)
					{
						fscanf(salesFile,"%d",&arrayID[row]);
					}//end if
					else
					{
						fscanf(salesFile,"%f",&array1[row][col-1]);
					}//end else
					fgetc(salesFile);
				}//End inner for loop
			}//end outer for loop
		}//end While loop

		fclose(salesFile);//close slaes.txt

		printf("\nID NUMBERS from ID array");//print ID numbers to the screen
			for(count=0;count<2;count++)
				printf("\n%d",arrayID[count]);
			printf("\n\n");
						//Print sales figures to the screen
			printf("SALES FIGURES from array1\n");
				for(row=0;row<2;row++)
				{
					for(col=1;col<6;col++)
						printf("%6.2f",array1[row][col-1]);
					printf("\n");
				}
				printf("\n\n");
				//print combined ID number and sales figures to the screen
				printf("ID NUMBER	SALES FIGURES");

				for(row=0;row<2;row++)
				{
					printf("\n");
					for(col=0;col<6;col++)
					{
						if(col==0)
							printf("%d	",arrayID[row]);
						else
						printf("7.2f",array1[row][col-1]);
					}//end inner for loop
				}//end outer for loop
				
	getch();
	return 0;
}
