#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;            //data field
    struct node *next;     //pointer or address field
};

struct node *start = NULL;

struct node * newnode(int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}

void addnode()      //function to add nodes in a linked list
{
    char ch;
    int data;
    struct node *ptr,*ptr1;
    do
    {
        printf("\nEnter data : ");
        scanf("%d",&data);
        ptr = newnode(data);
        if(start==NULL)
            start = ptr;
        else
        {
            ptr1 = start;
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

void display()
{
	struct node *ptr;
    if(start==NULL)
        printf("\nList is empty");
    else
    {
        ptr = start;
        while(ptr!=NULL)
        {
            printf("\n%d  ",ptr->data);
            ptr = ptr->next;
        }
    }
}
void rotate()
{
		int count=0;
		int k;
		struct node *ptr= start;
		printf("\n enter number of nodes by which you want to rotate:");
		scanf("\n%d",&k);
        while(ptr->next!=NULL)
        {
            ptr = ptr->next;
        }
        ptr->next=start;
        while(count<k)
        {
        	ptr=ptr->next;
        	count++;
        }
        start=ptr->next;
        ptr->next=NULL;
}
int main()
{
	addnode();
	display();
	rotate();
	display();
	
}
