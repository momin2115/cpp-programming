#include <iostream>
using namespace std;

typedef struct node{
	int data;
	struct node* link;
} node;

node* front = 0;
node* rear = 0;

void enqueue(int data){
	node* temp = new node;
	temp->data = data;
	temp->link = NULL;
	if(front==NULL&&rear==NULL){
		front = temp;
		rear = temp;
	}
	else{
		rear->link = temp;
		rear = temp;
	}
}

int dequeue(){
	int temp = front->data;
	front = front->link;
	return temp;
}

void print(){
	node* temp = front;
	while(temp!=NULL){
		cout<<temp->data<<endl;
		temp = temp->link;
	}
}

int main(void){
	enqueue(45);
	enqueue(50);
	enqueue(55);
	enqueue(60);
	print();
	cout<<dequeue()<<"Dequeued"<<endl;
	print();
}
