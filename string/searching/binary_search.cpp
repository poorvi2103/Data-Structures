#include<stdio.h>
#include<stdlib.h>
#define size 10
int arr[size];
void binarySearch(int arr[],int ele,int startIndex,int endIndex)
{
	while(startIndex<=endIndex)
   {
	 int mid=(startIndex+endIndex)/2;
	 if(arr[mid]==ele)
	 {
		printf("\n index is %d ",mid);
		return;
	 }
	 if(arr[mid]>ele)
		endIndex=mid-1;
	 else 
		startIndex=mid+1;
   }
   printf("\n unsuccessful search ,element not found");
	
}
int main()
{
	int i,ele;
	printf("\nenter elements in sorted order");
	for(i=0;i<=size-1;i++)
	{
		scanf("\n%d",&arr[i]);
	}
	printf("\nenter element to search");
	scanf("\n%d",&ele);
	binarySearch(arr,ele,0,size-1);
}
