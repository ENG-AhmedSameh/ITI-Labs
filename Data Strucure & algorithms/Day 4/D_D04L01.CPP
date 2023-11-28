#include <iostream.h>
#include<stdlib.h>
#include<conio.h>

class Node{
    public:
        int data;
        Node * pre;
        Node * next;
        Node(){
            pre = next =NULL;
        }
};

class LinkedList{
    private:
        Node * start;
        Node * end;
        int size;
    public:
        LinkedList();
        Node* searchOnNode(int key);
        void appendNode(Node * ele);
        void insertNode(Node* ele);
        int deleteNode(int key);
        void freeList();
        int getSize();
        int isEmpty();
        Node* getFirst();
        Node* getLast();
        Node* peekFirst();
        Node* peekLast();
        void display();
};

LinkedList::LinkedList(){
    start = end =NULL;
    size = 0;
}

Node* LinkedList::searchOnNode(int key){
    Node * temp = start;
    if(start==NULL)
        return NULL;
    
    while(temp&&temp->data!=key)
        temp = temp->next;

    return temp;
}

void LinkedList::appendNode(Node* ele){
    if(start == NULL)
        start = end = ele;
    else{
        ele->pre = end;
        end->next = ele;
        end = ele;
    }
    size++;
}

void LinkedList::insertNode(Node* ele){

    Node * temp = start;
    while(temp && (ele->data > temp->data))
        temp =  temp->next; //temp will carry the node i will insert new node before it(carry node larger than data of my node)
    
    if(!temp)//temp is null (linked list is empty or reached the last place cause new node has the largest data)
        appendNode(ele);
    else{ // temp is not null (there is data in linked list or the data isn't the largest)
        if(temp==start){ // smaller than the start node
            start->pre = ele;
            ele->next = start;
            start = ele;
        }else{ //node will be inserted between temp node and its pre
            temp->pre->next = ele;
            ele->pre = temp->pre;
            temp->pre = ele;
            ele->next = temp;
		}
		size++;
	}
}

int LinkedList::deleteNode(int key){
    Node * temp;
    if(!start) // Linked list is empty
        return 0; // failed
    
    temp = searchOnNode(key);
    if(!temp) // not found
        return 0; //failed

    if(start == temp && end == temp){ //the only node in linked list
        start = end = NULL;
        free(temp);
    }else{
        if(start == temp){ //first Node in linked list
            start = start ->next;
            start->pre = NULL;
            //start->next->pre=NULL;
            free(temp);
        }else if(end == temp){ //last Node
            end = end->pre;
            end->next = NULL;
            //end->pre->next = NULL;
            free(temp);
        }else{
            temp ->pre->next = temp ->next;
            temp->next->pre = temp ->pre;
            free(temp);
		}
	}

	size--;
	return 1;
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
	else
		start->pre = NULL;

	temp ->pre = temp ->next = NULL; //to make the one who will get this node know nothing about locations of other nodes in the linked list

	size--;
	return temp;
}

Node* LinkedList::getLast(){
	if(isEmpty())
		return NULL;
	Node * temp = end;
	end = end->pre;
	if(!end)//check if the start become null cause the linked list was containing only one node
		start = NULL;
	else
		end->next = NULL;

	temp ->pre = temp ->next = NULL; //to make the one who will get this node know nothing about locations of other nodes in the linked list

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

Node* LinkedList::peekLast(){
	if(isEmpty())
		return NULL;

	Node * temp = new Node();
	temp->data = end->data;

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


class Stack{
        LinkedList stkList;
        int existSize;
	public:
        Stack();
        ~Stack();
        int isFull();
        int isEmpty();
        int push(Node* ele);
        Node* pop();
        Node * peek();
        int getSize();
        void display();
};

Stack::Stack():stkList(){
    existSize = 0;
}
Stack::~Stack(){
    stkList.freeList();
}

int Stack::isFull(){
    Node * temp;
    if((temp=new Node())){
        delete temp;
        return 0;
    }
    return 1;
}

int Stack::isEmpty(){
    return !existSize;
}

Node * Stack::peek(){
    return stkList.peekLast();
}
int Stack::push(Node* ele){
    if(isFull())
        return 0;
    stkList.appendNode(ele);
    existSize++;
    return 1;
}

Node * Stack::pop(){
    if(isEmpty())
		return NULL;
    existSize--;
    return stkList.getLast();    
}
int Stack::getSize(){
    return existSize;
}
void Stack::display(){
    stkList.display();
}

int main(){
    clrscr();
    Stack s1;

    Node* n1 = new Node();
    n1->data = 2;
    s1.push(n1);

    Node* n2 = new Node();
    n2->data = 4;
    s1.push(n2);

    Node* n3 = new Node();
    n3->data = 6;
    s1.push(n3);

    Node* n4 = new Node();
    n4->data = 8;
    s1.push(n4);
    
    cout<<"After pushing 4 Nodes";
    s1.display();

    Node* tempNode= s1.pop();
    cout<<"Poped node data = "<<tempNode->data<<endl;
    cout<<"stack after pop: ";
	s1.display();
    free(tempNode);
    tempNode= s1.peek();
    cout<<"Peeked node data = "<<tempNode->data<<endl;
    cout<<"stack after peek: ";
	s1.display();

    cout<<"Sizee of stack = "<<s1.getSize();

	getch();
    return 0;
}