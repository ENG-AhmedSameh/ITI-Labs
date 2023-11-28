#include <iostream.h>
#include <conio.h>

class IntCollections{
	public:
		static int seqSearch(int *data, int size,int key);
		static int binarySearch(int *data, int size,int num);
		static int RbinarySearch(int *data, int lo, int hi ,int key);
		static int selectionSort(int *data, int size);
		static int bubbleSort(int *data, int size);
		static int mergeSort(int *data, int sizes);
};

int IntCollections::binarySearch(int * ptr, int size,int num){
	int i,lo=0,hi=size-1,mid;
	while(hi>=lo){
        mid = (hi+lo)/2;
        if(ptr[mid]> num)
            hi = mid-1;
        else if (ptr[mid]<num)
            lo = mid+1;
        else
            return mid;
    }
	return -1;
}

int IntCollections::RbinarySearch(int * ptr,int lo, int hi, int num){
    int mid;
    if(hi>=lo){
        mid = (lo+hi)/2;
        if(ptr[mid]>num)
            return IntCollections::RbinarySearch(ptr,lo,mid-1,num);
        else if (ptr[mid]<num)
            return IntCollections::RbinarySearch(ptr,mid+1,hi,num);
        else
            return mid;
    }
    return -1;
}

int main(){

	clrscr();

	int i,arr[]={10,13,15,17,18,22,33,50,55,60};
	int foundIndex, key;
    cout<<"\nPlease enter the number you want to search for using binary search: "<<endl;
    cin>>key;
	foundIndex= IntCollections::binarySearch(arr,10,key);
    if(foundIndex>-1)
        cout<<"\n Found at index = "<<foundIndex<<endl;
    else
        cout<<"\nNot Found"<<endl;

    cout<<"\nPlease enter the number you want to search for using recursuive binary search: "<<endl;
    cin>>key;
	foundIndex= IntCollections::RbinarySearch(arr,0,10,key);
    if(foundIndex>-1)
        cout<<"\n Found at index = "<<foundIndex<<endl;
    else
        cout<<"\nNot Found"<<endl;

	getch();
	return 0;
}