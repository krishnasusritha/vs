#include<iostream>
using namespace std;
struct queue
{
	int rear, front;
	int *a;
};
class queueclass
{
	public:
	int size;
	struct queue q;
	queueclass()
	{
		q.rear=q.front=0;
		q.a=NULL;
	}
	int getsize()
	{
		cout<<"enter size";
		cin>>size;
		q.a= new int[size];
		return size;
	}
	bool overflow()
	{
		if(q.front==(q.rear+1)%size)
			return true;
		else
			return false;
	}
	bool underflow()
	{
		if(q.front==q.rear)
			return 1;
		else
		 	return 0;
	}	 
	void enqueue(int a)
	{
		
		if(overflow())
			cout<<"queue is full";
		
		else 
		
		{
			q.rear=(q.rear+1)%size;
			q.a[q.rear]=a;
			
		}
	}
	void dequeue()
	{
		if(underflow())
			cout<<"queue is empty";
		else
		{
			q.front=(q.front+1)%size;
		
		}
	}

	void display()
	{
		int i;
		for( i=(q.front+1)%size;i!=q.rear;i=(i+1)%size)
		{
			cout<<q.a[i];
		}
		cout<<q.a[i];
	}
};
int main()
{
	queueclass qs;
	int l;
	int k=qs.getsize();
	for(int i=0;i<k-1;i++)
	{
		cin>>l;
		qs.enqueue(l);
	}
	qs.dequeue();
	qs.dequeue();
	qs.display();
	return 0;
}
	
			   
		
		

