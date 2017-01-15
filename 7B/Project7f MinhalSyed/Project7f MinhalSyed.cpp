// Project7f MinhalSyed.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>

int main(void)
{
	char tmp;
	int sum=0;
	int count=0;

	do
	{
	printf("Enter a numeric character....");
	fflush(stdin);
	scanf("%c",&tmp);//Is entered as a keyboard character

	printf("The character entered is %c\n",tmp);

		if(isdigit(tmp))//Replaces if(('0'<=tmp)&&(tmp<='0'))
			//Is it a digit? returns a non-0 if tmp is a figit, returns 0 if false

		{
			sum+=(tmp-0x30);//converts ASCII character you entered to integer value
							//The 'x'is an'x'not multiply
			count++;
		}
		else
		{
		printf("ERROR this is a -non-numeric entry");
		}
	}while(count<3);
		printf("The sum is %d",sum);
	
	getch();
	return 0;
}
