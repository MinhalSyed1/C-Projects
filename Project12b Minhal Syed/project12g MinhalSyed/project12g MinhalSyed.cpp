// project12g MinhalSyed.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main(void)
{
	FILE*salesFile;	//pointer for sales.txt
	int row,col;	//Vars for row column
	float array1[4][6];

	salesFile=fopen("E:sales.txt","r");//Open File

	if(salesFile==NULL)//Checl that file is available
	{
		printf("salesFile could not be opened. Program will Exit");
		getch();
		exit(1);
	}

	while(!feof(salesFile))//Load salesFile into array1 until EOF
	{
		for(row=0;row<4;row++)
		{
			for(col=0;col<6;col++)
			{
				fscanf(salesFile,"%f",&array1[row][col]);
				fgetc(salesFile);
			}
		}
	}//end while loop

	fclose(salesFile);//close sales.txt

	for(row=0;row<4;row++)//Print to screen
	{
		for(col=0;col<6;col++)
			printf("%6.2f",array1[row][col]);
		printf("\n");
	}
	getch();
	return 0;

}
