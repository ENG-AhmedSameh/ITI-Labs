#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void swap (int *x,int *y);

int main(void){
	int n1 , n2;
	system("cls");
	printf("Enter The Two Nunmbers: ");
	scanf("%d",&n1);
	scanf("%d",&n2);
	printf("Before Calling Swapping functions n1 = %d And n2 = %d",n1,n2);
	swap(&n1,&n2);
	printf("\nAfter calling swapping function n1 = %d And n2 = %d",n1,n2);
	getch();

	return 0;
}
void swap (int *x,int *y){
    int temp = *y;
    *y = *x;
    *x = temp;
}