#include<stdio.h>
#include<ctype.h>

int stack[20];
int top = -1;

void push(int x) {
	top++;
	stack[top] = x;
}

int pop() {
	return stack[top];
}

int postFixEvaluation(char *e){
	int n1,n2,n3,num;
	while(*e != '\0') {
		if(isdigit(*e)) {
			num = *e - 48;
			push(num);
			e++;
		}

		else {
			n1 = pop();
			top--;
			n2 = pop();
			top--;
			switch(*e) {
				case '+':
					n3 = n2 + n1;
					break;
				case '-':
					n3 = n2 - n1;
					break;
				case '*':
					n3 = n2 * n1;
					break;
				case '/':
					n3 = n2 / n1;
					break;
			}
			push(n3);
			e++;
		}

	}
	printf("\nThe result of expression  =  %d\n\n",pop());
}

int main() {
	char exp[20];
	printf("Enter the expression: ");
	gets(exp);
	
	postFixEvaluation(exp);
	
    return 0;
} 
