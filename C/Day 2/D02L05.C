#include <stdio.h>
#include <stdlib.h>
int main() {
	int i,j,n=10;
	int dx,dy;
   /*	system("cls");
	printf("Enter the number you want to display until it : ");
	scanf("%d",&n); */
	dx=80.0/(n+1);
	dy=25.0/(n+1);
	system("cls");

	/*draw the horizontal numbers of the
	multiple table and the stars under it*/
	for(i=n;i>=1;i--){
		gotoxy((n-i+1)*dx,1);
		printf("%d",i);
		gotoxy((n-i+1)*dx,2);
		printf("*");
	}

	/*draw the vertical numbers of the
	multiple table and the stars beside it*/
	for(i=n;i>=1;i--){
		gotoxy(1,(n-i+1)*dy+1);
		printf("%d",i);
		gotoxy(3,(n-i+1)*dy+1);
		printf("*");
	}
	//draw the content of the table
	for(i=n;i>=1;i--){
		for(j=n;j>=1;j--){
			gotoxy((n-i+1)*dx,(n-j+1)*dy+dy/2);
			printf("%d",i*j);
		}
	}
    getch();
}