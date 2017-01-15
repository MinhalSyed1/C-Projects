// Project9b MinhalSyed.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<conio.h>

int main(void)
{
	int row,col;//Counters for 'for loops'
	int multiArray[8][8];//Multi array 7 rows high, 7 columns wide

	for(row=1; row<8;row++)
		for(col=1;col<8;col++)
			multiArray[row][col]=row*col;
	
	for(row=1;row<8;row++)
	{
	for(col=1;col<8;col++)
		printf("%5d",multiArray[row][col]);
		printf("\n");//Newline for each increase in row
	}
	getch();
	return 0;
}
