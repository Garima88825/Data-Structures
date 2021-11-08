#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class node
{
	int val;
	node *left,*right;
	friend class BST;
	public:	
		node(int a=0,node *l=0,node *r=0)
		{
			left=l;
			val=a;
			right=r;
		}
};

class BST
{
	node *root;
	public:
		BST()
		{
			root=0;	
		}	
		void insert(int x)
		{
			if(!root)
				root=new node(x);
			else
			{
				node *p=root, *prev=0;
				while(p!=0)
				{
					prev=p;
					if(x<p->val)
						p=p->left;
					else
						p=p->right;
				}
				if(x<prev->val)
					prev->left=new node(x);
				else
					prev->right=new node(x);
			}
		}
		
		
		int height()
		{
			if(root)
				return height_tree(root);
			else
				return 0;
		}
		
		int height_tree(node *ptr)
		{
			if(!ptr)
				return 0;
			int l=height_tree(ptr->left);
			int r=height_tree(ptr->right);
			if(l>r)
				return (l+1);
			else
				return (r+1);
		}
		
		node *search(int x)
		{
			if(root)
			{
				node *curr=root;
				while(curr)
				{
					if(curr->val==x)
						return curr;
					else if(x<curr->val)
						curr=curr->left;
					else
						curr=curr->right;
				}
			}
			return 0;
		}
		void level_trav()
		{
			if(root)
			{
				queue<node *> q;
				node *curr=root;
				q.push(curr);
				while(!q.empty())
				{
					curr=q.front();
					cout<<curr->val<<" ";	
					q.pop();
					if(curr->left)
						q.push(curr->left);
					if(curr->right)
						q.push(curr->right);
				}
			}
		}
//		void preorder()
//		{
//			stack<node *>travstack;
//			node *p=root;
//			if(p!=0)
//			{
//				travstack.push(p);
//				while(!travstack.empty())
//				{
//					p=travstack.top();
//					travstack.pop();
//					cout<<p->val<<" ";
//					if(p->right!=0)
//						travstack.push(p->right);
//					if(p->left!=0)
//						travstack.push(p->left);
//				}
//			}
//		}
//		void postorder()
//		{
//			stack<node *>travstack;
//			node *p=root,*q=root;
//			while(p!=0)
//			{
//				for(;p->left!=0;p=p->left)
//					travstack.push(p);
//				while(p->right==0 || p->right==q)
//				{
//					cout<<p->val<<" ";
//					q=p;
//					if(travstack.empty())
//						return;
//					p=travstack.top();
//					travstack.pop();	
//				}
//				travstack.push(p);
//				p=p->right;
//			}
//		}
		void inorder_trav(node *ptr)
		{
			if(ptr)
			{
				inorder_trav(ptr->left);
				cout<<ptr->val<<" ";
				inorder_trav(ptr->right);
			}
		}
		
		void preorder_trav(node *ptr)
		{
			if(ptr)
			{
				cout<<ptr->val<<" ";
				preorder_trav(ptr->left);
				preorder_trav(ptr->right);
			}
		}
		
		void postorder_trav(node *ptr)
		{
			if(ptr)
			{
				postorder_trav(ptr->left);
				postorder_trav(ptr->right);
				cout<<ptr->val<<" ";
			}
		}
//		void inorder()
//		{
//			inorder_trav(root);
//		}
		void findand_deletebymerge(int x)
		{
			if(root)
			{
				node *curr=root,*prev=0;
				while(curr!=0)
				{
					if(curr->val==x)
						break;
					prev=curr;
					if(x<curr->val)
						curr=curr->left;
					else
						curr=curr->right;
				}
				if(curr!=0 && curr->val==x)
				{
					if(curr==root)
						deletebymerge(root);
					else if(prev->left==curr)
						deletebymerge(prev->left);
					else
						deletebymerge(prev->right);
				}
				else
					cout<<"ELEMENT NOT PRESENT !\n";
			}
			else
				cout<<"TREE IS EMPTY !\n";
		}
		void deletebymerge(node *&curr)
		{
			node *temp=curr;
			if(curr->right==0)
				curr=curr->left;
			else if(curr->left==0)
				curr=curr->right;
			else
			{
				temp=curr->left;
				while(temp->right!=0)
					temp=temp->right;
				temp->right=curr->right;
				temp=curr;
				curr=curr->left;
			}
			delete temp;
		}
		void findand_deletebycopy(int x)
		{
			if(root)
			{
				node *curr=root,*prev=0;
				while(curr!=0)
				{
					if(curr->val==x)
						break;
					prev=curr;
					if(x<curr->val)
						curr=curr->left;
					else
						curr=curr->right;
				}
				if(curr!=0 && curr->val==x)
				{
					if(curr==root)
						deletebycopy(root);
					else if(prev->left==curr)
						deletebycopy(prev->left);
					else
						deletebycopy(prev->right);
				}
				else
					cout<<"ELEMENT NOT PRESENT !\n";
			}
			else
				cout<<"TREE IS EMPTY !\n";
		}
		void deletebycopy(node *&curr)
		{
			node *prev,*temp=curr;
			if(curr->right==0)
				curr=curr->left;
			else if(curr->left==0)
				curr=curr->right;
			else
			{
				temp=curr->left;
				prev=curr;
				while(temp->right!=0)
				{
					prev=temp;
					temp=temp->right;
				}
				curr->val=temp->val;
				if(prev==curr)
					prev->left=temp->left;
				else
					prev->right=temp->left;
			}
		}
		
