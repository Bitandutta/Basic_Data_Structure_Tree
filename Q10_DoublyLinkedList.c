#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node *left, *right;
} node;

node *head = NULL, *tail = NULL;

void insert(int);
void display();
int searchByValue(int);
int searchByPos(int);
void insertByPos(int, int);
void deleteByValue(int);
void deleteByPos(int);
void reverse();

void insert(int value) {
	node *newnode = (node*)malloc(sizeof(node));// Creating new node

	newnode->data = value;
	newnode->left = NULL;
	newnode->right = NULL;

	if(head==NULL) { // insertion in head
		head = newnode;
		tail = newnode;
	} else {
		tail->right = newnode;
		newnode->left = tail;
		tail=newnode;
	}
}

void display() {

	node *temp = head;
	printf("\nList: ");
	while(temp != NULL) {
		printf("%d <-> ",temp->data);
		temp=temp->right;
	}
	printf("NULL\n");
	printf("\n");

}

int searchByValue(int value) {

	node *temp = head;
	while(temp != NULL) {
		if(temp->data == value) return 1;
		temp = temp->right;
	}

	return 0; //not found
}

int searchByPos(int pos) {

	node *temp = head;
	while(pos>1) {
		if (temp == NULL) return -999; // invalid location
		pos--;
		temp=temp->right;
	}

	return temp->data;
}

void insertByPos(int value, int pos) {
	if(pos < 1) {
		printf("\nInvalid Position\n");
		return; // invalid position
	}
	if(pos == 1) { // insert in head
		node *newnode = (node*)malloc(sizeof(node));// Creating new node
		newnode->data = value;
		newnode->right = head;
		newnode->left = NULL;
		head=newnode;
	} else {
		node *temp=head, *prevTemp = head;
		while(pos>1) {
			if (temp == NULL && pos>2) {
				printf("\nInvalid position!\n");
				return -999; // invalid location
			}
			pos--;
			prevTemp = temp;
			temp=temp->right;
		}

		node *newnode = (node*)malloc(sizeof(node));// Creating new node
		newnode->data = value;

		if(temp != NULL) { // insert in between beg and end anywhere
			prevTemp->right = newnode;
			newnode->left = prevTemp;
			newnode->right = temp;
			temp->left=newnode;
		} else { // insert at the end
			tail->right = newnode;
			newnode->left = tail;
			tail=newnode;
		}
	}
}

void deleteByValue(int elem) {
	node *temp = head, *prev_temp;
	if(temp==NULL) {
		printf("\nEmpty List!");
		return;
	}
	if(temp->data == elem) { // delete from head
		head= temp->right;
		temp->right->left=NULL;
		free(temp);
		return;
	}
	while(temp != NULL) {
		if(temp->data == elem && temp->right != NULL) { // element found to delete from between anywhere
			prev_temp->right = temp->right;
			temp->right->left=prev_temp;
			free(temp);
			return;
		} else if(temp->data == elem && temp->right == NULL) { // delete from end
			prev_temp->right=NULL;
			free(temp);
			return;
		}
		prev_temp = temp;
		temp = temp->right;
	}
	printf("\nElemnt not found!\n");
}


void deleteByPos(int pos) {
	node *temp = head, *prev_temp;
	if(temp==NULL || pos <1) {
		printf("\nInvalid Position!\n");
		return;
	}
	if(pos == 1) { // delete from head
		head= temp->right;
		temp->right->left=NULL;
		free(temp);
		return;
	}
	while(pos>1) {
		prev_temp = temp;
		temp = temp->right;
		pos--;
		if(temp==NULL) {
			printf("\nInvalid Position!\n");
			return;
		}
	}
	if(temp->right == NULL) { // delete from end
		prev_temp->right=NULL;
		free(temp);
	} else { // delete from between anywhere
		prev_temp->right = temp->right;
		temp->right->left=prev_temp;
		free(temp);
	}

}


int main() {
	int i;
	for(i=1; i<=10; i++) insert(i);

	display();

	printf("\nSearching for 5: %d", searchByValue(5));
	printf("\nSearching for 12: %d\n", searchByValue(12));
	printf("\nSearch by position for 5: %d", searchByPos(5));
	printf("\nSearch by position for 12: %d\n", searchByPos(12));

	printf("\nInserting 55 at position 3" );
	insertByPos(55, 3);
	display();
	printf("\nInserting 99 at position 11" );
	insertByPos(99, 11);
	display();
	printf("\nInserting 67 at position 1" );
	insertByPos(67, 1);
	display();

	printf("\nDeleting 5");
	deleteByValue(5);
	display();

	printf("\nDeleting by pos 10");
	deleteByPos(10);
	display();
	printf("\nDeleting by pos 21");
	deleteByPos(21);
	display();

}

