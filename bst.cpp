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
int minBst(node * root){
    if(!root){
        return -1;
    }
    while(root->left){
        root = root->left;
    }
    return root->data;
}
bool find(node * root,int data){
    while(root){
        if(root->data==data){
            return true;
        }
        if(root->data<data){
            root = root->right;
        }else{
            root = root->left;
        }
    }
    return false;
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
node * sortedLL(node * root){
    if(root==NULL){
        return NULL;
    }
    node * head = sortedLL(root->left);
    node * it = head;
    node * temp = new node(root->data);
    if(head){
        while(it->left){
            it = it->left;
        }
        it->left = temp;
    }else{
        head = temp;
    }
    it = temp;
    temp->left = sortedLL(root->right);
    return head;
}
void printLL(node * root){
    while(root){
        cout<<root->data<<" --> ";
        root = root->left;
    }
    cout<<"NULL"<<endl;
}
int height(node * root){
    if(root==NULL){
        return 0;
    }
    return max(height(root->left),height(root->right))+1;
}
bool checkbalanced(node * root){
    if(root==NULL){
        return true;
    }

    bool l = checkbalanced(root->left);
    bool r = checkbalanced(root->right);
    int lh = height(root->left);
    int rh = height(root->right);
    bool x = false;
    if(abs(lh-rh)<=1){
        x = true;
    }
    return l & r & x;
}
pair<bool,int> checkBalFast(node * root){
    if(root==NULL){
        pair<bool,int>p;
        p.first = true;
        p.second = 0;
        return p;
    }
    pair<bool,int>l =  checkBalFast(root->left);
    pair<bool,int>r =  checkBalFast(root->right);
    bool x = false;
    if(abs(l.second-r.second)<=1){
        x = true;
    }
    pair<bool,int>p;
    p.first = l.first & r.first & x;
    p.second = max(l.second,r.second)+1;
    return p;
}
pair<bool,pair<int,int> > checkBst(node* root){
    if(root==NULL){
        pair<bool,pair<int,int> > p;
        p.first = true;
        p.second.first = INT_MAX;
        p.second.second = INT_MIN;
        return p;
    }
    pair<bool,pair<int,int> > left = checkBst(root->left);
    pair<bool,pair<int,int> > right = checkBst(root->right);
    bool x = false;
    if(root->data >= left.second.second  && root->data < right.second.first){
        x = true;
    }
    pair<bool,pair<int,int> > p;
    p.first = left.first & right.first & x;
    p.second.first = min(left.second.first,root->data);
    p.second.second = max(right.second.second,root->data);
    return p;
}
int find(int k,int a[],node *root,int i)
{
	
	if(root->data==k)
	{
		a[i]=root->data;
		return i+1;
	}
	
	a[i]=root->data;
//	cout<<"shah"<<a[i]<<"___"<<k<<endl;
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


int main(){
node * root = NULL;
int n;
cin>>n;
for(int i=0;i<n;i++)
{
	int r;
	cin>>r;
	addElement(&root,r);
}
//preorder(root);
//	levelorder(root);
	int k1,k2;
	int a1[100],a2[100];
	cin>>k1>>k2;
	int index1=find(k1,a1,root,0);
	
//	cout<<endl;
//	cout<<"for a2";
	int index2=find(k2,a2,root,0);
	
	int i=0;
	
	
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
