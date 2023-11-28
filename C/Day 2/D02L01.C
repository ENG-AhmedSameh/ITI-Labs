#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main(void){
	int n,x,y,i=1,dx,dy;
	system("cls");
	do{
		printf("Please enter an odd number >1 : ");
		scanf("%d",&n);
	}while(n<=1||n%2==0);
	system("cls");

	dx=(80)/(n+1);
	dy=(25)/(n+1);

	x=(n/2)+1;
	y=1;
	gotoxy(dx*x,y*dy);
	printf("%d",1);
	for(i=2;i<=n*n;i++){
	 if(i % n !=0){
	  y--;
	  x--;
	  if(y < 1)
	   y=n;
	  if(x < 1)
	   x=n;

	}else{
		y++;
		if(y > n)
		 y=1;
		}
		gotoxy(x*dx,y*dy);
		printf("%d",i);
	}
	getch();
}