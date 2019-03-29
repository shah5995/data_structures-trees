#include<iostream>
using namespace std;
#include<set>
struct node
{
	int data;
	node *next;
	node(int data)
	{
		this->data=data;
		next=NULL;
	}
};
node * create_ll()
{
	int data;
	cin>>data;
	node *root=NULL;
	root=new node(data);
	node *it=root;
	cin>>data;
	while(data!=-1)
	{
		node *temp2=new node(data);
		it->next=temp2;
		it=it->next;
		cin>>data;
		
	}
		return root;
}
void print_ll(node *root)
{
	while(root!=NULL)
	{
		cout<<root->data<<"-->";
		root=root->next;
	}
	cout<<"END"<<endl;
	return;
}
int main()
{
	node * root1;
	node *root2;
	root1=create_ll();
	print_ll(root1);
	
	root2=create_ll();
		print_ll(root2);
		set<node *> union_,intersection;
		node *temp1=root1;
		while(temp1)
		{
			set<node *>::iterator it=union_.find(temp1);
			if(it==union_.end())
			{
				union_.insert(temp1);
			
			}
			
			
			temp1=temp1->next;
			
		}
		temp1=root2;
		while(temp1)
		{
			set<node *>::iterator it=union_.find(temp1);
			if(it==union_.end())
			{
				union_.insert(temp1);
			
			}
			else
			{
				intersection.insert(temp1);
			}
			temp1=temp1->next;
			
			
		}
		cout<<endl;
		set<node *>::iterator it=union_.begin();
		while(it!=union_.end())
		{
			node *temp=*it;
			cout<<temp->data<<" ";
			it++;
		}
			cout<<endl;
		set<node *>::iterator iit=intersection.begin();
		while(iit!=intersection.end())
		{
			node *temp=*iit;
			cout<<temp->data<<" ";
			iit++;
		}
	
	
}
