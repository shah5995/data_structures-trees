#include<iostream>
using namespace std;
#include<queue>

struct node
{
int data;
int degree;
node * left;
node* right;
node(int data)
	{
		this->data=data;
		left=right=NULL;
	}
};
node *btree()
{
//	cout<<"enter data &-1 for exit";
	int data;
	cin>>data;
	node * root=NULL;
	if(data!=-1)
	{
		 root=new node(data);
	}
	queue<node *> q;
	q.push(root);
	while(!q.empty())
	{
		node *top=q.front();
		q.pop();
	//	cout<<"enter the left data for"<<top->data<<"and -1 for NULL"<<endl;
		cin>>data;
		if(data!=-1)
		{
			node *left=new node(data);
			top->left=left;
			q.push(left);
		}
	//	cout<<"enter the right data for"<<top->data<<"and -1 for NULL"<<endl;
		cin>>data;
		if(data!=-1)
		{
			node *right=new node(data);
			top->right=right;
			q.push(right);
		}
	}
	return root;
	
}
void preorder(node *root)
{
	if(root==NULL)
	{
		return;
	}
	cout<<root->data<<" ";
	preorder(root->left);
preorder(root->right);
return;	
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
	
	node *root=nbtree();
	
	set_degree(root,0);

	
	
	pair<int ,int>p = levelorder(root);
//	cout<<p.first<<" "<<p.second<<endl;
	hashtable<node *> h(p.second-p.first+1);
	insert_into(root,h,p.first);
	h.print();
	
	
}
