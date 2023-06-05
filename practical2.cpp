#include<iostream>
#include<list>
using namespace std;
class sets
{
	public:
		int key,flag;
		list<int> listA, listB , unionlist , intersectionlist ,differencelist ;
		list<int>::iterator itA, itB ,itunion , itintersection ,itdifference;
		
		void insert()
		{
			int m,n;
			cout<<"\nNo. of element in set A : ";
			cin>>n;
			for(int i=0;i<n;i++)
			{
				cin>>key;
				listA.push_back(key);
			}
			cout<<"\nNo. of element in set B : ";
			cin>>m;
			for(int i=0;i<m;i++)
			{
				cin>>key;
				listB.push_back(key);
			}  
		}
		void display()
		{
			cout<<"\nset A : ";
			for(itA=listA.begin();itA!=listA.end();itA++)
			{
				cout<<*itA<<"\t";
			}
			cout<<endl;
			cout<<"\nset B : ";
			for(itB=listB.begin();itB!=listB.end();itB++)
			{
				cout<<*itB<<"\t";
			}
			cout<<endl;
		}
		void add()
		{
			char ch;
			cout<<"\nAdd elements in set (A/B) ? : ";
			cin>>ch;
			if(ch=='A' || ch=='a')
			{
				cout<<"\nEnter element to insert :";
				cin>>key;
				listA.push_back(key);
				cout << "\nElement Inserted in set A\n";
			}
			else if(ch=='B' || ch=='b')
			{
				cout<<"\nEnter element to insert :";
				cin>>key;
				listB.push_back(key);
				cout << "\nElement Inserted in set B\n";
			}
			else 
                cout << "Invalid Set!!!";
		}
		void search(int key)
		{
			for(itA=listA.begin(),itB=listB.begin();itA!=listA.end(),itB!=listB.end();itA++,itB++)
			{
				if(*itA==key)
				{
					cout<<"\nElement Present in Set A ";
					flag=1;
					break;
				}
				if(*itB==key)
				{
					cout<<"\nElement Present in Set B ";
					flag=1;
					break;
				}
				else
				{
				    flag=0;	
				}	  
			}
			if(flag==0)
				cout << "The Element is not Present\n";
		
		}
		void remove(int key)
		{
			search(key);
            if(flag == 1) 
			{
               listA.remove(key);
               listB.remove(key);
               cout << "Element Deleted\n";
            } 
			else 
			   cout << "Element not Deleted\n";
		}
		void unionset()
		{
			unionlist = listA;
			unionlist.insert(unionlist.end(), listB.begin(), listB.end());
            unionlist.sort();
            unionlist.unique();
            cout<<"\nUnion of Set A & B  : ";
			for(itunion=unionlist.begin();itunion!=unionlist.end();itunion++)
			{
				cout<<"\t"<<*itunion;
			}
			cout<<endl;
	   	}
		void intersectionset()
		{
		        for (itA = listA.begin(); itA != listA.end(); itA++) 
				{
                    for (itB = listB.begin(); itB != listB.end(); itB++) 
					{
                        if (*itA == *itB) 
						{
                          intersectionlist.push_back(*itA);
                        }
                    }
                }
                cout<<"\nIntersection of Set A & B  : ";
			    for(itintersection=intersectionlist.begin();itintersection!=intersectionlist.end();itintersection++)
			    {
				   cout<<"\t"<<*itintersection;
			    }
			    cout<<endl;
		}
		void differenceset()
		{
			int flag = 0;
            for (itA = listA.begin(); itA != listA.end(); itA++) 
			{
                 for (itB = listB.begin(); itB != listB.end(); itB++) 
				 {
                     if (*itA == *itB) 
					 {
                        flag = 0;
                        break;
                     } 
					 else 
					 {
                        flag = 1;
                     }
                }
                if (flag == 1) 
				{
                    differencelist.push_back(*itA);
                }
           }
           if (differencelist.empty()) 
                   cout << "The Set A & Set B are Equal\n";
           else 
		   {
		   	    cout<<"\Difference of Set A & B  : ";
			    for(itdifference=differencelist.begin();itdifference!=differencelist.end();itdifference++)
			    {
				   cout<<"\t"<<*itdifference;
			    }
			    cout<<endl;
		   }
       }  
};
int main()
{
	sets s;
	int choice,key;
	
	s.insert();
	do
	{ 
	   cout<<"\n****MENU***";
	   cout<<"\n1.Add Element\n2.Remove Element\n3.Search Element\n4.Display\n5.Union\n6.Intersection\n7.Difference\n8.Exit";
	   cout<<"\nEnter choice : ";
	   cin>>choice;	
	   
	   switch(choice)
	   {
	   	    case 1:s.add();break;
	   	    case 2:cout<<"\nEnter element to Delete : ";
	   	           cin>>key;
			       s.remove(key);
				   break;
	   	    case 3:cout<<"\nEnter element to search : ";
	   	           cin>>key;
			       s.search(key);
				   break;
	   	    case 4:s.display();break;
	   	    case 5:s.unionset();break;
	   	    case 6:s.intersectionset();break;
	   	    case 7:s.differenceset();break;
	   	    case 8:cout<<"\nThanks for using !!!";break;
	   	    default:cout<<"\nEnter valid Choice !!!";break;         
	   }
	   
	}while(choice!=8);
	return 0;
}
