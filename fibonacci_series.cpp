#include<iostream>
using namespace std;

void fib(int n)
{
	if(n<1)
	{
		cout<<"invalid no. of term";
		return;
	}
	if(n==1)
	{
		cout<<"0";
		return;
	}
	if(n==2)
	{
		cout<<"0"<<" "<<"1"<<" ";
		return;
	}
	else
	{
		int a=0,b=1,c;
		cout<<"0"<<" "<<"1"<<" ";
		for(int i=3;i<=n;i++)
		{
			c=a+b;
			a=b;
			b=c;
			cout<<c<<" ";
		}
		cout<<endl;
	}
}

int main(){
	cout<<"enter value of n";
	int n;
	cin>>n;
	fib(n);
	return(0);
}