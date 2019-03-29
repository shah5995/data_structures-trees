#include<iostream>
using namespace std;
#include<set>
struct node
{
int data;
node *left;
node *right;
node (int data)
{
	this->data=data;
	left=right=NULL;
	}	
};
void preorder2(node * root){
    if(root==NULL){
        return;
    }
     cout<<root->data<<" ";
    preorder2(root->left);
   
    preorder2(root->right);
    
    
}
node * create_tree(int arr[],int s,int e,node *root)
{
	if(s>e)
	{
		return NULL;
	}
	int r=(s+e)/2;
	root=new node(arr[(s+e)/2]);
root->left=create_tree(arr,s,r-1,root->left);
	root->right=create_tree(arr,r+1,e,root->right);
	return root;
}
pair<bool,int> count_subtree(node * root,int k1,int k2)
{
	if(root==NULL)
	{
		pair<bool,int>p;
		p.first=true;
		p.second=0;
		return p;
	}
	pair<bool,int>l=count_subtree(root->left,k1,k2);
		pair<bool,int>r=count_subtree(root->right,k1,k2);
		int x=false;
		if(root->data>=k1&&root->data<=k2)
		{
			x=true;
		}
		pair<bool,int> q;
		if(l.first && r.first && x)
		{
			q.first=true;
			q.second=l.second+r.second+1;
			return q;
		}
		else
		{
				q.first=false;
			q.second=l.second+r.second;
			return q;
		}
		
}
int main()
{
	int n;
	cin>>n;
	int arr[1000];
	set<int >k;
	for(int i=0;i<n;i++)
	{
		
		cin>>arr[i];
		k.insert(arr[i]);
	}
	
	node * root=NULL;
root=	create_tree(arr,0,n-1,root);
//preorder2(root);
int k1,k2;
cin>>k1>>k2;
pair<bool,int> p=count_subtree(root,k1,k2);
cout<<p.second;


}
