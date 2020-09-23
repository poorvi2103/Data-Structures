#include<stdio.h>
#include<stdlib.h>

struct doublell
{
    int data;            //data field
    struct doublell *fwd;     //pointer or address field
	struct doublell *bwd;
};

struct doublell *start = NULL;

struct doublell * newnode(int data)
{
    struct doublell *ptr = (struct doublell *)malloc(sizeof(struct doublell));
    ptr->data = data;
    ptr->fwd = NULL;
    ptr->bwd=NULL;
	return ptr;
}

void addnode()      //function to add nodes in a linked list
{
    char ch;
    int data;
    struct doublell *ptr,*ptr1;
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
            while(ptr1->fwd!=NULL)
            {
                ptr1 = ptr1->fwd;
            }
            ptr->bwd=ptr1;
            ptr1->fwd=ptr;
        }
        printf("\nDo you want to enter more nodes?(y/n): ");
        fflush(stdin);    //to empty the buffer if there is any previous value already stored in it
        ch = getchar();   //to get input from user, stores it in char type variable ch
    } while (ch=='y');   
}

void forwardDisplay(struct doublell* ptr)
{
    if(start==NULL)
        printf("\nList is empty");
    else
    {
        while(ptr!=NULL)
        {
            printf("%d  ",ptr->data);
            ptr = ptr->fwd;
        }
    }
}
void backwardDisplay(struct doublell* ptr)
{
	if(start==NULL)
		printf("\nlist is empty");
	else
	{
		while(ptr->fwd!=NULL)
		{
			ptr=ptr->fwd;
		}
		while(ptr!=NULL)
        {
            printf("%d  ",ptr->data);
            ptr = ptr->bwd;
        }
		
	}
}
int countNodes(struct doublell* ptr)
{
		int count=0;
    	while(ptr!=NULL)
    	{
    		count++;
    		ptr=ptr->fwd;
		}
    return count;
}
void insert()
{
	int pos,data,n;
	struct doublell* ptr;
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
		ptr->fwd=start;
		start->bwd=ptr;
		start=ptr;
		}
		else
		{
			struct doublell* ptr1=start;
			for(int c=0;c<pos-2;c++)
			{
				ptr1=ptr1->fwd;
			}
			ptr->fwd=ptr1->fwd;
			ptr->bwd=ptr1;
			ptr1->fwd=ptr;
			ptr->fwd->bwd=ptr;
		}
	}
}
void del()
{
	int pos,c,n;
	struct doublell *ptr=start;
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
				start=start->fwd;
				free(ptr);
				ptr=NULL;
				if(start!=NULL)
					start->bwd=NULL;
			}
			else
			{
				for(c=0;c<pos-1;c++)
			  {                       
				ptr=ptr->fwd;
		   	  }
			  ptr->bwd->fwd=ptr->fwd;
			  if(ptr->fwd!=NULL)                   //i.ptr is not last node
			  	ptr->fwd->bwd=ptr->bwd;
			  free(ptr);
			  ptr=NULL;
			}
		}
	}
}
void update()
{
	int pos,n,c;
	struct doublell* ptr;
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
			ptr=ptr->fwd;
			c++;
		}
		printf("\nenter new data:");
		scanf("%d",&ptr->data);
		
	}
}
void sum()
{
	int sum=0;
	for(struct doublell *ptr=start;ptr!=NULL;ptr=ptr->fwd)
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
		printf("\n3.forward dispaly");
		printf("\n4 backward dispaly");
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
		case 3:forwardDisplay(start);
			   break;
		case 4:backwardDisplay(start);
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
