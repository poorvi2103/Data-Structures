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

void addNode(int i)      //function to add nodes in a linked list
{
    char ch;
    int data;
    struct node *ptr,*ptr1;
    do
    {
        printf("\nEnter vertex : ");
        scanf("%d",&data);
        ptr = newnode(data);
        if(start[i]==NULL)                //first node
            start[i] = ptr;
        else
        {
            ptr1 = start[i];
            while(ptr1->next!=NULL)
            {
                ptr1 = ptr1->next;
            }
            ptr1->next = ptr;
        }
        printf("\nDo you want to enter more vertices?(y/n): ");
        fflush(stdin);    //to empty the buffer if there is any previous value already stored in it
        ch = getchar();   //to get input from user, stores it in char type variable ch
    } while (ch=='y');   
}
void createGraph(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("\nenter adjacent vertices of %d",arr[i]);
		addNode(i);
	}
}
void display(struct node* ptr,int i)
{
    
        while(ptr!=NULL)
        {
            printf("%d  ",ptr->data);
            ptr = ptr->next;
        }
}
int main()
{
	int n,i,arr[size];
	printf("\n enter no. of vertices");
	scanf("\n%d",&n);
	printf("\n enter vertices");
	for(i=0;i<n;i++)
	{
		scanf("\n%d",&arr[i]);
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	createGraph(arr,n);
	for(i=0;i<n;i++)
	{
		printf("\n adjacent vertices of %d are:",arr[i]);
		display(start[i],i);
	}
	
	
}
