#include<stdio.h>
#include<stdlib.h>
void countSort(int arr[],int size,int max)
{
	int count[max+1],output[size],i;
	for(i=0;i<=max;i++)
		count[i]=0;
	for(i=0;i<size;i++)                            //frequency of elements
		count[arr[i]]++;
	for(i=1;i<=max;i++)                            //giving index in sorted array
		count[i]=count[i]+count[i-1];
	for(i=size-1;i>=0;i--)                      //starting loop from  back for stability
	{
		//int x=count[arr[i]]-1;                         //giving index(x) of arr[i] in sorted array 
		//output[x]=arr[i];
		output[--count[arr[i]]] =arr[i];                        
	}
	for(i=0;i<size;i++)
		arr[i]=output[i];
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
