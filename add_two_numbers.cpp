#include <iostream>
using namespace std;

struct node{
	int digit;
	struct node* link;
};

struct node* addtoList(struct node* head,int data){
	struct node* ptr = new node;
	ptr->digit = data;
	ptr->link = NULL;
	if(head == NULL){
		head->digit = ptr->digit;
		head->link = ptr->link;
		head = ptr;
	}
	else{
		struct node* temp = head;
		while(temp->link!=NULL){
			temp = temp->link;
		}
		temp->link = ptr;
	}
	return head;
}

struct node* extract(int number){
	struct node* head = NULL;
	int digit;
	while(number>0){
		digit = number%10;
		number = number/10;
		head = addtoList(head,digit);
	}
	return head;
}

void print(struct node* head){
	while(head!=NULL){
		cout<<head->digit<<endl;
		head = head->link;
	}
}

int main(void){
	cout<<"print works"<<endl;
	struct node* head = NULL;
	head = extract(2569);
	cout<<head;
	print(head);
	
}
