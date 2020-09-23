#define size 5
#include<stdio.h>
int queue[size];
int front=-1,rear=-1;
void insert()
{
	//if(front==0&&rear==size-1||front==rear+1) or (rear+1)%size==front
	if((rear+1)%size==front)
	{
		printf("\nqueue is full");
		return;
	}
	if(front==-1)
		front=rear=0;
	else if(rear==size-1)									//*
		rear=0;
	else
		rear++;
	printf("\nenter data");
	scanf("%d",&queue[rear]);
	
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
	else if(front==size-1)                             //*
		front=0;
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
	if(rear>=front)
	{
		for(i=front;i<=rear;i++)
			printf("\n%d",queue[i]);
	}
	else                                                //*
	{
		for(i=front;i<=size-1;i++)
			printf("\n%d",queue[i]);
		for(i=0;i<=rear;i++)
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



