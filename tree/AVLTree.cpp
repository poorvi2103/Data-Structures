#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
struct tree
{
	int data;
	struct tree* left;
	struct tree*  right;
	int height;
};
struct tree* root=NULL;
struct tree* tnn(int data)
{
	struct tree* ptr=(struct tree*)malloc(sizeof(struct tree));
	ptr->data=data;
	ptr->height=1;                                              //height initialised from 1
	ptr->left=NULL;
	ptr->right=NULL;
	return ptr;
}
int height(struct tree* ptr)
{
	if(ptr==NULL)
		return 0;
	return ptr->height;
}
int max(int x,int y)
{
	if(x>y)
		return x;
	return y;
}
int getBF(struct tree* ptr)
{
	if(ptr==NULL)
		return 0;
	return height(ptr->left)-height(ptr->right);             //can aalso do ptr->left->height but will have problem in case of null,coz then null->height
}
struct tree* rightRotate(struct tree* ptr)
{
	struct tree* ptr1=ptr->left;
	struct tree* ptr2=ptr1->right;
	ptr->left=ptr2;
	ptr->right=ptr;
	ptr->height=max(height(ptr->left),height(ptr->right))+1;          
	ptr1->height=max(height(ptr1->left),height(ptr1->right))+1;
	return ptr1;
}
struct tree* leftRotate(struct tree* ptr)
{
	struct tree* ptr1=ptr->right;
	struct tree* ptr2=ptr1->left;
	ptr->right=ptr2;
	ptr1->left=ptr;
	ptr->height=max(height(ptr->left),height(ptr->right))+1;
	ptr1->height=max(height(ptr1->left),height(ptr1->right))+1;
	return ptr1;	
}

struct tree* insert(struct tree *ptr,int ele)                 
{
	int bf;
	if(ptr==NULL)                                  //first node
		return tnn(ele);          
	if(ele>ptr->data)
		ptr->right=insert(ptr->right,ele);
	else if(ptr->data>ele)
		ptr->left=insert(ptr->left,ele);
	else
		return ptr;									//i.e.if duplicate.then simply return ptr
	ptr->height=max(height(ptr->left),height(ptr->right))+1;             //updation of height
	bf=getBF(ptr);
	if(bf<-1 &&ptr->right->data<ele)                //RR rotation i.e rotate in left
		return leftRotate(ptr);
	if(bf<-1 &&ptr->right->data>ele)
	{
		ptr->right=rightRotate(ptr->right);
		return leftRotate(ptr);
	}
	if(bf>1&&ptr->left->data>ele)
		return rightRotate(ptr);
	if(bf>1&&ptr->left->data<ele)
	{
		ptr->left=leftRotate(ptr->left);
		return rightRotate(ptr);
	}
	return ptr;
}   
void createAVLTree()
{
	char ch;
	int ele;
	int data;
	printf("\n enter root data:");
	scanf("\n%d",&data);
	root=insert(root,data);
	printf("\n%d",root->data);
	do
	{
		printf("\n enter element");
		scanf("\n %d",&ele);
		root=insert(root,ele);
		printf("\n do you want to continue(y/n)");
		fflush(stdin);    //to empty the buffer if there is any previous value already stored in it
        ch = getchar();   //to get input from user, stores it in char type variable ch;
		
	}while(ch=='y'||ch=='Y');
}
void inorder(struct tree* ptr)
{
	if(ptr!=NULL)
	{
		inorder(ptr->left);
		printf("\n%d",ptr->data);
		inorder(ptr->right);
	}
}
struct tree* IterativeBinarySearch(struct tree *r,int ele)
{
	while(r!=NULL)
	{
		if(ele==r->data)
			return r;
		else if(ele<r->data)
			r=r->left;
		else
			r=r->right;
	}
	return NULL;
}
struct tree* RecursiveBinarySearch(struct tree *r,int ele)
{
	if(r!=NULL)
	{
		if(ele==r->data)
			return r;
		else if(ele<r->data)
			RecursiveBinarySearch(r->left,ele);
		else
			RecursiveBinarySearch(r->right,ele)	;
	}
	return NULL; 
}
int main()
{
	struct tree* ptr;
	createAVLTree();
	inorder(root);
	ptr=IterativeBinarySearch(root,10);
	printf("\n%d",ptr);
	ptr=RecursiveBinarySearch(root,10);
	printf("\n%d",ptr);
	
	
}
