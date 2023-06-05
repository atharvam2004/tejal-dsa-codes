#include<iostream>
#include<string.h>
using namespace std;
struct Client
{
	string name;
	int phone_num;
};
class HashTable{
	 public:
	 static const int size=10;
	 Client table[size];
	 int collision[size];
	 
	 HashTable()
	 {
	 	for(int i=0;i<size;i++)
	 	   collision[i]=0;
	 }
	 
	 int hash(int key)
	 {
	 	return key%size;
	 }
	
	 void linearprobing(Client client)
	 {
	 	int index=hash(client.phone_num);
	 	int count=0;
	 	while(collision[index]==1)
	 	{
	 	   index=(index+1)%size;
		   count++;	
		}
		table[index]=client;
		collision[index]=1;
		cout<<"\nInserted  "<<client.name<<" 's phone number with "<<count<<" no. of collisions using linear probing" ;
	 }
	 
	 void qudraticprobing(Client client)
	 {
	 	int index =hash(client.phone_num);
	 	int count=0;
	 	while(collision[index]!=0 && collision[index]!=client.phone_num)
	 	{
	 	   count++;
		   index=(index+count*count)%size;	
		}
		table[index]=client;
		collision[index]=1;
		cout<<"\nInserted  "<<client.name<<" 's phone number with "<<count<<" no. of collisions using qudratic probing" ;
	 }
	 
	 bool search(int number)
	 {
	 	int index=hash(number);
	 	int count=0;
	 	while(collision[index]!=0)
	 	{
	 		if(table[index].phone_num==number)
	 	    {
	 	       	cout<<table[index].name<<"Record Found with "<<count<<" no. of collisions.";
	 	       	return true;
			}
			index=(index+1)%size;
			count++;
		}
		cout<<"\nRecord not found...";
		    return false;
	 }
	 
};
int main()
{
     HashTable ht;
     string name;
     int number;
     int ch;
     int method;
     
     while(ch!=3)
     {
     	cout<<"\n1.Insert\n2.Search\n3.Exit\n";
     	cout<<"\nEnter choice : ";
     	cin>>ch;
     	switch(ch)
     	{
     		case 1:cout<<"\nEnter name & Phone number : ";
     		       cin>>name>>number;
     		       cout<<"\n1.LinearProbing\n2.QuadraticProbing\n";
     		       cout<<"\nEnter choice : ";
     		       cin>>method;
     		       if(method==1)
     		          ht.linearprobing({name,number});
     		       else if(method==2)
     		          ht.qudraticprobing({name,number});
     		       else
     		          cout<<"\nEnter valid choice !!!";
     		       break;
     		case 2:cout<<"\nEnter number to search : ";
     		       cin>>number;
     		       ht.search(number);
     		       break;
     		case 3:cout<<"\nThanks for using !!!!";
     		       break;
     	    default:cout<<"\nInvalid Choice !! ";
     	            break;
		}
	 }
	 return 0;
}
