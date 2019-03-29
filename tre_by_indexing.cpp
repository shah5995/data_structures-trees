#include<iostream>
using namespace std;
#include<queue>
struct node{
	int data;
	int degree;
	node * left;
	node * right;
	node (int data)
	{
		this->data=data;
		left=right=NULL;
	}
};
pair<int,int> find(int a[],int data,int n)
{
	int m=0;
	pair<int,int>p;
	p.first=-1;
	p.second=-1;
	for(int i=0;i<n;i++)
	{
		if(a[i]==data)
		{
			if(m==0)
			{
				m++;
				p.first=i;
			}
			else
			{
				p.second=i;
			}
			
		}
	}
	return p;
}
void preorder2(node * root){
    if(root==NULL){
        return;
    }
     cout<<root->data<<" ";
    preorder2(root->left);
   
    preorder2(root->right);
    
    
}
void create(node *&root,int a[],int data,int n)
{
	if(data==-1)
	{
		return ;
	}
	
	
	pair<int,int>p=find(a,data,n);
	if(p.first==-1)
	{
		root->left=NULL;
		root->right=NULL;
		return;
	}
	else
	{
		node  *temp=new node(p.first);
		root->left=temp;
		create(root->left,a,p.first,n);
		if(p.second!=-1)
		{
		
		node *temp2=new node(p.second);
		root->right=temp2;	
		create(root->right,a,p.second,n);
		return;
		}
		else
		{
			root->right=NULL;
			return;
		}
	}
	
}
void set_degree(node *&root,int k)
{
	if(root==NULL)
	{
		return;
	}
	root->degree=k;
	set_degree(root->left,k-1);
set_degree(root->right,k+1);
return;	
}
pair<int ,int> levelorder(node *root)
{
	
	
	//cout<<root->data;
	queue<node * >q;
	q.push(root);
	int i=1;
	pair<int,int>p;
	p.first=INT_MAX;
	p.second=INT_MIN;
	while(!q.empty())
	{
		 int nodeCount = q.size();  
  
         
        while (nodeCount > 0) 
        {  
            node *node = q.front();  
          //  cout << node->data << " "; 
			if(node->degree>p.second)
			{
				p.second=node->degree;
			 } 
			 if(node->degree<p.first)
			 {
			 	p.first=node->degree;
			 }
            q.pop();  
            if (node->left != NULL)  
                q.push(node->left);  
            if (node->right != NULL)  
                q.push(node->right);  
            nodeCount--;  
        }  
      //  cout << endl; 
		
		
	}
	return p;
}
template<typename T>
struct node2{
    int key;
    T value;
    node2 * next;

    node2(int key,T value){
        this->key = key;
        this->value = value;
        next=NULL;
    }
};
template <typename T>
class hashtable{
    node2<T> ** table;
    int ts;
    int cs;
    hashFn(int key,int min)
    {
    	return key-min;
	}
public:
    hashtable(int size=7){
        ts = size;
        cs = 0;
        table = new node2<T> * [size];
        for(int i=0;i<ts;i++){
            table[i] = NULL;
        }
    }
    void insert(int key,T value,int min){
        int index = hashFn(key,min);
        node2<T> * temp = new node2<T>(key,value);
        if(table[index]==NULL)
        {
        	table[index]=temp;
		}
		else
		{
			node2<T> *temp2=table[index];
			while(temp2->next!=NULL)
			{
				temp2=temp2->next;
			}
			temp2->next=temp;
			temp->next=NULL;
		}
        
        cs++;
    }
     void print(){
        for(int i=0;i<ts;i++){
            node2<T> * head = table[i];
            //cout<<i<<"-->";
            while(head){
                node * r=head->value;
                cout<<r->data<<" ";
                head = head->next;
            }
            cout<<endl;
        }
    }
};
void insert_into(node * root,hashtable<node *>&h,int p)
{
	if(root==NULL)
	{
		return;
	}
	h.insert(root->degree,root,p);
//	cout<<root->data<<" ";
	insert_into(root->left,h,p);
insert_into(root->right,h,p);
return;	
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	
	int a[1000],n,data;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]==-1)
		{
			data=i;
		}
	}
	node *root=new node(data);
	create(root,a,data,n);
	set_degree(root,0);

	
	
	pair<int ,int>p = levelorder(root);
//	cout<<p.first<<" "<<p.second<<endl;
	hashtable<node *> h(p.second-p.first+1);
	insert_into(root,h,p.first);
	h.print();
	//preorder2(root);
		
	}
}
