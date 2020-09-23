#include<conio.h>
#include<stdio.h>
#define n 10
int arr[n];
void countSort(int arr[],int size,int temp)
{
	int count[10],output[size],i;
	for(i=0;i<10;i++)
		count[i]=0;
	for(i=0;i<size;i++)                            //frequency
		count[(arr[i]/temp)%10]++;                   //frquency based on radix
	for(i=1;i<10;i++)                            
		count[i]=count[i]+count[i-1];
	for(i=size-1;i>=0;i--)                      
	{
		//int x=count[arr[i]]-1;                          
		//output[x]=arr[i];
		output[--count[(arr[i]/temp)%10]] =arr[i];                        
	}
	for(i=0;i<size;i++)
		arr[i]=output[i];
}
void radixSort(int arr[],int size,int max)
{
	int temp;
	for(temp=1;max/temp>0;temp=temp*10)
	{
		countSort(arr,size,temp);
	}
}
int main()
{
	int max=0,i;
	printf("enter 10 elements");
	for( i=0;i<=n-1;i++)
	{
		scanf("\n%d",&arr[i]);
	}
	for(i=0;i<=n-1;i++)
	{
		if(arr[i]>max)
			max=arr[i];
	}
	printf("\n max element is %d",max);
	radixSort(arr,n,max);
	printf("\narray after sorting:");
	for(i=0;i<=n-1;i++)
		printf("\n%d",arr[i]);
}
