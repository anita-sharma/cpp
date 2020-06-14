#include<iostream>
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

struct node* insert(struct node* head,int data)
{
	struct node* temp=newnode(data);
	temp->next=head;
	head=temp;

	return(head);


} 

struct node* insatend(struct node* head ,int data)
{
	struct node* temp=newnode(data);
	struct node* i=head;
	while(i->next!=NULL)
	{
		i=i->next;
	}
	i->next=temp;
	return(head);

}

struct node* insatmid(struct node* head,int pos,int data)
{
	if(pos==1)
	{
		return(insert(head,data));
	}
	pos--;
	struct node* temp=newnode(data);
	struct node* i=head;
	while(pos>1)
	{
		i=i->next;
		pos--;
		if(i==NULL)
		{
		cout<<"invalid position"<<endl;
		exit(0);
		}
	}
	
	temp->next=i->next;
	i->next=temp;
	return(head);

}

struct node* deletebegin(struct node* head)
{
	struct node* temp=head;
	head=head->next;
	free(temp);
	return(head);

}
struct node* deleteatend(struct node* head)
{
	
	if(head==NULL)
	{
		return(head);
	}
	if(head->next==NULL)
	{
		return(deletebegin(head));
	}
	struct node* i=head;
	while(i->next->next!=NULL)
	{
		i=i->next;

	}
	struct node* temp=i->next;
	i->next=NULL;
	free(temp);

	return(head);


}


struct node* deleteatmid(struct node* head,int pos)
{
	if(pos==1)
	{
		return(deletebegin(head));
	}
	pos--;
	struct node* i=head;
	while(pos>1)
	{
		i=i->next;
		pos--;
		if(i==NULL)
		{
		cout<<"invalid position"<<endl;
		exit(0);
		}
	}
	struct node* temp=i->next;
	if(i->next==NULL)
	{
		cout<<"invalid position"<<endl;
		exit(0);
	}
	i->next=i->next->next;
	free(temp);
	return(head);

}

int lengthoflist(struct node* head)
{
	int flag=0;
	struct node* i=head;
	while(i!=NULL)
	{
		i=i->next;
		flag++;
	}
	return(flag);
}

//lengthy approach

// int middleone(struct node* head)
// {
// 	int l=lengthoflist(head),pos=1;
// 	if(l==0)
// 	{
// 		return(0);
// 	}
// 	struct node* i=head;
// 	while(pos<=l/2)
// 	{
// 		pos++;
// 		i=i->next;
// 	}
// 	return(i->data);
// }

//fast approach(slow-fast approach)

int middleone(struct node* head)
{
	struct node* fast=head;
	struct node* slow=head;

	while(fast!=NULL && fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	return(slow->data);

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



int main()
{
	struct node *head;
	
	head=newnode(5);
	head->next=newnode(7);
	head->next->next=newnode(4);
	
	head=insert(head,15);
	head=insatend(head,8);
	head=insatmid(head,3,2);
	head=insatend(head,6);
	head=insatend(head,8);
	head=insatend(head,9);
	head=insatend(head,4);
	head=insatend(head,6);
	// head=deletebegin(head);
	// head=deleteatend(head);
	// head=deleteatmid(head,4);
	// head=deleteatmid(head,4);
	cout<<lengthoflist(head)<<endl;
	cout<<middleone(head)<<endl;
	print(head);

	return(0);
}