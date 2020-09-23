#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char s1[1000],s2[1000];
	int i=0,j=0,count1=0,count2=0,flag=0;
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
	if(count1!=count2)
	{
		printf("\n not anagram");
		return 0;
	}
	else
	{
		/*for(i=0;i<count1;i++)
		{
			for(j=0;j<count2;j++)
			{
				if(s1[i]!=s2[j])
				{
					continue;	
				}
				else
				{
					break;
				}
			}
		}*/
		while(s1[i])
		{
			if(s1[i]==s2[j])
			{
				i++;
				j=0;
				continue;
			}
			else
				j++;
			if(s2[j]=='\0')
			{
				printf("\n not anagram");
				return 0;
			}
		}
		printf("\n anagram");
	}
}
	
