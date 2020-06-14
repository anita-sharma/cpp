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



string postfix(string s)
{
	stack<char> st;
	int n=s.length();
	string ans="";
	for(int i=0;i<n;i++)
	{
		if((s[i]>96 && s[i]<123) || (s[i]>64 && s[i]<91 ))
		{
			ans =ans+s[i];
			
		}
		else if(s[i]=='(')
		{
			st.push(s[i]);
		

		}
		else if(s[i]==')')
		{
			while(st.top()!='(')
			{
				ans =ans+st.top();
				st.pop();

			}
			st.pop();
		}
		else
		{
			if(st.empty())
			{
				st.push(s[i]);
			}
			else
			{
				while(!st.empty() && prec(s[i])<=prec(st.top()))
				{
					ans=ans+st.top();
					st.pop();
				}
				st.push(s[i]);
			}
		}

	}
	while(!st.empty())
	{
		ans =ans+st.top();
		st.pop();
	}
	return(ans);

}

string prefix(string s){
	string rev="";
	for(int i=s.length()-1;i>=0;i--)
	{
		rev=rev+s[i];
	}
	string ans=postfix(rev);
	reverse(ans.begin(),ans.end());
	return(ans);
}

int main()
{
	cout<<"enter infix string"<<endl;
	string s;
	cin>>s;
	cout<<postfix(s)<<endl;
	cout<<prefix(s)<<endl;
	return(0);
}
