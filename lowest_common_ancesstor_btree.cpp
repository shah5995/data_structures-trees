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
pair<bool,int> lca(node * root,int k1,int k2)
{
	if (root==NULL)
	{
		pair<bool ,int>p;
		p.first=false;
		p.second=0;
		return p;
	}
	pair<bool,int>l=lca(root->left,k1,k2);
	pair<bool,int>r=lca(root->right,k1,k2);
	//cout<<endl<<root->data<<" is "<<l.first<<l.second<<"   "<<r.first<<r.second<<endl;
	pair<bool,int>q;
	q.first=false;
	q.second=0;
	if(root->data==k1||root->data==k2)
	{
		q.first=true;
		if(l.first==true||r.first==true)
		{
			q.second=root->data;
			return q;
		}
	}
	if(l.first && r.first)
	{
		q.first=true;
		q.second=root->data;
		return q;
	}
	else if(l.first||r.first)
	{
		q.first=true;
		if(l.second!=0)
		{
			q.second=l.second;
			return q;
		}
		if(r.second!=0)
		{
			q.second=r.second;return q;
		}
	
		return q;
	}
	
	return q;
	
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
int k1,k2;
cin>>k1>>k2;

pair<bool,int>p=	lca(root,k1,k2);
cout<<p.second;
}
