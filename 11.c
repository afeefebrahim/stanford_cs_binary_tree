struct node{
	int data;
	struct node* left;
	struct node* right;
};
#define TRUE 1
#define FALSE 0
#include<stdio.h>
#include<stdlib.h>
struct node* insert(struct node* ,int);
struct node* newnode(int data);
void printtree(struct node*);
int sametree(struct node*,struct node*);
main()
{
	int n ;
	struct node* head = NULL;
	struct node* tail = NULL;
	tail = insert(tail,6);
	tail = insert(tail,4);
	tail = insert(tail,3);
	head = insert(head,6);
	head = insert(head,4);
	head = insert(head,3);
//rintf("%d \n",head->data);
	 //printtree(head);
	n = sametree(tail,head);
	printf("%d \n", n);
	
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
int sametree(struct node* a,struct node* b)
{
	int er;	
	if(a == NULL && b==NULL)
		return TRUE;
	else if(a != NULL && b != NULL)
		return(a->data == b->data &&	sametree(a->left,b->left) &&  sametree(a->right,b->right));
		

/*	if(a->data != b->data){
		printf("error detected");
		er = FALSE;
		return er;
	}*/
}