		node* return_Root()
		{
			return root;
		}
};

int main()
{
	BST tree;
	cout<<"\tBINARY SEARCH TREE";
	cout<<endl<<"______________________________";
		cout<<endl<<"1. INSERT AN ELEMENT";
		cout<<endl<<"2. DELETE AN ELEMENT (MERGING)";
		cout<<endl<<"3. DELETE AN ELEMENT (COPYING)";
		cout<<endl<<"4. SEARCH AN ELEMENT x,CHANGE ITS VALUE TO y AND PLACE IT AT APPROPRIATE POSITION";
		cout<<endl<<"5. TRAVERSAL (PREORDER , POSTORDER , INORDER)";
		cout<<endl<<"6. LEVEL BY LEVEL TRAVERSAL";
		cout<<endl<<"7. DISPLAY THE HEIGHT";
		cout<<endl<<"8. EXIT";
	int x,choice;
	char ch;
	node* a;
	node* t;
	
	do
	{
		cout<<endl<<"ENTER YOUR CHOICE : ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				cout<<"ENTER THE ELEMENT YOU WANT TO INSERT : ";
				cin>>x;
				tree.insert(x);
				t=tree.return_Root();
				cout<<"INORDER : ";
				tree.inorder_trav(t);
				cout<<"\nPREORDER : ";
				tree.preorder_trav(t);
				break;
			
			case 2:
				cout<<"ENTER THE ELEMENT TO BE DELETED : ";
				cin>>x;
				tree.findand_deletebymerge(x);
				t=tree.return_Root();
				cout<<"INORDER : ";
				tree.inorder_trav(t);
				cout<<"\nPREORDER : ";
				tree.preorder_trav(t);
				break;
				
			case 3:
				cout<<"ENTER THE ELEMENT TO BE DELETED : ";
				cin>>x;
				tree.findand_deletebycopy(x);
				t=tree.return_Root();
				cout<<"INORDER : ";
				tree.inorder_trav(t);
				cout<<"\nPREORDER : ";
				tree.preorder_trav(t);
				break;
				
			case 4:
				cout<<"ENTER THE ELEMENT TO BE SEARCHED (x) : ";
				cin>>x;
				a=tree.search(x);
				if(a)
				{
					tree.findand_deletebycopy(x);
					cout<<"ENTER THE ELEMENT (y): ";
					cin>>x;
					tree.insert(x);
				}
				else
					{cout<<"ELEMENT NOT PRESENT ! \n";}
					
					t=tree.return_Root();
					cout<<"\nINORDER : ";
					tree.inorder_trav(t);
					cout<<"\nPREORDER : ";
					tree.preorder_trav(t);
					break;
				
			case 5:
				t=tree.return_Root();
				cout<<"INORDER : ";
				tree.inorder_trav(t);
				cout<<"\nPREORDER : ";
				tree.preorder_trav(t);
				cout<<"\nPOSTORDER : ";
				tree.postorder_trav(t);
				break;
				
			case 6:
				tree.level_trav();
				break;
				
			case 7:
				x=tree.height();
				cout<<"HEIGHT OF THE TREE : "<<x;
				break;
				
			case 8:
				cout<<"EXITING...";
				exit(0);
				break;				
		}	
		cout<<"\nDO YOU WANT TO CONTINUE : ";
		cin>>ch;
		
	}while(ch == 'Y' || ch == 'y');
		
	return 0;
}
