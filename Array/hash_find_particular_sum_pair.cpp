#include<stdio.h>
#define size 20
int hash[100];
int arr[size],n,sum;
int min,max;
void findMaxMin()
{
	int i=0;
	min=max=arr[0];
	for(i=1;i<n;i++)
	{
		if(arr[i]<min)
			min=arr[i];
		else if(arr[i]>max)                    //used else if and not if to reduce comparisions coz if any element is min,then it can't be max and vice versa
			max=arr[i];
	}
	printf("\n maximum element is %d:",max);
	printf("\n minimum element is %d:",min);
}
void findPair()
{
	int i;
	for(i=0;i<n;i++)
	{
		if(arr[i]<sum)
		{
			if(hash[sum-arr[i]]!=0)
			{
				printf("\n%d %d",arr[i],sum-arr[i]);
			}
			hash[arr[i]]++;
		}
	}
}
int main()
{
	
	printf("\n enter number of elements:");
	scanf("\n%d",&n);
	printf("\nenter sum:");
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
	findMaxMin();
	for(int i=0;i<=max;i++)                           //elements in hash[]=max
	{
		hash[i]=0;                              //initialising hsh[] to 0
	}
	findPair();
}
