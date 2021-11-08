#include <iostream>  
using namespace std; 
  
class Node  
{ 
    int data; 
    Node *prev, *next; 
     
    Node(){
			next = 0;
			prev = 0;
			data = 0;
		}
    Node(int elem=0)
		{
			prev = NULL;
			data = elem;
			next = NULL;
		}
    
    friend class Deque;
}; 
   
class Deque  
{ 
    Node* front; 
    Node* rear; 
 
  
public: 
    Deque() 
    { 
        front = rear = NULL; 
        
    } 
  
    // Operations on Deque 
    void insertFront(int data); 
    void insertRear(int data); 
    void deleteFront(); 
    void deleteRear(); 
    int getFront(); 
    int getRear(); 
    bool isEmpty(); 
    void clear(); 
}; 
   
bool Deque::isEmpty() 
{ 
    return (front == NULL); 
} 
    
void Deque::insertFront(int data) 
{ 
    Node* newNode = new Node(data); 
    
            
        if (front == NULL) 
            rear = front = newNode; 
  
        else 
        { 
            newNode->next = front; 
            front->prev = newNode; 
            front = newNode; 
        }     
        
    
} 
  
void Deque::insertRear(int data) 
{ 
    Node* newNode = new Node(data); 
    
    
        // If deque is empty 
        if (rear == NULL) 
            front = rear = newNode; 
   
        else 
        { 
            newNode->prev = rear; 
            rear->next = newNode; 
            rear = newNode; 
        } 
  
         
     
} 
  
void Deque::deleteFront() 
{ 
    if (isEmpty()) 
        cout << "\nUNDERFLOW"; 
  
    else 
    { 
        Node* temp = front; 
        front = front->next; 
   
        if (front == NULL) 
            rear = NULL; 
        else
            front->prev = NULL; 
        free(temp);
         
    } 
} 
  
void Deque::deleteRear() 
{  
    if (isEmpty()) 
        cout << "\nUNDERFLOW"; 
   
    else 
    { 
        Node* temp = rear; 
        rear = rear->prev; 
   
        if (rear == NULL) 
            front = NULL; 
        else
            rear->next = NULL; 
        free(temp); 
   
        
    } 
} 

int Deque::getFront() 
{ 
    if (isEmpty()) 
        return -1; 
    return front->data; 
} 
   
int Deque::getRear() 
{  
    if (isEmpty()) 
        return -1; 
    return rear->data; 
} 
  
void Deque::clear() 
{ 
    rear = NULL; 
    while (front != NULL)  
    { 
        Node* temp = front; 
        front = front->next; 
        free(temp); 
    } 
    
} 
   
int main() 
{ 
    Deque dq;
	
	cout<<"1: INSERT AT FRONT\n";
	cout<<"2: INSERT AT REAR\n";
	cout<<"3: DELETE AT FRONT\n";
	cout<<"4: DELETE AT REAR\n";
	cout<<"5: GET FRONT\n";
	cout<<"6: GET REAR\n";
	cout<<"7: IS EMPTY ?\n";
	cout<<"8: CLEAR\n";
	cout<<"9: EXIT\n";
	
	int option,x;
	char ch;
	do
	{
		cout<<"\nCHOOSE ONE OPERATION : ";
		cin>>option;
		
		switch(option)
		{
			case 1:
				cout<<"\nENTER THE ELEMENT TO BE ADD AT FRONT : ";
				cin>>x;
				dq.insertFront(x);
				break;
				
			case 2:
				cout<<"\nENTER THE ELEMENT TO BE ADD AT END : ";
				cin>>x;
				dq.insertRear(x);
				break;
				
			case 3:
				cout<<"\nDELETING FRONT ELEMENT...";
				dq.deleteFront(); 
				break;
				
			case 4:
				cout<<"\nDELETING REAR ELEMENT...";
				dq.deleteRear(); 
				break;
			case 5:
				cout << "\nFRONT ELEMENT: "
        			<< dq.getFront() << endl; 
				break;	
			
			case 6:
				cout << "\nREAR ELEMENT: "
        			<< dq.getRear() << endl; 
				break;	
				
			case 7:
				if(dq.isEmpty())
					cout<<"\nYES , IT IS EMPTY !";
				else
					cout<<"\nNO , IT IS NOT EMPTY !";	
				break;		
				
			case 8:
				cout<<"\nCLEARING...";
				dq.clear();
				break;
					
			case 9:
				cout<<"\nEXITING..";
		        exit(0); 
		        break;				
		}
		cout<<"\nDO YOU WANT TO CONTINUE [Y/N] : ";
		cin>>ch;
	}
	while(ch == 'Y' || ch == 'y');
    
    return 0; 
}

