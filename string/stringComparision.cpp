#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char s1[1000],s2[1000];
	int i,count1=0,count2=0,flag=0;
	printf("\nenter first string:");
	gets(s1);
	printf("\nenter second string:");
	gets(s2);
	while(s1[count1]!='\0')                      //calculating length of string
		count1++;
	printf("\nlenth of string1 is%d",count1);
	while(s2[count2]!='\0')
		count2++;
	printf("\nlenth of string2 is%d",count2);
	if(count1==count2)
	{
		for(i=0;i<=count1-1;i++)
		{
			if(s1[i]<s2[i])
			{
				printf("\ns1 is smaller");
				flag=1;
				break;
			}
			if(s2[i]<s1[i])
			{
				printf("\ns2 is smaller");
				flag=1;
				break;
			}
			
		}
		if(flag!=1)
			printf("\nboth strings are equal");
				
	}
	else if(count1<count2)                               //eg.code and codes
	{
		for(i=0;i<=count1-1;i++)
		{
			if(s1[i]<s2[i])
			{
				printf("\ns1 is smaller");
				flag=1;
				break;
			}
			if(s2[i]<s1[i])
			{
				printf("\ns2 is smaller");
				flag=1;
				break;	
			}
		}
		if(flag!=1)
			printf("\nstring1 is smaller");	
	}
	else
	{                                             //code planet and planet
		for(i=0;i<=count2-1;i++)
		{
			if(s1[i]<s2[i])
				printf("\ns1 is smaller");
				flag=1;
				break;
			if(s2[i]<s1[i])
				printf("\ns2 is smaller");
				flag=1;
				break;
		}
		if(flag!=1)
			printf("\nstring2 is smaller");		
	}
	
}
















