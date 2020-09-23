#include<stdio.h>
#include<stdlib.h>
#define size 5
int queue[size];
int front=-1,rear=-1;
void insert()
{
	if(rear==size-1)
	{
	  printf("\nqueue is full");
	  return;
	}
	if(front==-1)
	{
		rear=front=0;
	}
	else
		rear++;
	printf("\nenter data");
	scanf("\n%d",&queue[rear]);
}
void deleteelement()
{
	if(front==-1)
	{
		printf("\nqueue is empty");
		return;
	}
	if(front==rear)
		front=rear=-1;
	else
		front++;
}
void display()
{
	int i;
	if(front==-1)
	{
		printf("\nqueue is empty");
		return;
	}
	for(i=front;i<=rear;i++)
	{
	printf("\n%d",queue[i]);
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
