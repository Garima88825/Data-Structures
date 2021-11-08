#include<iostream>
using namespace std;

class queue
{
	private:
		int *ar;
		int size;
		int front;
		int rear;
		
	public:
		queue(int n)
		{
			size=n;
			ar=new int[size];
			front=-1;
			rear=-1;
		}
		void enqueue(int);
		int dequeue();
		int current_size();
		bool isEmpty();
		bool isFull();
		int frontEl();
		void clear();
		void display();
};

bool queue::isEmpty()
{
	return (front == -1 && rear == -1);
}

bool queue::isFull()
{
	return (front == (rear+1)%size);
}

void queue::enqueue(int val)
{
	if( !isFull() )
	{
		cout<<" ADDING..\n";
		if( isEmpty() )
		{
			front++;
			rear++;
			ar[rear]=val;
		}
		else
		{
			rear=(rear+1)%size;
			ar[rear]=val;	
	    //rear++;	
		//ar[(rear)%size]=val;
		
		}
	}
	else
		cout<<" QUEUE OVERFLOW..";
}

int queue::dequeue()
{
	if( isEmpty() )
		cout<<" QUEUE UNDERFLOW..";
	else
	{
		cout<<" REMOVING..";
		int x;
		if(front == rear)
		{
			x=ar[front];
			front=-1;
			rear=-1;
		}
		else
		{
			x=ar[front];
			front=(front+1)%size;
		}
	return x;
	}	
}

int queue::current_size()
{
	if(front>rear)
		return (size-front+rear-1);
	else
		return (rear-front+1);
}

void queue::clear()
{
	front=-1;
	rear=-1;
}

int queue::frontEl()
{
	if( !isEmpty() )
		return ar[front];
	else
		return -1;
}

void queue::display()
{
	cout<<" THE STATUS OF QUEUE : ";
	if(front>rear)
	{
		for(int i=front;i<size;i++)
			cout<<ar[i]<<" ";
		for(int i=0;i<=rear;i++)
			cout<<ar[i]<<" ";	
		cout<<endl;	
	}
	else
	{
		for(int i=front;i<=rear;i++)
			cout<<ar[i]<<" ";
		cout<<endl;
	}

//	for(int i=front;i<=(rear%size);i++)
//			cout<<ar[i]<<endl;	
}

int main()
{
	int s;
	cout<<" ENTER THE SIZE OF ARRAY : ";
	cin>>s;
	queue q1(s);
	int x;
	
	cout<<"\n 1 : ENQUEUE";
	cout<<"\n 2 : DEQUEUE";
	cout<<"\n 3 : CHECK IF THE QUEUE IS EMPTY";
	cout<<"\n 4 : CHECK IF THE QUEUE IS FULL";
	cout<<"\n 5 : GET THE FRONT ELEMENT OF THE QUEUE";
	cout<<"\n 6 : GET THE SIZE OF THE QUEUE";
	cout<<"\n 7 : CLEAR THE QUEUE";
	cout<<"\n 8 : DISPLAY THE QUEUE";
	cout<<"\n 9 : EXIT\n";
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
			if ( q1.isFull() )
				cout<<" YES ! THE QUEUE IS FULL\n";
			else
				cout<<" NO ! THE QUEUE IS NOT FULL\n";
			break;
			
		case 5:
			if( q1.frontEl() == -1)
				cout<<" SORRY ! THE QUEUE IS EMPTY\n";
			else
				cout<<" THE FRONT ELEMENT IN THE QUEUE : "<<q1.frontEl();					
			break;
		case 6:
			cout<<" THE CURRENT SIZE OF THE QUEUE : "<<q1.current_size();
			break;
				
		case 7:
			cout<<" CLEARING..\n";
			q1.clear();
			break;
		
		case 8:
			q1.display();
			break;
		
		case 9:
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
	












