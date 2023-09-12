#include<stdio.h>

void push(int);
int pop();
void display();
int isFull();
int isEmpty();
void initialise();

int arr[10],size,top, cache;

int main(){
	initialise();
	while(1){
	printf("\n1. initialise");
	printf("\n2. push");
	printf("\n3. pop");
	printf("\n4. display");
	printf("\n5. isFull");
	printf("\n6. isEmpty");
	printf("\nChoose 1-6: ");
	scanf("%d", &cache);
	switch(cache){
		case 1: initialise();
		        break;
		case 2: printf("Enter element to push: ");
		        scanf("%d", &cache);
		        push(cache);
		        break;
	    case 3: cache = pop();
	            (cache != -999) ? printf("\nPoped element: %d\n", cache) : printf("\nStack is Empty\n");
	            break;
	    case 4: display();
		        break;
		case 5: (isFull()) ? printf("\nStack is Full\n") : printf("\nStack is not Full\n");
		        break;
		case 6: (isEmpty()) ? printf("\nStack is Empty\n") : printf("\nStack is not Empty\n");
		        break;
	    default: return 0;
	}
  }
}

void initialise(){
	top=-1;
	size=(sizeof(arr)/sizeof(arr[0]));
}

int isFull(){
  if(top>=size-1) return 1;
  return 0;
}
int isEmpty(){
	if(top==-1) return 1;
	else return 0;
}

void display(){
	if(!isEmpty()) for(cache=top;cache>=0;cache--) printf("%d ", arr[cache]);
}

void push(int elem){
	if(!isFull()) arr[++top]=elem; 
    else printf("Stack is Full");
}

int pop(){
	if(!isEmpty()) return (arr[top--]); 
	else return -999;
}
