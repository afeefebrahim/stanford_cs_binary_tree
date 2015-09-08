/*
Compute the number of nodes in a tree.
*/
struct node {
	int data;
	struct node* left;
	struct node* right;
};
int count = 0;
#include<stdio.h>
#include<stdlib.h>
struct node* insert(struct node*,int);
struct node* newnode(int data);
int size(struct node* node);
main()
{
	int c;
	struct node* head = NULL;
	head = insert(head,3);
	head = insert(head,3);
	head = insert(head,2);
	head = insert(head,1);
	c = size(head);
	printf("%d \n", c);
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
	struct node* node = malloc(sizeof(struct node));
	node->data = n;
	node->left = NULL;
	node->right = NULL;
	return node;
}
int size (struct node* node)
{
	if(node == NULL)
		return count;
	else{
		size(node->left);
		count++;
		size(node->right);
	}
}
