#include<bits/stdc++.h>
using namespace std;

void bal(string s)
{
	stack<char> st;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='(' || s[i]=='[' || s[i]=='{')
		{
			st.push(s[i]);
		}
		else
		{
			if(s[i]==')' && st.top()=='(')
			{
				st.pop();
			}
			else if(s[i]=='}' && st.top()=='{' || s[i]==']' && st.top()=='[' )
			{
				st.pop();
			}
			else
				cout<<"imbalance"<<endl;

		}
	}
	if(st.empty())
	{
		cout<<"balanced"<<endl;
	}
}


int main()
{
	cout<<"enter string"<<endl;
	string s;
	cin>>s;
	bal(s);
	return(0);
}