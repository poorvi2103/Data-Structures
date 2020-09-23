#include<stdio.h>
#include<stdlib.h>
#define n 10
int arr[n];
void bubbleSort(int arr[])
{
	int x,i,j,k;
	for(j=0;j<=n-1;j++)
	{
		for(i=0;i<=n-j-1;i++)
		{
			if(arr[i]>arr[i+1])
			{
				x=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=x;	
				
			}
			
		}
	}
	printf("\n%sorted array is");
	for(k=0;k<=n-1;k++)
	{
		printf("\n  %d",arr[k]);
	}
}
int main()
{
	printf("enter 10 elements");
	for(int i=0;i<=n-1;i++)
	{
		scanf("\n%d",&arr[i]);
	}
	bubbleSort(arr);
}

