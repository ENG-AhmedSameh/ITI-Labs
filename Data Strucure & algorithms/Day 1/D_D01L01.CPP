#include <iostream.h>
#include <conio.h>

class IntCollections{
	public:
		static int seqSearch(int *data, int size,int key);
		static int binarySearch(int *data, int size,int key);
		static int RbinarySearch(int *data, int lo, int hi ,int key);
		static int selectionSort(int *data, int size);
		static int bubbleSort(int *data, int size);
		static int mergeSort(int *data, int sizes);
};

int IntCollections::seqSearch(int * data, int size,int key){
	int i;
	for(i=0;i<size;i++)
		if(data[i]==key)
			return i;
	return -1;
}

int main(){

	clrscr();

	int i,arr[]={12,-15,7,10,37,6,13,1,5,3};
	int foundIndex, key;
	cout<<"Enter number you want to search for: ";
	cin>>key;
	foundIndex= IntCollections::seqSearch(arr,10,key);

	if(foundIndex>-1)
		cout<<"\n Found in: "<<foundIndex<<endl;
	else
		cout<<"\n Not Found"<<endl;
	

	getch();
	return 0;
}