#include <iostream>
using namespace std;
struct node* addtoEmpty(struct node* head,int data);
struct node* addtoBegin(struct node* head, int data);
void addtoBeginpoint (struct node **head,int data);
void printData(struct node* head);
void addtoEnd(struct node* head,int data);



struct node 
{
	struct node *prev = NULL;
	int data;
	struct node *next = NULL;	
};

struct node* addtoEmpty(struct node* head,int data)
{
	struct node *temp = new node();
	temp->prev = NULL;
	temp->data = data;
	temp->next = NULL;
	head = temp;
	return head;
}

struct node* addtoBegin(struct node* head, int data)
{
	struct node *temp = new node();
	temp->data = data;
	temp->prev=NULL;
	temp->next = head;
	head->prev = temp;
	head = temp;
	return head;
}

void addtoBeginpoint (struct node **head,int data)
{
	struct node *temp = new node();
	temp->data = data;
	temp->prev=NULL;
	temp->next = *head;
	(*head)->prev = temp;
	*head = temp;
}

void addtoEnd(struct node* head,int data)
{
	struct node *temp = head;
	while(temp->next!=NULL)
	{
		temp = temp->next;
	}
	struct node *ptr = new node();
	ptr->data = data;
	ptr->prev = temp;
	ptr->next = NULL;
	temp->next = ptr;
}

void printData(struct node* head)
{
	struct node *ptr = head;
	while(ptr!=NULL)
	{
		cout<<ptr->data<<endl;
		ptr = ptr->next;
	}
}

void printCompleteList(struct node* head)
{
	struct node *ptr = head;
	while(ptr!=NULL)
	{
		cout<<ptr->prev<<"|"<<ptr->data<<"|"<<ptr->next<<endl;;
		ptr = ptr->next;
	}
}

struct node* addAfterPos(struct node* head, int data, int pos)
{		
		struct node* temp = head;
		while(pos!=1)
		{
			temp=temp->next;
			pos--;
		}
		struct node* ptr = new node();
		ptr->data=data;
		if(temp->next==NULL){
			temp->next = ptr;
			ptr->prev = temp;
		}
		else{
			ptr->prev=temp;
			ptr->next = temp->next;
			temp->next->prev = ptr;
			temp->next = ptr;
		}
	
	return head;	
}

struct node* addAtPos(struct node* head, int data, int pos)
{		
	if(pos==1)
	{
		head = addtoBegin(head,data);
	}
	else
	{
		struct node* temp = head;
		while(pos>2)
		{
			temp=temp->next;
			pos--;
		}
		struct node* ptr = new node();
		ptr->data=data;
		if(temp->next==NULL){
			temp->next = ptr;
			ptr->prev = temp;
		}
		else{
			ptr->prev=temp;
			ptr->next = temp->next;
			temp->next->prev = ptr;
			temp->next = ptr;
		}
	}
	
	return head;	
}

struct node* createList(struct node* head)
{
	int n,data,i;
	cout<<"Enter Number of nodes"<<endl;
	cin>>n;
	
	if(n==0){
		return head;
	}
	
	cout<<"Enter the data for the node 1"<<endl;
	cin>>data;
	head=addtoEmpty(head,data);
	
	for(i=1;i<n;i++)
	{
		cout<<"Enter the data for node "<<i+1<<endl;
		cin>>data;
		addtoEnd(head,data);
	}
	return head;
}

struct node* deleteFirst(struct node *head)
{
	head = head->next;
	delete head->prev;
	head->prev = NULL;
	return head;
}

void deleteLast(struct node *head)
{
	struct node *temp = head;
	while(temp->next->next!=NULL)
	{
		temp=temp->next;
	}
	delete temp->next;
	temp->next=NULL;
}

void deleteAtPos(struct node *head, int pos)
{
	struct node* temp = head;
	while(pos>1)
	{
		temp=temp->next;
		pos--;
	}
	struct node *temp2 = temp->prev;
	temp2->next=temp->next;
	temp->next->prev=temp2;
	delete temp;
}

struct node* reverseList(struct node* head)
{
	struct node* ptr1 = head;
	struct node* ptr2 = ptr1->next;
	ptr1->next = NULL;
	ptr1->prev = ptr2;
	while(ptr2!=NULL)
	{
		ptr2->prev = ptr2->next;
		ptr2->next = ptr1;
		ptr1 = ptr2;
		ptr2 = ptr2->prev;
	}	
	return ptr1;
}

int main()
{
	struct node *head = new node();
//	head = addtoEmpty(head,45);
//	head = addtoBegin(head,57);
//	addtoBeginpoint(&head,65);
//	addtoEnd(head,79);
//	addAfterPos(head,99,4);
//	addAtPos(head,89,3);
	head = createList(head);
//	head = deleteFirst(head);
//	deleteLast(head);
//	deleteAtPos(head,3);
	head = reverseList(head);
	printCompleteList(head);
}

