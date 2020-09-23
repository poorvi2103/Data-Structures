#include<stdio.h>
#include<stdlib.h>
void merge(int A[],int start,int mid,int end)
{
	int i=start,j=mid+1,k=start;
	int B[end+1];
	while(i<=mid&& j<=end)
	{
		if(A[i]<=A[j])
		{
			B[k++]=A[i++];
		}
		else
		{
			B[k++]=A[j++];
		}
	}
	while(i<=mid)
	{
		B[k++]=A[i++];
	}
	while(j<=end)
	{
		B[k++]=A[j++];
	}
	for(i=start;i<=end;i++)
	{
		A[i]=B[i];
	}
}
void mergeSort(int arr[],int start,int end)
{
	int mid;
	if(end>start)
	{
		mid=(start+end)/2;
		mergeSort(arr,start,mid);
		mergeSort(arr,mid+1,end);
		merge(arr,start,mid,end);
	}
}
int main()
{
	int arr[10];
	printf("enter 10 elements");
	for(int i=0;i<=9;i++)
	{
		scanf("\n%d",&arr[i]);
	}
	mergeSort(arr,0,9);
	printf("\nsorted array:");
	for(int i=0;i<=9;i++)
	{
		printf("\n%d",arr[i]);
	}
	
}
