/*finding single missing element in sorted array(having positive or negative values  only)using without hash table
                        	                 Time complexity=O(n)
                                        */
#include<stdio.h>
#define size 10
int arr[size],n;
void find()                                            //finding missing element
{
	int diff=0-arr[0];                               //index starts from 0 so difference =index-a[index]
	for(int i=1;i<n;i++)                           
	{
		if(i-arr[i]!=diff)
		{
			for(int j=1;j<arr[i]-arr[i-1];j++)
			{
				printf("\nmissing element is: %d",)
			}
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
	find();
}
