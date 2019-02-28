#include<iostream>
using namespace std;
class stack1
{
	int top;
	char *a;
	public:
	int size;
	stack1()
	{
		a=NULL;
		size=0;
		top=-1;
	}
		
	void push(char ele)
	{
		if(!isfull())
			a[++top]=ele;
		else
			cout<<"stack is full";
	}
	int pop()
	{
		char x='$';
		if(!isempty())
		{
			x=a[top--];
			if(x=='#')
				return 0;
		}
		else
			cout<<"stack is empty";
		
		return x;
	
	}
	int getsize()
	{
		cout<<"enter size";
		cin>>size;
	
		a=new char[size];
		return size;
	}
	bool isfull()
	{
		
		if(size-1==top)
			return true;
		else
			return false;
	}
	bool isempty()
	{
		if(top==-1)
			return true;
		else
			return false;
	}
	int peek()
	{
		char x;
		if(!isempty())
			x=a[top];
		return x;
	}	 	 
	
};
int precedence(char l)
{
	switch(l)
	{
		case '+':
		case '-':
			return 4;
		case '/':
		case '*':
			return 5; 
		case ')':
		case '(':
			return 3;
		default:
			return 1;
	}
	return 0;
}
int main()
{
	stack1 s;
	int k=s.getsize();
	int y=0,h=0;
	char *p, *result;
	p=new char[k];
	result= new char[k];
	
	cout<<"enter expression";
	cin>>p;
	s.push('#');
	
	for(int i=0;p[i]!='\0';i++)
	{
		if(isalpha(p[i]) || isdigit(p[i]))
		{
			result[y++]=p[i];
		}
		else if(p[i]=='(')
			s.push(p[i]);
		
		else if(p[i]==')')
		{
			while(s.peek()!='(')
			{
				
				result[y++]=s.pop();
			}
			s.pop();
		}
		else if(precedence(p[i])>precedence(s.peek()))
			s.push(p[i]);
			else
			{
				while(precedence(p[i])<=precedence(s.peek()))
				{
					result[y++]=s.pop();
				}	 
				s.push(p[i]);
			}
      }	
	  while(!s.isempty())
	  {
	  		
	  		result[y++]=s.pop();
	  }
	cout<<result;   
return 0;
}	 
					

