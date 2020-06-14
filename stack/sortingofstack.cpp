#include<bits/stdc++.h>
using namespace std;

int main()
{
	/* code */
	stack<int> s;
	s.push(23);
	s.push(2);
	s.push(56);
	s.push(11);
	s.push(40);
	int a[5];
	for(int i=0;i<5;i++)
	{
		a[i]=s.top();
		s.pop();
	}
	sort(a,a+5);
	for(int i=0;i<5;i++)
	{
		s.push(a[i]);
	}
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}

	return 0;
}