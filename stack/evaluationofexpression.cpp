#include<bits/stdc++.h>
using namespace std;


int prec(char ch)
{
	if(ch=='+' ||ch=='-')
		return(1);
	if(ch=='*' ||ch=='/')
		return(2);
	if(ch=='^')
		return(3);
	return(0);
}

int calc(int n1,int n2,char op)
{
	if(op=='+')
	{
		return(n1+n2);
	}
	if(op=='-')
	{
		return(n1-n2);
	}
	if(op=='*')
	{
		return(n1*n2);
	}
	return(n1/n2);
}

int myeval(string s)
{
	stack<int> st1;
	stack<char> st2;

	for(int i=0;i<s.length();i++)
	{
		if(s[i]>47 && s[i]<58)
		{
			int n=0;
			while(s[i]>47 && s[i]<58)
			{
				n=n*10+(s[i]-'0');
				i++;
			}
			i--;
			st1.push(n);
	
		}
		else if(s[i]=='(')
		{
			st2.push(s[i]);
		

		}
		else if(s[i]==')')
		{
			while(st2.top()!='(')
			{
					int n2=st1.top();
					st1.pop();
					int n1=st1.top();
					st1.pop();
					char op=st2.top();
					st2.pop();
					int n=calc(n1,n2,op);
					st1.push(n);
					
			}
			st2.pop();
		}
		else
		{
			if(st2.empty())
			{
				st2.push(s[i]);
			}
			else
			{
				while(!st2.empty() && prec(s[i])<=prec(st2.top()))
				{
					int n2=st1.top();
					st1.pop();
					int n1=st1.top();
					st1.pop();
					char op=st2.top();
					st2.pop();
					int n=calc(n1,n2,op);
					st1.push(n);

				}
				st2.push(s[i]);
			}
		}
	}
	while(!st2.empty())
	{
		int n2=st1.top();
		st1.pop();
		int n1=st1.top();
		st1.pop();
		char op=st2.top();
		st2.pop();
		int n=calc(n1,n2,op);
		st1.push(n);
	}
	return(st1.top());

}





int main()
{
	cout<<"enter string";
	string s;
	cin>>s;
	cout<<myeval(s)<<endl;
	return(0);
}