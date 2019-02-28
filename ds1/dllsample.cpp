#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
class doublelist
{
	struct node *start;
	public:
	doublelist()
	{
		
		start=NULL;
		
	}
	void insert_front(int ele)
	{	
		node *temp=new node;
		temp->data=ele;
		temp->prev=NULL; 	 
		temp->next=start;
		start=temp;
		
		
	}
	void insert_back(int ele)
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
			temp->prev=curr;
			
	
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
				temp->prev=curr;
				curr->next->prev=temp;
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
				temp->prev=NULL;
				start=temp;
			}
			while(curr!=NULL && curr->next->data!=spec)
				curr=curr->next;
			if(curr!=NULL)
			{
				temp->next=curr->next;
				temp->prev=curr;
				curr->next->prev=temp;
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
		start->prev=NULL;
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
				curr->next->prev=curr;
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
	
	
};
int main()
{
	doublelist dl;
	dl.insert_front(10);
	dl.insert_back(30);
  dl.insert_after(10,20);
	  dl.insert_back(50);
	dl.insert_before(50,40);
	dl.delete_first();
	dl.delete_last();
	dl.delete_spec(20);
	dl.insert_back(60);
	dl.insert_back(70);
	dl.Travelforward();
	return 0;
}
	

