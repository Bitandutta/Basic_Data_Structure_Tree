#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	struct node *left;
	int data;
	struct node *right;
} Node;
typedef struct Stack { // node defining for stack
	struct node* data;
	struct Stack* next;
} stack;


Node* getNode(int value);
void displayArr(int arr[], int size);
int insert_BST_rec(Node **root, int number);
int insert_BST_iterative(Node **root, int number);
int search_BST_rec(Node *root, int target);
Node *delete_by_copy(Node*, int);
Node *in_order_predecessor(Node*);
int countNonLeafNode(Node*);
int countLeafNode(Node*);
int inorder_iterative(Node*);
int isEmpty(stack*);
void push(stack**, Node*);
Node* pop(stack**);
Node *peek(stack *s);


int main() {

	Node *tree_1 = NULL, *tree_2 = NULL;
	int elem[] = { 5, 1, 8, 2, 6, 0, 78, 21, 45};

	int i, size = (sizeof(elem)/sizeof(elem[0])), counter=0;


	printf("Array to be inserted: ");
	displayArr(elem, (sizeof(elem)/sizeof(elem[0])) );

	// insertion
	printf("\n\nArray inserted in tree_1 by recursion: ");
	for(i=0; i<size; i++) if(!insert_BST_rec(&tree_1, elem[i])) printf("\nInsertion of element %d at position %d was not possible", elem[i],i);
	printf("\nIn-order of tree_1: ");
	inorder_iterative(tree_1);
	printf("\n\nArray inserted in tree_2 by iteration: ");
	for(i=0; i<size; i++) if(!insert_BST_iterative(&tree_2, elem[i])) printf("\nInsertion of element %d at position %d was not possible", elem[i],i);
	printf("\nIn-order of tree_2: ");
	inorder_iterative(tree_2);


	// delete
	printf("\n\nDeleting 78 from tree_1\nIn-order: ");
	delete_by_copy(tree_1, 78);
	inorder_iterative(tree_1);

	// searching
	printf("\n\nSearching for 45: %d", search_BST_rec(tree_1, 45));
	printf("\nSearching for 15: %d\n", search_BST_rec(tree_1, 15));

	// traversals
	printf("\nPre-order iterative: ");
	preorder_iterative(tree_1);

	printf("\nIn-order iterative: ");
	inorder_iterative(tree_1);

	printf("\nPost-order iterative: ");
	postOrder_iterative(tree_1);

	// leaf and non leaf calculation
	printf("\n\nNon-Leaf: %d", countNonLeafNode(tree_1));
	printf("\nLeaf: %d\n", countLeafNode(tree_1));

}

void displayArr(int arr[], int size) {
	int i;
	for(i=0; i<size; i++) printf("%d, ", arr[i]);
}


Node* getNode(int value) {
	Node *p = (Node*)(malloc(sizeof(Node)));
	p->data = value;
	p->left=NULL;
	p->right=NULL;
	return p;
}


int insert_BST_rec(Node **root, int number) {
	if(*root == NULL) {
		(*root) = getNode(number);
		return 1;
	} else if(number < (*root)->data) return insert_BST_rec( &((*root)->left), number);
	else if(number > (*root)->data) return insert_BST_rec( &((*root)->right), number);
	else return 0;
}

int insert_BST_iterative(Node **root, int number) {

	Node *n = getNode(number);
	Node *temp = *root, *p=NULL;

	if((*root) == NULL) {
		(*root)=n;
		return 1;
	}

	while(temp != NULL) {
		p = temp;
		if(number > temp->data) temp = temp->right;
		else if(number < temp->data) temp = temp->left;
		else return 0;
	}

	if(number > p->data) p->right = n;
	else p->left = n;

	return 1;
}

int search_BST_rec(Node *root, int target) {
	if(root == NULL) return 0;
	if(root->data == target) return 1;
	if(target > root->data)	return(search_BST_rec(root->right, target));
	else return(search_BST_rec(root->left, target));
}

Node *in_order_predecessor(Node *root) {
	root=root->left;
	while(root->right != NULL) root=root->right;
	return root;
}

Node *delete_by_copy(Node *root,int elem) {
	Node *ipre;
	if(root == NULL) return NULL;

	if(root->left==NULL && root->right==NULL) {
		free(root);
		return NULL;
	}

	if(elem < root->data) root->left = delete_by_copy(root->left,elem);
	else if(elem >root->data) root->right = delete_by_copy(root->right,elem);
	else {
		ipre = in_order_predecessor(root);
		root->data =ipre->data;
		root->left = delete_by_copy(root->left,ipre->data);
	}
	return root;
}

int countNonLeafNode(Node* root) {
	// Base cases.
	if (root == NULL || (root->left == NULL && root->right == NULL)) return 0;
	// If root is Not NULL and its one of its child is also not NULL
	return 1 + countNonLeafNode(root->left) + countNonLeafNode(root->right);
}
int countLeafNode(Node* node) {
	if(node == NULL) return 0;
	if(node->left == NULL && node->right==NULL) return 1;
	else return countLeafNode(node->left) + countLeafNode(node->right);
}

int preorder_iterative(Node* root) { //preorder Traversing function
	Node* temp = root;
	stack* s_temp = NULL;
	int flag = 1;
	while(flag) { //Loop run untill temp is null and stack is empty
		if(temp) {
			printf("%d ",temp->data);
			push(&s_temp,temp);
			temp = temp->left;
		} else {
			if(!isEmpty(s_temp)) {
				temp = pop(&s_temp);
				temp = temp->right;
			} else flag = 0;
		}
	}
}

int inorder_iterative(Node* root) { //Inorder Traversing function
	Node* temp = root;
	stack* s_temp = NULL;
	int flag = 1;
	while(flag) { //Loop run untill temp is null and stack is empty
		if(temp) {
			push(&s_temp,temp);
			temp = temp->left;
		} else {
			if(!isEmpty(s_temp)) {
				temp = pop(&s_temp);
				printf("%d ",temp->data);
				temp = temp->right;
			} else flag = 0;
		}
	}
}

void postOrder_iterative(Node* root) {
	if (root == NULL) return;
	stack *s_temp = NULL;
	do {
		while (root) {
			if (root->right)
				push(&s_temp, root->right);
			push(&s_temp, root);
			root = root->left;
		}

		root = pop(&s_temp);

		if (root->right && peek(s_temp) == root->right) {
			pop(&s_temp);
			push(&s_temp, root);
			root = root->right;
		} else {
			printf("%d ", root->data);
			root = NULL;
		}
	} while (!isEmpty(s_temp));
}

int isEmpty(stack* top) { // check if stack is empty
	if(top==NULL) return 1;
	else return 0;
}
void push(stack** top, Node* n) { //push node in stack
	stack* new_n = (stack*)malloc(sizeof(stack));
	new_n->data = n;
	new_n->next = (*top);
	(*top) = new_n;
}
Node* pop(stack** top_n) { // pop the node from stack
	Node* item;
	stack* top;
	top = *top_n;
	item = top->data;
	*top_n = top->next;
	free(top);
	return item;
}
Node *peek(stack *s) { // returns the topmost element
	if (isEmpty(s)) return NULL;
	return s->data;
}
