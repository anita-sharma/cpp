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

//func to insert nodes in tree in level order

struct node* insert(struct node* root,int data)
{
	struct node* temp =newnode(data);
	if(root==NULL)
		return(temp);
	queue<struct node*> q2;
	q2.push(root);
	while(!q2.empty())
	{
		struct node* i=q2.front();
		q2.pop();
		if(i->left==NULL)
		{
			i->left=temp;
			return(root);
		}
		else
		{
			q2.push(i->left);
		}
		if(i->right==NULL)
		{
			i->right=temp;
			return(root);
		}
		else
		{
			q2.push(i->right);
		}
	}

}	

int main(){

	struct node* root;


	//inorder(root);
	root=insert(root,1);
	root=insert(root,2);
	root=insert(root,3);
	root=insert(root,4);
	root=insert(root,5);
	bfs(root);

	cout<<endl;


	return(0);
}



