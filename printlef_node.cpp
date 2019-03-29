#include<iostream>
using namespace std;
#include<queue>
struct node
{
int data;
node * left;
node* right;
node(int data)
	{
		this->data=data;
		left=right=NULL;
	}
};
node *btree()
{
//	cout<<"enter data &-1 for exit";
	int data;
	cin>>data;
	node * root=NULL;
	if(data!=-1)
	{
		 root=new node(data);
	}
	queue<node *> q;
	q.push(root);
	while(!q.empty())
	{
		node *top=q.front();
		q.pop();
//		cout<<"enter the left data for"<<top->data<<"and -1 for NULL"<<endl;
		cin>>data;
		if(data!=-1)
		{
			node *left=new node(data);
			top->left=left;
			q.push(left);
		}
//		cout<<"enter the right data for"<<top->data<<"and -1 for NULL"<<endl;
		cin>>data;
		if(data!=-1)
		{
			node *right=new node(data);
			top->right=right;
			q.push(right);
		}
	}
	return root;
	
}
void print_leaf(node *root)
{
	if(root->left==NULL&&root->right==NULL)
	{
		cout<<root->data<<" ";
		return;
		
	}
	print_leaf(root->left);
	print_leaf(root->right);
	
}
int main()
{
	node * root=NULL;
	root=btree();
	print_leaf(root);
}
