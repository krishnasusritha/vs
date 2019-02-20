// ds1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
struct queue
{
	int front, rear;
	char *a;
};
class queue1
{
public:
	struct queue q1;
	int size;
	queue1()
	{
		q1.front = -1;
		q1.rear = -1;
	}
	void getsize()
	{
		cin >> size;
		q1.a = new char[size];
	}
	void enqueue(char x)
	{
		if (q1.rear == -1)
		{
			q1.rear++;
			q1.a[q1.rear] = x;
			q1.rear++;
			q1.front++;
		}
		else if (q1.rear != size)
			q1.a[q1.rear++] = x;
		else
			cout << "queue is full";
	}
	char dequeue()
	{
		char x;
		if (q1.front == -1 && q1.rear == -1)
			cout << "queue is empty";
		else if (q1.front == q1.rear)
		{
			x = q1.a[q1.front];
			q1.front = q1.rear = -1;
		}
		else
		{
			x = q1.a[q1.front];
			q1.front++;
		}
		return x;
	}
	void display()
	{
		if (q1.front != -1)
		{
			for (int i = 0; i < q1.rear; i++)
			{
				cout << q1.a[i];
			}
		}
	}
};
int main()
{
	queue1 q;
	int x = 0;
	q.getsize();
	q.enqueue('a');
	q.enqueue('a');
	q.display();
	x = q.dequeue();
    return 0;
}

