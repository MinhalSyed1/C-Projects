// project12f MinhalSyed.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main(void)
{
	int flag=0;
	char name[15];
	char sinNum[12];
	float rate,hours,total;
	FILE*payFile,*payoutFile;

		payFile=fopen("E:pay.txt","r");//Open file to read
		payoutFile=fopen("E:payout.txt","a");//Open file tot append

		//Insert file checking routine here

		flag=1;
		fprintf(payoutFile,"\nNew entry after this line!");//Mark append point in existing file

		while(flag==1)
		{

			while(!feof(payFile))
			{
				fscanf(payFile,"%14s%11s%f%f",name,sinNum,&rate,&hours);
				fgetc(payFile);

				total=rate*hours;
				fprintf(payoutFile,"\n%s	\t%s\t%6.2f",name,sinNum,total);

				printf("\n%s	\t%s\t%6.2f",name,sinNum,total);
			}//End innter loop

			fclose(payFile);
			fclose(payoutFile);

			flag=0;
		}//end outer while
	getch();
	return 0;
}
