/*
Given a binary search tree, print out
its data elements in increasing
sorted order.
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
main()
{
	struct node* head = NULL;
	head =insert(head,3);
	head = insert(head,4);
	head = insert(head,2);
	head = insert(head,6);
	head = insert(head,1);
	printtree(head);
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

