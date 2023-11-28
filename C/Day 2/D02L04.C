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
	for(i=1;i<=n;i++){
		gotoxy(i*dx,1);
		printf("%d",i);
		gotoxy(i*dx,2);
		printf("*");
	}

	/*draw the vertical numbers of the
	multiple table and the stars beside it*/
	for(i=1;i<=n;i++){
		gotoxy(1,i*dy+1);
		printf("%d",i);
		gotoxy(3,i*dy+1);
		printf("*");
	}
	//draw the content of the table
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			gotoxy(i*dx,j*dy+dy/2);
			printf("%d",i*j);
		}
	}
    getch();
}