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
		friend class deque;
};

class deque
{
	node* front; 
    node* rear; 
    int size; 
  
public: 
    deque() 
    { 
        front = rear = NULL; 
        size = 0; 
    } 
   
    void enqueue_front(int data); 
    void enqueue_rear(int data); 
    void dequeue_front(); 
    void dequeue_rear(); 
    int frontel(); 
    int rearel();  
    bool isEmpty(); 
    void clear(); 
};

bool deque::isEmpty() 
{ 
    return (front == NULL); 
} 

void deque::enqueue_front(int data) 
{ 
    node* temp;
	temp->val=data; 
    if (temp == NULL) 
        cout << "OverFlow\n"; 
    else 
    { 
        if (front == NULL) 
            {rear = temp;
			front = temp;}   
        else 
        { 
            temp->next = front; 
            front->prev = temp; 
            front = temp; 
        }  
        size++; 
    } 
} 

void deque::enqueue_rear(int data) 
{ 
    node* temp;
	temp->val=data; 
    
    if (temp == NULL) 
        cout << "OverFlow\n"; 
    else 
    {  
        if (rear == NULL) 
            {rear = temp;
			front = temp;}  
        else 
        { 
            temp->prev = rear; 
            rear->next = temp; 
            rear = temp; 
        }   
        size++; 
    } 
} 
 
void deque::dequeue_front() 
{ 
    
    if (isEmpty()) 
        cout << "UnderFlow\n"; 
   
    else 
    { 
        node* temp = front; 
        front = front->next; 
   
        if (front == NULL) 
            rear = NULL; 
        else
            front->prev = NULL; 
            
        delete temp; 
  
        size--; 
    } 
}  

void deque::dequeue_rear() 
{ 
    
    if (isEmpty()) 
        cout << "UnderFlow\n"; 

    else 
    { 
        node* temp = rear; 
        rear = rear->prev; 
   
        if (rear == NULL) 
            front = NULL; 
        else
            rear->next = NULL; 
        delete temp; 
  
        size--; 
    } 
} 

int deque::frontel() 
{ 
    if (isEmpty()) 
        return -1; 
    return front->val; 
} 
   
int deque::rearel() 
{ 
    
    if (isEmpty()) 
        return -1; 
    return rear->val; 
} 

void deque::clear() 
{ 
    rear = NULL; 
    while (front != NULL)  
    { 
        node* temp = front; 
        front = front->next; 
        delete temp; 
    } 
    size = 0; 
} 

int main()
{
	deque obj;
	int x;
	
	cout<<"\n1: INSERT AT FRONT";
	cout<<"\n2: INSERT AT END";
	cout<<"\n3: DELETE FROM FRONT";
	cout<<"\n4: DELETE FROM END";
	cout<<"\n5: GET THE FRONT ELEMENT";
	cout<<"\n6: GET THE REAR ELEMENT";
	cout<<"\n7: CLEAR";
	cout<<"\n8: EXIT";
	
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
				obj.enqueue_front(x);
//				cout<<"STATUS OF LIST 1 : ";
//				ob1.print();
				break;
				
			case 2:
				cout<<"ENTER THE ELEMENT YOU WANT TO INSERT AT REAR : ";
				cin>>x;
				obj.enqueue_rear(x);
//				cout<<"STATUS OF LIST 1 : ";
//				ob1.print();
				break;
				
			case 3:
				cout<<"DELETING FROM FRONT...";
				obj.dequeue_front();
//				cout<<"STATUS OF LIST 1 : ";
//				ob1.print();
				break;
				
			case 4:
			cout<<"DELETING FROM REAR...";
				obj.dequeue_rear();
//				cout<<"STATUS OF LIST 1 : ";
//				ob1.print();
				break;
				
			case 5:
				cout<<"ELEMENT AT FRONT : ";
				cout<<obj.frontel();
//				cout<<"STATUS OF LIST 1 : ";
//				ob1.print();
				break;	
			
			case 6:
				cout<<"ELEMENT AT REAR : ";
				cout<<obj.rearel();
//				cout<<"STATUS OF LIST 1 : ";
//				ob1.print();
				break;	
			
				
			case 7:
				cout<<"CLEARING... : ";
				obj.clear();
				break;
				
				
			case 8:
				cout<<"\nEXIT..";
		        exit(0); 
		        break;				
		}
		cout<<"DO YOU WANT TO CONTINUE [Y/N] : ";
		cin>>ch;
	}
	while(ch == 'Y' || ch == 'y');
}
   
