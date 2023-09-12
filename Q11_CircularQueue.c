#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
	int data;
	struct node* next;
} node;
node *front = NULL, *rear = NULL;

void enqueue(int d) { //Insert elements in Queue
	node *newnode = (node*)malloc(sizeof(node));
	newnode->data = d;
	newnode->next = NULL;

	if(rear==NULL && front==NULL) { // insert in the first location
		front = newnode;
		rear = newnode;
		rear->next = front;
	} else {
		rear->next = newnode;
		rear = newnode;
		newnode->next = front;
	}
}

int dequeue() { // Delete an element from Queue
	node *del = front;
	int data;
	if(front==NULL && rear==NULL){
		printf("\nQueue is Empty\n");
		return -999;
	} 
	else if(front == rear) {
		data = del->data;
		front = NULL;
		rear = NULL;
		free(del);
		return data;
	} else {
		data = del->data;
		front = front->next;
		rear->next = front;
		free(del);
		return data;
	}
}

void display() { // Print the elements of Queue
	node *temp = front;
	if(front==NULL && rear==NULL) printf("\nQueue is Empty\n");
	else {
		printf("\nQueue: ");
		do {
			printf("%d - ",temp->data);
			temp = temp->next;
		} while(temp != front);
		printf("\n");
	}
}

int main() {
	int opt,n,data;
        while(1){
		printf("\n1. Insert Data in Queue\n2. Display Queue \n3. Delete data from the Queue\n Choice: ");
		scanf("%d",&opt);
		if(opt<1 || opt >3) break;
		switch(opt) {
			case 1:
				printf("\nEnter the number of data: ");
				scanf("%d",&n);
				printf("\nEnter your data-\n");
				while(n>0) {
					scanf("%d",&data);
					enqueue(data);
					n--;
				}
				break;
			case 2:
				display();
				break;
			case 3:
				opt = dequeue();
				if(opt!=-999) printf("\nElement deleted: %d\n", opt);
				break;
			case 0:
				break;
			default:
				printf("\nIncorrect Choice");
		}
}
	return 0;
}
