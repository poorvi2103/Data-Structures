#include<stdlib.h>
#include<stdio.h>
struct tree
{
	int data;
	struct tree* left;
	struct tree*  right;
};
struct queue
{
	struct tree* data;
	struct queue* next;
};
struct queue* front=NULL;
struct queue* rear=NULL;
struct tree* tnn(int data)
{
	struct tree* ptr=(struct tree*)malloc(sizeof(struct tree));
	ptr->data=data;
	ptr->left=NULL;
	ptr->right=NULL;
	return ptr;
}
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
		front=rear=NULL;
	}
	else
	{
		front=front->next;
	}
	return ptr;
}
struct tree* createTree()
{
	struct tree* root;
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
	return root;

}
preorder(struct tree* ptr)
{
	if(ptr!=NULL)
	{
		printf("\n%d",ptr->data);
		preorder(ptr->left);
		preorder(ptr->right);
	}
}
inorder(struct tree* ptr)
{
	if(ptr!=NULL)
	{
		inorder(ptr->left);
		printf("\n%d",ptr->data);
		inorder(ptr->right);
	}
}
postorder(struct tree* ptr)
{
	if(ptr!=NULL)
	{
		postorder(ptr->left);
		postorder(ptr->right);
		printf("\n%d",ptr->data);
	}
}
int countAllNodes(struct tree* ptr)
{
	int c1,c2;
	if(ptr==NULL)
		return 0;
	else
	{
		c1=countAllNodes(ptr->left);
		c2=countAllNodes(ptr->right);
		return c1+c2+1;
	}
}
int countNodesHavingDeg2(struct tree* ptr)
{
	int c1,c2;
	if(ptr==NULL)
		return 0;
	else
	{
		c1=countNodesHavingDeg2(ptr->left);
		c2=countNodesHavingDeg2(ptr->right);
		if(ptr->left&&ptr->right)
			return c1+c2+1;
		else
			return c1+c2;
	}
}
int countNodesHavingDeg1(struct tree* ptr)
{
	int c1,c2;
	if(ptr!=NULL)
	{
		c1=countNodesHavingDeg1(ptr->left);
		c2=countNodesHavingDeg1(ptr->right);
		if(ptr->left&&!ptr->right||(!ptr->left&&ptr->right))
			return c1+c2+1;
		else
			return c1+c2;
	}
	return 0;
}
int countNodesHavingDeg0(struct tree* ptr)
{
	int c1,c2;
	if(ptr!=NULL)
	{
		c1=countNodesHavingDeg0(ptr->left);
		c2=countNodesHavingDeg0(ptr->right);
		if(!ptr->left&&!ptr->right)
			return c1+c2+1;
		else
			return c1+c2;
	}
	return 0;
}
int height(struct tree* ptr)
{
	int h1,h2;
	if(ptr==NULL)
		return 0;
	else
	{
		h1=height(ptr->left);
		h2=height(ptr->right);
		if(h1>h2)
			return h1+1;
		else
			return h2+1;
	}
}
int main()
{
	//int n;
	struct tree* root;
	root=createTree();
	printf("\npreorder is:");
	preorder(root);
	printf("\n inorder is:");
	inorder(root);
	printf("\npostorder is:");
	postorder(root);
	//n=countAllNodes(root);
	printf("\ntotal no.of nodes= %d",countAllNodes(root));
	printf("\n no.of nodes having degree 2= %d",countNodesHavingDeg2(root));
	printf("\n no.of nodes having degree 1= %d",countNodesHavingDeg1(root));
	printf("\n no.of nodes having degree 0= %d",countNodesHavingDeg0(root));
	printf("\nheight of tree is:%d",height(root));
}




























