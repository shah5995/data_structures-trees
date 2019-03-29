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
void preorder2(node * root,int k1,int k2){
    if(root==NULL){
        return;
    }
    if(root->data>=k1&&root->data<=k2)
    {
    	cout<<root->data<<" ";
	}
   preorder2(root->left,k1,k2);
   
   preorder2(root->right,k1,k2);
    
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
	
		modify_bst(root->left,sum);
	

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
int k1,k2;
cin>>k1>>k2;
cout<<"Preorder :  ";preorder(root);
cout<<endl;

cout<<"Preorder :  ";preorder2(root,k1,k2);

/*
int sum=0;
modify_bst(root,&sum);
preorder(root);*/
		cout<<endl;
	}

}
