#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char s[10];
	int i=0;
	int h=0;                                   //h will be stored in memory(64 bit i.e size of int),binary value of zero will be stored in 64 bits
	int x=1;
	printf("\nenter  string:");
	gets(s);
	puts(s);
	while(s[i])
	{
		int x=1;                                  //binary value of 1 will be stored in 64 bits
		x=x<<(s[i]-97);                               //left shifting 1(x) by s[i]-97(subtracting 97 coz only small letters
		//check wether s[i] is on or offi.e masking
		if((h&x)>0)                                     //i.e bit s[i] is on i.e. already s[i] has occured ,means now duplicate
			printf("\n%c",s[i]);
		else                                        //i.e. bit s[i] is off
			h=h|x;                          //merging
			
		i++;
			
	}
}
	
