#include <stdlib.h>

int main(){
	//Declartion Variables
	char c;
	int asciiValue;
	//Initialization of variables
	system("cls");
	printf("Please enter one charachter: ");
	c = getch();
	asciiValue = (int)c;
	printf("\nThe charachter you entered is %c and its ASCII code is %d",c,asciiValue);
	getch();
	return 0;
}