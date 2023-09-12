#include<stdio.h>
#include<stdlib.h>

void insert(int );
void display_List();
void deleteByPos(int);
void deleteMultipleOccurances(int);
void deleteDuplicate();
int insertAfter(int, int);

// linked list structure block
typedef struct Node {
	int data;
	struct Node *next;
} node;

node *head=NULL, *tail=NULL;

void display_List() {
	node *temp;
	temp=head;
	while(temp != NULL) {
		printf("%d -> ",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
	printf("\n");
}

void insert(int value) {
	node *newnode = (node*)malloc(sizeof(node));// Creating new node

	newnode->data = value;
	newnode->next = NULL;

	if(head==NULL) { // insertion in head
		head = newnode;
		tail = newnode;
	} else {
		tail->next=newnode;
		tail=newnode;
	}
}

void deleteByPos(int pos) {
	node *temp = head;
	int i;
	if(head==NULL) {
		printf("\nEmpty List!\n");
		return;
	}
	if(pos==0) {
		printf("\nElement deleted: %d\n",temp->data);
		head=head->next;
		temp->next=NULL;
		free(temp);// Node deleted
	} else {
		for(i=0; i<pos-1; i++) temp=temp->next;
		node *del = temp->next;
		printf("\nElement deleted: %d\n",del->data);
		temp->next = temp->next->next;
		del->next = NULL;
		free(del);// Node deleted
	}
}

void deleteMultipleOccurances(int number) {
	node *temp;

	if(head==NULL) {
		printf("\nEmpty List!\n");
		return;
	}

	while( (head != NULL) && (head->data == number) ) { // if elements are repeated in head
		node *del = head;
		head=head->next;
		del->next = NULL;
		free(del);
	}

	temp=head;

	while(temp->next != NULL) {
		if(temp->next->data == number) {
			node *del = temp->next;
			temp->next = temp->next->next;
			del->next = NULL;
			free(del);// Node deleted
		} else temp=temp->next;
	}
}

void deleteDuplicate() {
	if(head==NULL) {
		printf("\nEmpty List!\n");
		return;
	}
	node *temp1 = head, *temp2 = head, *del;

	while(temp1 != NULL) {
		temp2=temp1;
		while(temp2->next != NULL) {

			if(temp1->data == temp2->next->data) { // delete temp2->next
				del = temp2->next;
				temp2->next = temp2->next->next;
				del->next = NULL;
				free(del);// Node deleted
			}

			else temp2 = temp2->next;
		}

		temp1=temp1->next;
	}
}

int insertAfter(int value, int elem) {
	if(head==NULL) {
		printf("\nElement %d does not exist!", elem);
		return 0;
	}
	node *temp=head;

	while(temp!=NULL) {
		if(temp->data == elem) break;
		temp=temp->next;
	}

	if(temp==NULL) {
		printf("\nElement %d does not exist!", elem);
		return 0;
	}

	node *newnode = (node*)malloc(sizeof(node));// Creating new node

	newnode->data = value;
    newnode->next=temp->next;
	temp->next = newnode;
    return 1;
}

int main() {
    int i;
    insert(10);
    insert(10);
    insert(10);
    for(i=0;i<70;i+=10) insert(i);
	insert(10);
	insert(10);
	insert(10);
	insert(20);
	insert(30);
	insert(40);

	printf("Linked List:\n");
	display_List();
	
	printf("Inserting 65, after 60:\n");
	if(insertAfter(65, 60)) display_List();
	

	printf("After deleting multiple occurances of 10\n");
	deleteMultipleOccurances(10);
	display_List();

	printf("After deleting duplicates\n");
	deleteDuplicate();
	display_List();

	return 0;
}
