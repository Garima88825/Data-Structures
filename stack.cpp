#include<iostream>
#include<stdlib.h>
using namespace std;

class stack
{
	private:
		int top;
		int *ar;
		int size;
	
	public:
		stack(int n)
		{
			size=n;
			ar=new int[size];
			top=-1;
		}
		void push(int);
		int pop();
		bool isEmpty();
		bool isFull();
		int topEl();
		void clear();
		void display();
};
//checking if the stack is empty
bool stack::isEmpty()
{
	return (top == -1);
}
//checking if the stack is full
bool stack::isFull()
{
	return (top == size-1);
}
//pushing an element in the stack
void stack::push(int val)
{
	if( isFull() )
	{
		cout<<" STACK OVERFLOW";
		return;
	}
	ar[++top]=val;
}
//popping out an element from the stack 
int stack::pop()
{
	if( isEmpty() )
	{
		cout<<" STACK UNDERFLOW";
		return -1;
	}
	cout<<" POPPING..\n";
	return ar[top--];
}
//returning the topmost element of the stack
int stack::topEl()
{
	if( !isEmpty() )
		return ar[top];
	else
		return -1;
}
//clearing the stack
void stack::clear()
{
	top = -1;
}
//displaying the stack
void stack::display()
{
	cout<<" STACK\n";
	for(int i=top;i>=0;i--)
	{
		cout<<ar[i]<<endl;
	}
}
//main function
int main()
{
	int s;
	cout<<" ENTER THE SIZE OF THE ARRAY : ";
	cin>>s;
	stack s1(s);
	int x;
	
	cout<<"\n 1 : PUSH AN ELEMENT IN THE STACK";
	cout<<"\n 2 : POP OUT AN ELEMENT FROM THE STACK";
	cout<<"\n 3 : CHECK IF THE STACK IS EMPTY";
	cout<<"\n 4 : CHECK IF THE STACK IS FULL";
	cout<<"\n 5 : GET THE TOPMOST ELEMENT OF THE STACK";
	cout<<"\n 6 : CLEAR THE STACK";
	cout<<"\n 7 : DISPLAY THE STACK";
	cout<<"\n 8 : EXIT\n";
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
		
		case 4:
			if ( s1.isFull() )
				cout<<" YES ! THE STACK IS FULL\n";
			else
				cout<<" NO ! THE STACK IS NOT FULL\n";
			break;
			
		case 5:
			if( s1.topEl() == -1)
				cout<<" SORRY ! THE STACK IS EMPTY\n";
			else
				cout<<" THE TOPMOST ELEMENT IN THE STACK : "<<s1.topEl();					
			break;
			
		case 6:
			cout<<" CLEARING..\n";
			s1.clear();
			break;
		
		case 7:
			s1.display();
			break;
		
		case 8:
			cout<<" EXITING...\n";
			exit(0);
			break;
		
		default:
			cout<<" WRONG CHOICE\n";
	}
	cout<<"\n WANT TO IMPLEMENT MORE OPERATION ?(Y/N) : ";
	cin>>ch;
    }while(ch=='Y' || ch=='y');					
}
