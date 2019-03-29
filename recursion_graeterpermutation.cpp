#include<iostream>
using namespace std;
void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}
bool compare(char arr[],char str[])
{
	int i=0;
	int p,q;
	p=q=0;
	while(arr[i]!='\0')
	{
		p=p*10+(arr[i]-'0');
		q=q*10+(str[i]-'0');
		i++;
	}
//	cout<<p<<"  "<<q<<endl;
	if(p>q)
	{
		return true;
		
	}
	return false;
}
void permutate(char arr[100],int index,char str[]){
    if(arr[index]=='\0'){
    	if(compare(arr,str))
    	{
    	cout<<arr<<endl;	
		}
        
        return;
    }
    for(int j=index;arr[j]!='\0';j++){
        swap(arr[index],arr[j]);
        permutate(arr,index+1,str);
        swap(arr[j],arr[index]);
    }
    return;
}
int main(){
char arr[100],str[100] ;
cin.getline(arr,100);
int i=0;
while(arr[i]!='\0')
{
	str[i]=arr[i];
	i++;
}

str[i]='\0';
//cout<<"shah";
permutate(arr,0,str);
}
