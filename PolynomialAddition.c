#include<stdio.h>
#include<stdlib.h>

typedef struct Poly {
	int coeff;
	int exp;
	struct Poly *next;
} poly;

poly *A = NULL, *B = NULL, *Result = NULL;

poly *getNode(int c, int e) {
	poly *newnode = (poly*)malloc(sizeof(poly));
	newnode->coeff = c;
	newnode->exp = e;
	newnode->next = NULL;
	return newnode;
}

void insertTerm(poly **exp, int c, int e) {
	if(*exp == NULL) {
		*exp = getNode(c,e);
		return;
	}
	poly *pres = *exp, *prev = *exp;

	while(pres != NULL && ((pres->exp) > e)) {
		prev = pres;
		pres = pres->next;
	}

	if(pres == NULL) { // reached end
		poly *temp = getNode(c,e);
		prev->next = temp;

	} else if( (pres->exp) == e) { // insert in pres
		pres->coeff += c;
	} else { // insert between prev and pres
		poly *temp = getNode(c,e);
		if(prev->next == NULL) { // insertion in head
			*exp = temp;
			temp->next = prev;
		} else {
			prev->next = temp;
			temp->next = pres;
		}
	}
}

void polyAdd(poly **exp1, poly **exp2, poly **res) {
	if(*exp1 == NULL && *exp2 == NULL) {
		printf("\nNo valid expressions!\n");
		return;
	}
	poly *p1 = *exp1, *p2 = *exp2, *r = *res;
	while(p1 != NULL && p2 != NULL) {
		if(p1->exp == p2->exp) {
			poly *temp = getNode(p1->coeff + p2->coeff , p1->exp);
			if(r==NULL) {
				*res=temp;
				r=temp; // insert in head
			} else {
				r->next=temp;
				r=r->next;
			}
			p1=p1->next;
			p2=p2->next;
		} else if(p1->exp > p2->exp) {
			poly *temp = getNode(p1->coeff, p1->exp);
			if(r==NULL) {
				*res=temp;
				r=temp; // insert in head
			} else {
				r->next=temp;
				r=r->next;
			}
			p1=p1->next;
		} else {
			poly *temp = getNode(p2->coeff , p2->exp);
			if(r==NULL) {
				*res=temp;
				r=temp; // insert in head
			} else {
				r->next=temp;
				r=r->next;
			}
			p2=p2->next;
		}
	}
	while(p1!=NULL) {
		poly *temp = getNode(p1->coeff, p1->exp);
		if(r==NULL) {
			*res=temp;
			r=temp; // insert in head
		} else {
			r->next=temp;
			r=r->next;
		}
		p1=p1->next;
	}
	while(p2!=NULL) {
		poly *temp = getNode(p2->coeff , p2->exp);
		if(r==NULL) {
			*res=temp;
			r=temp; // insert in head
		} else {
			r->next=temp;
			r=r->next;
		}
		p2=p2->next;
	}
}

void display(poly *a) {
	printf("\nExp:\t");
	while(a != NULL) {
		printf("%d.x^%d", a->coeff, a->exp);
		a = a->next;
		if(a!=NULL) printf(" + ");
	}
	printf("\n");
}

int main() {
	insertTerm(&A, 5, 2);
	insertTerm(&A, 4, 3);
	insertTerm(&A, 3, 1);
	insertTerm(&A, 2, 0);

	display(A);

	insertTerm(&B, 6, 0);
	insertTerm(&B, 7, 3);
	insertTerm(&B, 8, 1);
	insertTerm(&B, 9, 2);

	display(B);

	polyAdd(&A, &B, &Result);

	display(Result);
}
