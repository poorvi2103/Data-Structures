#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;            //data field
    struct node *next;     //pointer or address field
};

struct node *start1 = NULL;
struct node *start2= NULL;
struct node * ptr2;

struct node * newnode(int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}

void addnode1()    //function to add nodes in a linked list
{
    char ch;
    int data;
    struct node *ptr,*ptr1;
    do
    {
        printf("\nEnter data : ");
        scanf("%d",&data);
        ptr = newnode(data);
        if(start1==NULL)
           	start1 = ptr;
       	else
       	{
           	ptr1 = start1;
           	while(ptr1->next!=NULL)
           	{
               	ptr1 = ptr1->next;
           	}
           	ptr1->next = ptr;
        }
        printf("\nDo you want to enter more nodes?(y/n): ");
        fflush(stdin);    //to empty the buffer if there is any previous value already stored in it
        ch = getchar();   //to get input from user, stores it in char type variable ch
    } while (ch=='y'); 
}
void addnode2()    //function to add nodes in a linked list
{
    char ch;
    int data;
    struct node *ptr,*ptr1;
    do
    {
        printf("\nEnter data : ");
        scanf("%d",&data);
        ptr = newnode(data);
        if(start2==NULL)
            	start2 = ptr;
        else
       	{
           	ptr1 = start2;
           	while(ptr1->next!=NULL)
           	{
               	ptr1 = ptr1->next;
           	}
           	ptr1->next = ptr;                    //ptr is last node's addressj
           	ptr2=ptr;                                //store  last element of 2nd linked list
        }
        printf("\nDo you want to enter more nodes?(y/n): ");
        fflush(stdin);    //to empty the buffer if there is any previous value already stored in it
        ch = getchar();   //to get input from user, stores it in char type variable ch
    } while (ch=='y'); 
    ptr->next=start1->next->next;
}
void display1()
{
	struct node *ptr;
    if(start1==NULL)
        printf("\nList is empty");
    else
    {
        ptr = start1;
        while(ptr!=NULL)
        {
            printf("%d  ",ptr->data);
            ptr = ptr->next;
        }
    }
}
void display2()
{
	struct node *ptr;
    if(start2==NULL)
        printf("\nList is empty");
    else
    {
        ptr = start2;
        while(ptr!=NULL)
        {
            printf("%d  ",ptr->data);
            ptr = ptr->next;
        }
    }
}
void intersection()
{
	printf("\n%d",ptr2->next->data);
}
int main()
{
	int ch;
	while(1)
	{
		printf("\n1.insert 1st linked list");
		printf("\n2.insert 2nd linked list");
		printf("\n3.DIsplay 1st linked list");
		printf("\n4.Display 2nd linked list");
		printf("\n5.intersection point");
		printf("\n6.exit");
		printf("\nenter choice:");
		scanf("\n%d",&ch);
		switch(ch)
		{
			case 1:addnode1();
					break;
			case 2:addnode2();
					break;
			case 3:display1();
					break;
			case 4:display2();
					break;
			case 5:intersection();
			        break;
			case 6:exit(0);
		}
	}
}
