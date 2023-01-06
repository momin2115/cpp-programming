#include <iostream>
using namespace std;
#define MAX 100

int stack_arr[MAX];
int top=-1;

int isFull(){
	if(top==MAX-1)
		return 1;
	else
		return 0;
}

int isEmpty(){
	if(top==-1)
		return 1;
	else
		return 0;
}

void push(int data){
	if(isFull()){
		cout<<"Stack Overflow"<<endl;
		return;
	}
	++top;
	stack_arr[top]=data;
}

int pop(){
	int value;
	if(isEmpty()){
		cout<<"Stack Underflow"<<endl;
		exit(1);
	}
	value = stack_arr[top];
	--top;
	return value;
}

int _top(){
	int value;
	if(isEmpty()){
		cout<<"Stack Underflow"<<endl;
		exit(1);
	}
	value = stack_arr[top];
	return value;
}

void print(){
		if(isEmpty()){
		cout<<"Stack is Empty"<<endl;
		exit(1);
	}
	for(int i=top;i>=0;i--){
		cout<<stack_arr[i]<<" ";
	}
	cout<<endl;
}

void prime_factor(int num){
	int i = 2;
	while(num!=1){
		while(num%i==0){
			push(i);
			num = num/i;
		}
	i++;
	}
}

void toBinary(int num){
	while(num!=0){
		push(num%2);
		num = num/2;
	}
}

//int main(void){
//	int choice, data;
//	while(1){
//		cout<<endl;
//		cout<<"1.Push"<<endl;
//		cout<<"2.Pop"<<endl;
//		cout<<"3.Print the topmost element"<<endl;
//		cout<<"4.Print all elements in the stack"<<endl;
//		cout<<"5.Quit"<<endl;
//		cin>>choice;
//
//	switch(choice){
//		case 1:
//			cout<<"Please enter the element to be pushed"<<endl;
//			cin>>data;
//			push(data);
//			break;
//		case 2:
//			data = pop();
//			cout<<"The Popped element is "<<data<<endl;
//			break;
//		case 3:
//			data = _top();
//			cout<<"The topmost element is "<<data<<endl;
//			break;
//		case 4:
//			print();
//			break;
//		case 5:
//			exit(1);
//		default:
//			cout<<"Please enter 1,2,3,4,5 "<<endl;
//	}
//}
//}



int main(void){
	int number;
	cout<<"Please enter the number: "<<endl;
	cin>>number;
	toBinary(number);
	cout<<"Binary number is "<<endl;
	while(top!=-1){
		cout<<pop()<<" ";
	}
}
