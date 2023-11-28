#include <iostream.h>
#include<stdlib.h>
#include<conio.h>

class Queue{
    int * queList, size, rear;

    public:
        Queue();
        Queue(int s);
        ~Queue();

        int isFull();
        int isEmpty();

        int input(int ele);
        int output(int &ele);
        int peek(int &ele);
};

Queue::Queue(){
    size = 10;
    rear = 0;
    queList = new int[size];
}

Queue::Queue(int s){
    size = s;
    rear = 0;
    queList = new int[size];
}

Queue::~Queue(){
    delete(queList);
}

int Queue::isFull(){
    if(rear == size)
        return 1;
    return 0;
}

int Queue::isEmpty(){
    return rear == 0;
}

int Queue::input(int data){
    if(isFull())
        return 0;
        queList[rear]=data;
        rear++;
        return 1;
}

int Queue::output(int& data){
    if(isEmpty())
        return 0;
	data = queList[0];
    for(int i=1;i<rear;i++)
        queList[i]=queList[i-1];
    rear--;
    return 1;
}

int Queue::peek(int & data){
    if(isEmpty())
        return 0;
	data = queList[0];
    return 1;
}

int main(){
    clrscr();
    Queue q;
    q.input(2);
    q.input(4);
    q.input(6);
    q.input(8);

    int temp;
    int outputResult = q.output(temp);
    int peekResult = q.peek(temp);
    

	getch();
    return 0;
}