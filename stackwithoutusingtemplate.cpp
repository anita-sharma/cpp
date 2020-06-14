#include<iostream>
using namespace std;


int st[30];
int top=-1;

int isempty()
{
	if(top==-1)
	{	
	return(1);
	}
	else
	{
		return(0);
	}	
}

int isfull()
{
	if(top==29)
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

void push(int n)
{
	if(isfull())
	{
		cout<<"stack is full";
	}
	else
	{
		top=top+1;
		st[top]=n;
	}
}

int pop()
{
	if(isempty())
		cout<<"stack is empty";
	else
	return(st[top--]);
}
int m,n;
int main()
{
	while(1)
	{cout<<"enter your choice 1.push\n 2.pop \n 3.print array 4.exit";
	cin>>m;
	switch(m)
	{
		case 1:
		
			cout<<"enter a no.";
			cin>>n;
			push(n);
			break;
		
		case 2:
		
			pop();
			break;
		
		case 3:
		
			for(int i=top;i>=0;i--)
			cout<<st[i]<<endl;
			break;
		
		case 4:
		exit(0);
	}
	

	}
	return(0);
}
