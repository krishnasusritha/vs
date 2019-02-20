#include "stdafx.h"
#include <iostream>
using namespace std;
struct node
{
	int data;
	int pow;
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
	void InsertFirst(int n,int p)
	{
		struct node *temp;
		temp = new node;
		temp->data = n;
		temp->pow = p;
		if (start == NULL)
			temp->next = NULL;
		temp->next = start;
		start = temp;
	}
	void InsertEnd(int n,int p)
	{
		if (start != NULL)
		{
			struct node *temp, *cur;
			temp = new node;
			temp->data = n;
			temp->pow = p;
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
	void add(sll s)
	{
		int temp;
		if (s.start != NULL&&start != NULL)
		{
			struct node *temp2, *temp1;
			sll s1;
			temp2 = s.start;
			temp1 = start;
			if (temp1->pow < temp2->pow)
			{
				s1.InsertFirst(temp2->data, temp2->pow);
				temp2 = temp2->next;
			}
			else if (temp1->pow > temp2->pow)
			{
				s1.InsertFirst(temp1->data, temp1->pow);
				temp1 = temp1->next;
			}
			else
			{
				temp = temp1->data + temp2->data;
				s1.InsertFirst(temp, temp1->pow);
				temp1 = temp1->next;
				temp2 = temp2->next;
			}
			while (temp1 != NULL || temp2 != NULL)
			{
				if (temp1->pow < temp2->pow)
				{
					s1.InsertEnd(temp2->data, temp2->pow);
					temp2 = temp2->next;
				}
				else if (temp1->pow > temp2->pow)
				{
					s1.InsertEnd(temp1->data, temp1->pow);
					temp1 = temp1->next;
				}
				else
				{
					temp = temp1->data + temp2->data;
					s1.InsertEnd(temp, temp1->pow);
					temp1 = temp1->next;
					temp2 = temp2->next;
				}

			}
			if (temp1 != NULL)
			{
				while (temp1 != NULL)
				{
					s1.InsertEnd(temp1->data, temp1->pow);
					temp1 = temp1->next;
				}
			}
			if (temp2 != NULL)
			{
				while (temp2 != NULL)
				{
					s1.InsertEnd(temp2->data, temp2->pow);
					temp2 = temp2->next;
				}
			}
			s1.TravelForward();
		}
		else
			cout << "no linked lisr";
	}


};
int main()
{
	sll s1, s2;
	int d, p,n;
	s1.InsertFirst(5, 3);
	cout << "eneter numbver of elements";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "enter num,pow";
		cin >> d >> p;
		s1.InsertEnd(d, p);
	}
	s2.InsertFirst(5, 3);
	cout << "eneter numbver of elements";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "enter num,pow";
		cin >> d >> p;
		s2.InsertEnd(d, p);
	}
	s1.add(s2);
	return 0;
	
}