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
		void setReal(float r);
		void setImag(float i);
		float getReal();
		float getImag();
		Complex add(Complex c);
		Complex sub(Complex c);
		void print();
		void setAll();
		void setAll(float f);
		void setAll(float r,float i);
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


void Complex::setReal(float r){
	real = r;
}

void Complex::setImag(float i){
	imag = i;
}

float Complex::getReal(){
	return real;
}

float Complex::getImag(){
	return imag;
}

void Complex::setAll(){
	real = 0;
	imag = 0;
}

void Complex::setAll(float f){
	this->real = f;
	this->imag = f;
}
void Complex::setAll(float real,float imag){
	this->real = real;
	this->imag = imag;
}

Complex Complex::add(Complex c){
	Complex temp;
	temp.real = real +c.real;
	temp.imag = imag+c.imag;
	return temp;
}

Complex Complex::sub(Complex c){
	Complex temp;
	temp.real = real-c.real;
	temp.imag = imag - c.imag;
	return temp;
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
	cout<<"Declaring myComp1:";
	Complex myComp1;
	cout<<"Declaring myComp2:";
	Complex myComp2(3,4);
	cout<<"Declaring resultComp:";
	Complex resultComp(5);

	myComp1.setReal(7);
	myComp1.setImag(2);

	cout<<"setting all parts of myComp2 with no passed parameters: ";
	myComp2.setAll();
	myComp2.print();
	cout<<"setting all parts of myComp2 with one passed parameter(5): ";
	myComp2.setAll(5);
	myComp2.print();
	cout<<"setting all parts of myComp2 with two passed parameters(12,8): ";
	myComp2.setAll(12,8);
	myComp2.print();

    cout<<"Using add function:"<<endl;
	resultComp = myComp1.add(myComp2);
	resultComp.print();

	cout<<"Using sub function:"<<endl;
	resultComp = myComp1.sub(myComp2);
	resultComp.print();

	getch();
	return 0;
}