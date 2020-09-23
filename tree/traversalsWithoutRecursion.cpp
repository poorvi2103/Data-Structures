h#include<stdlib.h>
#include<stdio.h>
                                                                //for tree
struct tree
{
	int data;
	struct tree* left;
	struct tree*  right;
};
struct tree* root;
//struct tree* lastAddress;
struct tree* tnn(int data)
{
	struct tree* ptr=(struct tree*)malloc(sizeof(struct tree));
	ptr->data=data;
	ptr->left=NULL;
	ptr->right=NULL;
	return ptr;
}

                                                                    //FOR QUEUE
struct queue
{
	struct tree* data;
	struct queue* next;
};
struct queue* front=NULL;
struct queue* rear=NULL;
struct queue* nn(struct tree* data)                                       //data of queue means address of nodes of tree
{
	struct queue* ptr=(struct queue*)malloc(sizeof(struct queue));
	ptr->data=data;
	ptr->next=NULL;
	return ptr;
}
void insert(struct tree* data)
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
struct tree*  deleteelement()
{
	struct tree* ptr;
	ptr=front->data;
	if(front==rear)										//single element
	{
	    //lastAddress=front->data;
		front=rear=NULL;
	}
	else
	{
		front=front->next;
	}
	return ptr;
}
 
                                                        //CREATION OF TREE


void createTree()
{
	//struct tree* root;
	struct tree* ptr;
	struct tree* ptr1;
	int data;
	printf("\n enter root data:");
	scanf("\n%d",&data);
	root=tnn(data);
	insert(root);
	while(front!=NULL)
	{
		ptr1=deleteelement();
		printf("\n enter left data:");
		scanf("\n%d",&data);
		if(data!=-1)
		{
			ptr=tnn(data);
			ptr1->left=ptr;
			insert(ptr);
		}
		printf("\n enter right data:");
		scanf("\n%d",&data);
		if(data!=-1)
		{
			ptr=tnn(data);
			ptr1->right=ptr;
			insert(ptr);
			
		}

	}
	

}
                                                      //FOR STACK
struct stack
{
	struct tree* data;
	struct stack* next=NULL;
};
struct stack* top=NULL;
struct stack* snn(struct tree* data)
{
	struct stack* ptr=(struct stack*)malloc(sizeof(struct stack*));
	ptr->data=data;
	ptr->next=NULL;
	return ptr;
}
void push(struct tree* data)
{
	struct stack* ptr=snn(data);
	if(top==NULL)
	{
		top=ptr;                           //root pushed	
	}	
	else
	{
		ptr->next=top;
		top=ptr;	
	}
}
struct tree* pop()
{
	struct tree* ptr=top->data;
	top=top->next;
	return ptr;
}
void preorder(struct tree* ptr)
{
	printf("\n%d",ptr->data);
	push(ptr);
	ptr=ptr->left;
	while(top!=NULL||ptr!=NULL)
	{
		if(ptr!=NULL)
		{
			printf("\n%d",ptr->data);
			push(ptr);
			ptr=ptr->left;
			
		}
		else
		{
			ptr=pop();
			ptr=ptr->right;
		}
	}
	//printf("\n%d",lastAddress->data);
}
void inorder(struct tree* ptr)
{
	while(top!=NULL||ptr!=NULL)
	{
		if(ptr!=NULL)
		{
			
			push(ptr);
			ptr=ptr->left;
			
		}
		else
		{
			ptr=pop();
			printf("\n%d",ptr->data);
			ptr=ptr->right;
		}
	}
	
}
void postorder(struct tree* ptr)                               //**
{
	if(ptr!=NULL)
	{
		postorder(ptr->left);
		postorder(ptr->right);
		printf("\n%d",ptr->data);
	}
}
void levelorder(struct tree* ptr)
{
	insert(ptr);
	while(front!=NULL)
	{	
		ptr=deleteelement();
		printf("\n%d",ptr->data);
		if(ptr->left!=NULL)
			insert(ptr->left);
		if(ptr->right!=NULL)
			insert(ptr->right);
	}
}
int main()
{
	//struct tree* root;
	createTree();
	printf("\npreorder is:");
	preorder(root);
	printf("\n inorder is:");
	inorder(root);
	printf("\npostorder is:");
	postorder(root);
	printf("\nlevelorder is:");
	levelorder(root);
}



























