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
    cout<<root->data<<" ";
    preorder(root->left);
    
    preorder(root->right);
    
    return;
}
node * root_delete(node * root,int k1)
{
	if(root->data<k1)
	{
		node *temp=root;
		if(root->right)
		{
			delete root;
			return temp->right;
		}
		return NULL;
	}
	root->left=root_delete(root->left,k1);
	return root;
}
node * root_delete2(node * root,int k1)
{
	if(root->data>k1)
	{
		node *temp=root;
		if(root->left)
		{
			delete root;
			return temp->left;
		}
		return NULL;
	}
	root->right=root_delete2(root->right,k1);
	return root;
}
int main(){
	int t;
	cin>>t;
	while(t--)
	{
		node * root = NULL;
int n;
cin>>n;
for(int i=0;i<n;i++)
{
	int r;
	cin>>r;
	addElement(&root,r);
}
cout<<"Preorder :";
preorder(root);
cout<<endl;
int k1,k2;
cin>>k1>>k2;
root=root_delete(root,k1);
root=root_delete2(root,k2);
cout<<"Preorder :";preorder(root);
		
	}


}
