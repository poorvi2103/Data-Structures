#include<stdio.h>
#include<stdlib.h>
void countSort(int arr[],int size,int max)
{
	int count[max+1],output[size],i,j=0;
	for(i=0;i<=max;i++)
		count[i]=0;
	for(i=0;i<size;i++)                            //frequency of elements
		count[arr[i]]++;
	i=0;
	while(j<=max && i<size)
	{
		if(count[j]>0)
		{	arr[i++]=j;
			count[j]--;
		}
		else
			j++;
	}
}
int main()
{
	int arr[]={4,2,1,2,1,4,1,9,6,3,4},max=0,i;
	for(i=0;i<11;i++)
	{
		if(arr[i]>max)
			max=arr[i];
	}
	printf("\n max element is %d",max);
	countSort(arr,11,max);
	printf("\narray after sorting:");
	for(i=0;i<11;i++)
		printf("\n%d",arr[i]);
}
