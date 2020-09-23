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
        if(start==NULL)                //first node
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
void insertAtSorted(
void insertionSort(struct node* ptr2)
{
	struct node *ptr3,start1=NULL;              //start1 is start of remaining unsorted linked list
	while(ptr2!=NULL)
	{
		
		ptr3=ptr2->next;
		start1=insertAtSorted(start1,ptr2);            
		ptr2=ptr3;
	}
}
