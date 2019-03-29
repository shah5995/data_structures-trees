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
bool check(node *root1,node* root2)
{
	if(root1==NULL&&root2==NULL)
	{
		return true;
	}
	if((root1==NULL&&root2!=NULL)||(root1!=NULL&&root2==NULL))
	{
		return false;
	}
	
	

	
	bool l1=check(root1->left,root2->left);
		bool r=check(root1->right,root2->right);
		return l1 & r ;
}
int main()
{
	node * root1=NULL;
	int n;
	cin>>n;
	root1=new node(n);
	root1=create_tree(root1);
	node*root2=NULL;
	 n;
	cin>>n;
	root2=new node(n);
	root2=create_tree(root2);
	if(check(root1,root2))
	{
		cout<<"true";
	}
	else
	{
		cout<<"false";
	}
//	levelorder(root1);
	
}
