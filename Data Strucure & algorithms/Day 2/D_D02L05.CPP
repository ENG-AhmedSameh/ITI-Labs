#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<iostream.h>
#include<string.h>
void displayBorders(void);
void displayMainMenu(void);
void displayEmployeeDataTitles(void);
void displayNewEmployeeScreen(void);
void saveEmployeeData(int id,char name[],int salary,int bouns,int deduct);
void displayEmployeesData();
void getNumberOfEmployees(void);
void searchForEmployeeScreen();
int searchByID();
int searchByName();
int getEmployeeIndexByID(int id);
int getEmployeeIndexByName(char * tempName);
void displaySelectedEmployeeData(int index);
void deleteEmployeeDateScreen();
void deleteByIndex(int index);
void displaySortScreen();
void sortEmployeesById(int size);
void sortEmployeesByName(int size);
void sortEmployeesByNetSalary(int size);
//void swapEmployees(Employee& emp1, Employee& emp2);

#define NORMAL_ATTR 0x07
#define HILIGHT_ATTR 0x70

struct Employee{
	char Name[50];
	int ID,Salary,Bouns,Deduct;
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
	char options[6][11] ={{'N','e','w',' ',' ',' ',' ','\0'},{'D','i','s','p','l','a','y','\0'},{'S','e','a','r','c','h',' ','\0'},{'D','e','l','e','t','e',' ','\0'},{'S','o','r','t',' ',' ',' ','\0'},{'E','x','i','t',' ',' ',' ','\0'}};
	system("cls");
	displayBorders();
	gotoxy(20,6);
	printf("Main Menu");
	do {
		for(i=0;i<6;i++){
			gotoxy(36,8+2*i);
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
			currentOption%=6;
		}else if (ch == 72){
			currentOption--;
			if (currentOption == -1)  currentOption =5;
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
			searchForEmployeeScreen();
			break;
		case 3:
		    deleteEmployeeDateScreen();
		    break;
        case 4:
            displaySortScreen();
			
		default:
			break;
	}
}

void displaySortScreen(){

    int currentOption = 0,i;
	char ch;
	char options[3][11] ={{'I','D',' ',' ',' ',' ',' ',' ',' ',' ','\0'},{'N','A','M','E',' ',' ',' ',' ',' ',' ','\0'},{'N','e','t',' ','S','a','l','a','r','y','\0'}};
	system("cls");
	displayBorders();
	gotoxy(20,6);
	printf("Sort By: ");
	do {
		for(i=0;i<3;i++){
			gotoxy(36,12+2*i);
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
	} while (ch != 13&&ch != 27);
    if (ch == 13){
        switch (currentOption)
        {
            case 0:
                sortEmployeesById(currentEmployee);
                break;
            case 1:
                sortEmployeesByName(currentEmployee);
                break;
            case 2:
                sortEmployeesByNetSalary(currentEmployee);
                break;
            default:
                break;
        }
        displayEmployeesData();
    }else if(ch == 27)
        displayMainMenu();
}

void swapEmployees(Employee& emp1, Employee& emp2){
    int tempID = emp1.ID;
    emp1.ID = emp2.ID;
    emp2.ID = tempID;

    char tempName[50];
    strcpy(tempName,emp1.Name);
    strcpy(emp1.Name,emp2.Name);
    strcpy(emp2.Name,tempName);

    int tempSalary = emp1.Salary;
    emp1.Salary = emp2.Salary;
    emp2.Salary = tempSalary;

    int tempBouns = emp1.Bouns;
    emp1.Bouns = emp2.Bouns;
    emp2.Bouns = tempBouns;

    int tempDeduct = emp1.Deduct;
    emp1.Deduct = emp2.Deduct;
    emp2.Deduct = tempDeduct;
}

void sortEmployeesById(int size){
    for (int i=0;i<size-1;i++){
		int minIndex=i;
		for (int j=i+1;j<size;j++)
        
			if(empArr[j].ID<empArr[minIndex].ID)
				minIndex=j;
		swapEmployees(empArr[i],empArr[minIndex]);
	}
}
void sortEmployeesByName(int size){
    for (int i=0;i<size-1;i++){
		int minIndex=i;
		for (int j=i+1;j<size;j++)
        
			if(strcmp(empArr[j].Name,empArr[minIndex].Name)<0)
				minIndex=j;
		swapEmployees(empArr[i],empArr[minIndex]);
	}
}
void sortEmployeesByNetSalary(int size){
    int netSalary1, netSalary2;
    for (int i=0;i<size-1;i++){
		int minIndex=i;
		for (int j=i+1;j<size;j++){
            netSalary1= empArr[j].Salary + empArr[j].Bouns - empArr[j].Deduct;
            netSalary2= empArr[minIndex].Salary + empArr[minIndex].Bouns - empArr[minIndex].Deduct;
			if(netSalary1<netSalary2)
				minIndex=j;
        }
		swapEmployees(empArr[i],empArr[minIndex]);
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
	char tempName[50];
	int i=0,tempID,tempSalary,tempBouns,tempDeduct,currentPosition=0;
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
	scanf("%d",&tempID);
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


void saveEmployeeData(int id,char name[],int salary,int bouns,int deduct){
	int i=0;
	char c,d;
	for (i=0;i<50;i++){
		empArr[currentEmployee].ID = id;
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
		printf("%d",empArr[i].ID);
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
		currentPosition == 3 ? textattr(HILIGHT_ATTR):textattr(NORMAL_ATTR);
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
		currentPosition == 3 ? textattr(HILIGHT_ATTR):textattr(NORMAL_ATTR);
		cprintf("Back");
		do{
			ch = getch();
		}while(ch != 97 &&ch != 100&& ch != 27);

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
				currentPosition = 3;
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

void searchForEmployeeScreen(){
	int searchOption=0;
	char ch;
	if (size == 0||currentEmployee == 0){
		system("cls");
		displayBorders();
		gotoxy(20,10);
		printf("There is no Employees to Search IN!!!");
		gotoxy(20,13);
		printf("  Press any key to back to Main Menu");
		getch();
		displayMainMenu();
		return;
	}
	clrscr();
	displayBorders();
	gotoxy(20,6);
	printf("Choose what you want to search with: ");

	do {
		if(searchOption == 0){
			gotoxy(36,12);
			textattr(HILIGHT_ATTR);
			cprintf("%s","ID  ");
		}else{
			gotoxy(36,12);
			textattr(NORMAL_ATTR);
			cprintf("%s","ID  ");
		}
		if(searchOption == 1){
			gotoxy(36,14);
			textattr(HILIGHT_ATTR);
			cprintf("%s","Name");
		}else{
			gotoxy(36,14);
			textattr(NORMAL_ATTR);
			cprintf("%s","Name");
		}

		ch = getch();
		if(ch == 80||ch ==72){
			if(searchOption==0)
				searchOption = 1;
			else
				searchOption = 0;
		}
	} while (ch != 13);
	textattr(NORMAL_ATTR);
	int index;
	switch (searchOption)
	{
		case 0:
			index=searchByID();
			break;
		case 1:
			index=searchByName();
			break;
		default:
			break;
	}

	clrscr();
	displayBorders();
	if(index>-1){
		displaySelectedEmployeeData(index);
		gotoxy(50,18);
		textattr(HILIGHT_ATTR);
		cprintf("Back");
		textattr(NORMAL_ATTR);
		char ch;
		do{
			ch = getch();
		}while(ch!=27&&ch!=13);
		displayMainMenu();
	}
	else if (index==-1){
		gotoxy(20,10);
		printf("No Employee is found with this Data!!!");
		gotoxy(20,13);
		printf("  Press any key to back to Main Menu");
		getch();
		displayMainMenu();
		//return;
	}
	//return;
}

int searchByID(){
	int index;
	int tempID;
	gotoxy(30,18);
	printf("Enter ID: ");
	cin>>tempID;
	index= getEmployeeIndexByID(tempID);
	return index;
}

int searchByName(){
	int index;
	char* tempName;
	gotoxy(30,18);
	printf("Enter Name: ");
	cin>>tempName;
	index= getEmployeeIndexByName(tempName);
	return index;
}

void displaySelectedEmployeeData(int index){
	system("cls");
	displayBorders();
	gotoxy(30,10);
	printf("ID \t: ");
	gotoxy(30,12);
	printf("Name\t: ");
	gotoxy(30,14);
	printf("Net Salary\t: ");
	gotoxy(43,10);
	printf("%d",empArr[index].ID);
	gotoxy(43,12);
	printf("%s",empArr[index].Name);
	gotoxy(43,14);
	float netSalary = empArr[index].Salary + empArr[index].Bouns - empArr[index].Deduct;
	printf("%0.2f",netSalary);
	
}


int getEmployeeIndexByID(int tempID){
	int i;
	for(i=0;i<currentEmployee;i++){
		if(empArr[i].ID==tempID)
			return i;
	}
	return -1;
}
int getEmployeeIndexByName(char * tempName){
	int i;
	for(i=0;i<currentEmployee;i++){
		if(strcmp(empArr[i].Name,tempName)==0)
			return i;
	}
	return -1;
}

void deleteEmployeeDateScreen(){
	int searchOption=0,index,currentOption=0;
	char ch;
	if (size == 0||currentEmployee == 0){
		system("cls");
		displayBorders();
		gotoxy(20,10);
		printf("There is no Employees to Delete from!!!");
		gotoxy(20,13);
		printf("  Press any key to back to Main Menu");
		getch();
		displayMainMenu();
		return;
	}
	clrscr();
	displayBorders();
	gotoxy(20,6);
	printf("Choose what you want to delete with: ");

	do {
		if(searchOption == 0){
			gotoxy(36,12);
			textattr(HILIGHT_ATTR);
			cprintf("%s","ID  ");
		}else{
			gotoxy(36,12);
			textattr(NORMAL_ATTR);
			cprintf("%s","ID  ");
		}
		if(searchOption == 1){
			gotoxy(36,14);
			textattr(HILIGHT_ATTR);
			cprintf("%s","Name");
		}else{
			gotoxy(36,14);
			textattr(NORMAL_ATTR);
			cprintf("%s","Name");
		}

		ch = getch();
		if(ch == 80||ch ==72){
			if(searchOption==0)
				searchOption = 1;
			else
				searchOption = 0;
		}
	} while (ch != 13);
	textattr(NORMAL_ATTR);
	switch (searchOption)
	{
		case 0:
			index=searchByID();
			break;
		case 1:
			index=searchByName();
			break;
		default:
			break;
	}

	clrscr();
	displayBorders();
	if(index>-1){
		displaySelectedEmployeeData(index);
		do {
			if(currentOption == 0){
				gotoxy(30,18);
				textattr(HILIGHT_ATTR);
				cprintf("%s","Delete");
				gotoxy(50,18);
				textattr(NORMAL_ATTR);
				cprintf("%s","Back");
			}else{
				gotoxy(30,18);
				textattr(NORMAL_ATTR);
				cprintf("%s","Delete");
				gotoxy(50,18);
				textattr(HILIGHT_ATTR);
				cprintf("%s","Back");
			}
			ch = getch();
			if(ch == 97||ch ==100){
				if(currentOption==0)
					currentOption = 1;
				else
					currentOption = 0;
			}
		}while(ch!=13);
		textattr(NORMAL_ATTR);
		if(currentOption==0){
			deleteByIndex(index);
			displayMainMenu();
			return;
		}else{
			displayMainMenu();
			return;
		}
	}
	else if (index==-1){
		gotoxy(20,10);
		printf("No Employee is found with this Data!!!");
		gotoxy(20,13);
		printf("  Press any key to back to Main Menu");
		getch();
		displayMainMenu();
	}
}
void deleteByIndex(int index){
	for(int i=index;i<currentEmployee-1;i++){
		empArr[i].ID = empArr[i+1].ID;
		empArr[i].Bouns = empArr[i+1].Bouns;
		empArr[i].Deduct = empArr[i+1].Deduct;
		strcpy(empArr[i].Name, empArr[i+1].Name);
	   //	empArr[index].Name = empArr[index+1].Name;
		empArr[index].Salary = empArr[index+1].Salary;
	}
	//free(empArr[currentEmployee-1]);
	currentEmployee--;
}
