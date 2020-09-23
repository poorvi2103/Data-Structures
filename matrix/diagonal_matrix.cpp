#include<stdio.h>
#define size 10
int arr[size],n;
int get(int i,int j)
{
	if(i==j)
		return arr[i];
	else if(i!=j)
		return 0;
}
void display()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j)
			{
				printf("%d ",arr[i]);
			}
			else
			{
				printf("0 ");
			}
		}
		printf("\n");
	}
}
int main()
{
	int i,j,ele;
	char ch;
	printf("\nenter no.of  diagonal elements: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nenter %d row,%d column diagonal element:",i,i);
		scanf("%d",&arr[i]);
	}
	printf("\nenter index of which element you want to get seperated by space");
	scanf("%d %d",&i,&j);
	if(i>=n||j>=n)
	{
		printf("\n no such index");
	}
	else
		printf("\n%d",get(i,j));
	printf("\n");
	display();
}
