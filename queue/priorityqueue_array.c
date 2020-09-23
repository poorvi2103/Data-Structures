#include<stdio.h>
#include<stdlib.h>
#define size 5
struct pqueue
{
	int data;
	int key;
};
struct pqueue queue[size];                //structure type array
int front=-1,rear=-1;
void insert()
{
	struct pqueue info;
	int i=0;
	if(rear==size-1)
	{
	  printf("\nqueue is full");
	  return;
	}
	if(front==-1)
	{
		front =rear=0; 								//front element
		printf("\nenter data");
		scanf("\n%d",&queue[front].data);
		printf("\nenter key");
		scanf("\n%d",&queue[front].key);
	}
	else
	{
		printf("\nenter data");
		scanf("\n%d",&info.data);
		printf("\nenter key");
		scanf("\n%d",&info.key);
		
		while(i<=rear)
		{
			if(queue[i].key<info.key)
			{
				i++;
			}
			else
			{
				int j=rear;
				while(j>=i)											//shifting elements
				{
					queue[j+1].data=queue[j].data;
					queue[j+1].key=queue[j].key;
					j--;
				}
				queue[i].data=info.data;
				queue[i].key=info.key;
				rear++;
			}
		}
		
	}
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
	printf("\n%d---->%d",queue[i].data,queue[i].key);
	}
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
