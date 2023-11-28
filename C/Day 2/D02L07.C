#include <stdio.h>
#include<stdlib.h>
void main(void)
{
	int arr[5],i,j,min,max;
	system("cls");
	for(i=0;i<5;i++)
	{
		printf("\nPlease Enter Next number: ");
		scanf("%d",&arr[i]);
	}
	min=arr[0];
	max=arr[0];
	for(j=0;j<5;j++)
	{
		if (arr[j]<min)
		min=arr[j];
	}
	printf("The minimum value is : %d \n",min);
	for(j=0;j<5;j++)
	{
		if (arr[j]>max)
		max=arr[j];
	}
	printf("The maximum value is : %d \n",max);
	getch();
}