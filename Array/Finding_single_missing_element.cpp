                                                /*finding single missing element from array using hash table
                                                  Time complexity:O(n)
												*/
                                                
#include<stdio.h>
#define size 10
int arr[size],n;
int min,max;
int hash[100];
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
void find()                                            //finding missing element
{
	for(int i=0;i<n;i++)
	{
		hash[arr[i]-min]++;            //increasing count
	}
	for(int i=0;i<=max-min;i++)                           //elements in hash[]=max-min+1
	{
		if(hash[i]==0)
		{
			printf("\nmissing element is: %d",i+min);
			break;
		}
	}
}
int main()
{
	printf("\n enter number of elements:");
	scanf("\n%d",&n);
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
	for(int i=0;i<=max-min;i++)                           //elements in hash[]=max-min+1
	{
		hash[i]=0;                              //initialising hsh[] to 0
	}
	find();
}
