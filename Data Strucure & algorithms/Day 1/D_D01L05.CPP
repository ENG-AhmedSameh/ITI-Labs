#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>

class Complex{
	private:
		int real;
		int imag;

	public:
		Complex(){
	        real=imag=0;
        }
		Complex(int r){
            real = imag =r;
        }
		Complex(int r, int i){
            real = r;
            imag = i;
        }
        int getReal(){
            return real;
        }
        int getImag(){
            return imag;
        }
};

class ComplexCollections{
	public:
		static int seqSearch(Complex * data, int size,Complex key);
		static int binarySearch(Complex * data, int size,Complex key);
		static int RbinarySearch(Complex * data, int lo, int hi ,Complex key);
		static int selectionSort(Complex * data, int size);
		static int bubbleSort(Complex * data, int size);
		static int mergeSort(Complex * data, int sizes);
};

int ComplexCollections::seqSearch(Complex * data, int size,Complex key){
	int i;
	for(i=0;i<size;i++)
		if(data[i].getReal()==key.getReal()&&data[i].getImag()==key.getImag())
			return i;
	return -1;
}


int ComplexCollections::binarySearch(Complex * ptr, int size,Complex key){
	int i,lo=0,hi=size-1,mid;
	while(hi>=lo){
		mid = (hi+lo)/2;
		if(ptr[mid].getReal()>key.getReal()){
			hi = mid-1;
        }
		else if (ptr[mid].getReal()<key.getReal()){
			lo = mid+1;
        }
		else{
            if(ptr[mid].getImag()>key.getImag())
			    hi = mid-1;
            else if(ptr[mid].getImag()<key.getImag())
				lo = mid +1;
            else
                return mid;
        }
	}
	return -1;
}


int main(){

	clrscr();
    int realPart,imagPart,foundIndex;
	Complex arr[5]={Complex(1,1),Complex(2,2),Complex(2,3),Complex(2,4),Complex(3,1)};
    cout<<"Enter real part of complex number you want to search for using linear : ";
    cin>>realPart;
    cout<<"\nEnter imag part of complex number you want to search for using linear : ";
    cin>>imagPart;
	foundIndex=ComplexCollections::seqSearch(arr,5,Complex(realPart,imagPart));
    if(foundIndex>-1)
        cout<<"\n Found at index = "<<foundIndex<<endl;
    else
        cout<<"\nNot Found"<<endl;


    cout<<"\n\n\nEnter real part of complex number you want to search for using binary : ";
    cin>>realPart;
    cout<<"\nEnter imag part of complex number you want to search for using binary : ";
    cin>>imagPart;
    foundIndex=ComplexCollections::binarySearch(arr,5,Complex(realPart,imagPart));
    if(foundIndex>-1)
        cout<<"\n Found at index = "<<foundIndex<<endl;
    else
        cout<<"\nNot Found"<<endl;

	getch();
	return 0;
}