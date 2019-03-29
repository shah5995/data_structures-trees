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
//static int index=0;

void preorder(node * root){
    if(root==NULL){
        return;
    }
    if(root->left!=NULL)
    {
    	cout<<" "<<root->left->data<<" => ";
	}
	else
	{
		cout<<" END => ";
	}
    cout<<root->data;
    if(root->right!=NULL)
    {
    	cout<<" <="<<" "<<root->right->data;
	}
	else
	{
		cout<<" <= END";
	}
	cout<<endl;
    preorder(root->left);
    preorder(root->right);
    return;
}
void levelorder(node * root){
    queue<node *>q;
    if(root){
        q.push(root);
    }
    while(!q.empty()){
        node * top = q.front();
        cout<<top->data<<" ";
        q.pop();
        if(top->left){
           q.push(top->left);
        }
        if(top->right){
            q.push(top->right);
        }
    }
}
void add_duplicate(node **root,int data)
{
	node *temp1=*root;
	if(temp1->data==data)
	{
		node *temp=new node(data);
		temp->left=temp1->left;
		temp1->left=temp;
		return ;
		
	}
	if(temp1->data>data)
	{
		add_duplicate(&temp1->left,data);
	}
	else
	{
		add_duplicate(&temp1->right,data);
	}

	
}
int main()
{
	node * root=NULL;
	int n;
	cin>>n;
	int a[10000];
	for(int i=0;i<2*n;i++)
	{
		cin>>a[i];
		
		addElement(&root,a[i]);
		a[i+1]=a[i];
		i++;
		addElement(&root,a[i]);
		
		
	}//preorder(root);cout<<endl;
	
	preorder(root);
	//levelorder(root);
}
