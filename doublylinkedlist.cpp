#include<iostream>
using namespace std;

class node
{
	node* prev;
	int val;
	node* next;
	
	public:
		node(node* ptr=0,int a=0,node* ptr1=0)
		{
			prev=ptr;
			val=a;
			next=ptr1;
			return;
		}
		friend class DLL;
};

class DLL
{
	node* head;
	node* tail;
	
	public:
		DLL()
		{
			head = new node(0,0,tail);
			tail= new node(head,0,0);
			head->next = tail;
			return;
		}
		~DLL();
		bool empty() const;
		void add(node* ptr,int a);
		void insertathead(int a);
		void insertatpos(int a,int pos);
		void insertattail(int a);
		int remove(node* ptr);
		int removefromhead();
		int removefrompos(int pos);
		int removefromtail();
		int removenode(int a);
		node* search(int a);
		void concatenate(DLL& ob1,DLL& ob2);
		void print();
};
bool DLL::empty() const
{
	return(head->next == tail); //is list empty?
}
DLL::~DLL(){ //destructor
	while(!empty()) removefromhead(); //remove all but sentinels
	delete head; //remove the sentinels
	delete tail; 
}

void DLL::add(node* ptr,int a)
{
	node* current=ptr->prev;
	current->next=ptr->prev=new node(current,a,ptr);
	return;
}

void DLL::insertathead(int a)
{
	add(head->next,a);
	return;
}

void DLL::insertatpos(int a,int pos)
{
	node* current = head->next;
	for(int i=1;current!=tail&&i<pos;i++)
	{
		current=current->next;
	}
	add(current,a);
	return;
}

void DLL::insertattail(int a)
{
	add(tail,a);
	return;
}

int DLL::remove(node* ptr)
{
	node* current=ptr->prev;
	ptr->next->prev=current;
	current->next=ptr->next;
	int temp=ptr->val;
	delete ptr;
	return temp;
}

int DLL::removefromhead()
{
	if(head->next!=tail)
	{
		cout<<"DELETING FROM FRONT...\n";
		return remove(head->next);
	}
	cout<<"LIST IS EMPTY !!\n";
	return -1;
	
}

int DLL::removefrompos(int pos)
{
	if(head->next!=tail)
	{
		node*current = head->next;
		int i=1;
		for(;current->next!=tail&&i<pos;i++,current=current->next);
		if(i==pos)
		{
			cout<<"REMOVING...\n";
			return remove(current);
		}
	}
	cout<<"EITHER THE LIST IS EMPTY OR YOU HAVE ENTERED THE POSITION WHICH IS OUT OF RANGE !!\n";
	return -1;	
}

int DLL::removefromtail()
{
	if(head->next!=tail)
	{
		cout<<"DELETING FROM END...\n";
		return remove(tail->prev);
	}
	cout<<"LIST IS EMPTY !!\n";
	return -1;
}

int DLL::removenode(int a)
{
	if(search(a)->next!=0)
	{
		return(remove(search(a)));
	}
	return -1;	
}

node* DLL::search(int a)
{
	node* current=head->next;
	while(current!=tail)
	{
		if(current->val==a)
		{
			return current;
		}
		current=current->next;
	}
	return NULL;
}

void DLL::concatenate(DLL& a,DLL& b)
{
node* temp;
	temp=a.head->next;
	while(temp->next != 0)
	{
		int x= temp->val;
		//addfront(data);
		insertattail(x);
		temp=temp->next;
	}
	temp=b.head->next;
	while(temp->next != 0)
	{
		int x=temp->val;
		//addfront(data);
		insertattail(x);
		temp=temp->next;
	}
	return;
}

void DLL::print()
{
	if(head->next!=tail)
	{
		node* current=head->next;
		while(current!=tail)
		{
			cout<<current->val<<" ";
			current=current->next;
		}
		cout<<endl;
	}
	return;
}

int main()
{
	DLL ob1;
	DLL ob2;
	DLL res;
	int x;
	int z;
	int pos;
	cout<<"\n1: INSERT AT FRONT";
	cout<<"\n2: INSERT AT POSITION";
	cout<<"\n3: INSERT AT END";
	cout<<"\n4: DELETE FROM FRONT";
	cout<<"\n5: DELETE AT POSITION";
	cout<<"\n6: DELETE FROM END";
	cout<<"\n7: SEARCH AN ELEMENT";
	cout<<"\n8: CONCATENATE";
	cout<<"\n9: EXIT";
	
	int choice;
	char ch;
	do
	{
		cout<<"\nENTER YOUR CHOICE : ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				cout<<"ENTER THE ELEMENT YOU WANT TO INSERT AT FRONT : ";
				cin>>x;
				ob1.insertathead(x);
				cout<<"STATUS OF LIST 1 : ";
				ob1.print();
				break;
				
			case 2:
				cout<<"ENTER THE ELEMENT AND THE POSITION : ";
				cin>>x>>pos;
				ob1.insertatpos(x,pos);
				cout<<"STATUS OF LIST 1 : ";
				ob1.print();
				break;
				
			case 3:
				cout<<"ENTER THE ELEMENT YOU WANT TO INSERT AT END : ";
				cin>>x;
				ob1.insertattail(x);
				cout<<"STATUS OF LIST 1 : ";
				ob1.print();
				break;
				
			case 4:
			//	cout<<"DELETING FROM FRONT...";
				ob1.removefromhead();
				cout<<"STATUS OF LIST 1 : ";
				ob1.print();
				break;
				
			case 5:
				cout<<"ENTER THE POSITION WHERE YOU WANT TO DELETE THE ELEMENT : ";
				cin>>pos;
				ob1.removefrompos(pos);
				cout<<"STATUS OF LIST 1 : ";
				ob1.print();
				break;	
			
			case 6:
			//	cout<<"DELETING FROM END...";
				ob1.removefromtail();
				cout<<"STATUS OF LIST 1 : ";
				ob1.print();
				break;	
				
			case 7:
				cout<<"ENTER THE ELEMENT YOU WANT TO SEARCH IN THE LIST : ";
				cin>>x;
				if(ob1.search(x) == NULL)
					cout<<"SEARCHING...NOT FOUND !!\n";
				else
					cout<<"SEARCHING...FOUND !!\n";
				
				break;
				
			case 8:
				cout<<"CONCATENATE \nENTER THE NUMBER OF ELEMENTS YOU WANT TO ENTER IN LIST 2 : ";
	            cin>>z;
	            cout<<endl;
	            for(int i=1;i<=z;i++)
	            {
		          cout<<"ENTER ELEMENT "<<i<<" : ";
		          cin>>x;
		          ob2.insertattail(x);
            	}
            	cout<<endl<<"\nLIST 2 : ";
            	ob2.print();
            	res.concatenate(ob1,ob2);	
			//	concatenate(ob2);	        
		        cout<<"\nCONCATENATED LIST : ";
		        res.print();
		    //    ob1.print();
		        break;
				
			case 9:
				cout<<"\nEXIT..";
		        exit(0); 
		        break;				
		}
		cout<<"DO YOU WANT TO CONTINUE [Y/N] : ";
		cin>>ch;
	}
	while(ch == 'Y' || ch == 'y');
}
