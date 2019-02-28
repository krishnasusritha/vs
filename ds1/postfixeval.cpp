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
int main()
{
	stack1 s;
	int k=s.getsize();
	char *p;
	p=new char[k];
	int first, second,h=0;

	cout<<"enter expression";
	cin>>p;
	for(int i=0;p[i]!='\0';i++)
	{
		if(isdigit(p[i]))
			s.push(p[i]);
		else if(p[i]=='+' || p[i]=='-' || p[i]=='*' || p[i]=='/')
		{
		
			second=(int)s.pop()-48;
			first=(int)s.pop()-48;

			switch(p[i])
			{
				
				case '+':
					h=first+second;
						s.push((char)h+48);
						break;
				case '-':
					h=first-second;
						s.push((char)h+48);
						break;
				case '*':
					h=first*second;
						s.push((char)h+48);
						break;
				case '/':
					h=first/second;
						s.push((char)h+48);
					break;
				default:
					return 0; 
				
			}
		}
	}
	cout<<(int)s.peek()-48;
return 0;
}
			
				
						   	   	      
			
	


