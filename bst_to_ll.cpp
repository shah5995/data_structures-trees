
#include<iostream>
#include<queue>
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
void levelorder(node * root){
    queue<node *>q;
    if(root){
        q.push(root);
    }
    while(!q.empty()){
        node * temp = q.front();
        cout<<temp->data<<" ";
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
        q.pop();
    }
}
void preorder(node * root){
    if(root==NULL){
        return;
    }
    cout<<root->data;
    preorder(root->left);
    preorder(root->right);
    return;
}
void postorder(node * root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data;
    return;
}
void inorder(node * root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
    return;
}
bool find(node * root,int data)
{
	if(root==NULL)
	{
		return false;
	}
	if(root->data==data)
	{
		return true;
	}
	bool ans;
	if(data>root->data)
	{
		ans=find(root->right,data);
		
	}
	else
	{
		ans=find(root->left,data);
	}
	return ans;
}

void print_ll(node *root)
{
	while(root!=NULL)
	{
		cout<<root->data<<" ";
		root=root->left;
	}
	return;
}
node * create_ll(node * root)
{
	if(root==NULL)
	{
		return root
	}
	
}

int main(){
node * root = NULL;
addElement(&root,5);
addElement(&root,3);addElement(&root,8);
addElement(&root,1);
addElement(&root,7);
addElement(&root,10);
addElement(&root,4);
addElement(&root,5);
levelorder(root);
node *root2=NULL;
root2=create_ll(root,root2);
//print_ll(root2);
}
