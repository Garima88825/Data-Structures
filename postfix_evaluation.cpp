#include<iostream>
#include<stack>
#include<string.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

int postfix(string ar)
{
	//cout<<n<<endl;
	stack <int> s;
	for(int i=0;i<ar.length();i++)
	{
		if( isdigit(ar[i]) && ar[i+1] == '\0')
		{
			int num=ar[i]-'0';
			s.push(num);
		}
		else if( isdigit(ar[i]) && ar[i+1] != '\0')
		{
			int num=0;
			while(ar[i] != ' ')
			 num=( num*10 )+ar[i++]-'0';
			
			s.push(num);		
		}
		else if( ar[i]=='+' || ar[i]=='-' || ar[i]=='*' || ar[i]=='/' || ar[i]=='^')
		{
			int a=s.top();
			s.pop();
			int b=s.top();
			s.pop();
			//cout<<a<<" "<<b<<endl;
			int num;
			if(ar[i]=='+')
				num=b+a;
			else if(ar[i]=='-')
				num=b-a;
			else if(ar[i]=='*')
				num=b*a;
			else if(ar[i]=='/')
				num=b/a;
			else 
				num=pow(b,a);
				
			s.push(num);					
		}
		else
			continue;
	}
	int f=s.top();
	return f;
}

int main()
{
	string s;
	cout<<" ENTER THE POSTFIX EXPRESSION : ";
	getline(cin,s);
	//int l=s.length();
	int answer=postfix(s);
	cout<<" THE RESULT AFTER EVALUATION : "<<answer;
	
	return 0;	
}
