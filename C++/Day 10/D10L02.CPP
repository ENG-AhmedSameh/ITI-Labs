#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

template <class T>
class Stack{

	private:
		int top;
		int size;
		T *ptr;
		static int counter;

	public:
        Stack(){
			top = 0;
			size = 10;
			ptr = new T[size];
			counter++;
			cout<<"    This is the default constructor"<<endl;
		}

		Stack(int n){
			top=0;
			size = n;
			ptr = new T[size];
			counter++;
			cout<<"    This is a constructor with one parameter"<<endl;
		}

		~Stack(){
			delete[] ptr;
			size=0;
			counter -- ;
			cout <<"    This is destructor"<<endl;
		}

        static int getCounter(){
			return counter;
		}

        Stack(Stack & s);

		int isFull();
		int isEmpty();
		int push(T n);
		int pop(T &n);
		Stack& operator= (Stack& s);

		

		friend void viewContent(Stack s);

		

};

template <class T>
int Stack<T>::counter = 0;

template <class T>
Stack<T>::Stack(Stack<T> & s){
	top  = s.top;
	size = s.size;
	ptr = new T[size];
	for(int i=0;i<top;i++){
		ptr[i] = s.ptr[i];
	}
    counter++;
	cout<<"    This is Copy Constructor"<<endl;
}

template <class T>
int Stack<T>::isFull(){
	return (top == size);
}

template <class T>
int Stack<T>::isEmpty(){
	return (top==0);
}
template <class T>
int Stack<T>::push(T n){
	if(isFull())
		return 0;
	ptr[top]=n;
	top++;
	return 1;
}


template <class T>
int Stack<T>::pop(T & n){
	if(isEmpty())
		return 0;
	top--;
	n = ptr[top];
	return 1;
}

template <class T>
Stack<T>& Stack<T>::operator= (Stack<T>& myS)
{
    if(ptr)
        delete[] ptr;
    top = myS.top;
    size = myS.size;
    ptr = new T[size];
    for (int i = 0; i < top; i++)
    {
        ptr[i] = myS.ptr[i];
    }
    return *this;
}

template <class T>
void viewContent (Stack<T> s){
	for(int i=0;i<s.top;i++)
		cout<<"    Element no {"<<i+1<<") = "<<s.ptr[i]<<endl;
}



int main(){

	clrscr();

	int n;
    clrscr();
    cout<<"************************INT Stack section***********************"<<endl;
    Stack<int> s1(5);
    cout<<"\nNo of Int Stacks is:"<<Stack<int>::getCounter();
    s1.push(10);
    s1.push(3);
	s1.push(2);
	s1.pop(n);
    cout << "\n1st integer: " <<n;
    s1.pop(n);
    cout << "\n2nd integer: " <<n<<endl;

    cout<<"***********************Char Stack section***********************"<<endl;
    Stack<char> s2;
    char nc;
    cout <<"\nNo of Char Stacks is:"<<Stack<char>::getCounter();
    s2.push('q');
    s2.push('r');
    s2.push('s');
    viewContent(s2) ;
	s2.pop(nc);
    cout << "\n1st character: " <<nc;
    s2.pop(nc);
    cout << "\n2nd character: " <<nc;

	getch();
	return 0;
}