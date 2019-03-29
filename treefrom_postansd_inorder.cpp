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
		root->data < root->left->data;
		x=false;
	}
	if(root->right)
	{
		root->data >= root->right->data;
		 x=false;
	}
	
	if(l.first && r.first && x)
	{
		
		q.first=true;
		q.second=max(l.second,r.second)+1;
		return q;
	}
	else
	{
		q.first=false;
		q.second=l.second;
		return q;
		
	}
}

int height(node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	int a=height(root->left);
	int b=height(root->right);
	return (max(a,b)+1);
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
	levelorder(root);
	
	
}
