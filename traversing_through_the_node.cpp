#include <stdio.h>
#include <stdlib.h>

struct node {
int data;
struct node *link;
};

void create_a_list(struct node *head){
	head->data = 45;
	
	struct node *current = (struct node*)malloc(sizeof(struct node));
	current->data = 98;
	head->link = current;
	
	current = (struct node*)malloc(sizeof(struct node));
	current->data = 3;
	current->link = NULL;
	head->link->link = current;
	
	printf("Created linked list \n");
	
	printf("%d \n",head->data);
	printf("%d \n",head->link);
	
	printf("%d \n",head->link->data);
	printf("%d \n",head->link->link);
	
	printf("%d \n",head->link->link->data);
	printf("%d \n",head->link->link->link);

}

void count_of_nodes(struct node *head){
	if(head == NULL)
	printf("The list is empty");
	struct node *ptr = NULL;
	ptr = head;
	int count = 0;
	while(ptr != NULL){
		count++;
		ptr = ptr->link;
	}
	printf("The number of nodes in the list is %d \n", count);
}

void print_data(struct node *head){
	if(head == NULL)
	printf("The list is empty");
	struct node *ptr = NULL;
	ptr = head;
	printf("Traversing and printing data \n");
	while(ptr != NULL){
		printf("%d \n",ptr->data);
		ptr = ptr->link;
	}
}

void add_node_at_end(struct node *head, int data){
	struct node *ptr, *temp = NULL;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->link = NULL;
	ptr = head;
	while(ptr->link != NULL){
		ptr=ptr->link;
	}
	ptr->link=temp;
}

struct node* optimal_add_at_end(struct node *ptr, int data){
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->link = NULL;
	ptr->link = temp;
	return temp;
}

struct node* add_node_at_begin(struct node *head, int data){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->link = head;
	return temp;
}

void add_node_at_begin_byref(struct node **head,int data){
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->link = *head;
	*head = temp;
}

void insert_at_a_position(struct node *head,int n,int data){
	struct node *ptr, *temp = NULL;
	int position;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	ptr = head;
	while(ptr!=NULL){
		position=position+1;
		if(position==(n-1))
		//printf("%d position\n",position);
		break;
		ptr=ptr->link;
	}
	temp->link = ptr->link;
	ptr->link = temp;	
}

struct node* delete_from_first(struct node *head){
	if(head == NULL)
		printf("List is already empty");
	struct node *temp = head;
	head = head->link;
	free(temp);
	temp=NULL;
	return head;
}

void delete_from_last(struct node *head){
	if(head == NULL)
		printf("List is already empty");
	else if(head->link == NULL){
		free(head);
		head=NULL;
	}
	else{
		struct node *temp = head;
		struct node *temp2= head;
		while(temp->link != NULL){
			temp2 = temp;
			temp2 = temp->link;
		}
		temp2->link = NULL; 
		free(temp);
		temp = NULL;
	}
}

int main(){
struct node *head = (struct node*)malloc(sizeof(struct node));
/*head->data = 45;
struct node *ptr = head;
ptr = optimal_add_at_end(ptr,98);
ptr = optimal_add_at_end(ptr,3);
ptr = optimal_add_at_end(ptr,67);
*/
//head = add_node_at_begin(head,89);
//add_node_at_begin_byref(&head,76);
//print_data(head);
//insert_at_a_position(head,7,57);
//print_data(head);

//count_of_nodes(head);


create_a_list(head);
//head=delete_from_first(head);


delete_from_last(head);
print_data(head);





//add_node_at_end(head,67);
//print_data(head);

return 0;
}
