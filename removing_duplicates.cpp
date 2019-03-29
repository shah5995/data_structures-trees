#include<iostream>
using namespace std;
#include<set>
int main()
{
	set<int >s;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int r;
		cin>>r;
		
		set<int>::iterator it=s.find(r);
		if(it==s.end())
		{
			s.insert(r);
		}
		
	}
	set<int >::iterator it=s.begin();
	while(it!=s.end())
	{
		cout<<*it<<" ";
		it++;
	}
}
