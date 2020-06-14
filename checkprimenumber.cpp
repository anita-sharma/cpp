#include<iostream>
using namespace std;

void prime(int n)
{
	int flag=0;

	for(int i=2;i<n;i++)
	{
		if(n%i==0)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
		cout<<"not prime no."<<endl;
	else
		cout<<"prime no.";
}
int main()
{
	int n;
	cin>>n;
	prime(n);
	return(0);
}

