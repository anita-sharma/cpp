#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node* next;
};

struct node* newnode(int data)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=NULL;
	return(temp);
}

void print(struct node* head){
	struct node* i=head;
	cout<<"linked list: ";
	while(i!=NULL)
	{
		cout<<i->data<<" ";
		i=i->next;
	}
	cout<<endl;
}

void isloop(struct node* head)
{
	unordered_set<struct node*> s;
	while(head!=NULL)
	{
		if(s.find(head)!=s.end())
		{
			cout<<"loop exist"<<endl;
			return;
		}
		s.insert(head);
		head=head->next;

	}

	cout<<"no loop"<<endl;
}

int main(){

	struct node *head;
	
	head=newnode(5);
	head->next=newnode(7);
	head->next->next=newnode(9);
	head->next->next->next=head;

	isloop(head);
	return(0);
}