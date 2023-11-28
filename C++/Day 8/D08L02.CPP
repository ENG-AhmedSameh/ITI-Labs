#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>

struct Complex{
	private:
		float real;
		float imag;

	public:
		Complex();
		Complex(float r);
		Complex(float r, float i);
		~Complex();
		void print();
	Complex (Complex &c){
		real = c.real;
		imag = c.imag;
		cout <<"    This is Copy constructor !!!!!!!"<<endl;
	}
};
Complex::Complex(){
	real=imag=0;
	cout<<"    Default Constructor is calling"<<endl;
}

Complex::Complex(float real, float imag){
	this->real = real;
	this->imag = imag;
	cout<<"    Constructor with two parameters is calling"<<endl;
}

Complex::Complex(float r){
	real = imag =r;
	cout<<"    Constructor with one parameters is calling"<<endl;

}

Complex::~Complex(){
	cout<<"    Destructor is calling"<<endl;
}

void Complex::print(){
	if(imag<0){
		cout<<real<<" - "<<fabs(imag)<<"i"<<endl;
	}else{
		cout<<real<<" + "<<imag<<"i"<<endl;
	}
}

int main(){
    
	clrscr();

	//if we write (Complex arr[3];) this will create a collection of 3 complex and will run the default constructor for every one of them
	Complex arr[3]={Complex(2), Complex(), Complex(5,7)};
	for(int i = 0 ; i<3 ; i++)
		arr[i].print();

	Complex * cptr;
	cptr = new Complex(2.1, 7.3);
	//memory leak here because how the complex were the pointer pointed at will be removed from the memory after the pointer pointed at something else?
	delete cptr;//to get over memory leak problem (delete will remove the data stored at the address stored at the pointer not the address itself) so it will rmove the complex(2.1,7.3)
	cptr = new Complex[12];

    getch();
	return 0;
}