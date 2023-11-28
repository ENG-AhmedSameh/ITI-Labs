#include <stdio.h>
#include <stdlib.h>

void main(void) {
	int currentOption = 0,i;
	char ch;
	char options[3][8] ={{'N','e','w',' ',' ',' ',' ','\0'},{'D','i','s','p','l','a','y','\0'},{'E','x','i','t',' ',' ',' ','\0'}};
	do {
		system("cls");
		for(i=0;i<3;i++){
			gotoxy(31,12+i);
			currentOption == i  ? printf("-->%s\n",options[i]) : printf("%s\n",options[i]);
		}

		ch = getch();
		if(ch == 80){
			currentOption++;
			currentOption%=3;
		}else if (ch == 72){
			currentOption--;
			if (currentOption == -1)  currentOption =2;
		}
	} while (ch != 13);

	gotoxy(40,15);
	printf("\n You choosed option : %s",options[currentOption]);
	getch();
    
}