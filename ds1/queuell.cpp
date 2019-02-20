#include "stdafx.h"
#include <iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
class queue
{
public:
	struct node *front, *rear;
	queue()
	{
		front = NULL;
		rear = NULL;
	}
	void enqueue(int n)
	{
		struct node *temp;
		temp->data = n;
		if (front == NULL&&rear == NULL)
			rear = temp;
		temp->next = front;
		front = temp;
	}
	int dequeue()
	{
		if (front != NULL)
		{
			struct node *cur;
			while (cur->next != rear)
				cur = cur->next;
			int n = rear->data;
			rear = cur;
			delete(cur->next);
			cur->next = NULL;
			return n;
		}
	}
	void TravelForward()
	{
		if (front != NULL)
		{
			struct node *temp = front;
			while (temp != NULL)
			{
				cout << temp->data;
				temp = temp->next;
			}
		}
	}
};
	int main()
	{
		queue s1;
		int n, l;
		cout << "enter number of elements";
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cout << "enter element to be inserted";
			cin >> l;
			s1.enqueue(l);
		}
		s1.TravelForward();
		l = s1.dequeue();
		//cout << l << endl;
		s1.TravelForward();
		l = s1.dequeue();
		s1.TravelForward();
		l = s1.dequeue();
	}