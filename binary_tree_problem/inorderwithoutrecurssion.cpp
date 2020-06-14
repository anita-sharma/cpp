#include<iostream>
#include<queue>
#include<stack>
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

//func to print tree data in  inorder w/o using recurssion

void inorder(struct node* root)
{
	if(root==NULL)
		return;
	stack<struct node*> st;
	struct node* temp=root;
	while(temp!=NULL || !st.empty())
	{
		while(temp!=NULL)
		{
			st.push(temp);
			temp=temp->left;

		}
		temp=st.top();
		st.pop();
		cout<<temp->data<<" ";
		temp=temp->right;
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
	inorder(root);

	cout<<endl;


	return(0);
}



