#include<stdio.h>
#include<stdlib.h>

void push(char);
char pop();
int isFull();
int isEmpty();
void initialise();
int balanced(char*);
int checkForMatch(char, char);

char arr[50];
int size,top;

int main(){
	char inp[50];
	initialise();// inintialises the stack variables
	
	printf("Enter your expression: ");
	scanf("%s", inp);
	
	if(balanced(inp)) printf("\nBalanced!");
	else printf("\nNot Balanced!");
	
	return 0;
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

void push(char elem){
	if(!isFull()) arr[++top]=elem; 
    else printf("Stack is Full");
}

char pop(){
	if(!isEmpty()) return (arr[top--]); 
	else return '\0'; // ASCII 0
}

int balanced(char inp[]){
	int i=0;
	if(inp[i] == '\0') return 0; // no expression given

	while(inp[i] != '\0'){
		
		if(inp[i] == '(' || inp[i] == '{' || inp[i] == '[') push(inp[i]);

		if(inp[i] == ')' || inp[i] == '}' || inp[i] == ']'){
			if(isEmpty()) return 0; // stack is empty so pop isn't possible
			if(!checkForMatch(pop(), inp[i]) ) return 0; // not matched
		} 
		i++;
	}
	if(!isEmpty()) return 0; // stack isn't empty means not balanced
	return 1;
}
int checkForMatch(char c1, char c2){
	if (c1 == '(' && c2 == ')') return 1;
    else if (c1 == '{' && c2 == '}') return 1;
    else if (c1 == '[' && c2 == ']') return 1;
    else return 0;
}
