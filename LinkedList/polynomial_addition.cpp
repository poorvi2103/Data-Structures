#include<stdio.h>
#include<stdlib.h>
struct pnomial
{
	int coeff;
	int exp;
	struct pnomial* next;
};
struct pnomial* start1=NULL;
struct pnomial* start2=NULL;
struct pnomial* start3=NULL;
struct pnomial* nn(int coeff,int exp)
{
	struct pnomial* p=(struct pnomial*)malloc(sizeof(struct pnomial));
	p->coeff=coeff;
	p->exp=exp;
	p->next=NULL;
	return p;
}
void insert1()
{
	int coeff;
	int exp;
	char ch;
	struct pnomial* ptr1;
	printf("\nenter first polynomial");
	do
	{
		
		printf("\nenter coefficient");
		scanf("\n%d",&coeff);
		printf("\nenter exponent ,please in decreasing and continuous order:)");
		scanf("\n%d",&exp);
		struct pnomial* ptr=nn(coeff,exp);
		if(start1==NULL)
			start1=ptr;
		else
		{
		    ptr1=start1;
			while( ptr1->next!=NULL)
			{
				ptr1=ptr1->next;
			}
			ptr1->next=ptr;	
		}
        printf("\nDo you want to enter more nodes?(y/n): ");
        fflush(stdin);    //to empty the buffer if there is any previous value already stored in it
        ch = getchar();   //to get input from user, stores it in char type variable ch
    } while (ch=='y');
	printf("\npolynomial1 is:   ");
	for(struct pnomial* pt=start1;pt!=NULL;pt=pt->next)
	{
		if(pt->coeff>0)
			printf("+%dx^%d",pt->coeff,pt->exp);
		else
			printf("%dx^%d",pt->coeff,pt->exp);
	}
}
void insert2()
{
	int coeff;
	int exp;
	char ch;
	struct pnomial* ptr1;
	printf("\nenter second polynomial");
    do
	{
		
		printf("\nenter coefficient");
		scanf("\n%d",&coeff);
		printf("\nenter exponent , please in decreasing and continuous order:)");
		scanf("\n%d",&exp);
		struct pnomial* ptr=nn(coeff,exp);
		if(start2==NULL)
			start2=ptr;
		else
		{
		    ptr1=start2;
			while( ptr1->next!=NULL)
			{
				ptr1=ptr1->next;
			}
			ptr1->next=ptr;	
		}
        printf("\nDo you want to enter more nodes?(y/n): ");
        fflush(stdin);    //to empty the buffer if there is any previous value already stored in it
        ch = getchar();   //to get input from user, stores it in char type variable ch
    } while (ch=='y');
	printf("\npolynomial2:");  
	for(struct pnomial* pt=start2;pt!=NULL;pt=pt->next)
	{
		if(pt->coeff>0)
			printf("+%dx^%d",pt->coeff,pt->exp);
		else
			printf("%dx^%d",pt->coeff,pt->exp);
			
	} 
}
void add()
{
	struct pnomial* ptr1=start1;         //traversing pointer
	struct pnomial* ptr2=start2; 
	struct pnomial* ptr;            //traversing pointer
	if(start1->exp>start2->exp)
	{
		while(ptr1->exp!=ptr2->exp)
		{
			ptr1=ptr1->next;
		}
		while(ptr1!=NULL&&ptr2!=NULL)
		{
			ptr1->coeff=ptr1->coeff+ptr2->coeff;
			ptr1=ptr1->next;
			ptr2=ptr2->next;
		}
		for(ptr=start1;ptr!=NULL;ptr=ptr->next)
		{
			printf("%dx^%d",ptr->coeff,ptr->exp);
		}
	}
	else
	{
		while(ptr1->exp!=ptr2->exp)
		{
			ptr2=ptr2->next;
		}
		while(ptr2!=NULL&&ptr1!=NULL)
		{
			ptr2->coeff=ptr1->coeff+ptr2->coeff;
			ptr1=ptr1->next;
			ptr2=ptr2->next;
		}
		printf("\nresultant polynomial");
		for(ptr=start2;ptr!=NULL;ptr=ptr->next)
		{
			if(ptr->coeff>=0)
				printf("+%dx^%d",ptr->coeff,ptr->exp);
			else
				printf("%dx^%d",ptr->coeff,ptr->exp);
		}	
	}
}
int main()
{

		
		insert1();
		insert2();
		printf("\n");
		add();
		
}
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
