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
        static void merge(int *data,int *leftArr,int leftSize,int *rightArr,int rightSize);
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

void IntCollections::merge(int *resultArr,int *leftArr,int leftSize,int *rightArr,int rightSize){
    int leftPosition=0, rightPosition=0, resultPosition=0;

    while(leftPosition<leftSize && rightPosition<rightSize){
        if(leftArr[leftPosition]<rightArr[rightPosition])
            resultArr[resultPosition++] = leftArr[leftPosition++];
        else
            resultArr[resultPosition++] = rightArr[rightPosition++];
    }

    while(leftPosition<leftSize)
        resultArr[resultPosition++] = leftArr[leftPosition++];
    while(rightPosition<rightSize)
        resultArr[resultPosition++] = rightArr[rightPosition++];
}

void IntCollections::mergeSort(int *data, int size){
	int i, mid,*lArr,*rArr;
	if(size<2)
		return;
	mid = size/2;
	lArr= new int[mid];
	rArr=new int[size-mid];

	for(i=0;i<mid;i++)
		lArr[i]=data[i];
	for(i=mid;i<size;i++)
        rArr[i-mid]=data[i];

    IntCollections::mergeSort(lArr,mid);
    IntCollections::mergeSort(rArr,size-mid);

    IntCollections::merge(data,lArr,mid,rArr,size-mid);

}


int main(){

    clrscr();

	int arr[N] = {54,12,32,97,11,4,53,87,18,17};
	IntCollections::mergeSort(arr,N);
    printArray(arr);

    getch();
    return 0;
}