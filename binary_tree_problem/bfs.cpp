#include<iostream>
#include<queue>
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

//func to print tree data in level order

void bfs(struct node* root)
{
	queue<struct node*> q1;
	if(root==NULL)
		return;
	q1.push(root);
	while(!q1.empty())
	{
		struct node* temp=q1.front();
		q1.pop();
		cout<<temp->data<<" ";
		if(temp->left!=NULL)
			q1.push(temp->left);
		if(temp->right!=NULL)
		{
			q1.push(temp->right);
		}

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
	bfs(root);
	cout<<endl;


	return(0);
}

