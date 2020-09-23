#include<stdio.h>
#define n 5
int arr[(n*(n+1))/2];
void insert(int i,int j,int ele)
{
	if(j>=i)                                                //inserting row by row
	{
		arr[(n-(i*(i-1))/2)+j-i]=ele;	
	}
}
int get(int i,int j)
{
	if(i<=j)
		return arr[(n-(i*(i-1))/2)+j-i];
	else if(i>j)
		return 0;
}
void display()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d ",get(i,j));
		}
		printf("\n");
	}
}
int main()
{
	int i,j,ele;
	char ch;
	for(i=0;i<(n*(n+1))/2;i++)
	{
		printf("\nenter row,column,element seperated by space");
		scanf("%d %d %d",&i,&j,&ele);
	}
	
	display();
}
