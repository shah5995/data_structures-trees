#include<iostream>
using namespace std;
template<typename T>
struct node2{
    int key;
    T value;
    node2 * next;

    node2(int key,T value){
        this->key = key;
        this->value = value;
    }
};
template <typename T>
class hashtable{
    node2<T> ** table;
    int ts;
    int cs;
    hashFn(int key,min)
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
        node2<T> * temp = new node2<T>(key,value,min);
        temp->next = table[index];
        table[index] = temp;
        cs++;
    }
     void print(){
        for(int i=0;i<ts;i++){
            node<T> * head = table[i];
            cout<<i<<"-->";
            while(head){
                cout<<head->key<<"-->";
                head = head->next;
            }
            cout<<"NULL"<<endl;
        }
    }
};
int main(){
hashtable<int> h;
h.insert("abc",1);
h.insert("wefwe",1);
h.insert("dsvd",1);
h.insert("asn",1);
h.insert("efe",1);
h.insert("vdd",1);
h.insert("eeq",1);
h.print();
h.erase("eeq");
h.print();

}

