#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void displayBorders(void);
void displayMainMenu(void);
void displayEmployeeDataTitles(void);
void displayNewEmployeeScreen(void);
void saveEmployeeData(char id[],char name[],int salary,int bouns,int deduct);
void displayEmployeesData();
void getNumberOfEmployees(void);
#define NORMAL_ATTR 0x07
#define HILIGHT_ATTR 0x70

struct Employee{
    char ID[50],Name[50];
    int Salary,Bouns,Deduct;
};
int size = 0;
int currentEmployee = 0;
struct Employee * empArr;
int main(void){
    displayMainMenu();
    free(empArr);
    return 0;
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

void getNumberOfEmployees(void){
    // int size ;
    system("cls");
    displayBorders();
    gotoxy(24,12);
    printf("Enter the number of Employees");
    gotoxy(30,13);
    printf("you want to insert: ");
    scanf("%d",&size);
    empArr = (struct Employee *)malloc(size*sizeof(struct Employee));
    //saveEmployesData();
    //displayMainMenu();
}

void displayNewEmployeeScreen(void){
    char tempID[50],tempName[50];
    int i=0,tempSalary,tempBouns,tempDeduct,currentPosition=0;
    char c;
    if(size == 0){
        getNumberOfEmployees();
    }else if(currentEmployee == size){
        system("cls");
        displayBorders();
        gotoxy(20,10);
        printf("You reached Maximum Number of employees!!!");
        gotoxy(20,13);
        printf("  Press any key to back to Main Menu");
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

/*void saveEmployesData(void){
    int i;
    for(i = 0;i<size;i++){
        displayBorders();
        displayEmployeeDataTitles();
        gotoxy(18,6);
        printf("Enter Data of Employee(%d of %d)",i+1 ,size);
        gotoxy(43,8);
        scanf("%s",&empArr[i].ID);
        gotoxy(43,10);
        getchar();
        gets(empArr[i].Name);
        gotoxy(43,12);
        scanf("%d",&empArr[i].Salary);
        gotoxy(43,14);
        scanf("%d",&empArr[i].Bouns);
        gotoxy(43,16);
        scanf("%d",&empArr[i].Deduct);
    }
}*/
void saveEmployeeData(char id[],char name[],int salary,int bouns,int deduct){
    int i=0;
    char c,d;
    for (i=0;i<50;i++){
        empArr[currentEmployee].ID[i] = id[i];
        empArr[currentEmployee].Name[i] = name[i];
    }
    empArr[currentEmployee].Salary = salary;
    empArr[currentEmployee].Bouns = bouns;
    empArr[currentEmployee].Deduct = deduct;
    currentEmployee++;
}

void displayEmployeesData(void){
    int i=0,currentPosition=0;
    float netSalary;
    char ch = 77;
    if (size == 0||currentEmployee == 0){
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
        gotoxy(18,6);
        printf("Saved Employee(%d of %d) note:Max = %d",i+1 ,currentEmployee,size);
        gotoxy(43,10);
        printf("%s",empArr[i].ID);
        gotoxy(43,12);
        printf("%s",empArr[i].Name);
        gotoxy(43,14);
        netSalary = empArr[i].Salary + empArr[i].Bouns - empArr[i].Deduct;
        printf("%0.2f",netSalary);

        gotoxy(20,18);
        currentPosition == 0 ? textattr(HILIGHT_ATTR):textattr(NORMAL_ATTR);
        cprintf("<<");
        gotoxy(25,18);
        currentPosition == 1 ? textattr(HILIGHT_ATTR):textattr(NORMAL_ATTR);
        cprintf(">>");
        gotoxy(50,18);
        currentPosition == 2 ? textattr(HILIGHT_ATTR):textattr(NORMAL_ATTR);
        cprintf("Back");
        if (ch==97)
                currentPosition = 0;
        else if(ch == 100)
                currentPosition = 1;
        gotoxy(20,18);
        currentPosition == 0 ? textattr(HILIGHT_ATTR):textattr(NORMAL_ATTR);
        cprintf("<<");
        gotoxy(25,18);
        currentPosition == 1 ? textattr(HILIGHT_ATTR):textattr(NORMAL_ATTR);
        cprintf(">>");
        gotoxy(50,18);
        currentPosition == 2 ? textattr(HILIGHT_ATTR):textattr(NORMAL_ATTR);
        cprintf("Back");
        //do{
            ch = getch();
        /*    printf("%d",ch);
        }while(ch != 97 ||ch != 100|| ch != 27);*/
        
        switch (ch)
        {
            case 97:
                if (i>0)
                    i--;
                else
                    i=currentEmployee-1;
                break;
            case 100:
                if (i<currentEmployee-1)
                    i++;
                else
                    i = 0;
                break;
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