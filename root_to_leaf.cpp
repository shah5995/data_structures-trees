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
void check(int a[],node * root,int k,int index)
{
	if(root->left==NULL&&root->right==NULL)
	{
		k=k-root->data;
		a[index]=root->data;
		if(k==0)
		{
		//	cout<<"shah      " ;
			int i=0;
			while(a[i]!=0)
			{
				cout<<a[i]<<" ";
				i++;
			}
		}
		return;
	}
	if(k<0)
	{
		return;
	}
	a[index]=root->data;
	//cout<<a[index];
	
	
	k=k-root->data;
	//cout<<k<<endl;
	check(a,root->left,k,index+1);
	//cout<<"He";
	check(a,root->right,k,index+1);
}
int main()
{
	node * root=NULL;
	int n;
	cin>>n;
	root=new node(n);
	root=create_tree(root);
	levelorder(root);
	int a[100]={0};
	int k;
	cin>>k;
	//cout<<"shah";
	check(a,root,k,0);
	
}
