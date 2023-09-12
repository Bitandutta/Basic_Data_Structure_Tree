//Split Link List

#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
}node;

node *n1_head=NULL, *n1_tail=NULL, *even_head=NULL, *even_tail=NULL, *odd_head=NULL, *odd_tail=NULL;

void splitOddEven();
void insertOriginalList(int value);
void displayOriginalList();
void displayEvenList();
void displayOddList();

void splitOddEven(){
  node *temp1=n1_head;
  
  if(temp1 != NULL){
    
	while(temp1 != NULL){
		
     if((temp1->data) & 1){ // odd
       node *newnode = (node*)malloc(sizeof(node));// Creating new node
       newnode->data = temp1->data;
	   newnode->next=NULL;
	   if(odd_head == NULL){ // insertion in head
		 odd_head = newnode;
		 odd_tail = newnode;
       }
       else {
         odd_tail->next=newnode;
		 odd_tail=newnode;
	   }
	 }
	 else { // even
	   node *newnode = (node*)malloc(sizeof(node));// Creating new node
       newnode->data = temp1->data;
	   newnode->next=NULL;
	   if(even_head == NULL){ // insertion in head
		 even_head = newnode;
		 even_tail = newnode;
       }
       else {
         even_tail->next=newnode;
		 even_tail=newnode;
	   }
	 }
	 temp1=temp1->next;
	}
  }
  
  else {
   printf("\nList is empty !\n");
   return;
  }
  
}


void insertOriginalList(int value) {
	node *newnode = (node*)malloc(sizeof(node));// Creating new node

	newnode->data = value;
	newnode->next = NULL;

	if(n1_head==NULL) { // insertion in head
		n1_head = newnode;
		n1_tail = newnode;
	} else {
		n1_tail->next = newnode;
		n1_tail = newnode;
	}
}

void displayOriginalList() {
	node *temp;
	temp=n1_head;
	while(temp != NULL) {
		printf("%d -> ",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
	printf("\n");
}
void displayEvenList() {
	node *temp;
	temp=even_head;
	while(temp != NULL) {
		printf("%d -> ",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
	printf("\n");
}
void displayOddList() {
	node *temp;
	temp=odd_head;
	while(temp != NULL) {
		printf("%d -> ",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
	printf("\n");
}


int main(){
  int i;
  for(i=0;i<=10;i++) insertOriginalList(i);
  
  printf("Original List:  ");
  displayOriginalList();
  
  splitOddEven();
  
  printf("Even List:  ");
  displayEvenList();
  printf("Odd List:  ");
  displayOddList();
  return 0;
}
