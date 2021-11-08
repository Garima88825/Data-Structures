#include<iostream>
using namespace std;
class sll;
class node
{
		int data;
		node* next;
	public:
//		int data;
//		node* next;
		node(int a=0,node* ptr=0)
		{
			data=a;
			next=ptr;			
		}
	friend class sll;
};
class sll
{
	private:
	    node* head;
	public:
		sll();
		~sll();
		void addfront(int val);
		void insertat(int val,int pos);
		void insertend(int val);
		void removefront();
		void removeat(int pos);
		node* search(int x);
		void concate(sll &a, sll &b);
		void print();
	   		
};

sll::sll()
{
	head=0;
}
sll::~sll()
{
	node* current=head;
	while(current != 0)
	{
		node* next=current->next;
		delete current;
		current=next;
	}
	head=0;
}
void sll::addfront(int val)
{
	head=new node(val,head);
}
void sll::insertat(int pos,int val)
{
	if(pos == 1)
		addfront(val);
	else{
	if(head)
	{
		node* current=head;
		int count=1;
		for( ;current != 0 && count < pos-1;current = current->next,count++); 
		
		if(current)
		{
			current->next=new node(val,current->next);
		}
		else
		{
			insertend(val);	
		}
	}
}
}
void sll::insertend(int val)
{
	if(head)
	{
		node* current;
		for(current=head; current->next != 0; current=current->next);
		
		current->next=new node(val,0);
	}
	else
		head=new node(val,0);
}
void sll::removefront()
{
	if(head)
	{
		node* temp=head;
		head=head->next;
		delete temp;
	}
}
		
void sll::removeat(int pos)
{
	int counter=0;
	node* ptr;
	if(head==0)
	{
		cout<<"\nList is empty"<<endl;
	}
	node* temp=head;
	if(pos==1)
	{
		head=temp->next;
	}
	else
	{
		while(temp!=0)
		{
			temp=temp->next;
			counter++;
		}
		if(pos>0 &&pos<=counter)
		{
			temp=head;
			for(int i=1;i<pos;i++)
			{
				ptr=temp;
				temp=temp->next;
			}
			ptr->next=temp->next;
			cout<<"\nElement deleted"<<endl;
		}
	
		else
		{
			cout<<"Position out of range "<<endl;
		}
	}
		delete(temp);
		
}

node* sll::search(int val)
{
  int index=0;
    node* current=head;

    while (current != 0 && current->data != val)
    {
        index++;
        current = current->next;
    }

    return (current != 0) ? current : NULL;
}

void sll::concate(sll &a ,sll &b)
{
	node* temp;
	temp=a.head;
	while(temp!=0)
	{
		int x= temp->data;
		//addfront(data);
		insertend(x);
		temp=temp->next;
	}
	temp=b.head;
	while(temp!=0)
	{
		int x=temp->data;
		//addfront(data);
		insertend(x);
		temp=temp->next;
	}
}



void sll::print()
{
	node* temp= head;
	while(temp!=0)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
int main()
{
	sll a;
	sll b;
	sll result;
//	cout<<"\nEnter no of elements you want to enter to List 1:";
//	int n;
//	cin>>n;int data;
//	for(int i=1;i<=n;i++)
//	{
//		cout<<"\nEnter element "<<i<<" : ";
//		cin>>data;
//		a.insertend(data);
//	}
//	cout<<"\nList 1: ";
//	a.print();

	cout<<"\n\nMenu\n1.addfront\n2.insertat\n3.removefront\n4.removeat\n5.search\n6.concatenate\n7.Exit\n";
	char ch;
	do
	{
	
	cout<<"\nEnter your choice: ";
	 int choice;
	cin>>choice;
	switch(choice)
	{
		case 1: cout<<"\nADD FRONT";
		       int x,y;
		       cout<<"\nEnter data you want to add in front of list 1: ";
		       cin>>x;
		       a.addfront(x);
		       cout<<"List 1 after adding new element: ";
		       a.print();
		        
		       
		break;       
		case 2: cout<<"\nINSERT AT";
		        int pos,data;
	        	cout<<"\nEnter the position where you want to insert in list 1 and data you want to enter: ";
	        	cin>>pos>>data;
	        	a.insertat(pos,data);
	        	cout<<"New list 1: ";
	        	a.print();
	       	 	
	    break;
	    
	    case 3:cout<<"\nREMOVE FRONT"; 
	           a.removefront() ;
	           cout<<"\nAfter removing front in list 1 :";
	           a.print();
	          
	     break;
		 case 4: cout<<"\nREMOVE AT";
		         cout<<"\nEnter the position you want to remove from list 1: ";
		         int p;
		         cin>>p;
		         a.removeat(p);
              	cout<<"\nList 1 after removing element at index "<<p<<" : ";
             	a.print();
             	
		 break;   
		 case 5: cout<<"\nSEARCH\n";
		         int m;
	            cout<<"Enter element you want to search in list 1 : ";
	            cin>>m;
             	if(a.search(m) == NULL)
				    cout<<"ELEMENT NOT FOUND !";
				else
					cout<<"ELEMENT FOUND ! \n";
             	
         break;
         case 6: cout<<"\nCONCATENATE";
                 cout<<"Enter no of elements you want to enter to List 2 : ";
                 int z;
	             cin>>z;int data1;
	            for(int i=1;i<=z;i++)
	            {
		          cout<<"\nEnter element "<<i<<" : ";
		          cin>>data1;
		          b.insertend(data1);
            	}
            	cout<<endl<<"\nList 2: ";
            	b.print();
		         result.concate(a,b);
		         cout<<"\nConcatenated list: ";
		         result.print();
				 	
		  break;
		  case 7: cout<<"\nEXIT";
		         exit(0);                
	}
     
     cout<<"\nPress y to continue: ";
     cin>>ch;
 }while(ch=='y'||ch=='Y');
}
	
	
	

