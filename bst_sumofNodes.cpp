#include<iostream>
#include<queue>
#include<cmath>
using namespace std;
struct node{
    int data;
    node * left;
    node * right;
    node(int data){
    this->data = data;
    left = right = NULL;
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
void preorder(node * root){
    if(root==NULL){
        return;
    }
   
    cout<<root->data;
    
   
	cout<<endl;
    preorder(root->left);
    
    preorder(root->right);
    
    return;
}
void modify_bst(node * root,int* sum)
{
	if(root==NULL)
	{
		return;
	}
	modify_bst(root->right,sum);
	int p=root->data;
	*sum=*sum+p;
	root->data=*sum;
	
	//cout<<root->data;
	modify_bst(root->left,sum);
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
void preorder2(node * root){
    if(root==NULL){
        return;
    }
     cout<<root->data<<" ";
    preorder2(root->left);
   
    preorder2(root->right);
    
    return;
}
node * create_from_inorder(int a[],int s,int e,node * root)
{
	if(s>e)
	{
		return NULL;
	}
	root=new node(a[(s+e)/2]);
	int r=(s+e)/2;
	root->left=create_from_inorder(a,s,r-1,root->left);
	root->right=create_from_inorder(a,r+1,e,root->right);
	return root;
}
int main(){
	
		node * root = NULL;
int n,a[1005];
cin>>n;
for(int i=0;i<n;i++)
{
	
	cin>>a[i];
	
}
root=create_from_inorder(a,0,n-1,root);
//preorder(root);
//cout<<endl;
int sum=0;
modify_bst(root,&sum);
//cout<<"Preorder :";
preorder2(root);
//cout<<endl;
}

