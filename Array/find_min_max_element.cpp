              /*finding minimum and maximum element from array in single loop with minimum comparisions
                    Time Complexity=O(n)
                    best case: when array is in descending order(only first if statement run in below program)
                               comparisions:n-1
                    worst case:when array is in ascending order (both if statements should run in below code)
                               comparisions:2(n-1)
              */

#include<stdio.h>
#define size 10
int arr[size],n;
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
}

