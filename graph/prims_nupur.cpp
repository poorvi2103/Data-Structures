//Depth First Search
//It is like preorder traversal of tree i.e. if spaning tree is made for this graph and we calculate its preorder then it will be the DFS of the graph

#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int data;
    struct stack *next;
};

struct stack *top=NULL;

struct stack * newnode(int data)
{
    struct stack *ptr = (struct stack *)malloc(sizeof(struct stack));
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}

void push(int data)
{
    struct stack *ptr;
    ptr = newnode(data);
    if(top==NULL)
        top = ptr;
    else
    {
        ptr->next = top;
        top = ptr;
    }
}

int pop()
{
    struct stack *ptr=top;
    int data=top->data;
    top = top->next;
    free(ptr);
    ptr = NULL;
    return data;
}

int checkUnvisitedAdj(int vertex, int graph[7][7], int visited[])
{
    int i;
    for(i=0; i<7; i++)
    {
        if(graph[vertex][i]==1 && visited[i]==0)
        {
            push(vertex);
            return i;
        }
    }
    return -1;
}

void DFS(int start, int visited[], int graph[7][7])
{
    int vertex, i;
    printf("%d ",start);
    visited[start] = 1;
    vertex = checkUnvisitedAdj(start, graph, visited); 
    while(top)
    {
        if(vertex < 0)
        {
            vertex = pop();
            vertex = checkUnvisitedAdj(vertex, graph, visited);
        }
        else
        {
            printf("%d ",vertex);
            visited[vertex] = 1;
            vertex = checkUnvisitedAdj(vertex, graph, visited);
        }
    }
}

int main()
{
    
    int adj_matrix[7][7]={{0,1,1,1,0,0,0},
                          {1,0,1,0,0,0,0},
                          {1,1,0,1,1,0,0},
                          {1,0,1,0,1,0,0},
                          {0,0,1,1,0,1,1},
                          {0,0,0,0,1,0,0},
                          {0,0,0,0,1,0,0}};
    int visited[7]={0};
    printf("\nDepth First Search(DFS) : ");
    DFS(2,visited, adj_matrix);
    return 0;
}
