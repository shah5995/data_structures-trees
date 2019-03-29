#include<iostream>
using namespace std;
#include<set>
int main()
{
	set<int > m;
	int data;
	cin>>data;
	m.insert(data);
	while(data!=-1)
	{
			cin>>data;
	set<int>::iterator it=m.find(-data);
		if(it==m.end())
		{
			m.insert(data);
		}
		else
		{
			cout<<data<<"  "<<-data<<endl;
			m.erase(it);
		}
	
	}
}
