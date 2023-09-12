#include<stdio.h>
#include<stdlib.h>

void insert(int );
void displayList();
int searchByValue(int);
int searchByPos(int);
int insertByPos(int, int);
void deleteByPos(int);
void deleteByValue(int);
void reverse();

// linked list structure block
typedef struct Node {
	int data;
	struct Node *next;
} node;

node *head=NULL, *tail=NULL;

void displayList() {
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

void deleteByValue(int value) {
	node *temp = head;
	if(head==NULL) {
		printf("\nEmpty List!\n");
		return;
	}
	if(temp->data == value) {
		printf("\nElement deleted: %d\n",temp->data);
		head=head->next;
		temp->next=NULL;
		free(temp);// Node deleted
	} else { 
		while(temp->next->data != value) {
			temp=temp->next;
			if( temp == NULL) {
				printf("Element not found!\n");
				return;
			}
		}
		node *del = temp->next;
		printf("\nElement deleted: %d\n",del->data);
		temp->next = temp->next->next;
		del->next = NULL;
		free(del);// Node deleted
	}
}

int searchByValue(int value) {
	node *temp = head;
	if(head==NULL) return -999;

	while(temp != NULL) {
		if(temp->data == value) return 1; // success
		temp = temp->next;
	}
	return -999; // not found
}
int searchByPos(int pos) {
	node *temp = head;
	int i;
	if(head==NULL) return -999;

	for(i=0; i<pos-1; i++){
		temp=temp->next;
		if(temp == NULL && i!=pos-1) return -999;
	} 
	if(temp!=NULL) return temp->data;
	else return -999; // not found
}

int insertByPos(int value, int pos) {
	if(head==NULL && pos>0 || pos<0) {
		printf("\nInvalid position!\n");
		return -999; // unsuccesful
	}

	if(pos == 0) {
		node *newnode = (node*)malloc(sizeof(node));// Creating new node
		newnode->data = value;
		newnode->next=head;
		head = newnode;
		return 1;
	}

	node *temp=head;
	int i;
	for(i=1; i<pos; i++) {
		temp=temp->next;
		if(temp == NULL && i != (pos-2)) {
			printf("\nInvalid position!\n");
			return -999; // not possible
		}

	}

	node *newnode = (node*)malloc(sizeof(node));// Creating new node
	newnode->data = value;
	newnode->next=temp->next;
	temp->next = newnode;
	return 1;
}

void reverse() {
	node *prev = NULL, *current = head, *next = NULL;
	tail = head;
	while (current != NULL) {
		next = current->next; // save next ad
		current->next = prev; // Reverse current node's ad
		prev = current;
		current = next;
	}
	head = prev;
}

int main() {
	int choice, pos;

	while(1) {

		printf("\n1. Create (insert)\n");
		printf("2. Display\n");
		printf("3. Search by Element\n");
		printf("4. Search by Position\n");
		printf("5. Insert by Position\n");
		printf("6. Delete by Value\n");
		printf("7. Delete by Position\n");
		printf("8. Reverse\n");
		printf("Enter choice: ");
		scanf("%d", &choice);

		//if(choice < 1 || choice >8) break;

		switch(choice) {
			case 1:
				printf("\nEnter element to insert: ");
				scanf("%d", &choice);
				insert(choice);
				break;
			case 2:
				displayList();
				break;
			case 3:
				printf("\nEnter element to search: ");
				scanf("%d", &choice);
				choice = searchByValue(choice);
				if(choice == 1) printf("\nElement is found!");
				else printf("\nElement is not found!");
				break;
			case 4:
				printf("\nEnter position to search: ");
				scanf("%d", &choice);
				choice = searchByPos(choice);
				if(choice != -999) printf("\nElement found is %d", choice);
				else printf("\nElement not found!");
				break;
			case 5:
				printf("\nEnter element to insert: ");
				scanf("%d", &choice);
				printf("\nEnter position: ");
				scanf("%d", &pos);
				insertByPos(choice, pos-1);
				break;
			case 6:
				printf("\nEnter element to delete: ");
				scanf("%d", &choice);
				deleteByValue(choice);
				break;
			case 7:
				printf("\nEnter position to delete: ");
				scanf("%d", &choice);
				deleteByPos(choice);
				break;
			case 8:
				reverse();
				displayList();
				break;
			default:
				return 0;
		}
	}
	return 0;
}
