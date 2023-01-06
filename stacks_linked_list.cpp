#include <iostream>
using namespace std;

typedef struct node {
	int data;
	struct node* link;
} node;

node* top = 0;
node* top1 = 0;
node* top2 = 0;


void push(node** top,int data){
	node* temp = new node;
	temp->data = data;
	temp->link = *top;
	*top = temp;
}

node* pop(node** top){
	node* data = (*top);
	*top = data->link;
	return data;
}

void print(node* top){
	node* temp = top;
	while(temp!=NULL){
		cout<<temp->data<<endl;
		temp = temp->link;
	}
}

int check_pallindrome(node** top1,node** top2){
	while(*top1!=NULL && *top2!=NULL){
		if(!(pop(*top1)->data==(pop(*top2)->data)){
			return 0;	
		}
		return 1;		
	}
}

int main(void){
		int n, data;
		cout<<"Enter the number of nodes for the first linked list"<<endl;
		cin>>n;
		for(int i=1;i<=n;i++){
			cout<<"Enter the data for node: "<<i<<endl;
			cin>>data;
			push(&top,data);
			push(&top2,data);
		}
		while(top!=NULL){
			node* data = pop(&top);
			push(&top1,data->data);
		}
		cout<<".....................top2"<<endl;
		print(top2);
		cout<<".....................top1"<<endl;
		print(top1);
		
		if(check_pallindrome(&top1,&top2)){
			cout<<"true"<<endl;
		}
		else{
			cout"false"<<endl;
		}		
}
