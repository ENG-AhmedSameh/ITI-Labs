#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void readArray (int * arrPtr,int size);
void printArray(int * arrPtr,int size);

int main(void){
	int * dynamicArray,size;
	system("cls");
	printf("Please enter The Size of the int array : ");
	scanf("%d",&size);
	dynamicArray = (int *) malloc(size * sizeof(int));
	readArray(dynamicArray,size);
	printArray(dynamicArray,size);
	getch();
	free(dynamicArray);
    return 0;
}

void readArray (int * arrPtr,int size){
	int i;
	printf("Please Enter %d numbers : ",size);
	for (i=0;i<size;i++){
		scanf("%d",&arrPtr[i]);
	}
}

void printArray (int * arrPtr,int size){
    int i;
    printf("The Array you entered = {");
    for (i=0;i<size;i++){
        printf("%d, ",arrPtr[i]);
    }
    printf("\b\b}");
}