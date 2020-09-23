#include<stdio.h>
#include<stdlib.h>
struct stack
{
	int data;
	struct stack* next;
	
};
struct stack* top=NULL;
struct stack* nn(int data)
{
	struct stack* p=(struct stack*)malloc(sizeof(struct stack));
	p->data=data;
	p->next=NULL;
	return p;
}
void push()
{
	char ch;
	int data;
	struct stack* ptr;
	do
	{
		printf("\nenter data");
		scanf("\n%d",&data);
		ptr=nn(data);
		if(top==NULL)
		{
			top=ptr;
		}
		else
		{
			ptr->next=top;
			top=ptr;
		}
		printf("\ndo you want to enter more nodes?(y/n) ");
		scanf("\n%c",&ch);
	}while(ch=='y'||ch=='Y');
}
void pop()
{
	struct stack* ptr;
	if(top==NULL)
	{
		printf("\nqueue is empty");
		return;
	}
	else
	{
		ptr=top;
		top=top->next;
		free(ptr);
		ptr=NULL;
	}
}
void peek(struct stack* ptr)
{
	if(top==NULL)
	{
		printf("\nqueue is empty");
	}
	else
	{
		while(ptr!=NULL)
		{
			printf("\n%d",ptr->data);
			ptr=ptr->next;
		}
	}
}
int main()
{
	int ch;
	while(1)
	{
		printf("\n1.push");
		printf("\n2.pop");
		printf("\n3.peek");
		printf("\n4.exit");
		printf("\nenter choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:push();
					break;
			case 2:pop();
			       break;
			case 3:peek(top);
			        break;
			case 4:exit(0);
			
		}
	}
}
