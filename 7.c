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
int haspathsum(struct node*,int);
main()
{
	int s = 0;
	struct node* head = NULL;
	head =insert(head,3);
	head = insert(head,4);
	head = insert(head,2);
	head = insert(head,6);
	head = insert(head,1);
	head = insert(head,9);
	//printtree(head);
	s = haspathsum(head,s);
	printf("%d\n",s); 

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
int haspathsum(struct node* p,int sum)
{
	if(p == NULL)
		return 0;
	sum = sum+p->data;
	if(p->left == NULL && p->right == NULL)
		printf("%d \n", sum);
	else{
		haspathsum(p->left,sum);
		haspathsum(p->right,sum);
	}
}

	
