struct node{
	int data;
	struct node* left;
	struct node* right;
};
#include<stdio.h>
#include<stdlib.h>
struct node* insert(struct node*,int);
struct node* newnode(int);
void mirror(struct node*);
void printtree(struct node*);
main()
{
	int s = 0;
	struct node* head = NULL;
//	head =insert(head,3);
//	head = insert(head,4);
	head = insert(head,2);
	head = insert(head,6);
	head = insert(head,1);
	head = insert(head,9);
	printtree(head);
	printf("\n");
	mirror(head);
	printtree(head);
	printf("\n");
//	s = haspathsum(head,s);
//	printf("%d\n",s); 

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
void mirror(struct node*p)
{
	struct node* temp;
	if(p == NULL)
		return;
	else{
		mirror(p->left);
/*		temp = p->left;
		p->left = p->right;
		p->right = temp;*/
		mirror(p->left);
	}

}
void printtree(struct node* p)
{

	if(p != NULL){
		printf("%d \t",p->data);
		printtree(p->left);
		
		printtree(p->right);
	}
	
		
}
