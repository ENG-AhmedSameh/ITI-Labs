#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void readArray (int ** arrPtr,int arrSize,int * stringSizesArr);
void printArray(int ** stringArray,int arrSize);

int main(void){
	char ** stringArray;
	int arrSize,tempSize,i;
	int * stringsSizesArray;
	system("cls");
	printf("Please enter The Size of the array : ");
	scanf("%d",&arrSize);
	stringArray = (int **) malloc(arrSize * sizeof(char));
	stringsSizesArray = (int * ) malloc(arrSize*sizeof(int));
	for(i=0;i<arrSize;i++){
		printf("\nPlease enter The Size of the string number %d: ",i+1);
		scanf("%d",&stringsSizesArray[i]);
		stringArray[i] = (int *)malloc((stringsSizesArray[i]+1) * sizeof(char));
	}

	readArray(stringArray,arrSize,stringsSizesArray);
	printArray(stringArray,arrSize);
	getch();

	return 0;
}

void readArray (int ** arrPtr,int arrSize,int * stringsSizesArr){
	int i=0,j,temp2;
	float temp1;
	for (i=0;i<arrSize;i++){
		printf("Please Enter string no %d of size %d chars : ",i+1,stringsSizesArr[i]);
        flushall();
		fgets(arrPtr[i],stringsSizesArr[i]+1,stdin);

	}
}

void printArray (int ** arrPtr,int arrSize){
	int i,j;
	printf("The Array you entered = {");
	for (i=0;i<arrSize;i++){
		printf("%s, ",arrPtr[i]);
	}
	printf("\b\b}");
}