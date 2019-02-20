#include "stdafx.h"
#include <iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
class stack
{
public:
	struct node *top;
	stack()
	{
		top = NULL;
	}
	void push(int n)
	{
		struct node *temp;
		temp->data = n;
		temp->next = NULL;
		if(top!=NULL)
		top->next = temp;
		top = temp;
	}
	int pop()
	{
		struct node *temp;
		int n;
		temp = top;
		n = top->data;
		top = top->next;
		top->next = NULL;
		delete(temp);
		return n;
	}
	void TravelForward()
	{
		if (top != NULL)
		{
			struct node *temp = top;
			while (temp != NULL)
			{
				cout << temp->data<<"    ";
				temp = temp->next;
			}
		}
	}
};
	int main()
	{
		stack s1;
		int n,l=0;
		cout << "enter number of elements";
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cout << "enetr elemet";
			cin >> l;
			s1.push(l);
		}
		s1.TravelForward();
		cout<<s1.pop()<<endl;
		s1.TravelForward();
		cout<<s1.pop()<<endl;
		s1.TravelForward();
		return 0;
	}


