#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	struct node *left;
	int data;
	struct node *right;
}Node;

Node* getNode(int value);
void in_trav_rec(Node*p); // left root right
void pre_trav_rec(Node*p); // root left right
void post_trav_rec(Node *p); // left right root


int main(){
  Node *root;
  int cache;
  
  root = getNode(10);
  root->left = getNode(5);
  root->right = getNode(7);
  root->left->right = getNode(2);
  root->right->left = getNode(8);
  root->right->right = getNode(9);
  root->left->left = getNode(89);
  
  printf("In order recursive: ");
  in_trav_rec(root);
  
  printf("\n\nPre order recursive: ");
  pre_trav_rec(root);
  
  printf("\n\nPost order recursive: ");
  post_trav_rec(root);
  
}

Node* getNode(int value){
  Node *p = (Node*)(malloc(sizeof(Node)));
  p->data = value;
  p->left=NULL;
  p->right=NULL;
  return p;
}

void in_trav_rec(Node*p){
	if(p!=NULL){
		in_trav_rec(p->left);
		printf("%d, ", p->data);
		in_trav_rec(p->right);
	}
}

void pre_trav_rec(Node*p){
	if(p!=NULL){
		printf("%d, ", p->data);
		pre_trav_rec(p->left);
		pre_trav_rec(p->right);
	}
}

void post_trav_rec(Node*p){
	if(p!=NULL){
		post_trav_rec(p->left);
		post_trav_rec(p->right);
		printf("%d, ", p->data);
	}
}
