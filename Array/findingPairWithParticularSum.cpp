#include<stdio.h>
#define size 10
int arr[size],n,sum;
void find()
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)                          complexity=o(n*n)
		{
			if(arr[i]+arr[j]==sum)
			{
				printf("\n%d %d",arr[i],arr[j]);
				break;
			}
			
		}
	}
}
int main()
{
	
	printf("\n enter number of elements:");
	scanf("\n%d",&n);
	printf("\nenter sum");
	scanf("%d",&sum);
	printf("\nenter elements:");
	for(int i=0;i<n;i++)
	{
		scanf("\n%d",&arr[i]);
	}
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	find();
}
