#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
int n=10;
int arr[10];
void insert(int data)
{
	int index,i=0;
	while(i<n)
	{
		index=((data%10)+i*(7-(data%7)))%10;                 //index=(h(x)+i*(R-(x%R)))%10  ,R=7coz size of array =10,so just smaller prime number
		if(arr[index]!=-1)
		{
			i++;
		}
		else
		{
			arr[index]=data;
			break;
		}
	}
}
int search(int data)
{
	int index,i=0;
	while(i<n&& index!=-1)
	{
		index=((data%10)+i*(7-(data%7)))%10; 
		if(arr[index]==data)
		{
			return 1;                   //successful search
		}
		else
		{
			i++;
		}
	}
	return -1;
}
int main()
{
	int i,ele,result;
	char ch;
	for(i=0;i<n;i++)
	{
		arr[i]=-1;
	}
	i=1;                              //reinitialise i for future use
	do
	{
		printf("\n enter element");
		scanf("\n%d",&ele);
		insert(ele);
		i++;
		if(i<=n)
		{
			printf("\nwant to add more elemets?(y/n)");
			fflush(stdin);    
        	ch = getchar();
		}   
    } while((ch=='y'||ch=='Y')&&i<=n);
    printf("\nenter element to search");
    scanf("%d",&ele);
	result=search(ele);
	if(result==1)
	{
		printf("\nsuccessful search");
	}
	else
	{
		printf("\nunsucessful search");
	}
    
    
    
}
