#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *link;
};

void create(struct node *head){
	head->data=45;
	
	struct node* ptr = (struct node*)malloc(sizeof(struct node));
	ptr->data=35;
	head->link=ptr;
	
	ptr = (struct node*)malloc(sizeof(struct node));
	ptr->data=25;
	head->link->link=ptr;
	ptr->link = NULL;
	
	ptr = (struct node*)malloc(sizeof(struct node));
	ptr->data=75;
	head->link->link->link=ptr;
	ptr->link = NULL;	
}

void print_data(struct node *head){
	struct node *ptr = NULL;
	ptr = head;
	if(head==NULL)
	{
		printf("The list is Empty");
	}
	else if(head->link==NULL)
	{
		printf("%d",ptr->data);
		printf("%d",ptr->link);
	}
	else{
		while(ptr != NULL){
			printf("%d  ",ptr->data);
			printf("%d  ",ptr->link);
			ptr = ptr->link	;
		}	
	}	
}

void delete_last(struct node *head){
	struct node *ptr = head;
	struct node *ptr2 = head;
	while(ptr->link!=NULL){
		ptr2 = ptr;
		ptr = ptr->link;
	}
	ptr2->link = NULL;
	free(ptr);
	ptr = NULL;
}

void delete_last_using_single(struct node* head){
	struct node* temp = head;
	while(temp->link->link!=NULL)
	{
		temp=temp->link;
	}
	free(temp->link);
	temp->link=NULL;
}

struct node* delete_from_pos(struct node* head,int pos)
{	
	struct node* temp1 = head;
	struct node* temp2 = head;
	if(head==NULL)
		printf("Linked List is empty \n");
	else if(pos==1){
			head=temp1->link;
			free(temp1);
			temp1=NULL;
	}
	else{
		pos=pos-1;
		while(temp1->link!=NULL && pos!=0){
			pos--;
			temp2=temp1;
			temp1=temp1->link;
		}
		temp2->link=temp1->link;
		free(temp1);
		temp1=NULL;		
	}
	return head;
}
	
struct node* delete_list(struct node* head){
	struct node* temp = head;
	while(head!=NULL){
		temp=temp->link;
		free(head);
		head=temp;
	}
	return head;
}

struct node* reverse_list(struct node* head)
{
	struct node* prev = NULL;
	struct node* next = NULL;
	while(head!=NULL)
	{
		next = head->link;
		head->link = prev;
		prev = head;
		head = next;
	}
	head = prev;
	return head;
}

int main(){
	struct node *head = (struct node*)malloc(sizeof(struct node));
	create(head);
	print_data(head);
//	delete_last_using_single(head);
//	head = delete_from_pos(head,4);
//	head = delete_list(head);
	head = reverse_list(head);
	printf("\n After delete \n");
	print_data(head);
}

