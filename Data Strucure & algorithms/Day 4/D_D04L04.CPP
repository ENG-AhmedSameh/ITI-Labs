#include <iostream.h>
#include<stdlib.h>
#include<conio.h>


class Node{
    public:
        int data;
        Node * next;
        Node(){
            next =NULL;
        }
};

class LinkedList{
    private:
        Node * start;
        Node * end;
        int size;
    public:
        LinkedList();
        void appendNode(Node * ele);
        int deleteNode(int key);
        void freeList();
        int getSize();
        int isEmpty();
        Node* getFirst();
        Node* peekFirst();
        void display();
};

LinkedList::LinkedList(){
    start = end =NULL;
    size = 0;
}


void LinkedList::appendNode(Node* ele){
    if(start == NULL)
        start = end = ele;
    else{
        end->next = ele;
        end = ele;
    }
    size++;
}



void LinkedList::freeList(){
	Node * temp = start;
	while(temp){
		start = start->next;
		free(temp);
		temp = start;
	}
	end = NULL;
	size = 0;
}

int LinkedList::getSize(){
	return size;
}

int LinkedList::isEmpty(){
	return start == NULL;
}

Node* LinkedList::getFirst(){
	if(isEmpty())
		return NULL;
	Node * temp = start;
	start = start->next;
	if(!start)//check if the start become null cause the linked list was containing only one node
		end = NULL;

	temp ->next = NULL; //to make the one who will get this node know nothing about locations of other nodes in the linked list

	size--;
	return temp;
}


Node* LinkedList::peekFirst(){
	if(isEmpty())
		return NULL;

	Node * temp = new Node();
	temp->data = start->data;

	return temp;
}

void LinkedList::display(){
	if(isEmpty()){
		cout<<"{}"<<endl;
		return;
	}
	Node* temp = start;
	cout<<"{";
	while(temp){
		cout<<temp->data<<", ";
		temp = temp->next;
	}
	cout<<"\b\b}"<<endl;
}


class Queue{
	int existSize;
	LinkedList queList;

	public:
		Queue();
		~Queue();

		int isFull();
		int isEmpty();

		int input(Node * ele);
		Node * output();
		Node * peek();
		void display();
		int getSize();
};

Queue::Queue():queList(){
	existSize = 0;
}


Queue::~Queue(){
	queList.freeList();
}

int Queue::isFull(){
    Node * temp;
    if((temp=new Node())){ //No enough memory
        delete temp;
        return 0;
    }
    return 1;
}

int Queue::isEmpty(){
    return existSize == 0;
}

int Queue::input(Node* ele){
    if(isFull())
        return 0;
	queList.appendNode(ele);
    existSize++;
    return 1;
}

Node * Queue::output(){
    if(isEmpty())
        return NULL;
	Node * temp = queList.getFirst();
    existSize --;
    return temp;
}

Node * Queue::peek(){
    if(isEmpty())
        return NULL;
	Node * temp = queList.peekFirst();
    return temp;
}    

void Queue::display(){
    queList.display();
}

int Queue::getSize(){
    return existSize;
}

int main(){
    clrscr();
    Queue q1;

    Node* n1 = new Node();
    n1->data = 2;
    q1.input(n1);

    Node* n2 = new Node();
    n2->data = 4;
    q1.input(n2);

    Node* n3 = new Node();
    n3->data = 6;
    q1.input(n3);

    Node* n4 = new Node();
    n4->data = 8;
    q1.input(n4);
    
    cout<<"After inputing 4 Nodes";
    q1.display();

    Node* tempNode= q1.output();
    cout<<"Output node data = "<<tempNode->data<<endl;
    cout<<"Queue after pop: ";
	q1.display();
    free(tempNode);
    tempNode= q1.peek();
    cout<<"Peeked node data = "<<tempNode->data<<endl;
	cout<<"Queue after peek: ";
	q1.display();

    cout<<"Size of Queue = "<<q1.getSize();

	getch();
    return 0;
}