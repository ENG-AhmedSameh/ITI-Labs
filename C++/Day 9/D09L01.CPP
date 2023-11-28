#include<iostream.h>
#include<stdio.h>
#include<conio.h>

class Base {
	protected:
		int a;
		int b;
	public:

		Base(){
			a=b=0;
		}

		Base(int n){
			a=b=n;
		}

		Base(int x,int y){
			a=x;
			b=y;
		}

		void setA(int x){
			a=x;
		}

		int getA(){
			return a;
		}

		void setB(int x){
			b=x;
		}

		int getB(){
			return b;
		}
		int calculateSum(){
			return a+b;
		}
		void disp(){
			cout<<"Function of Parent Class";
		}
};

class Derived :public Base{

	private:
		int c;

	public:

		Deriverd():Base(){
			c=0;
		}

		Deriverd(n):Base(n){
			c=n;
		}

		Deriverd(int x,int y,int z):Base(x,y){
			c=z;
		}

		void setC(int z){
			c=z;
		}

		int getC{
			return c;
		}
		int calculateSum(){
			return Base::calculateSum()+c;
		}
		void disp() {
			cout<<"Function of Child Class";
		}
};

int main(){

	clrscr();

	Base b(5,4) ;
	cout<<b.calculateSum()<<endl ;
	Derived obj1 ;
	obj1.setA(3) ;
	obj1.setB(7) ;
	obj1.setC(1) ;
	Derived obj2(20) ;
	Derived obj3(4,5,6) ;
	cout<<"obj1: "<<obj1.calculateSum()<<endl ; // =11
	cout<<"obj2: "<<obj2.calculateSum()<<endl ; // =60
	cout<<"obj3: "<<obj3.calculateSum()<<endl ; // =15
	cout<<"obj1: "<<obj1.Base::calculateSum()<<endl ; //only =10

	getch();
	return 0;
}