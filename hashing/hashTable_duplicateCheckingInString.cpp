#include<conio.h>
#include<stdio.h>
int main()
{
	char s[1000];
	int hash[26]={0},i=0;
	printf("\nenter string\n");
	gets(s);
	while(s[i])
	{
		hash[s[i]-97]++;	                             //ascii of 'a' is 97
		i++;
	}
	for(i=0;i<26;i++)
	{
		if(hash[i]>1)                                   //i.e.duplicates present
		{
			printf("\n%c",i+97);                      //printing that duplicate
			printf("\ncount of %c is %d ",i+97,hash[i]);
			
		}
	}
}
