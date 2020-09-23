												//double ended queue
			//1.input(inser) restricted dequeue 													2.output(deletion) restricted dequeue
		//(insert only from right and delete from both sides)									(insert from both sides but delete from left)


#include<stdio.h>
#include<stdlib.h>
struct Deque
{
	int data;
	struct dequeue* next;
};
struct Deque* front=NULL;
struct Deque* rear=NULL;
struct Deque* nn(int data)
{
	struct Deque* p=(struct Deque*)
	
}
void insertLeft()
{
	int data;
	struct Deque *ptr;
	printf("\nenter data");
	scanf("%d",&data);
	ptr=nn(data);
	if(front==NULL)
		front=rear=ptr;
	else
	{
		ptr->next=front;
	    front=ptr;
	}
}
void insertRight()
{
	int data;
	struct Deque *ptr;
	printf("\nenter data");
	scanf("%d",&data);
	ptr=nn(data);
	if(front==NULL)
		front=rear=ptr;
	else
	{
		rear->next=ptr;
        rear=ptr;
	
	}
}
deleteLeft()



		
												
