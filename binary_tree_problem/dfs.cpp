#include<iostream>
using namespace std;

struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct node* newnode(int data)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return(temp);
}

void inorder(struct node* root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}
void preorder(struct node* root)
{
	if(root!=NULL)
	{
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}

}
void postorder(struct node* root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		
		postorder(root->right);
		cout<<root->data<<" ";
	}

}

int main(){

	struct node* root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(5);
	root->right->left=newnode(6);
	root->right->right=newnode(7);
	root->right->left->right=newnode(13);
	root->right->right->left=newnode(14);

	//inorder(root);
	//inorder(root);
	preorder(root);


	return(0);
}

	