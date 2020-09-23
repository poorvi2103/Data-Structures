#include<stdlib.h>
#include<stdio.h>
struct tree
{
	int data;
	struct tree* left;
	struct tree*  right;
};
struct tree* root=NULL;
struct tree* tnn(int data)
{
	struct tree* ptr=(struct tree*)malloc(sizeof(struct tree));
	ptr->data=data;
	ptr->left=NULL;
	ptr->right=NULL;
	return ptr;
}
struct tree* insert(struct tree *r,int ele)                  //time complexity for creating bst with n nodes is nlogn
{
	struct tree* ptr1;
	struct tree* ptr=NULL;
	while(r!=NULL)
	{
		ptr=r;                         //back pointer coz after loop termination,r will be null
		if(ele==r->data)
			return NULL;              //duplicates not allowed
		else if(ele<r->data)
			r=r->left;
		else
			r=r->right;
	}
	ptr1=tnn(ele);                  
	if(ptr!=NULL)	             //coz in case of root,ptr will be null
	{
		if(ele>ptr->data)
			ptr->right=ptr1;
		else
	    	ptr->left=ptr1;
	}
	return(ptr1);                    //only for inserting root,otherwise no use
	
}
void createBSTree()
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
		insert(root,ele);
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
int INS(struct tree* ptr)              //finding inorder successori.e leftmost element of right subtree
{
	while(ptr&&ptr->left)                //i.e.while ptr1=null and ptr->left!=null
	{
		ptr=ptr->left;
	}
	return ptr->data;
}
int INP(struct tree* ptr)             //finding inorder predessori.e rightmost element of left subtree
{
	while(ptr&&ptr->right)
	{
		ptr=ptr->right;    
	}
	return ptr->data;
	
}
struct tree* del(struct tree * ptr,int ele)
{
	struct tree* ptr1;
	if(ptr!=NULL)
	{
		if(!ptr->left&&!ptr->right&&ptr->data==ele) ;                  //leaf node
		{
			if(ptr==root)                       //if root only
			{
				root=NULL;
				return NULL;
			}
			free(ptr);
			return NULL;
		}
		else                      //reaching/searching elemenT which we want to delete
		{
			if(ele>ptr->data)
				ptr->right=del(ptr->right,ele);
			else if(ele<ptr->data)
				ptr->left=del(ptr->left,ele);
			else
			{
				if(height(ptr->left)<height(ptr->right))        //will delete from where height is more so that height remains  balanced coz if height is balanced then searching will be fast
			   {
				ptr1=INS(ptr->right);                      //ptr1 is inorder successor here of ptr which we want to deletegly
				ptr->data=ptr1->data;
				ptr->right=del(ptr->right,ptr1->data);	
					
			   }
			   else
			   {
				ptr1=INP(ptr->left);
				ptr->data=ptr1->data;
				ptr->left=del(ptr->left,ptr1->data);
			   }
			}
		}                   //end of else
		return ptr;        
	}                      //end of if
	return NULL;
}
int height(struct tree * ptr)
{
	int x,y;
	x=height(ptr->left)
	y=height(ptr->right);
	if(x>y)
		return x+1;
	else
		return y+1;
}
int main()
{
	int ele;
	struct tree* ptr;
	createBSTree();
	inorder(root);
	ptr=IterativeBinarySearch(root,10);
	printf("\n%d",ptr);
	ptr=RecursiveBinarySearch(root,10);
	printf("\n%d",ptr);
	printf("\n inorder successor of root is:%d",root->right);
	printf("\n inorder predessor is:%d",root->left);
	printf("\n enter elemnt to delete");
	scanf("\n%d",&ele);
	del(root,ele);
	inorder(root);
}
