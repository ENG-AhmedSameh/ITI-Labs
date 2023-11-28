#include<iostream.h>
#include<stdlib.h>
#include<conio.h>

template <class T>
class Node{
    public:
        T data;
        Node * pre;
        Node * next;
        Node(){
            pre = next =NULL;
        }
};
template <class T>
class LinkedList{
	private:
		Node<T> * start;
        Node<T> * end;
        int size;
    public:
        LinkedList();
		Node<T>* searchOnNode(int key);
		void appendNode(Node<T> * ele);
		void insertNode(Node<T>* ele);
		int deleteNode(int key);
		void freeList();
		int getSize();
		int isEmpty();
		Node<T>* getFirst();
		Node<T>* getLast();
		Node<T>* peekFirst();
        Node<T>* peekLast();
        void display();
};
template <class T>
LinkedList<T>::LinkedList(){
    start = end =NULL;
    size = 0;
}
template <class T>
Node<T>* LinkedList<T>::searchOnNode(int key){
	Node<T> * temp = start;
    if(start==NULL)
        return NULL;
    
    while(temp&&temp->data!=key)
        temp = temp->next;

    return temp;
}
template <class T>
void LinkedList<T>::appendNode(Node<T>* ele){
    if(start == NULL)
        start = end = ele;
    else{
        ele->pre = end;
        end->next = ele;
        end = ele;
    }
    size++;
}
template <class T>
void LinkedList<T>::insertNode(Node<T>* ele){

	Node<T> * temp = start;
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
template <class T>
int LinkedList<T>::deleteNode(int key){
	Node<T> * temp;
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
template <class T>
void LinkedList<T>::freeList(){
	Node<T> * temp = start;
	while(temp){
		start = start->next;
		free(temp);
		temp = start;
	}
	end = NULL;
	size = 0;
}
template <class T>
int LinkedList<T>::getSize(){
	return size;
}

template<class T>
int LinkedList<T>::isEmpty(){
	return start == NULL;
}

template<class T>
Node<T>* LinkedList<T>::getFirst(){
	if(isEmpty())
		return NULL;
	Node<T> * temp = start;
	start = start->next;
	if(!start)//check if the start become null cause the linked list was containing only one node
		end = NULL;
	else
		start->pre = NULL;

	temp ->pre = temp ->next = NULL; //to make the one who will get this node know nothing about locations of other nodes in the linked list

	size--;
	return temp;
}

template<class T>
Node<T>* LinkedList<T>::getLast(){
	if(isEmpty())
		return NULL;
	Node<T> * temp = end;
	end = end->pre;
	if(!end)//check if the start become null cause the linked list was containing only one node
		start = NULL;
	else
		end->next = NULL;

	temp ->pre = temp ->next = NULL; //to make the one who will get this node know nothing about locations of other nodes in the linked list

	size--;
	return temp;
}

template <class T>
Node<T>* LinkedList<T>::peekFirst(){
	if(isEmpty())
		return NULL;

	Node<T> * temp = new Node<T>();
	temp->data = start->data;

	return temp;
}
template <class T>
Node<T>* LinkedList<T>::peekLast(){
	if(isEmpty())
		return NULL;

	Node<T> * temp = new Node<T>();
	temp->data = end->data;

	return temp;
}

template<class T>
void LinkedList<T>::display(){
	if(isEmpty()){
		cout<<"{}"<<endl;
		return;
	}
	Node<T>* temp = start;
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
	cout<<"***********************Int list***********************"<<endl;
	LinkedList<int> list1;

	Node<int>* n1= new Node<int>();
	n1->data=2;
	list1.appendNode(n1);

	Node<int>* n2 = new Node<int>();
	n2->data=4;
	list1.appendNode(n2);

	Node<int>* n3 = new Node<int>();
	n3->data=6;
	list1.appendNode(n3);

   	Node<int>* n4 = new Node<int>();
	n4->data=8;
	list1.appendNode(n4);

	Node<int>* n5 = new Node<int>();
	n5->data='5';
    list1.insertNode(n5);

	cout<<"List after append & insert: ";
	list1.display();

   	Node<int>* tempNode = list1.searchOnNode(5);
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

    cout<<"***********************Char list***********************"<<endl;

	LinkedList<char> list2;

	Node<char>* n6= new Node<char>();
	n6->data='c';
	list2.appendNode(n6);

	Node<char>* n7 = new Node<char>();
	n7->data='e';
	list2.appendNode(n7);

	Node<char>* n8 = new Node<char>();
	n8->data='t';
	list2.appendNode(n8);

	Node<char>* n9 = new Node<char>();
	n9->data='q';
	list2.appendNode(n9);

	Node<char>* n10 = new Node<char>();
	n10->data='d';
	list2.insertNode(n10);

	cout<<"List after append & insert: ";
	list2.display();

	Node<char>* tempNode2 = list2.searchOnNode('t');
	cout<<"Data of node returned from search = "<<tempNode2->data<<endl;

	if(list2.deleteNode('e'))
		cout<<"Node Deleted successfully"<<endl;
	else
		cout<<"Delete Failed, NO Node with this data"<<endl;

	cout <<"List after Delete: ";
	list2.display();
	cout<<"Size of the list = "<<list2.getSize()<<endl;;

	free(tempNode2); // free it before assign any other value to it to be away from making memory leak

	tempNode2 = list2.peekFirst();
	cout<<"First Peeked Node = "<<tempNode2->data<<endl;

	delete(tempNode2);

	tempNode2 = list2.peekLast();
	cout<<"last Peeked Node = "<<tempNode2->data<<endl;

	cout <<"List after applaying Peek methods: ";
	list2.display();

	delete(tempNode2);

	tempNode2 = list2.getFirst();
	cout<<"Data of node returned from getFirst: "<<tempNode2->data<<endl;
	delete(tempNode2);
	tempNode2 = list2.getLast();
	cout<<"Data of node returned from getLast: "<<tempNode2->data<<endl;

	cout<<"List after applaying get methods: ";
	list2.display();
	delete(tempNode2);

	list2.freeList();
	cout<<"List after applaying free method: ";
	list2.display();

	getch();
	return 0;
}