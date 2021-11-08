#include<iostream>
using namespace std;

class node
{
	public:
		int data;
		node* left;
		node* right;
		int ht;
};

node *insert(node *,int);
node *Delete(node *,int);
void preorder(node *);
void inorder(node *);
int height( node *);
node *rotateright(node *);
node *rotateleft(node *);
node *RR(node *);
node *LL(node *);
node *LR(node *);
node *RL(node *);
int BF(node *);

int main()
{
	node *root;
	int x,n,i,op;
	
	cout<<"\n1)Create:";
	cout<<"\n2)Insert:";
	cout<<"\n3)Delete:";
	cout<<"\n4)Print:";
	cout<<"\n5)Quit:";
	
	do
	{
		cout<<"\n\nEnter Your Choice:";
		cin>>op;
		
		switch(op)
		{
			case 1: cout<<"\nEnter no. of elements:";
					cin>>n;
					cout<<"\nEnter tree data:";
					root=NULL;
					for(i=0;i<n;i++)
					{
						cin>>x;
						root=insert(root,x);
					}
					break;
				
			case 2: cout<<"\nEnter a data:";
					cin>>x;
					root=insert(root,x);
					break;
					
			case 3: cout<<"\nEnter a data:";
					cin>>x;
					root=Delete(root,x);
					break;
			
			case 4: cout<<"\nPreorder sequence:\n";
					preorder(root);
					cout<<"\n\nInorder sequence:\n";
					inorder(root);
					cout<<endl;
					break;			
		}
	}while(op!=5);
	
	return 0;
}
 
node * insert(node *T,int x)
{
	if(T==NULL)
	{
		//T=(node*)malloc(sizeof(node));
		T=new node();
		T->data=x;
		T->left=NULL;
		T->right=NULL;
	}
	else
		if(x > T->data)		
		{
			T->right=insert(T->right,x);
			if(BF(T)==-2)
				if(x>T->right->data)
					T=RR(T);
				else
					T=RL(T);
		}
		else
			if(x<T->data)
			{
				T->left=insert(T->left,x);
				if(BF(T)==2)
					if(x < T->left->data)
						T=LL(T);
					else
						T=LR(T);
			}
		
		T->ht=height(T);
		
		return(T);
}
 
node * Delete(node *T,int x)
{
	node *p;
	
	if(T==NULL)
	{
		return NULL;
	}
	else
		if(x > T->data)		
		{
			T->right=Delete(T->right,x);
			if(BF(T)==2)
				if(BF(T->left)>=0)
					T=LL(T);
				else
					T=LR(T);
		}
		else
			if(x<T->data)
			{
				T->left=Delete(T->left,x);
				if(BF(T)==-2)	
					if(BF(T->right)<=0)
						T=RR(T);
					else
						T=RL(T);
			}
			else
			{
				
				if(T->right!=NULL)
				{	
					p=T->right;
					
					while(p->left!= NULL)
						p=p->left;
					
					T->data=p->data;
					T->right=Delete(T->right,p->data);
					
					if(BF(T)==2)
						if(BF(T->left)>=0)
							T=LL(T);
						else
							T=LR(T);\
				}
				else
					return(T->left);
			}
	T->ht=height(T);
	return(T);
}
 
int height(node *T)
{
	int lh,rh;
	if(T==NULL)
		return(0);
	
	if(T->left==NULL)
		lh=0;
	else
		lh=1+T->left->ht;
		
	if(T->right==NULL)
		rh=0;
	else
		rh=1+T->right->ht;
	
	if(lh>rh)
		return(lh);
	
	return(rh);
}
 
node * rotateright(node *x)
{
	node *y;
	y=x->left;
	x->left=y->right;
	y->right=x;
	x->ht=height(x);
	y->ht=height(y);
	return(y);
}
 
node * rotateleft(node *x)
{
	node *y;
	y=x->right;
	x->right=y->left;
	y->left=x;
	x->ht=height(x);
	y->ht=height(y);
	
	return(y);
}
 
node * RR(node *T)
{
	T=rotateleft(T);
	return(T);
}
 
node * LL(node *T)
{
	T=rotateright(T);
	return(T);
}
 
node * LR(node *T)
{
	T->left=rotateleft(T->left);
	T=rotateright(T);
	
	return(T);
}
 
node * RL(node *T)
{
	T->right=rotateright(T->right);
	T=rotateleft(T);
	return(T);
}
 
int BF(node *T)
{
	int lh,rh;
	if(T==NULL)
		return(0);
 
	if(T->left==NULL)
		lh=0;
	else
		lh=1+T->left->ht;
 
	if(T->right==NULL)
		rh=0;
	else
		rh=1+T->right->ht;
 
	return(lh-rh);
}
 
void preorder(node *T)
{
	if(T!=NULL)
	{
		cout<<T->data<<" (Bf ="<<BF(T)<<") ";
		preorder(T->left);
		preorder(T->right);
	}
}
 
void inorder(node *T)
{
	if(T!=NULL)
	{
		inorder(T->left);
		cout<<T->data<<" (Bf ="<<BF(T)<<") ";
		inorder(T->right);
	}
}
