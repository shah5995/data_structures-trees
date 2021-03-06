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
void print_pair_sum(node * root,int k1,set<int> &k)
{
	if(root==NULL)
	{
		return;
	}
	if(root->data>k1)
	{
		return;
	}
	print_pair_sum(root->left,k1,k);
	int r=k1-root->data;
	if(r!=root->data)
	{
	
	set<int >::iterator it=k.find(r);
	if(it!=k.end())
	{
		cout<<root->data<<" "<<r<<endl;
		k.erase(it);
		k.erase(k.find(root->data));
	}	
	}
	
	print_pair_sum(root->right,k1,k);
	
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
int k1;
cin>>k1;
print_pair_sum(root,k1,k);
}
