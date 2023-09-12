//  polynomial  addition  and multiplication using linked list 
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int coeff;
	int expo;
	struct node *next;
	
}node;

node *poly1 = NULL;
node *poly2 = NULL;
node *poly  = NULL;
node *ex1 = NULL;
node *ex2	=NULL;
node *multiply  = NULL;


node *insert(node *ptr,node *poly);
node *getnode(int x,int y)
{
	node *ptr;
	ptr=(node*)malloc(sizeof(node));
	ptr->coeff =x;
	ptr->expo =y;
	ptr->next=NULL;
	
	return ptr;
}
void create(node **poly1)
{
	int a,b;
	node *ptr,*p;
	printf("\nEnter the coefficient and exponent of the term  : (enter -99 for any one to stop)  ");
	scanf("%d %d",&a,&b);
	while(a != -99 || b != -99)
	{
		ptr=getnode(a,b);
		if(*poly1==NULL)
		{
			*poly1 = ptr;
			p = ptr;
		}
		else
		{
			p->next=ptr;
			p=p->next;
		}
		printf("Enter the coefficient and exponent of the term  : (enter -99 for any one to stop)  ");
		scanf("%d %d",&a,&b);
	}
}

void display(node *poly1)
{
	node *ptr;
	ptr = poly1;
	if(ptr==NULL)
	printf("list not found");
	
	else
	{
		while(ptr!=NULL)
		{
			printf(" %dx^%d ",ptr->coeff,ptr->expo);
			ptr = ptr->next;
		}
		printf("\n");
	}
}

void polynomial_addition()
{
	node *p,*q,*z,*g,*ptr;
	p=poly1;
	q=poly2;
	
	while(p!=NULL && q!=NULL)
	{
	  if(p->expo == q->expo)
	  {
	  	ptr=getnode(p->coeff+q->coeff,p->expo);
	  	if(poly==NULL)
	  	{
	  		poly=ptr;
	  		g=ptr;
		}
		else
		{
			g->next=ptr;
			g=g->next;
		}
		p=p->next;
		q=q->next;
		}
		else
	  {
	  	if(p->expo > q->expo)
	  	{
	  		ptr=getnode(p->coeff,p->expo);
	  		if(poly==NULL)
	  		{
	  			poly=ptr;
	  			g=ptr;
			}
			else
			{
				g->next=ptr;
				g=g->next;
			}
			p=p->next;
	  	}
		else
		{
			ptr=getnode(q->coeff,q->expo);
			if(poly==NULL)
			{
				poly=ptr;
				g=ptr;
			}
			else
			{
				g->next=ptr;
				g=g->next;
			}
			q=q->next;
	  		
		}
	  }
	}
	

	while(p!=NULL)
	{
		ptr=getnode(p->coeff,p->expo);
		if(poly==NULL)
		{
			poly=ptr;
			g=ptr;
		}
		else
		{
			g->next=ptr;
			g=g->next;
		}
		p=p->next;
		
	}
	while(q!=NULL)
	{
		ptr=getnode(q->coeff,q->expo);
		if(poly==NULL)
			{
				poly=ptr;
				g=poly;
			}
			else
			{
				g->next=ptr;
				g=g->next;
			}
			q=q->next;
	}
}

void polynomial_multiplication()
{
	node *p,*q,*ptr;
	p=ex1;
	while(p!=NULL)
	{	
		q=ex2;
			while(q!=NULL)
			{
			ptr=getnode((p->coeff * q->coeff),(p->expo + q->expo));
			multiply = insert(ptr,multiply);
			q=q->next;	
			}
		p=p->next;
	}
}

node *insert(node *ptr,node *multiply)
{
	node *prevnode,*list;
	if(multiply==NULL)
	{multiply=ptr;
		return multiply;
	}
	if(ptr->expo > multiply->expo)
	{
		ptr->next=multiply;
		multiply = ptr;

		return multiply;
	}
	else 
	{
		list =prevnode=multiply;
		while(list!=NULL)
		{
			if(ptr->expo == list->expo)
			{
				list->coeff=(list->coeff+ptr->coeff);
					free(ptr);
				return multiply;
			}
			
			if(ptr->expo > list->expo)
			{
				ptr->next=list;
				prevnode->next=ptr;
				return multiply;
			}
			if((list->next)==NULL)
			{
				list->next =ptr;
				return multiply;
			}
			prevnode=list;
			list=list->next;
		}
	}
	return multiply;

}

int main()
{
	int choice;
	while(1)
	{
		printf("\n1.To  add two polynomial ");
		printf("\n2.To multiply two polynomial ");
		printf("\n3.To exit  ");
		printf("\nenter your choice ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				  	printf("\nenter data for 1st polynomial expression  : ");
				  	create(&poly1);
				    printf("Exp 1: ");
					display(poly1);
					printf("\nenter data for 2nd polynomial expression : ");
				  	create(&poly2);
				  	printf("Exp 2: ");
				  	display(poly2);
				  	polynomial_addition();
				  	printf("\nExp 1 + Exp 2: ");
				  	display(poly);
				  	printf("\n");
				  	break;
				  
			case 2:
				printf("\nenter data for 1st polynomial expression  : ");
				  create(&ex1);
				  printf("Exp 1: ");
				  display(ex1);
				  printf("\nenter data for 2nd polynomial expression : ");
				  create(&ex2);
				  printf("Exp 2: ");
				  display(ex2);
				  polynomial_multiplication();

				  printf("\nExp 1 * Exp 2: ");
				  
				  display(multiply);
				  printf("\n");				  
				  break;
			case 3:
					exit(0);
					break;
			default :
				printf("\nInvalid input");
				break;
				
				  
		}
	}
}
