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
	int i=1;
	while(!q.empty())
	{
		 int nodeCount = q.size();  
  
         
        while (nodeCount > 0) 
        {  
            node *node = q.front();  
            cout << node->data << " ";  
            q.pop();  
            if (node->left != NULL)  
                q.push(node->left);  
            if (node->right != NULL)  
                q.push(node->right);  
            nodeCount--;  
        }  
        cout << endl; 
		
		
	}
	
}
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
node * node_delete(node * root,int element)
{
	if(root==NULL)
	{
		return NULL;
	}
	if(root->data==element)
	{
		if(root->left==NULL&& root->right==NULL)
		{
			delete root;
			return NULL;
		}
		if(root->left==NULL)
		{
			node *it=root;
			it=it->right;
			delete root;
			return it;
		}
		
		if(root->right==NULL)
		{
			node *it=root;
			it=it->left;
			delete root;
			return it;
		}
		// two child
		node *parent=root;
		node *it=root->left;
		if(it->right==NULL)
		{
			it->right=root->right;
			delete root;
			return it;
		}
		while(it->right!=NULL)
		{
			parent=it;
			it=it->right;
		}
		parent->right=it->left;
		it->right=root->right;
		it->left=root->left;
		delete root;
		return it;
	}
	if(root->data>element)
	{
		root->left=node_delete(root,element);
	}
	else
	{
		root->right=node_delete(root,element);
	}
	return root;
}
int main()
{
	node * root=NULL;
	int n;
	cin>>n;
	root=new node(n);
	root=create_tree(root);
	levelorder(root);
	int element;
	cin>>element;
	root=node_delete(root,element);
	levelorder(root);
	
}
