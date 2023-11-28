#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
class Stack{

	private:
		int top;
		int size;
		int *ptr;

	public:
		int isFull();
		int isEmpty();
		int getSize();
		int push(int n);
		int pop(int &n);

		Stack(){
			top = 0;
			size = 10;
			ptr = new int[size];
		}

		Stack(int n){
			top=0;
			size = n;
			ptr = new int[size];
		}

		~Stack(){
			delete[] ptr;
			size=0;
		}

};


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
int Stack::getSize(){
	return size;
}



int main(){

	clrscr();

	clrscr();
	Stack s1;
	s1.push(2);
	s1.push(4);
	s1.push(6);
	s1.push(8);

	int temp;
	s1.pop(temp);
	cout<<"Poped node data = "<<temp<<endl;

	cout<<"Size of stack = "<<s1.getSize();

	getch();
	return 0;
}