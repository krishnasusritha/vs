#include "stdafx.h"
#include <iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
class sll
{
public:
	struct node *start;
	sll()
	{
		start = NULL;
	}
	void InsertFirst(int n)
	{
		struct node *temp;
		temp = new node;
		temp->data = n;
		if (start == NULL)
			temp->next = NULL;
		temp->next = start;
		start = temp;
	}
	void InsertEnd(int n)
	{
		if (start != NULL)
		{
			struct node *temp, *cur;
			temp = new node;
			temp->data = n;
			cur = start;
			while (cur->next != NULL)
				cur = cur->next;
			cur->next = temp;
			temp->next = NULL;
		}
		else
		{
			cout << "no linked list";
		}
	}
	void InsertAt (int n,int x)
	{
		if (start != NULL)
		{
			struct node *temp, *cur;
			temp = new node;
			temp->data = n;
			cur = start;
			while (cur!= NULL&&cur->data != x)
				cur = cur->next;
			if (cur != NULL)
			{
				temp->next = cur->next;
				cur->next = temp;
			}
			else
				cout << "element not found";
		}
		else
		{
			cout << "no linked list";
		}
	}
	void InsertBefore(int n, int x)
	{
		if (start != NULL)
		{
			struct node *temp, *cur;
			temp = new node;
			temp->data = n;
			cur = start;
			while (cur->next != NULL&&cur->next->data != x)
				cur = cur->next;
			if (cur != NULL)
			{
				temp->next = cur->next;
				cur->next = temp;
			}
		}
	}
	int DeleteFront()
	{
		int x;
		if (start != NULL)
		{
			struct node *temp = start;
			x = temp->data;
			start = temp->next;
			delete(temp);
		}
		return x;
	}
	int DeleteLast()
	{
		int x;
		if (start != NULL)
		{
			struct node *temp = start;
			while (temp->next->next != NULL)
				temp = temp->next;
			x = temp->next->data;
			temp->next = NULL;
			delete(temp);
		}
		return(x);
	}
	void DeleteSpec(int n)
	{
		if (start != NULL)
		{
			struct node *temp = start;
			while (temp->next != NULL&&temp->next->data != n)
				temp = temp->next;
			temp->next = temp->next->next;
			temp = temp->next;
			delete(temp);
		}
		else
			cout << "element not found";
	}
	void TravelForward()
	{
		if (start != NULL)
		{
			struct node *temp = start;
			while (temp != NULL)
			{
				cout << temp->data;
				temp = temp->next;
			}
		}
	}

	void TravelReverse(node *start)
	{
		if (start != NULL)
			TravelReverse(start->next);
		cout << start->data;

	}
};
int main()
{
	sll s1;
	int n,l;
	s1.InsertFirst(2);
	cout << "enter number of elements";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "enter element to be inserted";
		cin >> l;
		s1.InsertEnd(l);
	}
	s1.InsertAt(5, 4);
	s1.InsertBefore(3, 5);
	l=s1.DeleteFront();
	cout << l<<endl;
	l = s1.DeleteLast();
	cout << l << endl;
	s1.DeleteSpec(5);
	s1.TravelForward();
	s1.TravelReverse(s1.start);
	return 0;
}