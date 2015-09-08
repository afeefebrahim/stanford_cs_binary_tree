/*
Given a binary tree, print its
nodes according to the "bottom-up"
postorder traversal.
*/
struct node{
	int data;
	struct node* left;
	struct node* right;
};
#include<stdio.h>
#include<stdlib.h>
struct node* insert(struct node*,int);
struct node* newnode(int);
void printtree(struct node*);
void printpostorder(struct node*);
main()
{
	struct node* head = NULL;
	head =insert(head,3);
	head = insert(head,4);
	head = insert(head,2);
	head = insert(head,6);
	head = insert(head,1);
	printpostorder(head);
	printf("\n"); 

}
struct node* insert(struct node* p,int n)
{
	if(p == NULL)
		return newnode(n);
	if(p->data >= n)
		p->left = insert(p->left,n);
	else
		p->right = insert(p->right,n);
	return p;
}
struct node* newnode(int n)
{
	struct node* newnode = malloc(sizeof(struct node));
	newnode->data = n;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}
void printtree(struct node* p)
{
	if(p != NULL){
		printtree(p->left);
		printf("%d \t",p->data);
		printtree(p->right);
	}
	
}
void printpostorder(struct node* current)
{
	printtree(current->left);
	printf("%d \t", current->data);
	printtree(current->right);
}
