#include<iostream>
using namespace std;
#include<cstring>
#include<queue>
struct node
{
	int data;
	node *left;
	node *right;
	node (int data)
	{
		this->data=data;
		node *left=NULL;
		node* right=NULL;
	}
	
};
node* create_tree(node *root)
{
	
	char create[10];
	cin>>create;
	if(strlen(create)==4)
	{
		int data;
		node *temp;
		cin>>data;
		temp=new node(data);
		root->left=temp;
		temp->left=create_tree(temp);
		
	}//10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false
	else
	{
		root->left=NULL;
	}
	cin>>create;
		if(strlen(create)==4)
	{
		int data;
		node *temp1;
		cin>>data;
		temp1=new node(data);
		root->right=create_tree(temp1);
		
	}
	else
	{
			root->right=NULL;
	}
	return root;
	
}
void levelorder(node *root)
{
	
	if(root==NULL)
	{
		cout<<"null";
		return;
	}
	//cout<<root->data;
	queue<node * >q;
	q.push(root);
	while(!q.empty())
	{
		node *p=q.front();
		cout<<p->data<<" ";
		q.pop();
		if(p->left==NULL&&p->right==NULL)
		{
			continue;
		}
		else if(p->left==NULL)
		{
			q.push(p->right);
		}
		else if(p->right==NULL)
		{
			q.push(p->left);
		}
		else
		{
		
		q.push(p->left);
		q.push(p->right);	
		}
	}
	
}
int main()
{
	node * root=NULL;
	int n;
	cin>>n;
	root=new node(n);
	root=create_tree(root);
	levelorder(root);
	
}
