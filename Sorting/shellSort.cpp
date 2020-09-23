#include<conio.h>
#include<stdio.h>
int arr[10];
void shellSort(int n)
{
	int j,gap,i,temp;
	for(gap=n/2;gap>=1;gap=gap/2)                       //loop for gap
	{
		for(j=gap;j<=n-1;j++)                          //loop for j
		{
				
			for(i=j-gap;i>=0;i=i-gap)                             //loop for swapping
			{
				if(arr[i]>=arr[i+gap])
				{
					temp=arr[i];
					arr[i]=arr[i+gap];
					arr[i+gap]=temp;
				}
				else
				{
					break;
				}
			}
		}
	}
}
int main()
{
	printf("enter 10 elements");
	for(int i=0;i<=9;i++)
	{
		scanf("\n%d",&arr[i]);
	}
	shellSort(10);
	printf("\nsorted array is");
	for(int k=0;k<=9;k++)
	{
		printf("\n  %d",arr[k]);
	}

}
