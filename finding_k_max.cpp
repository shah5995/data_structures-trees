#include<iostream>
using namespace std;
#include<queue>
int main()
{
	int k,data;
	cin>>k;
	priority_queue<int,vector<int>,greater<int> >q;
	int i=0;
	cin>>data;
	while(data!=-1)
	{
		if(i<k)
		{
			q.push(data);
			
		}
		else
		{
			q.pop();
			q.push(data);
			
		}
		queue<int> q2;
		cout<<"current k- max";
			while(!q.empty())
	{
		q2.push(q.top());
		cout<<q.top()<<" ";
		q.pop();
	}
	cout<<endl;while(!q2.empty())
	{
		q.push(q2.front());
		q2.pop();
	}
		
		i++;
		cin>>data;
	}

	
}
