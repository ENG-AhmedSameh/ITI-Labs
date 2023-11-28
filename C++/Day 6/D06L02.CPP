#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
class Stack{

	private:
		int top;
		int size;
		int *ptr;
		static int counter;

	public:
		int isFull();
		int isEmpty();
		int push(int n);
		int pop(int &n);
		static int getCounter(){
			return counter;
		}

		Stack(){
			top = 0;
			size = 10;
			ptr = new int[size];
			counter++;
			cout<<"    This is the default constructor"<<endl;
		}

		Stack(int n){
			top=0;
			size = n;
			ptr = new int[size];
			counter++;
			cout<<"    This is a constructor with one parameter"<<endl;
		}

		~Stack(){
			delete[] ptr;
			size=0;
			counter -- ;
			cout <<"    This is destructor"<<endl;
		}

		friend void viewContent(Stack s);

		Stack(Stack & s){
			top  = s.top;
			size = s.size;
			ptr = new int[size];
			for(int i=0;i<top;i++){
				ptr[i] = s.ptr[i];
			}
			cout<<"    This is Copy Constructor"<<endl;
		}

};

int Stack::counter = 0;

int Stack::isFull(){
	return (top == size);
}

int Stack::isEmpty(){
	return (top==0);
}
int Stack::push(int n){
	if(isFull())
		return 0;
	ptr[top]=n;
	top++;
	return 1;
}



int Stack::pop(int & n){
	if(isEmpty())
		return 0;
	top--;
	n = ptr[top];
	return 1;
}

void viewContent (Stack s){
	for(int i=0;i<s.top;i++)
		cout<<"    Element no {"<<i+1<<") = "<<s.ptr[i]<<endl;
}



int main(){

	clrscr();

	int num;
	cout<<"Section of count how many stacks has been created"<<endl;
	cout<<"*************************************************"<<endl;
	cout<<"The number of objects created = "<<Stack::getCounter()<<endl;
	cout<<"Declaring stack s1 : ";
	Stack s1(2);
	cout<<"Declaring stack s2 : ";
	Stack s2(5);
	cout<<"The number of objects created = "<<Stack::getCounter()<<endl;


	/*
	{
		cout<<"\n************** We entered finite scope *************"<<endl;
		cout<<"Declaring stack s3 : ";
		Stack s3(10);
		cout<<"The number of objects created = "<<Stack::getCounter()<<endl;
	}
	cout<<"************* We left the finite scope *************"<<endl;
	cout<<"The number of objects created = "<<Stack::getCounter()<<endl;

	cout<<"\nSection pushing 3 members in s1(size 2) then view its content then pop from it"<<endl;
	cout<<"*******************************************************************************"<<endl;
	s1.push(5);
	s1.push(14);
	s1.push(20);

	cout<<"View s1 Content : "<<endl;
	viewContent(s1);

	if(s1.pop(num)){
		cout<<"First poped number from s1: "<<num<<endl;
	}

	if(s1.pop(num)){
		cout<<"Second poped number from s1: "<<num<<endl;
	}
	if(s1.pop(num)){
		cout<<"Third poped number from s1: "<<num<<endl;
	}else
		cout<<"Third poped number from s1: Stack is Empty"<<endl;

	*/





	cout<<"\nSection apllaying copy constructor then pop from copy"<<endl;
	cout<<"*****************************************************"<<endl;
	s1.push(5);
	s1.push(14);
	s1.push(20);

	cout<<"create s4 which is copy from s1: ";
	Stack s4(s1);
	cout<<"pop from s4: "<<endl;
	s4.pop(num);
	cout<<num<<endl;
	s4.pop(num);
	cout<<num<<endl;

	getch();
	return 0;
}