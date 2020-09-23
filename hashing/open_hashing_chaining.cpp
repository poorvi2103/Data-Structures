#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
# define size 20
struct node
{
    int data;            //data field
    struct node *next;     //pointer or address field
};

struct node* start[size];

struct node * newnode(int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}
void insert(int data)
{
		struct node *ptr,*ptr1,*ptr2=NULL;
		ptr=newnode(data);
		ptr1=start[data%10];
		while(ptr1!=NULL&&ptr->data>ptr1->data)
		{
			ptr2=ptr1;                           //ptr2 is back pointer
			ptr1=ptr1->next;
		}
		ptr->next=ptr1;
		if(ptr1!=start[data%10])                      //i.e. ptr1 is not pointing to first node
		{
			ptr2->next=ptr;
		}
		else
			start[data%10]=ptr;
		
}
int search(int data)
{
	struct node *ptr=start[data%10];
	while(ptr)
	{
		if(ptr->data==data)
			return 1;
		if(ptr->data>data)
			return -1;                     //since in sorted array,so this condition means element is not present
		ptr=ptr->next;
	}
	return -1;                 //only execute whn ptr is null
}
int main()
{
	int ele,result,element;
	char ch;
	do
	{
		printf("\n enter element");
		scanf("\n%d",&ele);
		insert(ele);
		printf("\nwant to add more elemets?(y/n)");
		fflush(stdin);    
        ch = getchar();   
    } while(ch=='y'||ch=='Y');
	printf("\n enter element to search: ");
	scanf("%d",&element);
	result=search(element);
	if(result==1)
	{
		printf("\nsuccessful search");
	}
	else
	{
		printf("\nunsucessful search");
	}
	
}
