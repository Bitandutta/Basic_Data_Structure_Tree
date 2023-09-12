#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
}node;
node *head=NULL;

void printCL();
void insertCL(int);
void insertCL_beg(int);
void insertCL_end(int);

void printCL(){
	node *temp=head;
	while(temp->next != head){
		printf("%d ", temp->data);
		temp=temp->next;
	}
	printf("%d ", temp->data);
	printf("\n");
}

void insertCL(int data){
	node *newNode = (node *) malloc(sizeof(node));
	newNode->data = data;
	newNode->next=head;
	if(head==NULL){
		head=newNode;
		head->next=head;
		return;
	}
	node *temp=head;
	while((temp->next) != head) temp=temp->next;
	temp->next=newNode;
}


void insertCL_beg(int data){
	node *newNode = (node*)malloc(sizeof(node));
	newNode->data = data;
	newNode->next=head;
	if(head==NULL) return;
	node *temp=head, *end;
	while((temp->next) != head) temp=temp->next;
	head=newNode;
	temp->next=head;
}

void insertCL_end(int data){
	node *newNode = (node*)malloc(sizeof(node));
	newNode->data = data;
	if(head==NULL) return;
	node *temp=head;
	while((temp->next) != head)	temp=temp->next;
	newNode->next=head;
	temp->next=newNode;
}

int main(){
	int i;
	for(i=1;i<=10;i++) insertCL(i);
	printf("\nOriginal List: ");
	printCL();
	
	insertCL_beg(56);
	printf("\nAfter inserting 56 in the begining: ");
	printCL();
	insertCL_end(90);
	printf("\nAfter inserting 90 in the end: ");
	printCL();
}
