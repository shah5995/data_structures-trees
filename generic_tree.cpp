#include<iostream>
using namespace std;
#include<queue>
struct node
{
	int data;
	int child;
	node ** children;
	node(int data,int child)
	{
		this->data=data;
		this->child=child;
		children=new node *[child];
		for(int i=0;i<child;i++)
		{
			children[i]=NULL;
		}
	}
};
node* create_generic_tree(node *root)
{
	int data,child;
	cin>>data>>child;
	if(child==0)
	{
		root=new node(data,child);
		root->children=NULL;
		//cout<<endl<<root->data<<"  --";
		return root;
	}
	root=new node(data,child);
//	cout<<root->data<<"  --";
	int i=0;
	while(i<child)
	{
		root->children[i]=create_generic_tree(root->children[i]);
		i++;
		
	}
	return root;
	
}
int level_order(node * root,int k)
{
	queue<node *>q;
	int sum=0;
	q.push(root);
	while(!q.empty())
	{
		int size=q.size();
		
		while(size>0)
		{
			
			node *r=q.front();
			cout<<r->data<<" ";
			if(k==0)
			{
				sum=sum+r->data;
			}
			q.pop();
			int c=r->child;
			//cout<<endl<<c;
			int i=0;
			while(i<c)
			{
				q.push(r->children[i]);
				i++;
			}
			size--;
			
		}
		cout<<endl;
		k--;
	}
	return sum;
}
int main()
{
	node *root=NULL;
	root=create_generic_tree(root);
	int k;
	cin>>k;
	cout<<level_order(root,k);
	
}
