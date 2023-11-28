#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void displayBorders(void);
void displayMainMenu(void);
void displayEmployeeDataTitles(void);
void displayNewEmployeeScreen(void);
void saveEmployeeData(char id[],char name[],int salary,int bouns,int deduct);
void displayEmployeesData();
#define NORMAL_ATTR 0x07
#define HILIGHT_ATTR 0x70
struct Employee{
    char ID[50],Name[50];
    float Salary,Bouns,Deduct;
}emp;
int currentEmployee = 0;

void main(void) {
    displayMainMenu();
	//getch();
}

void displayBorders(void){
    int i=0;
    for(i=0;i<25;i++){
        gotoxy(15+i*2,5);
        printf("*");

        gotoxy(15+i*2,25-5);
        printf("*");
    }
    for(i=0;i<=15;i++){
    
        gotoxy(15,5+i);
        printf("*");
        
        gotoxy(80-15,5+i);
        printf("*");
    }
}

void displayMainMenu(void){
    int currentOption = 0,i;
	char ch;
	char options[3][11] ={{'N','e','w',' ',' ',' ',' ','\0'},{'D','i','s','p','l','a','y','\0'},{'E','x','i','t',' ',' ',' ','\0'}};
    system("cls");
	displayBorders();
    gotoxy(20,8);
    printf("Main Menu");
    do {
		for(i=0;i<3;i++){
			gotoxy(36,10+2*i);
			if(currentOption == i){
                textattr(HILIGHT_ATTR);
                cprintf("%s",options[i]);
            }else{
                textattr(NORMAL_ATTR);
                cprintf("%s",options[i]);
            }
		}
        //printf("\x1b[0m");

		ch = getch();
		if(ch == 80){
			currentOption++;
			currentOption%=3;
		}else if (ch == 72){
			currentOption--;
			if (currentOption == -1)  currentOption =2;
		}
	} while (ch != 13);

    switch (currentOption)
    {
        case 0:
            displayNewEmployeeScreen();
            break;
        case 1:
            displayEmployeesData();
            break;
        case 2:
            break;
        default:
            break;
    }
}

void displayNewEmployeeScreen(void){
    char tempID[50],tempName[50];
    int i=0,tempSalary,tempBouns,tempDeduct,currentPosition=0;
    char c;
    if(currentEmployee == 1){
        system("cls");
        displayBorders();
		gotoxy(23,10);
		printf("There is already saved employee !!!");
		gotoxy(23,13);
        printf(" Press any key to back to Main Menu");
        getch();
        displayMainMenu();
        return;
    }
    displayEmployeeDataTitles();
    gotoxy(25,18);
    printf("\x1b[97mSave");   
    gotoxy(50,18);
    printf("\x1b[97mBack");
    printf("\x1b[0m");

    gotoxy(43,6);
    scanf("%s",&tempID);
    gotoxy(43,8);
    getchar();
    gets(tempName);
    gotoxy(43,10);
    scanf("%d",&tempSalary);
    gotoxy(43,12);
    scanf("%d",&tempBouns);
    gotoxy(43,14);
    scanf("%d",&tempDeduct);
    do{
        gotoxy(25,18);
        currentPosition == 0 ? textattr(HILIGHT_ATTR):textattr(NORMAL_ATTR);
        cprintf("Save");
        gotoxy(50,18);
        currentPosition == 1 ? textattr(HILIGHT_ATTR):textattr(NORMAL_ATTR);
        cprintf("Back");
        //printf("\x1b[0m");
        c = getch();
        if (c ==0)
            c = getch();
        if (c == 75 && currentPosition ==1)
            currentPosition = 0;
        else if(c == 77 && currentPosition ==0)
            currentPosition = 1;
    }while(c != 13);
    if (currentPosition == 0){
        saveEmployeeData(tempID,tempName,tempSalary,tempBouns,tempDeduct);
        displayMainMenu();
    }else
        displayMainMenu();
}

void saveEmployeeData(char id[],char name[],int salary,int bouns,int deduct){
    int i=0;
    char c,d;
    for (i=0;i<50;i++){
        emp.ID[i] = id[i];
        emp.Name[i] = name[i];
    }
    emp.Salary = salary;
    emp.Bouns = bouns;
    emp.Deduct = deduct;
    currentEmployee++;
    currentEmployee = 1;
}

void displayEmployeesData(){
    int i=0,isExtendedKey = 1, currentPosition=0;
    float netSalary;
    char ch = 77;
    if (currentEmployee == 0){
        system("cls");
        displayBorders();
        gotoxy(20,10);
        printf("There is no Employees to be displayed!!!");
        gotoxy(20,13);
        printf("  Press any key to back to Main Menu");
        getch();
        displayMainMenu();
        return;
    }
    displayEmployeeDataTitles();
    do{
        system("cls");
        displayBorders();
        gotoxy(30,10);
        printf("ID \t: ");
        gotoxy(30,12);
        printf("Name\t: ");
        gotoxy(30,14);
        printf("Net Salary\t: ");
        gotoxy(18,5);
        printf("Employee(%d of %d)",i+1 , currentEmployee);
        gotoxy(43,10);
        printf("%s",emp.ID);
        gotoxy(43,12);
        printf("%s",emp.Name);
        gotoxy(43,14);
        netSalary = emp.Salary + emp.Bouns - emp.Deduct;
        printf("%0.2f",netSalary);

        gotoxy(50,18);
        cprintf("Back");
    
        //do{
            ch = getch();
        /*    printf("%d",ch);
        }while(ch != 97 ||ch != 100|| ch != 27);*/
        
        switch (ch)
        {
            case 27:
                currentPosition = 2;
                break;
        }
    }while(ch!= 27);

    displayMainMenu();
}

void displayEmployeeDataTitles(void){
    system("cls");
    displayBorders();
    gotoxy(30,6);
    printf("ID \t: ");
    gotoxy(30,8);
    printf("Name\t: ");
    gotoxy(30,10);
    printf("Salary\t: ");
    gotoxy(30,12);
    printf("Bouns\t: ");
    gotoxy(30,14);
    printf("Deduct\t: ");
}