#include <iostream.h>
#include <conio.h>
#include<string.h>

#define N 5

class stringCollections{
	public:
		static int seqSearch(char **data, int size,char* key);
		static int binarySearch(char ** data, int size,char* key);
		static int RbinarySearch(char ** data, int lo, int hi ,char* key);
		static void selectionSort(char ** data, int size);
		static void bubbleSort(char ** data, int size);
		static void mergeSort(char ** data, int sizes);
		static void swap(char** s1,char** s2);
};


void stringCollections::swap(char** x,char** y){
	char* temp;
	temp=*x;
	*x=*y;
	*y=temp;
	/*strcpy(temp,x);
	strcpy(x,y);
	strcpy(y,temp);*/
}

void printArray(char** arr){
	cout<<"{"<<arr[0]<<", ";
	for (int i=1;i<N-1;i++){
		cout<<arr[i]<<", ";
	}
	cout<<arr[N-1]<<"}";
}

void stringCollections::selectionSort(char** data, int size){
	for (int i=0;i<size-1;i++){
		int minIndex=i;
		for (int j=i+1;j<size;j++)
			if(strcmp(data[j],data[minIndex])<0)
				minIndex=j;
		stringCollections::swap(&data[i],&data[minIndex]);
	}
}

int main(){

	clrscr();

	int i;
	char* arr[N]={"ahmed","marwannn","amgaaaad","amr","islam"};
	stringCollections::selectionSort(arr,N);
    printArray(arr);
	getch();
	return 0;
}