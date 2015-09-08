/*
Given a non-empty binary search tree,
return the minimum data value found in that tree.
Note that the entire tree does not need to be searched.
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
int min_value(struct node*);
main()
{
	int n = 0;
	struct node* head = NULL;
	head = insert(head,4);
	head = insert(head,5);
	head = insert(head,3);
	head = insert(head,6);
	n = min_value(head);
	printf("%d \n",n);
}
struct node* insert(struct node* node, int n)
{
	if(node == NULL)
		return newnode(n);
	if(node->data >= n)
		node->left = insert(node->left,n);
	else
		node->right = insert(node->right,n);
	return node;
}
struct node* newnode(int n)
{
	struct node* newnode = malloc(sizeof(struct node));
	newnode->data = n;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}
int min_value(struct node* p)
{
	int i;
	while(p->left != NULL){
		p = p->left;
		i = p->data;
	}
	return i;
}
	
