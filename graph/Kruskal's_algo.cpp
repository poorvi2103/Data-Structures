#include<stdio.h>
#include<stdlib.h>
#define size 1000
int n1;                               //no of edges
int n2;                             //no. of vertices
int graph[3][size];                         //no.of columns in graph=no.of edges
int parent[size];                           //size of parent  =  no. of vertex      , parent array gives parent of particular vertex
int visited[size];                			//size of visited = no.of edges
int result[2][size];                       //no.of columns in result =  eges of minimum spanning tree = vertex -1 i.e n2-1
void createGraph()
{
	int i;
	for(i=0;i<n1;i++)
	{
		printf("\nenter starting vertex");
		scanf("\n%d",&graph[0][i]);
		printf("\nenter end vertex");
		scanf("\n%d",&graph[1][i]);
		printf("\nenter cost");
		scanf("\n%d",&graph[2][i]);
	}
	for(i=0;i<n1;i++)
	{
		printf("%d ",graph[0][i]);
	}
	printf("\n");
	for(i=0;i<n1;i++)
	{
		printf("%d ",graph[1][i]);
	}
	printf("\n");
	for(i=0;i<n1;i++)
	{
		printf("%d ",graph[2][i]);
	}
	printf("\n");
}
void unionVertex(int v1,int v2)
{
	if(parent[v1]>parent[v2])                //elements in v2 is more than v1(coz negative values),then make v2 parent
	{
		parent[v2]=parent[v1]+parent[v2];
		parent[v1]=v2;
	}
	else
	{
		parent[v1]=parent[v1]+parent[v2];
		parent[v2]=v1;
	}
}
int find(int v)                              //find parent of v in parent[]
{
	int v1=v;                                    //so that original v is stored if want to use in future
	while(parent[v1]>0)                            //coz to find parent of union set,parent[] value should be negative
	{
		v1=parent[v1];
	}
	return v1;                                   //return parent of union set
}
void minimumCost()
{
	int i=0,j,p,v1,v2;
	while(i<n2-1)                        //coz no.of columns in result[][]= no.of vertex-1 = n2-1
	{
		int min=999999;
		for(j=0;j<n1;j++)
		{
			if(visited[j]==0&& graph[2][j]<min)      
			{
				min=graph[2][j];                       //finding minimum cost from graph
				p=j; 
				v1=graph[0][j];                                    //store j in p
				v2=graph[1][j];
				
			}                     
		}
		visited[p]=1;
		if(find(v1)!=find(v2))
		{
			result[0][i]=v1;
			result[1][i]=v2;
			unionVertex(find(v1),find(v2));
			i++;
		}
	}
	
	
	
}
int main()
{
	int i;	
	printf("\nenter no.of edges");
	scanf("\n%d",&n1);
	printf("\nenter no. of vertices");
	scanf("\n%d",&n2);
	for( i=0;i<n1;i++)
	{
		visited[i]=0;
	}
	for(i=0;i<n2;i++)
	{
		parent[i]=-1;
	}
	createGraph();
	minimumCost();
	printf("\nresult is:");
	printf("\n");
	for(i=0;i<n2-1;i++)
	{
		printf("%d ",result[0][i]);
	}
	printf("\n");
	for(i=0;i<n2-1;i++)
	{
		printf("%d ",result[1][i]);
	}
}
