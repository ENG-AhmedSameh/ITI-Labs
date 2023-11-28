#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
class Stack{

	private:
		int top;
		int size;
		int *ptr;
		int lastPushedElement;
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

	  /* 	Stack(Stack & s){
			top  = s.top;
			size = s.size;
			ptr = new int[size];
			for(int i=0;i<top;i++){
				ptr[i] = s.ptr[i];
			}
			cout<<"    This is Copy Constructor"<<endl;
		}*/

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
	lastPushedElement = n;
	return 1;
}



int Stack::pop(int & n){
	if(isEmpty())
		return 0;
	top--;
	n = ptr[top];
	if (n!=lastPushedElement){
		top=0;
		return 0;
	}
	top--;
	lastPushedElement = ptr[top];
    top++;
	return 1;
}

void viewContent (Stack s){
	for(int i=0;i<s.top;i++)
		cout<<"    Element no {"<<i+1<<") = "<<s.ptr[i]<<endl;
}



int main(){

	clrscr();

	int num;
		cout<<"Declaring stack s1 : ";
	Stack s1(2);
	cout<<"Declaring stack s2 : ";
	Stack s2(5);

	cout<<"\nSection pushing 3 members in s1(size 2) then view its content then pop from it"<<endl;
	cout<<"*******************************************************************************"<<endl;
	s1.push(5);
	s1.push(14);
	s1.push(20);

	cout<<"View s1 Content : "<<endl;
	viewContent(s1);
	while(1){
		if(s1.pop(num)){
			cout<<"poped number from s1: "<<num<<endl;
		}else{
			cout<<"there is nothing to be poped from s1 .. stack is empty !!";
			break;
		}
	}

	getch();
	return 0;
}