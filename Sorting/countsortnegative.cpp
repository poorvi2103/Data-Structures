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
	int arr[]={-4,4,-2,1,2,-1,4,1,-9,6,-3,4},max=0,i,flag,min;
	for(i=0;i<=11;i++)
	{
		if(arr[i]<0)
			min=arr[i];                    //finding first negative element
		flag=1;
		break;
	
	}
	if(flag==1)                          //finding largest negative
	{
		for(int j=i;j<=11;j++)
		if(min>arr[j])
			min=arr[j];
	}
	printf("\n min element is %d",min);
	min=(-min);
	printf("\n min after sign change is %d",min);
	          //adding min to every element
	for(i=0;i<=11;i++)
	{
		arr[i]=arr[i]+min;
	}
	for(i=0;i<=11;i++)
	{
		if(arr[i]>max)
			max=arr[i];
	
	}
	printf("\n intermediate array:");
	for(i=0;i<11;i++)
		printf("\n%d",arr[i]);
	printf("\n max element is %d",max);
	countSort(arr,11,max);
	for(i=0;i<=11;i++)
	{
		arr[i]=arr[i]-min;
	}
	
	printf("\narray after sorting:");
	for(i=0;i<11;i++)
		printf("\n%d",arr[i]);
}
