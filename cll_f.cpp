#include<iostream>
using namespace std;
class node{
	
	node *next;
	int value;
	
	node()
	{
		next=0;
		value=0;		
	}
	node(node *ptr,int x)
	{
		next=ptr;
		value=x;
	}
	
	friend class CLL;
};
class CLL{
	node *tail;
	public:
	CLL()
	{
		tail=0;
	}
	CLL(node *a,int b)
	{
		tail->next=a;
		tail->value=b;
	}
	~CLL()
	{
		node *current=tail;
		if(current)
		{
			node *ptr=current->next;
			while(ptr!=tail)
			{
				current=ptr;
				ptr=ptr->next;
				delete current;	
			}
			delete tail;  
			tail=0;
		}
	}	
	
	void insertatfront(int);
	void insertafterel(int,int); 
	void insertatend(int);        
	void delfromend();      
	void removefromfront(); 
	void removeele(int);  
	node* searchel(int);  
	void concatenate(CLL &c);
	void display();
};


//display the list
void CLL::display()
{
		if(tail)
		{
			node *current=tail->next;
			while(current!=tail)
			{
				cout<<current->value<<" , ";
				current=current->next;
			}
			cout<<current->value<<endl;
		}
		else
			cout<<"The list is empty\n";
	
}

//insert at front
void CLL::insertatfront(int el)
{               
	if(tail==0)
	{
		tail=new node();
		tail->next=tail;
		tail->value=el;
	}
	else
	{
		node *New=new node(tail->next,el);
		tail->next=New;
	}
}

//insert after an element
void CLL::insertafterel(int el,int ins)
{
	node *New=searchel(el);
	if(New!=tail)
	{
		node *a=new node(New->next,ins);
		New->next=a;	
	}
	else
	{
		node *a=new node(New->next,ins);
		New->next=a;
		tail=a;		
	}
}

//insert at end
void CLL::insertatend(int el)
{
	if(tail)
	{
		tail = tail->next=new node(tail->next,el);
		return;
	}
	tail = new node(0,el);
	tail->next=tail;
}

//remove from front
void CLL::removefromfront()
{
	node *current=tail->next;
	tail->next=tail->next->next;
	delete current;
}

//remove from end
void CLL::delfromend()
{
	node *current=tail->next;
	while(current->next!=tail)
	{
		current=current->next;		
	}	
	current->next=current->next->next;
	delete tail;
	tail=current;
}

//remove an element
void CLL::removeele(int el)
{
	node *temp=tail->next;
	node *current=searchel(el);
	while(temp->next!=current)
	{
		temp=temp->next;
	}
	temp->next=current->next;
	delete current;
}

//search an element
node* CLL::searchel(int el)
{
	
	int flag=0;
	node *current=tail->next;
	for(;current->value!=el;current=current->next)
	{
		if(current==tail)
		{
			flag=1;
			break;
		}
	}
	if(flag)
		return 0;
	return current;
}

//concatenate the list
void CLL::concatenate(CLL &c)
{
	node* curr=tail->next;
	tail->next=c.tail->next;
	c.tail->next=curr;
	tail=c.tail;
	c.tail=0;	
}

//main function
int main()
{
	node *ptr;
	int choice;
	CLL l1;
	CLL l2;
	int x;
	int data1;
	int pos;
		cout<<"1.INSERT ELEMENT AT FRONT\n";
		cout<<"2.INSERT AFTER\n";
		cout<<"3.INSERT ELEMENT AT BACK\n";
		cout<<"4.REMOVE FROM FRONT\n";
		cout<<"5.REMOVE AT\n";
		cout<<"6.REMOVE FROM BACK\n";
		cout<<"7.SEARCH\n";
		cout<<"8.CONCATENATE\n";
		cout<<"9.EXIT\n";
		char ch;
	do
	{
		cout<<"\nENTER YOUR CHOICE : ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"ENTER THE ELEMENT YOU WANT TO ADD AT FRONT : ";
				cin>>x;
				l1.insertatfront(x);
				cout<<"INSERTING...\n";
				break;
				
			case 2:				
				cout<<"ENTER THE ELEMENT AND POSITION AFTER WHICH YOU WANT TO INSERT : ";
				cin>>x>>pos;		
				l1.insertafterel(pos,x);
				cout<<"INSERTING...\n";
				break;
				
			case 3:
				cout<<"ENTER THE ELEMENT YOU WANT TO ADD AT BACK : ";
				cin>>x;
				l1.insertatend(x);
				cout<<"INSERTING...\n";
				break;
				
			case 4:
				l1.removefromfront();
				cout<<"REMOVING...\n";
				break;
			
			case 5:
				cout<<"ENTER THE POSITION OF ELEMENT YOU WANT TO REMOVE : ";
				cin>>pos;
				l1.removeele(pos);
				cout<<"REMOVING...\n";
				break;
			
			case 6:
				l1.delfromend();
				cout<<"REMOVING...\n";
				break;
				
			case 7:
				
				cout<<"ENTER THE ELEMENT TO SEARCH : \n";
				cin>>x;
				ptr = l1.searchel(x);
				if(ptr!=0)
					cout<<"FOUND !!\n";
				else
					cout<<"NOT FOUND !!\n";
				break;                   
				
			case 8:
				cout<<"ENTER THE NUMBER OF ELEMENTS YOU WANT IN LIST 2 : ";
				cin>>x;
				
	            for(int i=1;i<=x;i++)
	            {
		          cout<<"\nENTER ELEMENT "<<i<<" : ";
		          cin>>data1;
		          l2.insertatend(data1);
            	}
				l1.concatenate(l2);
				l1.display();
				break;
				
			case 9:
				cout<<"EXITING...";
				exit(0);
				break;
			
		}
		cout<<"\nPRESS Y TO CONTINUE : ";
    	cin>>ch;
 		}
		while(ch=='y'||ch=='Y');	
}
				
			
			
		
