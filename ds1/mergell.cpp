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
	void merge(sll l1)
	{
		if (start != NULL&&l1.start != NULL)
		{
			struct node *temp1 = start, *temp2 = l1.start;
			sll s3;
			if (temp1->data <= temp2->data)
			{
				s3.InsertFirst(temp1->data);
				temp1 = temp1->next;
			}
			else
			{
				s3.InsertFirst(temp2->data);
				temp2 = temp2->next;
			}
			while (temp1 != NULL&&temp2 != NULL)
			{
				if (temp1->data <= temp2->data)
				{
					s3.InsertEnd(temp1->data);
					temp1 = temp1->next;
				}
				else
				{
					s3.InsertEnd(temp2->data);
					temp2 = temp2->next;
				}
			}
			while (temp1 != NULL)
			{
				s3.InsertEnd(temp1->data);
				temp1 = temp1->next;
			}
			while (temp2 != NULL)
			{
				s3.InsertEnd(temp2->data);
				temp2 = temp2->next;
			}
			s3.TravelForward();
		}
		
	}
};
	int main()
	{
		sll s1, s2;
		int n, i,l;
		s1.InsertFirst(9);
		cout << "enter number of elements";
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cout << "enter element to be inserted";
			cin >> l;
			s1.InsertEnd(l);
		}
		s2.InsertFirst(2);
		cout << "enter number of elements";
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cout << "enter element to be inserted";
			cin >> l;
			s2.InsertEnd(l);
		}
		s1.merge(s2);
		s1.TravelForward();
		s2.TravelForward();
		return 0;
	}
