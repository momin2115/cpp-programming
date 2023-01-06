#include <stdio.h>
#include <stdlib.h>

struct node {
int data;
struct node *link;
};

int main(){
struct node *head = (struct node*)malloc(sizeof(struct node));
head->data = 45;

struct node *current = (struct node*)malloc(sizeof(struct node));
current->data = 98;
head->link = current;

current = (struct node*)malloc(sizeof(struct node));
current->data = 3;
current->link = NULL;
head->link->link = current;

printf("%d \n",head->link);
printf("%d \n",head->data);

printf("%d \n",head->link->link);
printf("%d \n",head->link->data);


printf("%d \n",head->link->link->data);
printf("%d \n",head->link->link->link);

return 0;
}
