                                //finding pairs which give sum k in sorted array without using hash table
#include<stdio.h>
#define size 10
int arr[size],n,k;
void findPair()
{
	int i=0,j=n-1;                            //starting j from end
	while(j>i)
	{
		if(arr[i]+arr[j]==k)
		{
			printf("\n%d  %d",arr[i],arr[j]);
			i++;
			j--;
		}
		else if(arr[i]+arr[j]>k)
			j--;
		else
			i++;
	}
}
int main()
{
	printf("\n enter number of elements:");
	scanf("\n%d",&n);
	printf("\nenter sum value:");
	scanf("\n%d",&k);
	printf("\nenter elements:");
	for(int i=0;i<n;i++)
	{
		scanf("\n%d",&arr[i]);
	}
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	findPair();
}
