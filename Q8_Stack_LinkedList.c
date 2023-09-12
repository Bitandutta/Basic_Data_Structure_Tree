#include<stdio.h>
#include<stdlib.h>

void push(int);
int pop();
void displayStack();
int stackSize();

typedef struct Node {
	int data;
	struct Node *next;
}node;
node *head = NULL;

void push(int elem){
	node *newNode = (node*)malloc(sizeof(node));// Creating new node
	newNode->data=elem;
	newNode->next=head;
	head=newNode;
}

int pop(){
	int val = head->data;
	node *del = head;
	head = head->next;
	del->next=NULL;
	free(del); // node is deleted
	return val;
}

void displayStack(){
	node *temp=head;
	printf("\nStack: \n");
	while(temp!=NULL){
		printf("%d ", temp->data);
		temp=temp->next;
	} 
	printf("\n");
}
int stackSize(){
	node *temp=head;
	int counter=0;
	while(temp!=NULL){
		counter++;
		temp=temp->next;
	} 
    return counter;
}

int main(){
	int i;
	for(i=1; i<=10; i++) push(i);
	displayStack();
	printf("Stack Size: %d\n", stackSize());
	printf("\nPopped: %d\n", pop());
	printf("Popped: %d\n", pop());
	displayStack();
	printf("Stack Size: %d\n", stackSize());
	printf("\nPushed: 50\nPushed: 100\n");
	push(50);
	push(100);
	displayStack();
	printf("Stack Size: %d\n", stackSize());
}
