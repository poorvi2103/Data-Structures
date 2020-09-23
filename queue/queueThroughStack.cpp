#include<stdio.h>
#include<stdlib.h>
struct stack
{
	int data;
	struct stack* next;
	
};
struct stack* top1=NULL;
struct stack* top2=NULL;
struct stack* nn(int data)
{
	struct stack* p=(struct stack*)malloc(sizeof(struct stack));
	p->data=data;
	p->next=NULL;
	return p;
}
void insert()
{
	int data;
	struct stack* ptr;
	printf("\nenter data");
	scanf("\n%d",&data);
	ptr=nn(data);
	if(top1==NULL)
	{
		top1=ptr;
	}
	else
	{
		ptr->next=top1;
		top1=ptr;
	}
}
void deletion()
{
	struct stack* ptr;
	struct stack* ptr1;
	if(top1==NULL&&top2==NULL)
	{
		printf("\nqueue is empty");
		return;
	}
	if(top2==NULL)                                            // pop from stack1 andx push into stack2
	{
		while(top1!=NULL)
		{
			ptr=top1;
			top1=top1->next;
			ptr->next=top2;
			top2=ptr;
		}	
	}
	if(top2!=NULL)                                        //pop from stack 2 i.e.delete
	{
		ptr1=top2;
		printf("\n%d",ptr1->data);
		top2=top2->next;
		free(ptr1);
		ptr1=NULL;
	}
}
int main()
{
	int ch;
	while(1)
	{
		printf("\n1.insert");
		printf("\n2.delete");
		printf("\n3.exit");
		printf("\nenter your choice");
		scanf("\n%d",&ch);
		switch(ch)
		{
		case 1:insert();
			   break;
		case 2:deletion();
			   break;	
		//case 3:display();
		//	   break;
		case 3:return 0;
			   break;
		default:printf("\ninvalid choice");
	    }
	}
}
