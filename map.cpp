#include<bits/stdc++.h>
using namespace std;

int main()
{
	map<int,string> mapname;
	int n;
	string s;
	for(int i=0;i<5;i++)
	{
		cout<<"enter id and name"<<endl;
		cin>>n>>s;
		mapname[n] = s;	
	}
	for(auto i=mapname.begin();i!=mapname.end();i++)
	{
		cout<<i->first<<" : "<<i->second<<endl;
	}	
     return(0);
}
