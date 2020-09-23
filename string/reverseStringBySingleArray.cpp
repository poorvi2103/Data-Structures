#include<conio.h>
#include<stdio.h>
int main()
{
	int i=0,k=0;
	char arr1[2000],temp;
	printf("\n enter string:");
	gets(arr1);
	while(arr1[k]!='\0')             //length of arr1 is k
		k++;
	int j=k;
	printf("\nlength of string is %d",j);
	while(i!=j||j==i-1)
	{
		temp=arr1[j];
		arr1[j]=arr1[i];
		arr1[i]=temp;
		i++;
		j--;
	}
	printf("\n reverse string is:");
	for(i=0;i<=k;i++)
	{
		printf("%c",arr1[i]);
	}
	
	
}
