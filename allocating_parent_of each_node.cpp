#include<iostream>
using namespace std;
#include<cstring>
#include<queue>
struct node
{
	int data;
	node *left;
	node *right;
	node * parent;
	node (int data)
	{
		this->data=data;
		node *left=NULL;
		node* right=NULL;
		parent=NULL;
	}
	
};
node *create_tree(node * root)
{
	char create[10];
	cin>>create;
	if(strlen(create)==5)
	{
		root->left=NULL;
		
		//return root->left;
	}
	else
	{
		int data;
		cin>>data;
		node *temp=new node(data);
		root->left=create_tree(temp);
	
		
	}
	cin>>create;
	if(strlen(create)==5)
	{
		root->right=NULL;
		return root;
	}
	else
	{
		int data;
		cin>>data;
		node *temp2=new node(data);
		root->right=create_tree(temp2);
	
		
	}
	
	return root;
	
}
void preorder(node * &root,node * parent)
{
	if(root==NULL)
	{
		return;
	}
		root->parent=parent;
/*	cout<<"root =="<<root->data<<"   parent==";
	if(parent==NULL)
	{
		cout<<"0";
	}
	else
	{
	cout<<parent->data<<endl;	
	}
	*/

preorder(root->left,root);
preorder(root->right,root);	
}
int main()
{
	node * root=NULL;
	int n;
	cin>>n;
	root=new node(n);
	root=create_tree(root);
//	levelorder(root);
preorder(root,NULL);
}
//10 true 20 true 30 false false true 40 false false true 50 true 60 false false true 70 false false 
