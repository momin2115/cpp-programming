#include <iostream>
using namespace std;

struct node{
	int data;
	struct node* link;
};

struct node* addinEmpty(int data){
	struct node* temp = new node();
	temp->data=data;
	temp->link=temp;
	return temp;
}

struct node* addAtBeg(struct node* tail,int data){
	struct node* temp = new node;
	temp->data=data;
	temp->link=tail;
	tail->link = temp;
	return tail;
}

struct node* addAtEnd(struct node* tail, int data){
	struct node* temp = new node;
	temp->data = data;
	temp->link = tail->link;
	tail->link = temp;
	return temp; 
}

void printList(struct node* tail){
	struct node* temp = tail->link ;
	do{
		cout<<temp->data<<endl;
		temp=temp->link;
	}while(temp!=tail->link);
}

void printCompleteList(struct node* tail){
	struct node* temp = tail->link ;
	do{
		cout<<temp->data<<"  "<<temp->link<<endl;
		temp=temp->link;
	}while(temp!=tail->link);
}


struct node* createList(struct node* tail){
	int n,data;
	cout<<"How may items should be in the list??"<<endl;
	cin>>n;
	cout<<"Please enter data for node 1"<<endl;
	cin>>data;
	tail = addinEmpty(data);
	
	for(int i=1;i<n;i++){
		cout<<"Please enter data for node "<<i+1<<endl;
		cin>>data;
		tail = addAtEnd(tail,data);
	}
	return tail;		
}

struct node* addAfterPos(struct node* tail, int data,int pos){
	struct node* temp = tail->link;
	struct node* ptr = new node;
	ptr->data = data;
	while(pos>1)
	{
		temp=temp->link;
		pos--;
	}
	ptr->link=temp->link;
	temp->link = ptr;
	if(temp==tail){
	tail = tail->link;
	}
	return tail;
}

void deleteFromBeg(struct node* tail){
	struct node* temp = tail->link;
	tail->link = temp->link;
	delete temp;
}

struct node* deleteFromLast(struct node* tail){
	struct node* temp = tail->link;
	while(temp->link!=tail){
		temp=temp->link;
	}
	temp->link=tail->link;
	delete tail;
	return temp;
}

struct node* deleteAtPos(struct node* tail,int pos){
	struct node* temp = tail->link;;
	while(pos>2){
		temp=temp->link;
		pos--;
	}
	struct node* ptr = temp->link;
	temp->link=ptr->link;
	if(ptr==tail){
		tail=temp;
	}
	delete ptr;
	return tail;
}

void countingElements(struct node* tail){
	struct node* temp = tail->link;
	int c=0;
	do{
		c++;
		temp=temp->link;
	}while(temp!=tail->link);
	cout<<"There are "<<c<<" elements in the list"<<endl;
}

int searchForAnElement(struct node* tail,int data){
	struct node* temp = tail->link;
	int index = 0;
	do{
		index++;
		if(temp->data == data){
			return index;
		}
		temp=temp->link;
	}
	while(temp!=tail->link);
	return -1;
}

int main(){
	struct node* tail;
	tail = addinEmpty(34);
	tail = addAtBeg(tail,45);
	tail = addAtEnd(tail,57);
	tail = addAfterPos(tail,89,3);
//	tail = createList(tail);
//	tail = deleteFromLast(tail);
//	printCompleteList(tail);
//	tail = deleteAtPos(tail,2);
	printCompleteList(tail);
//	int index = searchForAnElement(tail,57);
	cout<<"The element 57 is in "<<searchForAnElement(tail,60)<<" position."<<endl;
	countingElements(tail);
	printCompleteList(tail);
	
	return 0;
}
