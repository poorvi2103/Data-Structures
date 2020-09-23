#include<stdio.h>
#include<stdlib.h>
struct queue
{
	int data;
	struct queue* next;
};
struct queue* front=NULL;
struct queue* rear=NULL;
struct queue* nn(int data)
{
	struct queue* ptr=(struct queue*)malloc(sizeof(struct queue));
	ptr->data=data;
	ptr->next=NULL;
	return ptr;
}

void insert()
{
	int data;
	printf("\nenter data");
	scanf("\n%d",&data);
	struct queue* ptr=nn(data);
	if(front==NULL)										//empty queue
	{
		front=rear=ptr;
	}
	else
	{
		rear->next=ptr;
		rear=ptr;
	}
}
void deleteelement()
{
	struct queue* ptr;
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
	struct queue* ptr1=front;
	if(front==NULL)
	{
			printf("\nempty queue");
			return;
    }
	while(ptr1!=NULL)
	{
		printf("\n%d",ptr1->data);
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
