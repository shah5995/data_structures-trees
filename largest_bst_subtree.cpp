#include<iostream>
using namespace std;
#include<queue>
#include<vector>
struct node
{
int data;
int degree;
node * left;
node* right;
node(int data)
	{
		this->data=data;
		left=right=NULL;
		degree=0;
	}
};
int find(vector<int>v,int s,int e,int d){
    for(int i=s;i<=e;i++){
        if(v[i]==d){
            return i;
        }
    }
    return -1;
}
node * treeFromPreAndIn(vector<int>pre,int pstart,int pend,vector<int>in,int istart,int iend){
    if(pstart>pend){
        return NULL;
    }
    int rootData = pre[pstart];
    int index = find(in,istart,iend,rootData);
    int l = index - istart;
    int r = iend - index;
    node * root = new node(rootData);
    root->left = treeFromPreAndIn(pre,pstart+1,pstart+l,in,istart,index-1);
    root->right = treeFromPreAndIn(pre,pstart+l+1,pend,in,index+1,iend);
    return root;
}
pair<bool,int> max_sub_bst(node *root)
{
	if(root==NULL)
	{
		pair<bool,int>p;
		p.first=true;
		p.second=0;
		return p;
	}
	pair<bool,int>l=max_sub_bst(root->left);
	pair<bool,int>r=max_sub_bst(root->right);
	
	pair<bool,int>q;
	bool x=true;
	if(root->left)
	{
	   if(	root->data < root->left->data)
		x=false;
	}
	if(root->right)
	{
		if(root->data >= root->right->data)
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
	vector<int >pre,in;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int r;
		cin>>r;
		pre.push_back(r);
	}
	
	for(int i=0;i<n;i++)
	{
		int r;
		cin>>r;
		in.push_back(r);
	}
	node * root=treeFromPreAndIn(pre,0,n-1,in,0,n-1);
	
	pair<bool,int>p=max_sub_bst(root);
	cout<<p.second;
	cout<<endl;
	//cout<<height(root);
	
}
