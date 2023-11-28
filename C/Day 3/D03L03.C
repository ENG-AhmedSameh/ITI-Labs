#include <stdio.h>
#include <stdlib.h>
float getPower(float num , int pow);
int main() {
    float n;
    int p;
    system("cls");
    printf("Please Enter the number: ");
    scanf("%f",&n);
    printf("\nPlease enter the power: ");
    scanf("%d",&p);
	printf("\nThe result = %0.8f",getPower(n,p));
    getch();
}
float getPower(float num , int pow){
    if(pow<0)
    {
        return 1/getPower(num,-1*pow);
    }
    if(pow == 1)
        return num;
    return num * getPower(num,pow-1);
}