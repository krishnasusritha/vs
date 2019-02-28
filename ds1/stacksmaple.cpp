#include<iostream>
using namespace std;
struct stack
{
	int n;
	int *a;
	int top;
};
class stack1
{
	struct stack s;
	public:
	int size;
	stack1()
	{
		s.a=NULL;
		s.n=0;
		s.top=-1;
	}
	int getsize()
	{
		cout<<"enter size";
		cin>>size;
		s.a=new int[size];
		return size;
	}
	void push(int ele)
	{
		if(!isfull())
			s.a[++s.top]=ele;
		else
			cout<<"stack is full";
	}
	int pop()
	{
		int x=-999;
		if(!isempty())
			x=s.a[s.top--];
		else
			cout<<"stack is empty";
		return x;
	
	}
	bool isfull()
	{
		
		if(size-1==s.top)
			return true;
		else
			return false;
	}
	bool isempty()
	{
		if(s.top==-1)
			return true;
		else
			return false;
	}
	int peek()
	{
		int x;
		if(!isempty())
			x=s.a[s.top];
		cout<<x<<"\n";
		return x;
	}	 	 
	void display()
	{
		for(int i=0;i<=s.top;i++)
			cout<<s.a[i]<<"\n";
	}
};
int main()
{
	class stack1 s1;
	int q=s1.getsize();
	for(int i=0;i<q;i++)
	{
		int element;
		cin>>element;
		s1.push(element);
	}
	s1.display();
	s1.pop();
	s1.pop();
	s1.peek();
	s1.pop();
	s1.pop();
	s1.pop();
	s1.display();
}

