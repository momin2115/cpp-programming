#include <iostream>
using namespace std;

struct node{
	float coeff;
	int expo;
	struct node* link;
};



struct node* insertInSorted(struct node* head, float coeff, int expo){
	struct node* temp = NULL;
	struct node* newP = new node;
	newP->coeff = coeff;
	newP->expo = expo;
	newP->link=NULL;
	if(head==NULL||expo>head->expo){
		newP->link=head;
		head=newP;
	}
	else{
		temp = head;
		while(temp->link!=NULL && expo<=temp->link->expo){
			temp=temp->link;
		}
		newP->link = temp->link;
		temp->link = newP;
	}
	return head;
}

void printPoly(struct node* head){
	struct node* temp = head;
	while(temp!=NULL){
		cout<<temp->coeff<<"x^"<<temp->expo;
		if(temp->link!=NULL){
			cout<<"+";
		}
		else{
			cout<<" "<<endl;
		}
		temp=temp->link;
	}
}

struct node* create(struct node* head){
	int n, expo;
	float coeff;
	cout<<"Enter the number of terms in the polynomial"<<endl;
	cin>>n;
	for(int i = 0;i < n;i++){
		cout<<"Enter the coefficient for term "<<i+1<<endl;
		cin>>coeff;
		cout<<"Enter the exponent for term "<<i+1<<endl;
		cin>>expo;
		head = insertInSorted(head,coeff,expo);
	}
	return head;
}

struct node* polyAdd(struct node* head1, struct node* head2){
	struct node* ptr1=head1;
	struct node* ptr2=head2;
	struct node* head3 = NULL;
	while(ptr1!=NULL&&ptr2!=NULL){
		if(ptr1->expo = ptr2->expo){
			head3 = insertInSorted(head3,(ptr1->coeff+ptr2->coeff),ptr1->expo);
			ptr1=ptr1->link;
			ptr2=ptr2->link;
		}
		else if(ptr1->expo > ptr2->expo){
			head3 = insertInSorted(head3,ptr1->coeff,ptr1->expo);
			ptr1=ptr1->link;
		}
		else{
			head3 = insertInSorted(head3,ptr2->coeff,ptr2->expo);
			ptr2=ptr2->link;
		}
	}
	while(ptr1!=NULL){
		head3 = insertInSorted(head3,ptr1->coeff,ptr1->expo);
		ptr1=ptr1->link;
	}
	while(ptr2!=NULL){
		head3 = insertInSorted(head3,ptr2->coeff,ptr2->expo);
		ptr2=ptr2->link;
	}
	return head3;
}

struct node* polyProduct(struct node* head1, struct node* head2){
	struct node* ptr1 = head1;
	struct node* ptr2 = head2;
	struct node* head3 = NULL;
	while(ptr1!=NULL){
		ptr2=head2;
		while(ptr2!=NULL){
			head3 = insertInSorted(head3,(ptr1->coeff*ptr2->coeff),(ptr1->expo+ptr2->expo));
			ptr2 = ptr2->link;
		}
		ptr1 = ptr1->link;
	}
	return head3;
}

struct node* removeDuplicates(struct node* head){
	struct node* temp = NULL;
	struct node* ptr = head;
	while(ptr->link!=NULL){
		if(ptr->expo==ptr->link->expo){
			ptr->coeff=(ptr->coeff+ptr->link->coeff);
			temp = ptr->link;
			ptr->link = temp->link;
			delete temp;
			temp = NULL;
		}
		else{
			ptr=ptr->link;
		}
	}
	return head;
}

int main(void){
	struct node* head1 = NULL;
	struct node* head2 = NULL;
	struct node* head3 = NULL;
	cout<<"Enter the Polynomial 1"<<endl;
	head1 = create(head1);
	cout<<"Enter the Polynomial 2"<<endl;
	head2 = create(head2);
	printPoly(head1);
	printPoly(head2);
//	head3=polyAdd(head1,head2);
	head3=polyProduct(head1,head2);
	head3 = removeDuplicates(head3);
	printPoly(head3);
}
