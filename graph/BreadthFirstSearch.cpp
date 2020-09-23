#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#define size 10
int graph[size][size];
int n;
struct queue
{
	int data;
	struct queue* next;
};
struct queue* front=NULL;
struct queue* rear=NULL;
struct queue* nn(int data)
{
	struct queue* ptr=(struct queue*)malloc(sizeof(struct queue));
	ptr->data=data;
	ptr->next=NULL;
	return ptr;
}

void insert(int data)
{
	struct queue* ptr=nn(data);
	if(front==NULL)										//empty queue
	{
		front=rear=ptr;
	}
	else
	{
		rear->next=ptr;
		rear=ptr;
	}
}
int del()
{
		struct queue* ptr;
		int x;
		x=front->data;
		ptr=front;
		front=front->next;
		free(ptr);
		ptr=NULL;
		return x;
}

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
void BFS(int s,int visit[])
{
	int y,i;
	insert(s);
	printf("\n%d",s);
	visit[s]=1;
	while(front)
	{
		y=del();
		for(i=0;i<n;i++)            //checking adjacent vertex
		{
			if(graph[y][i]==1&& visit[i]==0)
			{
				printf("\n%d",i);
				visit[i]=1;
				insert(i);
			}
		}
		
	}
}
int main()
{
	int i;
	printf("\nenter no. of vertices:");
	scanf("\n%d",&n);
	createGraph();
	int visit[n];
	for(int i=0;i<n;i++)
	{
		visit[i]=0;
	}
	BFS(1,visit);
}
