// Alternative merge two linked list

#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
}node;

node *n1_head=NULL, *n1_tail=NULL, *n2_head=NULL, *n2_tail=NULL, *merged_head=NULL, *merged_tail=NULL;

void mergeLinkedListAlternative();
void insertNode1(int value);
void insertNode2(int value);
void displayNode1();
void displayNode2();
void displayMergedList();

void mergeLinkedListAlternative(){
  node *temp1=n1_head, *temp2=n2_head;
  int c=1;
  if(temp1 != NULL || temp2 != NULL){ // atleast one list have data
    
	while(temp1 != NULL && temp2 != NULL){
		
     if(c==1){ // insert temp1->data
       node *newnode = (node*)malloc(sizeof(node));// Creating new node
       newnode->data = temp1->data;
	   newnode->next=NULL;
	   if(merged_head == NULL){ // insertion in head
		 merged_head = newnode;
		 merged_tail = newnode;
       }
       else {
         merged_tail->next=newnode;
		 merged_tail=newnode;
	   }
       temp1=temp1->next;
       c=0;
	 }
	 else { // insert temp2->data
	   node *newnode = (node*)malloc(sizeof(node));// Creating new node
       newnode->data = temp2->data;
	   newnode->next=NULL;
	   if(merged_head == NULL){ // insertion in head
		 merged_head = newnode;
		 merged_tail = newnode;
       }
       else {
         merged_tail->next=newnode;
		 merged_tail=newnode;
	   }
       temp2=temp2->next;
       c=1;
	 }
	}
	
	while(temp1 != NULL) { // inserting rest of list1
       node *newnode = (node*)malloc(sizeof(node));// Creating new node
       newnode->data = temp1->data;
	   newnode->next=NULL;
	   if(merged_head == NULL){ // insertion in head
		 merged_head = newnode;
		 merged_tail = newnode;
       }
       else {
         merged_tail->next=newnode;
		 merged_tail=newnode;
	   }
       temp1=temp1->next;
	}
	
	while(temp2 != NULL) { // inserting rest of list2
       node *newnode = (node*)malloc(sizeof(node));// Creating new node
       newnode->data = temp2->data;
	   newnode->next=NULL;
	   if(merged_head == NULL){ // insertion in head
		 merged_head = newnode;
		 merged_tail = newnode;
       }
       else {
         merged_tail->next=newnode;
		 merged_tail=newnode;
	   }
       temp2=temp2->next;
	 }
  }
  
  else {
   printf("\nTwo merging list are empty !\n");
   return;
  }
}


void insertNode1(int value) {
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
void insertNode2(int value) {
	node *newnode = (node*)malloc(sizeof(node));// Creating new node

	newnode->data = value;
	newnode->next = NULL;

	if(n2_head==NULL) { // insertion in head
		n2_head = newnode;
		n2_tail = newnode;
	} else {
		n2_tail->next = newnode;
		n2_tail = newnode;
	}
}
void displayNode1() {
	node *temp;
	temp=n1_head;
	while(temp != NULL) {
		printf("%d -> ",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
	printf("\n");
}
void displayNode2() {
	node *temp;
	temp=n2_head;
	while(temp != NULL) {
		printf("%d -> ",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
	printf("\n");
}
void displayMergedList() {
	node *temp;
	temp=merged_head;
	while(temp != NULL) {
		printf("%d -> ",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
	printf("\n");
}


int main(){
  int i;
  insertNode1(1);
  insertNode1(9);
  insertNode1(15);
  insertNode1(18);
  insertNode1(20);
  insertNode2(2);
  insertNode2(4);
  insertNode2(19);
  insertNode2(25);
  insertNode2(35);
  insertNode2(45);
  
  printf("List 1:  ");
  displayNode1();
  printf("List 2:  ");
  displayNode2();
  
  mergeLinkedListAlternative();
  printf("Merged List Alternative:  ");
  displayMergedList();
  return 0;
}
