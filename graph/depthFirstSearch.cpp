#include<stdio.h>
#include<stdlib.h>
#define size 10
int graph[size][size];
int n;
int visit[1000];
int x;

struct stack
{
	int data;
	struct stack* next;
	
};
struct stack* top=NULL;
struct stack* nn(int data)
{
	struct stack* p=(struct stack*)malloc(sizeof(struct stack));
	p->data=data;
	p->next=NULL;
	return p;
}
void push(int data)
{
	struct stack* ptr;
	ptr=nn(data);
	if(top==NULL)
	{
		top=ptr;
	}
	else
	{
		ptr->next=top;
		top=ptr;
	}		
}
void pop()
{
	struct stack* ptr;
		ptr=top;
		top=top->next;
		free(ptr);
		ptr=NULL;
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
int checkAdjUnvisited(int y)
{
	for(int i=0;i<n;i++)
	{
		if(graph[y][i]==1&&visit[i]==0)
		{
			push(y);
			return i;                                 //returns unvisited adjacent node of y
		}	
	return -1;
}
void DFS(int start)
{
    int i,j,k,l;
	printf("\n%d",start);
	visit[start]=1;
	x=checkAdjUnvisited(start);
	while(top!=NULL)
	{
		if(x!=-1)                   //i.e.adjacent unvisited is present
		{
			printf("\n%d",x);
			visit[x]=1;
			x=checkAdjUnvisited(x);
		}
		else
		{
			x=top->data;
			l=checkAdjUnvisited(k);
				if(l==-1)
				{
					pop();
				}
				else
				{
					i=l;
				}
			}
		}
	}
}
int main()
{
	int i;
	printf("\nenter no. of vertices:");
	scanf("\n%d",&n);
	for(x=0;x<n;x++)
	{
		visit[x]=0;
	}
	createGraph();
	DFS(0);
}
