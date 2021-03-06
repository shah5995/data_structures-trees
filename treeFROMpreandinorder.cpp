#include<iostream>
using namespace std;
#include<queue>
#include<vector>
struct node
{
int data;
node * left;
node* right;
node(int data)
	{
		this->data=data;
		left=right=NULL;
	}
};
node *btree()
{
	cout<<"enter data &-1 for exit";
	int data;
	cin>>data;
	node * root=NULL;
	if(data!=-1)
	{
		 root=new node(data);
	}
	queue<node *> q;
	q.push(root);
	while(!q.empty())
	{
		node *top=q.front();
		q.pop();
		cout<<"enter the left data for"<<top->data<<"and -1 for NULL"<<endl;
		cin>>data;
		if(data!=-1)
		{
			node *left=new node(data);
			top->left=left;
			q.push(left);
		}
		cout<<"enter the right data for"<<top->data<<"and -1 for NULL"<<endl;
		cin>>data;
		if(data!=-1)
		{
			node *right=new node(data);
			top->right=right;
			q.push(right);
		}
	}
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

void postorder(node *root)
{
	if(root==NULL)
	{
		return;
	}
	postorder(root->left);
	
	
postorder(root->right);
cout<<root->data<<" ";
return;	
}

void inorder(node *root)
{
	if(root==NULL)
	{
		return;
	}
	
	inorder(root->left);
	cout<<root->data<<" ";
inorder(root->right);
return;	
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
	while(!q.empty())
	{
		node *p=q.front();
		cout<<p->data<<" ";
		q.pop();
		if(p->left==NULL&&p->right==NULL)
		{
			continue;
		}
		else if(p->left==NULL)
		{
			q.push(p->right);
		}
		else if(p->right==NULL)
		{
			q.push(p->left);
		}
		else
		{
		
		q.push(p->left);
		q.push(p->right);	
		}
	}
	
}
int node_greater(node *root,int n)
{
	if(root==NULL)
	{
		return 0;
	}
int left=node_greater(root->left,n);
	int right=node_greater(root->right,n);
	int c=0;
	if(root->data>n)
	{
		c++;
	}
	return(left+right+c);
	
}
int sum(node *root)
{
	if(root==NULL){
		return 0;
	}
	if(root->left==NULL&&root->right==NULL)
	{
		return root->data;
	}
	if(root->left==NULL)
	{
		return (root->data+root->right->data);
	}
	
	if(root->right==NULL)
	{
		return (root->data+root->left->data);
	}
}

void depth(node *root,int k)
{
	queue<node *>q1;
	queue<node *>q2;
	q1.push(root);
	while(k--)
	{
		if(q1.empty())
		{
		while(!q2.empty())
		{
			q1.push(q2.front());
			q2.pop();
			
			}	
		}
		else
		{
			while(!q1.empty())
		{
			q2.push(q1.front());
			q1.pop();
			
			}	
		}
	
			
		}
		if(q1.empty())
		{
			while(!q2.empty())
			{
				node *n=q2.front();
				cout<<n->data<<" ";
				q2.pop();
			}
		}
		
		else
		{
			while(!q1.empty())
			{
				node *n=q1.front();
				cout<<n->data<<" ";
				q1.pop();
			}
		}
		
		
	}
	int find(vector<int>in,int s,int p,int k)
	{
		for(int i=s;i<=p;i++)
		{
			if(in[i]==k)
			{
				return i;
			}
		}
		return -1;
	}
node * construct_tree(vector<int>post,int p_start,int p_end,vector<int>in,int i_start,int i_end)
{
	if(p_end<p_start)
	{
		return NULL;
	}
	int rootdata=post[p_end];
	int index=find(in,i_start,i_end,rootdata);
	int l=index-i_start-1;
	int r=i_end-index-1;
	node *root=new node(rootdata);
	root->left=construct_tree(post,p_start,p_start+l,in,i_start,i_start+l);
	root->right=construct_tree(post,p_end-r,p_end,in,index+1,i_end);
	return root;
	
}
int main()
{
	vector<int> post;
	post.push_back(3);
	post.push_back(4);
	post.push_back(2);
	post.push_back(6);
	post.push_back(5);
	post.push_back(1);
	
	vector<int> in;
	in.push_back(3);
	in.push_back(2);
	in.push_back(4);
	in.push_back(1);
	in.push_back(6);
	in.push_back(5); 
	cout<<"shah";
	node* root=construct_tree(post,0,5,in,0,5); 
	cout<<"shah";
	levelorder(root);
    
	
}
