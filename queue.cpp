#include <iostream>
using namespace std;

#define MAX 5
int queue[MAX];
int front=-1;
int rear=-1;

void enqueue(int data){
	if(rear==MAX-1){
		cout<<"Queue Overflow"<<endl;
		exit(1);
	}
	else if(front==-1&&rear==-1){
		front++;
		rear++;
	}
	else{
		rear++;
	}
	queue[rear]=data;
}

int dequeue(){
	int data;
	if(front==-1&&rear==-1){
		cout<<"Queue is empty"<<endl;
	}
	else if(front == rear){
		data = queue[front];
		front = 0;
		front = 0;
	}
	else{
		data = queue[front];
		front++;
	}
	return data;
}

int peek(){
	return queue[front];
}

void display(){
	cout<<"The queue is"<<endl;
	for(int i=front;i<=rear;i++){
		cout<<queue[i]<<endl;
	}
}

int main(void){
	enqueue(5);
	enqueue(6);
	enqueue(7);
	display();
	cout<<"peek"<<peek()<<endl;
	dequeue();
	display();
}
