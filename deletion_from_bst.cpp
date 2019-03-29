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
static int index=0;

void preorder(node * root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    return;
}
void InRange(node * root,int k1,int k2,int a[]){
    if(root==NULL){
        return;
    }
    if(root->data<k1||root->data>k2)
    {
    a[index++]=root->data;	
	}
    //cout<<root->data<<" ";
    InRange(root->left,k1,k2,a);
    InRange(root->right,k1,k2,a);
    return;
}
node * removeElement(node * root,int element){
    if(root==NULL){
        return NULL;
    }
    if(root->data==element){
        // 0 child
        if(!root->left && !root->right){
            delete root;
            return NULL;
        }

        //1 child
       if(root->left==NULL&&root->right!=NULL)
       {
       	node *it=root->right;
       	delete root;
       	return it;
	   }
	   
       if(root->left!=NULL&&root->right==NULL)
       {
       	node *it=root->left;
       	delete root;
       	return it;
	   }

        //2 child
        node * parent = root;
        node * it = root->right;
        if(it->left==NULL){
            it->left = root->left;
            delete root;
            return it;
        }
        while(it->left!=NULL){
            parent = it;
            it = it->left;
        }
        parent->left = it->right;
        it->left = root->left;

        if(root->right!=it){
            it->right = root->right;
        }
        delete root;
        return it;
    }

    if(root->data < element){
        root->right = removeElement(root->right,element);
    }else{
        root->left = removeElement(root->left,element);
    }
    return root;
}
int main(){
	int t;
	cin>>t;
	while(t--)
	{
		index=0;
	
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
cout<<"Preorder : ";
preorder(root);
cout<<endl;

int a[1000];
InRange(root,k1,k2,a);

//cout<<"shah"<<index<<endl;
for(int i=0;i<index;i++)
{
	//cout<<"delete"<<a[i]<<endl;
	root=removeElement(root,a[i]);
	//preorder(root);cout<<endl;
}
//	root=removeElement(root,6);
cout<<"Preorder : ";preorder(root);
cout<<endl;
}
}
