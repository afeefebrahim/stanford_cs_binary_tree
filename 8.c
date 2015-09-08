/*
Given a binary tree, print out all of its root-to-leaf
paths, one per line. Uses a recursive helper to do the work.
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
void printpaths(struct node* node);
void printpathsrecur(struct node* node, int path[], int pathLen);
void printarray(int ints[], int len);
main()
{
	struct node* head = NULL;
	head = insert(head,10);
	head = insert(head,5);
	head = insert(head,7);
	head = insert(head,3);
	head = insert(head,2);
	head = insert(head,5);
	head = insert(head,4);
	head = insert(head,1);
	printpaths(head);
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
void printpaths(struct node* p)
{
	int path[1000];
	printpathsrecur(p,path,0);
}
void printpathsrecur(struct node* node,int path[],int pathlen)
{
	if(node == NULL)
		return;
	path[pathlen] = node->data;
	pathlen++;
	if(node->left == NULL && node->right == NULL)
		printarray(path,pathlen);
	else{
		printpathsrecur(node->left,path,pathlen);
		printpathsrecur(node->right,path,pathlen);
	}
}
void printarray(int path[],int lim )
{
	int i;
	for(i = 0; i< lim; i++)
		printf("%d\t",path[i]);
	printf("\n");
}

	
