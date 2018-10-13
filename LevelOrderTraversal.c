#include<stdio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *left,*right;
};
typedef struct node Node;
Node* q[20];
int r=0,f=0;
void enqueue(Node* root)
{
	q[r]=root;
	r++;
}
Node* dequeue()
{
	Node* temp=q[f];
	f++;
	return temp;
}
void printLevel(Node* root)
{
	Node* key=root;
	while(key!=NULL)
	{
		printf("\t%d",key->data);
		if(key->left!=NULL)
			enqueue(key->left);
		if(key->right!=NULL)
			enqueue(key->right);
		key=dequeue();
	}
}
Node* newnode(int data)
{
	Node* node=(Node*)malloc(sizeof(Node));
	node->data=data;
	node->left=node->right=NULL;
}
void main()
{
	Node* root=newnode(10);
	root->left=newnode(5);
	root->right=newnode(13);
	printf("\nLevel Order:");
	printLevel(root);	
}
