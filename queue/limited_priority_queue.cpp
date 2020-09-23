                                                          //limited priority queue
#include<stdio.h>
#include<stdlib.h>
#define size 5
int priority1[size];
int rear1=-1,front1=-1;
int priority2[size];
int rear2=-1,front2=-1;
void insert1()
{
	int data;
	if(rear1==size-1)
	{
		printf("\ncan not enter this key");
		return;
	}
	if(front1==-1)
		front1=rear1=0;
	else
	{
		rear1++;
	}
	printf("\nenter data");
	scanf("\n%d",&priority1[rear1]);
	if(rear1==0)
		front1==0;
}
void insert2()
{
	int data;
	if(rear2==size-1)
	{
		printf("\ncan not enter this key");
		return;
	}
	if(front2==-1)
		front2=rear2=0;
	else
	{
		rear2++;
	}
	printf("\nenter data");
	scanf("\n%d",&priority2[rear2]);
	if(rear2==0)
		front2==0;
}
void deletion()
{
	if(front1==-1&&front2==-1)
	{
		printf("\nqueue is empty");
		return;
	}
	//if(front1==rear1&&rear1!=-1)          //one element in priority1
	//	front1=rear1=-1;
	//else if(front1!=-1&&front1!=rear1)
	//{
	//	front1++;
	//}
	//else if(front1==-1&&front2==rear2&&rear2!=-1)     //one element in priority2
	//{
	//	front2=rear2=-1;
	//}
	//else
	//	front2++;
	if()
}
void display()
{
	int i;
	if(front1==-1&&front2==-1)
	{
		printf("\nqueue is empty");
		return;
	}
	if(front1!=-1)
	{
		for(i=front1;i<=rear1;i++)
		{
			printf("\n%d",priority1[i]);
		}	
	}
	if(front2!=-1)
		for(i=front2;i<=rear2;i++)
		{	
			printf("\n%d",priority2[i]);
		}
}
int main()
{
	int ch;
	int key;
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
		case 1:printf("\nenter key");
			   scanf("\n%d",&key);
			   if(key==1)
		       		insert1();
               else if(key==2)
					insert2();
			   else
			   		printf("\ninvalid key");
			   break;
		case 2:deletion();
			   break;	
		case 3:display();
			   break;
		case 4:return 0;
			   break;
		default:printf("\ninvalid choice");
	    }
	}
}
