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
node *leaf_del(node * root)
{
	if(root==NULL)
	{
		return NULL;
	}
	if(root->left==NULL&&root->right==NULL)
	{
		delete root;
		return NULL;
	}
	
	root->left=leaf_del(root->left);
	root->right=leaf_del(root->right);
	return root;
	
}

int levelorder(node *root)
{
	
	if(root==NULL)
	{
		cout<<"null";
		return -1;
	}
	//cout<<root->data;
	queue<node * >q;
	q.push(root);
	int sum=0;
	while(!q.empty())
	{
		 int nodeCount = q.size();  
  
         
        while (nodeCount > 0) 
        {  
            node *node = q.front();  
            sum+=node->data; 
            q.pop();  
            if (node->left != NULL)  
                q.push(node->left);  
            if (node->right != NULL)  
                q.push(node->right);  
            nodeCount--;  
        }  
       // cout << endl; 
		
		
	}
	return sum;
	
}

int main()
{
	node * root=NULL;
	int n;
	cin>>n;
	root=new node(n);
	root=create_tree(root);
//	
//	root=leaf_del(root);
	//	preorder(root);
		cout<<levelorder(root);;
	
}
