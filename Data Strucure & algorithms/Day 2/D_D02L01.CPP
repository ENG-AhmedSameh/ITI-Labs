#include<iostream.h>
#include<conio.h>

#define N 10

class IntCollections{
	public:
		static int seqSearch(int *data, int size,int key);
		static int binarySearch(int *data, int size,int key);
		static int RbinarySearch(int *data, int lo, int hi ,int key);
		static void selectionSort(int *data, int size);
		static void bubbleSort(int *data, int size);
		static void mergeSort(int *data, int sizes);
		static void swap(int& x,int& y);
};

void IntCollections::swap(int& x,int& y){
	int temp=x;
	x=y;
	y=temp;
}

void printArray(int *arr){
	cout<<"{"<<arr[0]<<",";
	for (int i=1;i<N-1;i++){
		cout<<arr[i]<<", ";
	}
    cout<<arr[N-1]<<"}";
}

void IntCollections::selectionSort(int *data, int size){
	for (int i=0;i<size-1;i++){
		int minIndex=i;
		for (int j=i+1;j<size;j++)

			if(data[j]<data[minIndex])
				minIndex=j;
		IntCollections::swap(data[i],data[minIndex]);
	}
}


int main(){

    clrscr();

	int arr[N] = {54,12,32,98,11,4,53,87,18,17};
	IntCollections::selectionSort(arr,N);
    printArray(arr);

    getch();
    return 0;
}