#include<stdio.h>
#include<stdlib.h>
#define size 20
int n;
int srtend[size][2];
int graph[size][size];
void createGraph()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		printf("\n enter adjacent vertices of %d are present or not ,in sequence 0 to %d(0 if not conected and 1 if connected )",i,n-1);
		for(j=0;j<n;j++)
		{
			scanf("%d",&graph[i][j]);	
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",graph[i][j]);	
			
		}
		printf("\n");
	}
}
int main()
{
	int i;
	printf("\nenter no. of vertices:");
	scanf("\n%d",&n);
	createGraph();
	for(i=0;i<=1;i++)
	{
		for(j=0;j<n-1;j++)
		{
			srtend[i][j]=-1;
		}
	}
	
}

