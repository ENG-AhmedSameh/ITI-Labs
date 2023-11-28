#include <iostream.h>
#include <conio.h>
#include<string.h>
class stringCollections{
	public:
		static int seqSearch(char **data, int size,char* key);
		static int binarySearch(char ** data, int size,char* key);
		static int RbinarySearch(char ** data, int lo, int hi ,char* key);
		static int selectionSort(char ** data, int size);
		static int bubbleSort(char ** data, int size);
		static int mergeSort(char ** data, int sizes);
};


int stringCollections::binarySearch(char** ptr, int size,char* key){
	int i,lo=0,hi=size-1,mid,result;
	while(hi>=lo){
		mid = (hi+lo)/2;
		result=strcmp(ptr[mid],key);
		if(result>0)
			hi = mid-1;
		else if (result<0)
			lo = mid+1;
		else
			return mid;
	}
	return -1;
}



int main(){

	clrscr();

	int i;
	char* arr[5]={"ahmed","body","camilya","doby","emad"};
	int foundIndex;
	char* tempString;
	cout<<"\nPlease enter the string you want to search for using binary search: "<<endl;
	cin>>tempString;
	foundIndex= stringCollections::binarySearch(arr,10,tempString);
	if(foundIndex>-1)
		cout<<"\n Found at index = "<<foundIndex<<endl;
	else
		cout<<"\nNot Found"<<endl;
	getch();
	return 0;
}