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
	node * parent;
node(int data)
	{
		this->data=data;
		left=right=NULL;
		degree=0;
		parent=NULL;
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
node * find(node * root,int k)
{
	if(root==NULL)
	{
		return NULL;
	}
	if(root->data==k)
	{
		return root;
	}
	node *temp;
	
		temp=find(root->left,k);
		if(temp)
		{
			return temp;
		}
		
			temp=find(root->right,k);
	return temp;
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
void move_down(node * root,int k)
{
	
	if(!root)
	{
		return;
	}
		if(k==0)
	{
		cout<<root->data<<" ";
		return;
		
	}

	move_down(root->left,k-1);
	move_down(root->right,k-1);
}
void move_up(node *root,int k,int q)
{

	if(root->parent==NULL)
	{
		if(k==0)
		{
			cout<<root->data<<" ";
			return;
		}
		
		return ;
	}

	if(q==0)
	{
		move_down(root->parent->right,k-2);
	}
	else
	{
	     move_down(root->parent->left,k-2);
	}
	int p;
	if(root->parent==NULL)
	{
		p=5;
	}
	else
	{
		if(root->parent->left->data==root->data)
		{
			p=0;
		}
		else if(root->parent->right->data==root->data)
		{
				p=1;
		}
	
	}
		if(k==0)
	{
		cout<<root->data<<" ";
		return;
	}

	move_up(root->parent,k-1,p);
}

void print_root_at_distance(node * root,int k)
{
//	cout<<root->data<<endl<<endl;
	if(root==NULL)
	{
		return;
	}
	move_down(root,k);
	int p;
	if(root->parent==NULL)
	{
		p=5;
	}
	else
	{
		if(root->parent->left->data==root->data)
		{
			p=0;
			
		}
		else
		p=1;
		
	}
//	cout<<p<<endl;
	move_up(root,k,p);
}//10 20 30 80 40 90 50 60 100 70 110  80 30 20 40 90 10 100 60 50 70 110
//
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
//	levelorder(root);
	preorder(root,NULL);
	int t;
	cin>>t;
	while(t--)
	{
		int data,k;
		cin>>data;
		node *temp=find(root,data);
	//	cout<<temp->data;
		
		cin>>k;
		print_root_at_distance(temp,k);
		cout<<endl;
	}
	
	
}
