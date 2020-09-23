#include<stdio.h>
#include<stdlib.h>
#define n 5
int arr[n];
void add()
{
	
	printf("\nenter array:");
	for(int i=0;i<=n-1;i++)
	{
		scanf("\n%d",&arr[i]);
	}
		
}
void selectionSort()
{
	int i,j;
	int min;
	int x;
	for(i=0;i<n;i++)                //for passes
	{
		min=i;
		int j;
		
		for(j=i+1;j<n;j++)
		{
		
			if(arr[j]<arr[min])
			{
				min=j;	
			}
		}                            j//swapping
		x=arr[min];
		arr[min]=arr[i];
		arr[i]=x;
		
	}
	
}
void display()
{
	int i;
	printf("\nsorted array is:");
	for(i=0;i<n;i++)
	{
		printf("\n%d",arr[i]);	
	}
}
int main()
{
	add();
	selectionSort();
	display();
}


