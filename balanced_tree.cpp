#include<iostream>
using namespace std;
#include<cstring>
#include<queue>
#include<cmath>
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
pair<int ,bool> check_balanced(node *root)
{
	if(root==NULL)
	{
		pair<int,bool> p;
		p.first=0;
		p.second=true;
		return p;
	}
	pair<int,bool>l=check_balanced(root->left);
	pair<int,bool>r=check_balanced(root->right);
	bool x=false;
	if(abs(l.first-l.second)<=1)
	{
		x=true;
	}
	pair<int,bool> ans;
	ans.first=x & l.second & r.second;
	ans.second=max(l.second,r.second)+1;
	return ans;
	
}
int main()
{
	node * root=NULL;
	int n;
	cin>>n;
	root=new node(n);
	root=create_tree(root);
	pair<int,bool>p;
	p=check_balanced(root);
	if(p.second)
	{
		cout<<"true";
	}
	else
	{
		cout<<"false";
	}
}
