#include<iostream>
using namespace std;

class node
{
	int val;
	node* next;
	
	public:
		node(int a=0,node* ptr=0)
		{
			val=a;
			next=ptr;
		}
		
		friend class queue;
};

class queue
{
	node* tail;
	
	public:
		queue()
		{
			tail=0;			
		}
//		queue(node* ptr=0)
//		{
//			tail=ptr;
//		}
		~queue()
		{
			node* curr=tail->next;
        	node* temp;
        	do{
        		temp = curr;
				delete temp;
				curr = curr->next;        		
			}while(curr!=tail->next);
			tail = 0;			
		}
		
		void enqueue(int a);
		void dequeue();
		int frontEl();
		bool isEmpty();
		void clear();
		void print();	
};

void queue::enqueue(int a)
{
	if(tail)
	{
		tail = tail->next=new node(a,tail->next);
		return;
	}
	tail = new node(a,0);
	tail->next=tail;
}

void queue::dequeue()
{
	if(tail)
	{
		node* curr=tail->next;
		//int a = curr->val;
		if(curr==tail)
		{
			tail=0;			
		}
		else
		{
		    tail->next=curr->next;
		}
		delete curr;
	
	}
	else
		cout<<"\n UNDERFLOW\n";	
}

int queue::frontEl()
{
	if(isEmpty())
		return -1;
	
	return tail->next->val;
}

bool queue::isEmpty()
{
	return !tail;
}

void queue::clear()
{
	node* current=tail->next;
	if(tail)
	{
	while(tail->next!=tail)
	{
		tail->next=current->next;
		delete current;
		current=tail->next;
	}
	delete tail;
	tail=0;
	}
}

void queue::print()
{
	if(tail)	
	{
		node* curr = tail->next;
		do{
			cout<<curr->val<<" ";
			curr=curr->next;
		}
		while(curr!=tail->next);
		cout<<endl;
	}
	return;
}

int main()
{
	queue q1;
	int x;
	
	cout<<"\n 1 : ENQUEUE";
	cout<<"\n 2 : DEQUEUE";
	cout<<"\n 3 : CHECK IF THE QUEUE IS EMPTY";
	cout<<"\n 4 : GET THE FRONT ELEMENT OF THE QUEUE";
	cout<<"\n 5 : CLEAR THE QUEUE";
	cout<<"\n 6 : DISPLAY THE QUEUE";
	cout<<"\n 7 : EXIT\n";
	int choice;
	char ch;
	do{
	cout<<" ENTER YOUR CHOICE : ";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			cout<<" ENTER THE ELEMENT YOU WANT TO ENQUEUE : ";
			cin>>x;						
			q1.enqueue(x);
			break;
		
		case 2:
			q1.dequeue();
			break;
		
		case 3:
			if ( q1.isEmpty() )
				cout<<" YES ! THE QUEUE IS EMPTY\n";
			else
				cout<<" NO ! THE QUEUE IS NOT EMPTY\n";
			break;
			
		case 4:
			if( q1.frontEl() == -1)
				cout<<" SORRY ! THE QUEUE IS EMPTY\n";
			else
				cout<<" THE FRONT ELEMENT IN THE QUEUE : "<<q1.frontEl();					
			break;
			
		case 5:
			cout<<" CLEARING..\n";
			q1.clear();
			break;
			
		case 6:
			cout<<" THE QUEUE : ";
			q1.print();			
			break;
		
		case 7:
			cout<<" EXITING...\n";
			exit(0);
			break;
			
	}
	cout<<"\n WANT TO IMPLEMENT MORE OPERATION ?(Y/N) : ";
	cin>>ch;
    }while(ch=='Y' || ch=='y');
}
