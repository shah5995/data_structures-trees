#include<iostream>
#include<queue>
using namespace std;
struct node{
    int data;
    node * left;
    node * right;
    int depth;
    node(int data){
        this->data = data;
        left = right = NULL;
    }
};
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
int find(vector<int>v,int s,int e,int d){
    for(int i=s;i<=e;i++){
        if(v[i]==d){
          //  cout<<i<<endl;
			return i;
            
        }
    }
    return -1;
}

node * treeFrompostAndIn(vector<int>post,int pstart,int pend,vector<int>in,int istart,int iend){
    if(pstart>pend){
        return NULL;
    }
    int rootData = post[pend];
    int index = find(in,istart,iend,rootData);
    int l=index-pstart;
   int  r=pend-index;

    node * root = new node(rootData);
    
      root->right = treeFrompostAndIn(post,l,l+r-1,in,l+1,iend);  
    root->left = treeFrompostAndIn(post,pstart,l-1,in,istart,l-1);

    
    return root;
}
int main(){
//in[]   = {4, 8, 2, 5, 1, 6, 3, 7}
//post[] = {8, 4, 5, 2, 6, 7, 3, 1} 
vector<int>post;
post.push_back(8);
post.push_back(4);
post.push_back(5);
post.push_back(2);
post.push_back(6);
post.push_back(7);

post.push_back(3);
post.push_back(1);


vector<int >in;
in.push_back(4);
in.push_back(8);
in.push_back(2);
in.push_back(5);
in.push_back(1);
in.push_back(6);

in.push_back(3);
in.push_back(7);
node * root = treeFrompostAndIn(post,0,7,in,0,7);
levelorder(root);
}
