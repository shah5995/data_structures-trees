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
void printInRange(node * root,int k1,int k2){
    if(root==NULL){
        return;
    }
    if(root->data > k1){
        printInRange(root->left,k1,k2);
    }
    if(root->data >=k1 && root->data<=k2){
        cout<<root->data<<" ";
    }
    if(root->data <k2 ){
         printInRange(root->right,k1,k2);
    }
}
void notInRange(node * root,int k1,int k2){
    if(root==NULL){
        return;
    }
    if(root->data < k1){
        notInRange(root->right,k1,k2);
    }
    if(root->data <=k1 && root->data>=k2){
        cout<<root->data<<" ";
    }
    if(root->data >k2 ){
         printInRange(root->left,k1,k2);
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
cout<<"# preorder : ";
preorder(root);
cout<<endl;

cout<<"# Nodes within range are : ";
printInRange(root,k1,k2);
cout<<endl;
notInRange(root,k1,k2);
}
}
