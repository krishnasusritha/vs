#include<iostream>
using namespace std;
struct node
{
	int coeff;
	int var;
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
	
	void insert_back(int coeff1,int var1)
	{
		
			node *temp=new node;
			temp->var=var1;
			temp->coeff=coeff1;
			temp->next=NULL;
			node *curr;
			curr=start;
			if(start==NULL)
				start=temp;
			else
			{
				while(curr->next!=NULL)
				{
					curr=curr->next;
				}
				curr->next=temp;
			}
	
	}
void add(list l1, list l2)
{
	node *t1=l1.start;
	node *t2=l2.start;
//	  node *t3= new node;
//	  t3=this->start;	 
	while(t1!=NULL && t2!=NULL)
	{
		if(t1->var== t2->var)
		{
			//t3->coeff =t1->coeff+t2->coeff;
			insert_back(t1->coeff+t2->coeff, t1->var);
			t1=t1->next;
			t2=t2->next;
			//t3=t3->next;
			
		}
		else if(t1->var<t2->var)
		{
			
			insert_back(t2->coeff,t2->var);
			t2=t2->next;
		}
		else if(t1->var>t2->var)
		{
			insert_back(t1->coeff,t1->var);
			t1=t1->next;
		}
	}
	while(t1!=NULL)
	{
		insert_back(t1->coeff, t1->var);
		t1= t1->next;
	}
	while(t2!=NULL)
	{
		insert_back(t2->coeff, t2->var);
		t2= t2->next;
	}
}

	 


	void Travelforward()
	{
		node *curr=start;
		while(curr!=NULL)
		{
			cout<<curr->coeff<<" ";
			cout<<"x^" << curr->var<<"\n";
			curr=curr->next;
		}
		cout<<"\n";
	}
	
	
	
};
int main()
{
	list l1, l2,l3;
	l1.insert_back(10,3);
	l1.insert_back(30,2);
	l1.insert_back(50,1);
	l2.insert_back(33,3);
	
	l2.insert_back(60,2);
	l2.insert_back(70,1);
	l3.add(l1,l2);
	l3.Travelforward();
}
	

