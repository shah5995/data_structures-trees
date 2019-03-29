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
int find(int a[],int data,int s,int e)
{
	for(int i=s;i<=e;i++)
	{
		if(a[i]==data)
		{
			return i;
		}
	}
}
node * build_bst(int a[],int s,int e,int n)
{
	if(s>e)
	{
		
	
		//cout<<"shah";
		return NULL;
	}
	
	int data=a[(s+e)/2];
	node *root=new node(data);
//	cout<<root->data;
	int index=(s+e)/2;
	//cout<<index<<"  s"<<s<<" e"<<e<<endl;
	root->left=build_bst(a,s,index-1,n);
	root->right=build_bst(a,index+1,e,n);
	return root;
	
	
	
}
void preorder(node *root)
{
	if(root==NULL)
	{
		return;
	}
	cout<<root->data<<" ";
	preorder(root->left);
preorder(root->right);
return;	
}

int main()
{
	int n,a[10000];
	int t;
	cin>>t;
	while(t--)
	{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	
	}
node * root=NULL;
root=build_bst(a,0,n-1,n);
preorder(root);
//			cout<<endl;levelorder(root);
	}

	
}
