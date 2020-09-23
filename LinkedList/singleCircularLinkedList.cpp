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
        {
        	start = ptr;
            start->next=start;
		}
        else
        {
        	ptr1=start;
			while(ptr1->next!=start)
        	{
        		ptr1=ptr1->next;        //ptr1 is pointing last node
			}
			ptr->next=ptr1->next;
			ptr1->next=ptr;
        }
        printf("\nDo you want to enter more nodes?(y/n): ");
        fflush(stdin);    //to empty the buffer if there is any previous value already stored in it
        ch = getchar();   //to get input from user, stores it in char type variable ch
    } while (ch=='y');   
}

void display(struct node* ptr)
{
    if(start==NULL)
        printf("\nList is empty");
    else
    {
        do
        {
            printf("%d  ",ptr->data);
            ptr = ptr->next;
        }while(ptr!=start);
    }
}
int countNodes(struct node* ptr)
{
	int count=0;
	if(start==NULL)
		return 0;
	else
	{
		do
        {
            count++;
            ptr = ptr->next;
        }while(ptr!=start);
    	return count;
    }
}
void insert()
{
	int pos,data,n;
	struct node* ptr,*ptr1;;
	n=countNodes(start);
	printf("\n enter position");
	scanf("\n%d",&pos);
	if(pos<=0||pos>n+1)
		printf("\ninvalid position");
	else
	{
		printf("\nenter data");
		scanf("\n%d",&data);
		ptr=newnode(data);
		if(pos==1)
		{
			ptr1=start;
			ptr->next=start;
			start=ptr;
			while(ptr1->next!=start)      //i.e ptr1 pointing last node
			{
				ptr1=ptr1->next;
			}
			ptr1->next=start;
		}
		else
		{
			struct node* ptr1=start;
			for(int c=0;c<pos-2;c++)
			{
				ptr1=ptr1->next;          //ptr1 pointing to position-1 node
			}
			ptr->next=ptr1->next;
			ptr1->next=ptr;
		}
	}
}
void del()
{
	int pos,c,n;
	struct node *ptr=start,*ptr1;
	if(start==NULL)
        printf("\nList is empty");
	else
	{
		printf("\nenter position:");
		scanf("\n%d",&pos);
		n=countNodes(start);
		if(pos<=0||pos>n+1)
			printf("\ninvalid position");
		else
		{
			if(pos==1)
			{
				start=start->next;
				free(ptr);
				ptr=NULL;
			}
			else
			{
				for(c=0;c<pos-1;c++)
			  {
				ptr1=ptr;                         //ptr1=back pointer
				ptr=ptr->next;
		   	  }
			  ptr1->next=ptr->next;
			  free(ptr);
			  ptr=NULL;
			}
		}
	}
}
void update()
{
	int pos,n,c;
	struct node* ptr;
	printf("\n enter position:");
	scanf("%d",&pos);
	n=countNodes(start);
	if(pos<=0||pos>n)
		printf("\ninvalid position");
	else
	{
		ptr=start;
		c=0;
		while(pos-1>c)         //ptr pointing node which we want to update
		{
			ptr=ptr->next;
			c++;
		}
		printf("\nenter new data:");
		scanf("%d",&ptr->data);
		
	}
}
void sum()
{
	int sum=0;
	for(struct node *ptr=start;ptr!=NULL;ptr=ptr->next)
	{
		sum=sum+ptr->data;	
	}
	printf("\nsum is:%d",sum);
}
int main()
{
	int ch,x;
	while(1)
	{
		printf("\n1.add");
		printf("\n2.insert");
		printf("\n3.dispaly");
		printf("\n4.recursive dispaly");
		printf("\n5.count nodes");
		printf("\n6.delete");
		printf("\n7.update");
		printf("\n8.sum of data");
		printf("\n9.exit");
		printf("\nenter your choice");
		scanf("\n%d",&ch);
		switch(ch)
		{
			case 1:addnode();
					break;
		case 2:insert();
			   break;	
		case 3:display(start);
			   break;
		case 5:x=countNodes(start);
				printf("\nno.of nodes is %d",x);
				break;
		case 6:del();
				break;
		case 7:update();
				break;
		case 8: sum();
				break;
		case 9:exit(0);
		default:printf("\ninvalid choice");
	    }
	}
}
