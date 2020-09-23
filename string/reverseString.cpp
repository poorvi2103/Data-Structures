#include<conio.h>
#include<stdio.h>
int main()
{
	int i,j=0,k=0;
	char arr1[2000],arr2[2000];
	printf("\n enter string:");
	gets(arr1);
	while(arr1[k]!='\0')             //length of arr1 is k
		k++;
	for(i=k-1;i>=0;i--)
	{
		
		arr2[j]=arr1[i];
		j++;
	}
	for(i=0;i<k;i++)
	{
		printf("%c",arr2[i]);
	}
	
	
}
