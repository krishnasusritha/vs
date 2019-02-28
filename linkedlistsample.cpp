#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
class list
{
	struct node *start;
	public:
	list()
	{
		
		start=NULL;
	}
	void insert_front(int ele)
	{	 	 
		
		
			node *temp=new node;
			temp->data=ele;
			temp->next=start;
			start=temp;
		
	}
	void insert_back(int ele)
	{
		if(start==NULL)
			cout<<"list is empty";
		else
		{
			node *temp=new node;
			temp->data=ele;
			temp->next=NULL;
			node *curr;
			curr=start;
			while(curr->next!=NULL)
			{
				curr=curr->next;
			}
			curr->next=temp;
		}
	}
	void insert_after(int spec, int ele)
	{
		if(start==NULL)
			cout<<"list is empty";
		else
		{
			node *temp=new node;
			temp->data=ele;
			node *curr=start;
			while(curr!=NULL && curr->data!=spec)
				curr=curr->next;
			if(curr!=NULL)
			{
				temp->next=curr->next;
				curr->next=temp;
			}
		}
	}
	void insert_before(int spec, int ele)
	{
		if(start==NULL)
			cout<<"list is empty";
		else
		{
			
			node *temp=new node;
			temp->data=ele;
			node *curr=start;
			if(start->data==spec)
			{
				temp->next=start;
				start=temp;
			}
			while(curr!=NULL && curr->next->data!=spec)
				curr=curr->next;
			if(curr!=NULL)
			{
				temp->next=curr->next;
				curr->next=temp;
			}
		}
	}
	int delete_first()
	{
		int x=-99;
		x=start->data;
		node *curr;
		curr=start;
		start=curr->next;
		delete curr;
		return x;
	}
	
	void delete_last()
	{
		int x=-99;
	
		node *curr;
		curr=start;
		while(curr->next->next!=NULL)
			curr=curr->next;
		delete curr->next;
		curr->next=NULL;
		
	}
	void delete_spec(int ele)
	{
		int x=-99;
	
		node *curr,*temp;
		curr=start;
		if(start->data==ele)
		{
			temp=start;
			start=temp->next;
			delete temp;
		}
		else
		{	 
		while(curr->next!=NULL && curr->next->data!=ele)
			curr=curr->next;
			if(curr->next!=NULL)
			{
				temp=curr->next;
				curr->next=temp->next;
				delete temp;
			}	 	 	 	 
		
		}
	}
	
		
		
		
	
	
	void Travelforward()
	{
		node *curr=start;
		while(curr!=NULL)
		{
			cout<<curr->data<<" ";
			curr=curr->next;
		}
		cout<<"\n";
	}
	void Travelbackward()
	{
		if(start!=NULL)
			print(start);
	}
	void print(node *h)
	{
		if(h!=NULL)
		{
			
			print(h->next);
			cout<<h->data<<" ";
		}
		
		
	}
	void reverse()
	{
		node *prev=NULL, *next=NULL;
		node *curr=start;
		while(curr!=NULL)
		{
			next=curr->next;
			curr->next=prev;
			prev=curr;
			curr=next;
		}
		start=prev;
	}
	
};
int main()
{
	list l;
	l.insert_front(10);
	l.insert_back(30);
	l.insert_after(10,20);
	l.insert_back(50);
	l.insert_before(50,40);
	l.delete_first();
	l.delete_last();
	l.delete_spec(20);
	l.insert_back(60);
	l.insert_back(70);
	l.Travelforward();
	l.Travelbackward();
	l.reverse();
	l.Travelforward();
}
	

