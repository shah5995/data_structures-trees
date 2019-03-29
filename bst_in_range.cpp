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
void preorder2(node * root){
    if(root==NULL){
        return;
    }
     cout<<root->data<<" ";
    preorder2(root->left);
   
    preorder2(root->right);
    
    return;
}
pair<bool,int> max_sub_bst(node *root,int k1,int k2)
{
	if(root==NULL)
	{
		pair<bool,int>p;
		p.first=true;
		p.second=0;
		return p;
	}
	pair<bool,int>l=max_sub_bst(root->left,k1,k2);
	pair<bool,int>r=max_sub_bst(root->right,k1,k2);
	
	pair<bool,int>q;
	bool x=true;
	if(root->left)
	{
	   if(	root->data < k1)
		x=false;
	}
	if(root->right)
	{
		if(root->data >= k2)
		 x=false;
	}
	
	if(l.first && r.first && x)
	{
		
		q.first=true;
		q.second=(l.second+r.second)+1;
	//	cout<<q.first<<q.second<<endl;
		return q;
	}
	else 
	{
		q.first=false;
		if(x==false)
		{
			q.second=max(l.second,r.second);
		
		}
		else if(l.first==false)
		{
			q.second=r.second;
		}
		else
		{
			q.second=l.second;
		}
	//	cout<<q.first<<q.second<<endl;
			return q;
		
	}
}
int main()
{
	int n,k1,k2;
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
cin>>k1>>k2;
pair<bool,int>p=max_sub_bst(root,k1,k2);
	cout<<p.second;
	cout<<endl;
}
