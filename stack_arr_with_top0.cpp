#include <iostream>
using namespace std;
#define MAX 5

int first;
int arr[MAX];

int isEmpty(){
	if(first==-1)
		return 1;
	else
		return 0;
}

int isFull(){
	if(first==MAX-1)
		return 1;
	else
		return 0;
}

void push(int data){
	if(isFull()){
		cout<<"Stack Overflow"<<endl;
		return;
	}
	for(int i=first;i>=0;i--){
		arr[i+1]=arr[i];
	}
	first++;
	arr[0]=data;
}

int pop(){
	if(isEmpty()){
		cout<<"Stack Underflow"<<endl;
		exit(1);
	}
	int value = arr[0];
	for(int i=0;i<first;i++){
		arr[i]=arr[i+1];
	}
	first--;
	return value;
}

int peek(){
	return arr[0];
}

void print(){
	if(isEmpty()){
		cout<<"Stack is Empty"<endl;
		return;
	}
	for(int i=0;i<first;i++){
		cout<<arr[i]<<" ";
	}
}

void prime_factor(int num){
	
}

int main(void){
	push(2);
	push(4);
	push(7);
	print();
}
