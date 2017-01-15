// Project9 MinhalSyed.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<conio.h>

int main(void)
{
	int row,col;
	int multiArray[4][3]={{10,5,-3},//Notice the use of curly brackets
						{9,0,0},	//For rows high, three columns wide
						{32,20,1},	//Spot the commas!
						{0,0,8}};
	printf("This is the array.\n\n");
	
	for(row=0;row<4;row++)
	{
		for(col=0;col<3;col++)
			printf(" %2d",multiArray[row][col]);
			printf("\n");
	}
	getch();
	return 0;
}
