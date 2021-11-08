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
			return;
		}
		friend class stack;
};

class stack
{
	private:
		node* top;
	
	public:
		stack()
		{
			top=NULL;
		}
		void push(int);
		int pop();
		bool isEmpty();
		int topEl();
		void clear();
		void display();
};

void stack::push(int a)
{
	 
    node* temp = new node();  
   
    if (!temp) 
    {  
        cout << "\n OVERFLOW";    
    }  
    
	temp->val = a;  
    
    temp->next = top;  

    top = temp; 
}

int stack::pop()
{
	node* temp;  
    
    if (isEmpty())  
    {  
        cout << "\n UNDERFLOW" << endl;    
    }  
    else
    {    
        temp = top;  
    
        top = top->next;  
   
        temp->next = NULL;  
        delete temp;  
    }  
}

bool stack::isEmpty()
{
	return top == NULL; 
}

int stack::topEl()
{
	if(isEmpty())
	{
		return -1;
	}
	return top->val;
}

void stack::clear()
{
	node* current=top;
	while(current != 0)
	{
		node* next=current->next;
		delete current;
		current=next;
	}
	top=NULL;
}

void stack::display()
{
	node* temp = top;  
        while (temp) 
        {   
            cout << temp->val << " ";   
            temp = temp->next;  
        }  
}

int main()
{
	int s;
	stack s1;
	int x;
	
	cout<<"\n 1 : PUSH AN ELEMENT IN THE STACK";
	cout<<"\n 2 : POP OUT AN ELEMENT FROM THE STACK";
	cout<<"\n 3 : CHECK IF THE STACK IS EMPTY";
	cout<<"\n 4 : GET THE TOPMOST ELEMENT OF THE STACK";
	cout<<"\n 5 : CLEAR THE STACK";
	cout<<"\n 6 : DISPLAY";
	cout<<"\n 7 : EXIT\n";
	int choice;
	char ch;
	do{
	cout<<" ENTER YOUR CHOICE : ";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			cout<<" ENTER THE ELEMENT YOU WANT TO PUSH : ";
			cin>>x;
			cout<<" PUSHING..\n";			
			s1.push(x);
			break;
		
		case 2:
			s1.pop();
			break;
		
		case 3:
			if ( s1.isEmpty() )
				cout<<" YES ! THE STACK IS EMPTY\n";
			else
				cout<<" NO ! THE STACK IS NOT EMPTY\n";
			break;
		
//		case 4:
//			if ( s1.isFull() )
//				cout<<" YES ! THE STACK IS FULL\n";
//			else
//				cout<<" NO ! THE STACK IS NOT FULL\n";
//			break;
			
		case 4:
			if( s1.topEl() == -1)
				cout<<" SORRY ! THE STACK IS EMPTY\n";
			else
				cout<<" THE TOPMOST ELEMENT IN THE STACK : "<<s1.topEl();					
			break;
			
		case 5:
			cout<<" CLEARING..\n";
			s1.clear();
			break;
		
		case 6:
			s1.display();
			break;
		
		case 7:
			cout<<" EXITING...\n";
			exit(0);
			break;
		
		default:
			cout<<" WRONG CHOICE\n";
	}
	cout<<"\n WANT TO IMPLEMENT MORE OPERATION ?(Y/N) : ";
	cin>>ch;
    }while(ch=='Y' || ch=='y');
	
	return 0;		
}
