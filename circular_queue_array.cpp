#include <iostream>
using namespace std;

#define MAX 5
int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int data){
	if(front==-1&&rear==-1){
		front = rear = 0;
		queue[rear]=data;
	}
	else if(((rear+1)%MAX)==front){
		cout<<"Queue is full"<<endl;
	}
	else{
		rear = (rear+1)%MAX;
		queue[rear]=data;
	}
	 
}

int dequeue(){
	int data;
	if(front==-1&&rear==-1){
		cout<<"Queue is empty"<<endl;
		return 0;
	}
	else if(front == rear){
		data = queue[front];
		front = rear = -1;
	}
	else{
		data = queue[front];
		front = (front+1)%MAX;
	}
	return data;
	
}

void display(){
	int i = front;
	if(front==-1&&rear==-1){
		cout<<"Queue is empty"<<endl;
	}
	else{
		cout<<"Queue is............"<<endl;
		while(i!=rear){
			cout<<queue[i]<<" "<<i<<endl;
			i = (i+1)%MAX;
		}
		cout<<queue[rear]<<endl;
	}
}

int main(void){
	enqueue(5);
	enqueue(6);
	enqueue(7);
	enqueue(8);
	enqueue(9);
	display();
	cout<<dequeue()<<"dequeued element"<<endl;
	display();
	enqueue(10);
	display();
	cout<<"dequeued"<<dequeue()<<endl;
	enqueue(12);
	display();
	enqueue(45);
	
}
