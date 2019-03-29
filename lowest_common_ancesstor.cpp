#include<iostream>
using namespace std;
#include<cstring>
#include<queue>
#include<vector>
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
void addElement(node ** root,int data){
    if(*root==NULL){
        *root = new node(data);
        return;
    }
    node * temp = new node(data);
    node * it = *root;
    while(it!=NULL){
        if(it->data<data){
            if(it->right==NULL){
                it->right = temp;
                return;
            }
            it = it->right;
        }else{
            if(it->left==NULL){
                it->left = temp;
                return;
            }
            it = it->left;
        }
    }
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

int find(int k,int a[],node *root,int i)
{
	
	if(root->data==k)
	{
		return i;
	}
	
	a[i]=root->data;
	cout<<"shah"<<a[i]<<"___"<<k<<endl;
	//cout<<v[m++];
	int p=0;
	if(root->data > k)
	{
		p=find(k,a,root->left,i+1);
	}
	else
	{
		p=find(k,a,root->right,i+1);
	}
	return p;
}

int main()
{
	node * root=NULL;

int n;
cin>>n;
cout<<n;
for(int i=0;i<n;i++)
{
	cout<<"shah";
	int r;
	cin>>r;
	addElement(&root,r);
}
cout<<"shah";
	levelorder(root);
	int k1,k2;
	int a1[100],a2[100];
	cin>>k1>>k2;
	int index1=find(k1,a1,root,0);
	for(int i=0;i<index1;i++)
	{
		cout<<a1[i];
	}
	int index2=find(k2,a2,root,0);
	
	int i=0;
	
	cout<<endl;
		for(int i=0;i<index2;i++)
	{
		cout<<a2[i];
	}
	int lcs;
	
	while(i<index1)
	{
		if(a1[i]==a2[i])
		{
			lcs=a1[i];
		}
		else
		{
			break;
		}
		i++;
	}
	cout<<lcs;

	
}
