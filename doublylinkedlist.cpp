#include <iostream>
using namespace std;

struct node{
	int data;
	struct node* prev;
	struct node* next;
};

struct node* addInEmpty(struct node* tail,int data){
	tail = new node;
	tail->data = data;
	tail->prev = tail;
	tail->next = tail;
	return tail;
}

void printList(struct node* tail){
	struct node* temp = tail->next;
	do{
		cout<<temp->data<<endl;
		temp=temp->next;
	}while(temp!=tail->next);
}

struct node* addAtBeg(struct node* tail,int data){
	struct node* ptr = tail->next;
	struct node* temp = new node;
	temp->data = data;
	temp->prev = tail;
	temp->next = ptr;
	ptr->prev = temp;
	tail->next = temp;
	return tail;
}

struct node* addAtEnd(struct node* tail, int data){
	struct node* temp = new node;
	temp->data = data;
	temp->prev = tail;
	temp->next = tail->next;
	tail->next = temp;
	return temp;
}

struct node* addAfterPos(struct node* tail, int data,int pos){
	struct node* temp = tail->next;
	while(pos>1){
		temp=temp->next;
		pos--;
	}
	struct node* ptr = new node;
	ptr->data = data;
	ptr->prev = temp;
	ptr->next = temp->next;
	temp->next = ptr;
	if(temp==tail){
		tail = ptr;
	}
	return tail;
}

struct node* deleteFirst(struct node* tail){
	if(tail==NULL){
		cout<<"List is already empty"<<endl;
	}
	else if(tail->next == tail){
		delete tail;
	}
	else{
		struct node* temp = tail->next;
		tail->next=temp->next;
		temp->next->prev=tail;
		delete temp;
	}
	return tail;
}

struct node* deleteLast(struct node* tail){
	if(tail==NULL){
		cout<<"List is already empty"<<endl;
	}
	else if(tail->next == tail){
		delete tail;
	}
	else{
		struct node* temp = tail->prev;
		temp->next = tail->next;
		tail->next->prev = temp;
		delete tail;
		tail = temp;
	}
	return tail;
}

struct node* deleteAtPos(struct node* tail,int pos){
	if(tail==NULL){
		cout<<"List is already empty"<<endl;
	}
	else if(tail->next == tail){
		delete tail;
	}
	else{
		
	}
	struct node* temp = tail->next;
	while(pos>2){
		temp=temp->next;
		pos--;
	}
	struct node* ptr = temp->next;
	temp->next=ptr->next;
	ptr->next->prev=temp;
	delete ptr;	
	return tail;
}

struct node* createList(struct node* tail){
	int n,data;
	cout<<"Enter the number of nodes to be created: "<<endl;
	cin>>n;
	cout<<"Enter the data for node 1"<<endl;
	cin>>data;
	tail = addInEmpty(tail,data);
	for(int i = 1;i<n;i++){
		cout<<"Enter the data for node "<<i+1<<endl;
		cin>>data;
		tail = addAtEnd(tail,data);
	}
	return tail;
}

struct node* addAtPos(struct node* tail, int data,int pos){
	struct node* temp = tail->next;
	while(pos>2){
		temp=temp->next;
		pos--;
	}
	struct node* ptr = new node;
	ptr->data = data;
	ptr->prev = temp;
	ptr->next = temp->next;
	temp->next = ptr;
	if(temp==tail){
		tail = ptr;
	}
	return tail;
}

struct node* addInSorted(struct node* tail,int data){
	int index=0,flag=0;
	struct node* temp = tail->next;
	if(tail==NULL || temp->data>data){
		tail = addAtBeg(tail,data);
		return tail;
	}
	else{
		do{	
		index++;
		if(temp->data>data){
			tail = addAtPos(tail,data,index);
			flag = 1;
			break;
		}
		temp=temp->next;
		}while(temp!=tail->next);
		if(flag==0){
			tail = addAtEnd(tail,data);
		}
	}

	return tail;
}

int main(void){
	struct node* tail = NULL;
	int data;
//	tail = addAtBeg(tail,67);
//	tail = addAtBeg(tail,95);
//	tail = addAtEnd(tail,34);
//	printList(tail);
//	tail = addAfterPos(tail,78,1);
//	cout<<"After add"<<endl;
//	printList(tail);
////	cout<<"After Delete"<<endl;
////	tail = deleteFirst(tail);
////	cout<<"After Delete last"<<endl;
////	tail = deleteLast(tail);
//	tail = deleteAtPos(tail,3);
//	cout<<"After deleting at pos 3"<<endl;
//	printList(tail);
	tail = createList(tail);
	cout<<".............................."<<endl;
	printList(tail);
	cout<<"Enter the number to be added"<<endl;
	cin>>data;
//	tail = addAtPos(tail,40,3);
	tail = addInSorted(tail,data);
	cout<<".............................."<<endl;
	printList(tail);
}

