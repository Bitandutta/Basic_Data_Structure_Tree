#include <stdio.h>
#define SIZE 7

typedef struct Stack {
	int top;
	int array[SIZE];
} stack;

void initialize(stack *s) {
	s->top = -1;
}

int isFull(stack *s) {
	if(s->top >= SIZE-1) return 1;
	else return 0;
}

int isEmpty(stack *s) {
	if(s->top == -1) return 1;
	else return 0;
}


void push(stack *s, int num) {
	if (isFull(s)) printf("\nStack is Full...\n");
	else  s->array[++s->top] = num;
}

int pop(stack *s) {
	if (isEmpty(s)) {
		printf("\nStack is Empty...\n");
		return -999;
	} else return s->array[s->top--];
}

void printStack(stack *s) {
	int i = s->top;
	while(i>=0) printf("%d ", s->array[i--]);
}

stack* reverse(stack *s) {
	stack *st_temp = (stack*)malloc(sizeof(stack)); // temporary stack is created
	initialize(st_temp);
	int i = s->top;
	while(i>=0) {
		push(st_temp, pop(s)); // temporary stack is filled with elements of original
		i--;
	}
	// now we delete original stack and return the new
	free(s);
	return st_temp;
}

int main() {

	stack *st= (stack*)malloc(sizeof(stack)); // stack is created

	initialize(st);

	push(st, 1);
	push(st, 2);
	push(st, 3);
	push(st, 4);
	push(st, 5);
	printf("Original Stack\n");
	printStack(st);
	st = reverse(st);
	printf("\nReversed Stack\n");
	printStack(st);
	return 0;
}

