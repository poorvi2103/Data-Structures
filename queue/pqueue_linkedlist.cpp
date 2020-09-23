#include<stdio.h>
#include<stdlib.h>
struct pqueue
{
	int data;
	int key;
	struct pqueue* next;
};
struct pqueue* front=NULL;
struct pqueue* rear=NULL;
struct pqueue* nn(int data,int key)
{
	struct pqueue* p=(struct pqueue*)malloc(sizeof(struct pqueue));
	p->data=data;
	p->key=key;
	p->next=NULL;
	return p;
}
void insert()
{
	int data;
	int key;
	struct pqueue* ptr; 							//storing pointer
	struct pqueue* ptr1;							//traversing pointer
	struct pqueue* ptr2;							//back pointer
	printf("\nenter data");
	scanf("\n%d",&data);
	printf("\nenter key");
	scanf("\n%d",&key);
	ptr=nn(data,key);
	if(front==NULL)									//front element
	{
		front=rear=ptr;
	}
	else if(ptr->key<=front->key)					//insert at first position
	{
		ptr->next=front;
		front=ptr;	
	}
	else if(ptr->key>=rear->key)
	{
		rear->next=ptr;
	}
	else
	{
		ptr1=front;
		while(ptr1!=rear)
		{
			if(ptr->key>=ptr1->key)
			{
				ptr2=ptr1;
				ptr1=ptr1->next;
			}
			else
			{
				ptr->next=ptr2->next;
				ptr2->next=ptr;	
				
			}
		}
	}
	
}

void deleteelement()
{
	struct pqueue* ptr;
	if(front==NULL)
	{
		printf("\nempty queue");
		return;
	}
	if(front==rear)										//single element
	{
		front=rear=NULL;
	}
	else
	{
		ptr=front;
		front=front->next;
		free(ptr);
		ptr=NULL;
	}
}
void display()
{
	struct pqueue* ptr1=front;
	if(front==NULL)
	{
			printf("\nempty queue");
			return;
    }
	while(ptr1!=NULL)
	{
		printf("\n%d---->%d",ptr1->data,ptr1->key);
		ptr1=ptr1->next;
	}
}
int main()
{
	int ch;
	while(1)
	{
		printf("\n1.insert");
		printf("\n2.delete");
		printf("\n3.display");
		printf("\n4.exit");
		printf("\nenter your choice");
		scanf("\n%d",&ch);
		switch(ch)
		{
		case 1:insert();
			   break;
		case 2:deleteelement();
			   break;	
		case 3:display();
			   break;
		case 4:return 0;
			   break;
		default:printf("\ninvalid choice");
	    }
	}
}

