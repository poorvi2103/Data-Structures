#include<stdio.h>
#include<stdlib.h>
partition(int arr[],int start,int end)
{
		int pivot=arr[end],i,index=start,temp;
		for(i=start;i<end;i++)
		{
			if(arr[i]<=pivot)
			{
				temp=arr[i];
				arr[i]=arr[index];
				arr[index]=temp;
				index++;h
			}
		}
		arr[end]=arr[index];
		arr[index]=pivot;
		return index;
}
void quickSort(int arr[],int start,int end)
{
	int pindex;
	if(end>start)
	{
		pindex=partition(arr,start,end);
		quickSort(arr,start,pindex-1);         //left array
		quickSort(arr,pindex+1,end); 
		          //right arrayfj
	}
}
int main()
{
	int i;
	int arr[]={7,2,1,6,8,5,4,9,3};
	quickSort(arr,0,8);
	for(i=0;i<=8;i++)
		printf("\n%d",arr[i]);
}
