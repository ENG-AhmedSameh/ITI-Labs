#include<iostream.h>
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


int main(){
	//clrscr();
	system("cls");
	LinkedList list1;

	Node* n1= new Node();
	n1->data=2;
	list1.appendNode(n1);

	Node* n2 = new Node();
	n2->data=4;
	list1.appendNode(n2);

	Node* n3 = new Node();
	n3->data=6;
	list1.appendNode(n3);

	Node* n4 = new Node();
	n4->data=8;
	list1.appendNode(n4);

	Node* n5 = new Node();
	n5->data=5;
	list1.insertNode(n5);

	cout<<"List after append & insert: ";
	list1.display();

	Node* tempNode = list1.searchOnNode(5);
	cout<<"Data of node returned from search = "<<tempNode->data<<endl;

	if(list1.deleteNode(4))
		cout<<"Node Deleted successfully"<<endl;
	else
		cout<<"Delete Failed, NO Node with this data"<<endl;

	cout <<"List after Delete: ";
	list1.display();
	cout<<"Size of the list = "<<list1.getSize()<<endl;;

	free(tempNode); // free it before assign any other value to it to be away from making memory leak

	tempNode = list1.peekFirst();
	cout<<"First Peeked Node = "<<tempNode->data<<endl;

	delete(tempNode);

	tempNode = list1.peekLast();
	cout<<"last Peeked Node = "<<tempNode->data<<endl;

	cout <<"List after applaying Peek methods: ";
	list1.display();

	delete(tempNode);

	tempNode = list1.getFirst();
	cout<<"Data of node returned from getFirst: "<<tempNode->data<<endl;
	delete(tempNode);
	tempNode = list1.getLast();
	cout<<"Data of node returned from getLast: "<<tempNode->data<<endl;

	cout<<"List after applaying get methods: ";
	list1.display();
	delete(tempNode);

	list1.freeList();
	cout<<"List after applaying free method: ";
	list1.display();

	getch();
	return 0;
}