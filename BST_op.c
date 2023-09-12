/*Write a C Program to create a Binary Search Tree and include following operations in tree:
(a) Insertion (Recursive and Iterative Implementation)  done
(b) Deletion by copying
(c) Deletion by Merging
(d) Search a no. in BST  done
(e) Display its pre-order, postorder and in-order traversals Recursively
(f) Display its level-by-level traversals
(g) Display height of tree*/
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	struct node *left;
	int data;
	struct node *right;
}node;
void in_trav_rec(node *root);


node *get_Node(int n)
{
	node *ptr;
	ptr = (node *)malloc(sizeof(node));
	ptr->left = NULL;
	ptr->data = n;
	ptr->right = NULL;
	return ptr;
}

int insert_BST(node **root,int n)
{
	if((*root)==NULL)
	{
		*root = get_Node(n);
		return 1;
	}
	else if(n >(*root)->data)
	return insert_BST(&((*root)->right),n);

	else if(n <(*root)->data)
	return insert_BST(&((*root)->left),n);
	
	else
	return 0;
}
void in_trav_rec(node *root)
{
	if(root!=NULL)
	{
		in_trav_rec(root->left);
		printf("%d ",root->data);
		in_trav_rec(root->right);		
	}	
}

int insert_BST_iter(node **root,int n)
{
	node *num =get_Node(n);
	
 	node *temp=NULL,*p=NULL;
 
 	if(*root==NULL)
 	{
 		*root = num;
 		return 1;
	 }
	 temp =*root;
	 while(temp!=NULL)
	 {
	 	p=temp;
	 	
	 	if(n> temp->data)
	 	temp=temp->right;
		 
		else
		temp=temp->left;
		 
	 }	
	 
	 if(n > p->data)
	 p->right = num;
	 
	 else if(n < p->data)
	 p->left = num;
	 
	 else
	 return 0;
}

int bst_search(node *root,int target)
{
	if(root == NULL)
	return 0;
	
	if(root->data == target)
	{
		return 1;
    }

		while(root!=NULL)
		{
			if(root->data < target)
			{
				return bst_search(root->right,target);
			}
		
			else
			{
				 //if(root->data < target)
				return bst_search(root->left,target);
			}
		}
}
void pre_trav_rec(node *root)
{
	if(root!=NULL)
	{
		printf("%d ",root->data);
		pre_trav_rec(root->left);
		pre_trav_rec(root->right);	
	}	
}

void post_trav_rec(node *root)
{
	if(root!=NULL)
	{
		post_trav_rec(root->left);
		post_trav_rec(root->right);
		printf("%d ",root->data);
		}	
}
int tree_level(node *root)
{
	if(root==NULL)
	return -1;
	
	else
	return tree_level(root->left)+1;
}
int level_order_traversal(node *root,int level)
{
    if(root==NULL)
    return 0;

    else if(level==0)
     printf(" %d ",root->data);

     else if(level>0)
     {
        level_order_traversal(root->left,level-1);
        level_order_traversal(root->right,level-1);
     }
     else
     printf("\n\t No nodes are present");
}
node *in_order_predecessor(node *root)
{
    root=root->left;
    while(root->right != NULL)
    {
        root=root->right;
    }
    return root;
}
node *delete_by_copy(node *root,int elem)
{
    node *ipre;
    if(root == NULL)
    {
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){
        free(root);
        return NULL;
    }
   

    if(elem < root->data)
    root->left = delete_by_copy(root->left,elem);

    else if(elem >root->data)
    root->right = delete_by_copy(root->right,elem);

    else{
        ipre = in_order_predecessor(root);
        root->data =ipre->data;
        root->left = delete_by_copy(root->left,ipre->data);
    }
    return root;

}
int main()
{
    node *root =NULL ;
    int arr1[20],arr2[20],i,n1,n2,elem,option,counter,ans;
   int choice;
   while(1)
   {
    printf("\n\t*BINARY SEARCH TREE OPERATIONS*");
    printf("\n\t**********MENU*********");
    printf("\n\t 1.To Create the tree by insertion :");
    printf("\n\t 2.To Deletion a node by copying :");
    printf("\n\t 3.To Search  a node  ");
    printf("\n\t 4.To Display inorder,preorder and postorder traversals");
    printf("\n\t 5.To Display  level by level traversals : ");
    printf("\n\t 6.To display height of the tree : ");
    printf("\n\t 7.To exit ");
    printf("\n\t Enter your choice...............");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
                printf("\n\t Enter 1 for insertion by recusrsion  : ");
                printf("\n\t Enter 2 for insertion by iteration  : ");
                scanf("%d",&option);
                switch(option)
                {
                    case 1:
                        printf("\n\t enter the element : ");
                        scanf("%d",&elem);

                        insert_BST(&root,elem);
                    break;
                    case 2:
                    printf("\n\t enter the element : ");
                        scanf("%d",&elem);

                        insert_BST_iter(&root,elem);
                    break;
                    default:printf("\n\t invalid input!");
                            break;

                }
                break;
            case 2:
                    printf("\n\t enter the element to be deleted ");
                    scanf("%d",&elem);
                    printf("\n\t");
                    in_trav_rec(root);
                    printf("\n\t");
                    printf("\n\t after deletion :.......");
                    delete_by_copy(root,elem);
                    printf("\n\t");
                    in_trav_rec(root);
                    break;
            case 3:
                    printf("\n\n\t enter the element  which is to be searches in th binary treee :  ");
                    scanf("%d",&elem);
        
                    ans = bst_search(root,elem); 
        
                    if(ans)
                    printf("\n\n\t the element  is present in the binary tree");
                    else
                    printf("\nelement is not present in the binary tree ");	
                    printf("\n\n\t the element  is present  \n\n\t and number of comparison required is : %d ",ans);
                break;
            case 4:
                    printf("\n\t inorder traversal  :   \n\n\t");

                    in_trav_rec(root);
                    printf("\n\t preorder traversal  :   \n\n\t");
                    pre_trav_rec(root);
                    printf("\n\t postorder traversal  :   \n\n\t");
                    post_trav_rec(root);
                    break;
            case 5:
                        for(i=0;i<=(tree_level(root));i++)
                        {
                           printf("\n %d ",i); level_order_traversal(root,i);
                        }
                        break;
            case 6: 
                    printf("\n\t the height of the tree is :   ");
                    ans=tree_level(root);
                    printf("\n\t %d ",ans);
                    break;
            case 7:
                exit(0);
                break;
                default : printf("\n\t wrong choice!!!!!!!!!!");
                        break;

    }
   }
    return 0;
}