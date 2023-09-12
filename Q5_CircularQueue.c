#include<stdio.h>
#include<stdlib.h>

void initialise();
void enqueue(int);
int dequeue();
void display();

int queue[4], front, rear, size = sizeof(queue)/sizeof(queue[0]);

void initialise() {
	front = -1;
	rear = -1;
}

void enqueue(int elem) { // insert

	if((front == 0 && rear== size-1) || (front == rear+1) ) printf("queue is full");
	else {
		if (front == -1) {
			front=0;
			rear=0;
		} else {
			if (rear == size-1) rear=0;
			else rear++;
		}
	}
	queue[rear] = elem;
}


int dequeue() {
	int elem;
	if (front == -1) {
		printf("\nQueue is empty!\n");
		return -1;
	} else {
		elem=queue[front];
		if (front == rear) {
			front=-1;
			rear=-1;
		} else {
			if(front == size-1) front = 0;
			else front++;
		}
		return elem;
	}
}

void display() {
	int front_pos=front, rear_pos=rear;
	if (front_pos == -1 ) printf("\nUnder-flow");
	else {
		if ( front_pos <= rear_pos) {
			while(front_pos <= rear_pos) {
				printf("%d, ", queue[front_pos]);
				front_pos++;
			}
		} else {
			while(front_pos <= size-1) {
				printf("%d, ", queue[front_pos]);
				front_pos++;
			}
			front_pos= 0;
			while ( front_pos <= rear_pos) {
				printf("%d, ", queue[front_pos]);
				front_pos++;
			}

		}
	}
}

int main() {
	int choice;
	initialise();
	while(1) {
		printf("\n1. Initialise\n");
		printf("2. Insert\n");
		printf("3. Delete\n");
		printf("4. Display\n");
		printf("Enter choice: ");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				initialise();
				break;
			case 2:
				printf("Enter element to insert: ");
				scanf("%d", &choice);
				printf("\n");
				enqueue(choice);
				break;
			case 3:
				printf("\nDeleted elem is %d", dequeue());
				break;
			case 4:
				printf("\nQueue: ");
				display();
				printf("\n");
				break;
			default:
				return 0;
		}
	}

}
