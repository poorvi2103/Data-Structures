#include<stdio.h>
#include<conio.h>
int linearSearch(int arr[], int startIndex,int endIndex,int ele)
{
	int i;
	for(i=startIndex;i<=endIndex;i++)
	{
		if(arr[i]==ele)
		{
			int x=arr[i];                                            //(tranposition approach )
			arr[i]=arr[i-1];                             //(swapping)
			arr[i-1]=x;
			return i;
		}
	}
	return -1;
}
int main()
{
	int arr[]={11,12,7,10,9,6,13,8,19,5,17};
	int ele,result;
	printf("\nenter element to search");
	scanf("%d",&ele);
	result=linearSearch(arr,0,10,ele);
	if(result>=0)
		printf("\nelement found at %d index",result);
	else
		printf("\nelement not found ");
}
