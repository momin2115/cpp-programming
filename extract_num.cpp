#include <iostream>
using namespace std;

struct node{
	int data;
	struct node* link;
};

struct node* addtoList(struct node* head,int data){
	struct node* ptr = new node;
	ptr->data = data;
	ptr->link = NULL;
	if(head==NULL){
		return ptr;
	}
	else{
		struct node* temp = head;
		struct node* temp1 = temp;
		while(temp!=NULL){
			temp1 = temp;
			temp = temp->link;
		}
		temp1->link=ptr;
		return head;
	}
}

void print(struct node* head){
	while(head!=NULL){
		cout<<head->data<<" "<<head->link<<endl;
		head = head->link;
	}
}

struct node* extract(int number){
	struct node* head = NULL;
	int digit=0;
	while(number>0){
		digit = number%10;
		number = number/10;
		head = addtoList(head,digit);
	}
	return head;
}

struct node* addList(struct node* head1, struct node* head2){
	struct node* ptr1 = head1;
	struct node* ptr2 = head2;
	struct node* head3 = NULL;
	int res,carry=0;
	while(ptr1!=NULL && ptr2!=NULL){
		res = ptr1->data+ptr2->data+carry;
		if(res>9){
			res = res%10;
			carry = 1;
		}
		else{
			carry = 0;
		}
		head3 = addtoList(head3,res);
		ptr1=ptr1->link;
		ptr2=ptr2->link;
	}
	while(ptr1!=NULL){
		cout<<"ptr 1 has more digit"<<endl;
		res = ptr1->data+carry;
		if(res>9){
			res = res%10;
			carry = 1;
		}
		else{
			carry = 0;
		}
		head3 = addtoList(head3,res);
		ptr1=ptr1->link;
	}
	while(ptr2!=NULL){
		cout<<"ptr2 hs more digit"<<endl;
		res = ptr2->data+carry;
		if(res>9){
			res = res%10;
			carry = 1;
		}
		else{
			carry = 0;
		}
		head3 = addtoList(head3,res);
		ptr2=ptr2->link;
	}
	if(carry==1){
		head3 = addtoList(head3,carry);
	}
	return head3;
}

int main(void){
	int num1,num2;
	cout<<"Enter the first number"<<endl;
	cin>>num1;
	cout<<"Enter the second number"<<endl;
	cin>>num2;
	struct node* head1 = extract(num1);
	struct node* head2 = extract(num2);
	print(head1);
	print(head2);
	struct node* head3 = addList(head1,head2);
	print(head3);
}
