#include <stdio.h>
#include <stdlib.h>
void displayBorders(int dx, int dy, int initialXPosition,int initialYPosition);
void takeAndDisplayNumbers(int dx, int dy, int initialXPosition,int initialYPosition);
int main() {
	int dx=10,dy=4,initialXPosition,initialYPosition;
	initialXPosition = (80-5.5*dx)/2; //5.5 places (0.5 for sum and 4 places for numbers and 1 place for vertical line)
	initialYPosition = (25-4*dy)/2;
	system("cls");
	displayBorders(dx, dy, initialXPosition, initialYPosition);
	takeAndDisplayNumbers(dx, dy, initialXPosition, initialYPosition);
	getch();
}

void displayBorders(int dx, int dy, int initialXPosition,int initialYPosition){
	int i;
	/*draw the horizontal numbers of the
	multiple table and the stars under it*/
	for(i=1;i<=4;i++){
		gotoxy(initialXPosition+i*dx,initialYPosition);
		printf("%d",i);
		gotoxy(initialXPosition+i*dx,initialYPosition+1);
		printf("*");
	}
	gotoxy(initialXPosition+5*dx,initialYPosition);
	printf("Sum");	
	gotoxy(initialXPosition+5*dx,initialYPosition+1);
	printf("*");

	/*draw the vertical numbers of the
	multiple table and the stars beside it*/
	for(i=1;i<=3;i++){
		gotoxy(initialXPosition,initialYPosition+i*dy);
		printf("%d",i);
		gotoxy(initialXPosition+3,initialYPosition+i*dy);
		printf("*");
	}
	gotoxy(initialXPosition,initialYPosition+4*dy);
	printf("AVG");
	gotoxy(initialXPosition+3,initialYPosition+4*dy);
	printf("*");
}

void takeAndDisplayNumbers(int dx, int dy, int initialXPosition,int initialYPosition){
	int i,j;
	int arr[3][4];
	int sum[3];
	float avg[5] ={0,0,0,0,0};
	for(i=1;i<=3;i++){
		for(j=1;j<=4;j++){
			gotoxy(initialXPosition+j*dx,initialYPosition+i*dy);
			scanf("%d",&arr[i-1][j-1]);
			avg[j-1]+=arr[i-1][j-1]/3.0;
			if(i==3){
				gotoxy(initialXPosition+j*dx,initialYPosition+i*dy+dy);
				printf("%0.2f",avg[j-1]);
			}
		}
		gotoxy(initialXPosition+5*dx,initialYPosition+i*dy);
		sum[i-1]=arr[i-1][0]+arr[i-1][1]+arr[i-1][2]+arr[i-1][3];
		printf("%d",sum[i-1]);
	}
	gotoxy(initialXPosition+5*dx,initialYPosition+4*dy);
	printf("%0.2f",(avg[0]+avg[1]+avg[2]+avg[3])/4.0);
}