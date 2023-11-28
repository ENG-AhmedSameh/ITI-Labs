#include <stdio.h>
#include<conio.h>
void main(void)
{
	int arr[5],readCounter,writeCounter;
	clrscr();
	for(readCounter=0;readCounter<5;readCounter++)
	{
		printf("\nPlease Enter next number: ");
		scanf("%d",&arr[readCounter]);
	}
	for(writeCounter=0;writeCounter<5;writeCounter++)
	{
		printf("%d \n",arr[writeCounter]);
	}
	getch();
}