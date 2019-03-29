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
void reverse(queue<node * > q)
{
	if(q.empty())
	{
		return;
	}
	node * r=q.front();
	q.pop();
	reverse(q);
	cout<<r->data<<" ";
	q.push(r);
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
	int i=0;
	while(!q.empty())
	{
		 int nodeCount = q.size();
		  if(i%2!=0)
		 {
		
			  {
			  	reverse(q);
			  }
		 }
		  
  
         
        while (nodeCount > 0) 
        {  
            node *node = q.front();
			if(i%2==0)
			{
				cout << node->data << " ";  
			  }  
			  
			  
            
            q.pop();
		  
            if (node->left != NULL)  
                q.push(node->left);  
                	if (node->right != NULL)  
                q.push(node->right); 
             
            nodeCount--;  
        }  
        i++;
      
        //cout <<" "; 
		
		
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
int main()
{
	node * root=NULL;
	int n;
	cin>>n;
	root=new node(n);
	root=create_tree(root);
	levelorder(root);
	
}
