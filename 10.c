struct node{
	int data;
	struct node* left;
	struct node* right;
};
#include<stdio.h>
#include<stdlib.h>
struct node* insert(struct node* ,int);
struct node* newnode(int data);
void printtree(struct node*);
void doubletree(struct node*);
main()
{
	struct node* head = NULL;
	head = insert(head,6);
	head = insert(head,4);
	head = insert(head,1);
//rintf("%d \n",head->data);
	 printtree(head);
	printf("\n");
	doubletree(head);
	printtree(head);
	printf("\n");
}
struct node* insert(struct node* current,int n)
{
	if(current == NULL)
		return(newnode(n));
	if(current->data >= n)
		current->left =insert(current->left,n);
	else
		current->right =insert(current->right,n);
	return current;
}
struct node* newnode(int n)
{
	struct node* node = malloc(sizeof(struct node));
	node->data = n;
	node->left = NULL;
	node->right = NULL;
	return node;
}
void printtree(struct node* p)
{
	
	if(p != NULL){
		printtree(p->left);
		printf("%d \t",p->data);
		printtree(p->right);
	}
	
		
}	
void doubletree(struct node* p)
{
	struct node* temp = p;
	if(p != NULL){
		doubletree(p->left);
		p = insert(p,p->data);
		doubletree(p->right);
	}
	
}


