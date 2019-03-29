#include<iostream>
#include<queue>
using namespace std;

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

void degree(node *root)
{
	if(root==NULL)
	{
		return;
	}
	int p=0;
	if(root->left!=NULL)
	{
		p++;
	}
	if(root->right!=NULL)
	{
		p++;
	}
	cout<<"degree of"<<root->data<<"=="<<p<<endl;
	degree(root->left);
	degree(root->right);
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
			node *top=q2.front();
			if(top->left)
			{
			q1.push(q2.front());	
			}
			if(top->right)
			{
				q1.push(q2.front());
			}
			
			q2.pop();
			
			}	
		}
		else
		{
			while(!q1.empty())
		{
				node *top=q1.front();
			if(top->left)
			{
			q2.push(q1.front());	
			}
			if(top->right)
			{
				q2.push(q1.front());
			}
			
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
//1 2 3 4 5 7 -1 6 -1 -1 -1 -1 -1 -1 -1
bool find(node *root,int k)
{
	if(root==NULL)
	{
		return false;
	}
	if(root->data==k)
	{
		return true;
	}
	bool l=find(root->left,k);
	if(l)
	{
		return true;
	}
	
	bool r=find(root->right,k);
	if(r)
	{
		return true;
	}
	return false;
	
}
node * swap(node *left,node *right,node *root)
{
	root->left=right;
	root->right=left;
	return root;
}
node * mirror(node * root)
{
	if(root==NULL)
	{
		return NULL;
	}
	node *left=mirror(root->left);
	node *right=mirror(root->right);
	
	return swap(left,right,root);
}
node * mirror2(node * root)
{
	if(root==NULL)
	{
		return NULL;
	}
	node *new_root=new node(root->data);
	new_root->left=mirror(root->right);
	new_root->right=mirror(root->left);
	
	return new_root;
}

int main()
{
	node *root=btree();
preorder(root);
cout<<endl;	degree(root); 
	cout<<height(root)<<endl; 
	depth(root,1);
	cout<<endl<<find(root,12)<<endl;
	node *new_root=mirror2(root);
	cout<<new_root->left->data<<" "<<new_root->right->data<<endl;
	preorder(new_root);
	root=mirror(root);
	cout<<root->left->data<<" "<<root->right->data<<endl;
	preorder(root);
}
