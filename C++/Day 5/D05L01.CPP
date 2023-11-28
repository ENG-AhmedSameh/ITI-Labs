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
		cout <<"\n This is Copy constructor !!!!!!!"<<endl;
	}
};



Complex::Complex(){
	real=imag=0;
	cout<<"\n Default Constructor is calling";
}

Complex::Complex(float real, float imag){
	this->real = real;
	this->imag = imag;
	cout<<"\n Constructor with two parameters is calling";
}

Complex::Complex(float r){
	real = imag =r;
	cout<<"\n Constructor with one parameters is calling";

}

Complex::~Complex(){
	cout<<"\n Destructor is calling";
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
		cout<<"\n "<<real<<" - "<<fabs(imag)<<"i"<<endl;
	}else{
		cout<<"\n "<<real<<" + "<<imag<<"i"<<endl;
	}
}

int main(){

	clrscr();

	Complex myComp1;
	Complex myComp2(3,4);
	Complex resultComp(5);
	myComp1.setReal(7);
	myComp1.setImag(2);
	myComp2.setAll(12,8);

	resultComp = myComp1.add(myComp2);
	resultComp.print();

	resultComp = myComp1.sub(myComp2);
	resultComp.print();

	getch();
	return 0;
}