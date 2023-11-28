#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<iostream.h>
#include<string.h>
void displayBorders(void);
void displayMainMenu(void);
void displayEmployeeDataTitles(void);
void displayNewEmployeeScreen(void);
void saveEmployeeData(char id[],char name[],int salary,int bouns,int deduct);
void displayEmployeesData();
void getNumberOfEmployees(void);
void searchForEmployeeScreen();
int searchByID();
int searchByName();
int getEmployeeIndexByID(char * id);
int getEmployeeIndexByName(char * tempName);
void displaySelectedEmployeeData(int index);
void deleteEmployeeDateScreen();
void deleteByIndex(int index);

#define NORMAL_ATTR 0x07
#define HILIGHT_ATTR 0x70

struct Employee{
	char ID[50],Name[50];
	int Salary,Bouns,Deduct;
};
int size = 0;
int currentEmployee = 0;
struct Employee * empList;
int main(void){
	displayMainMenu();
	free(empList);
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
	char options[5][11] ={{'N','e','w',' ',' ',' ',' ','\0'},{'D','i','s','p','l','a','y','\0'},{'S','e','a','r','c','h',' ','\0'},{'D','e','l','e','t','e',' ','\0'},{'E','x','i','t',' ',' ',' ','\0'}};
	system("cls");
	displayBorders();
	gotoxy(20,6);
	printf("Main Menu");
	do {
		for(i=0;i<5;i++){
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
			currentOption%=5;
		}else if (ch == 72){
			currentOption--;
			if (currentOption == -1)  currentOption =4;
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
	empList = (struct Employee *)malloc(size*sizeof(struct Employee));
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


void saveEmployeeData(char id[],char name[],int salary,int bouns,int deduct){
	int i=0;
	char c,d;
	for (i=0;i<50;i++){
		empList[currentEmployee].ID[i] = id[i];
		empList[currentEmployee].Name[i] = name[i];
	}
	empList[currentEmployee].Salary = salary;
	empList[currentEmployee].Bouns = bouns;
	empList[currentEmployee].Deduct = deduct;
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
		printf("%s",empList[i].ID);
		gotoxy(43,12);
		printf("%s",empList[i].Name);
		gotoxy(43,14);
		netSalary = empList[i].Salary + empList[i].Bouns - empList[i].Deduct;
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
	char* tempID;
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
	printf("%s",empList[index].ID);
	gotoxy(43,12);
	printf("%s",empList[index].Name);
	gotoxy(43,14);
	float netSalary = empList[index].Salary + empList[index].Bouns - empList[index].Deduct;
	printf("%0.2f",netSalary);
	
}


int getEmployeeIndexByID(char * tempID){
	int i;
	for(i=0;i<currentEmployee;i++){
		if(strcmp(empList[i].ID,tempID)==0)
			return i;
	}
	return -1;
}
int getEmployeeIndexByName(char * tempName){
	int i;
	for(i=0;i<currentEmployee;i++){
		if(strcmp(empList[i].Name,tempName)==0)
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
		//return;
	}
}
void deleteByIndex(int index){
	for(int i=index;i<currentEmployee-1;i++){
		strcpy(empList[i].ID, empList[i+1].ID);
	   // 	empList[index].ID = empList[index+1].ID;
		empList[i].Bouns = empList[i+1].Bouns;
		empList[i].Deduct = empList[i+1].Deduct;
		strcpy(empList[i].Name, empList[i+1].Name);
	   //	empList[index].Name = empList[index+1].Name;
		empList[index].Salary = empList[index+1].Salary;
	}
	//free(empList[currentEmployee-1]);
	currentEmployee--;
}
