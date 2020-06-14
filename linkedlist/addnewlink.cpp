#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node* next;
};

void print(struct node* root)
{
	struct node* temp = root;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

struct node* newnode(int data)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	return(temp);
}



int main()
{
	struct node* head;
	head = newnode(5);
	head->next = newnode(2);
	head->next->next = newnode(19);
	print(head);		
	return(0);
}
