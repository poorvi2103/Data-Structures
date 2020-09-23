#include<stdio.h>
#include<stdlib.h>
char infix[30]="a+b/(c*d)*(e+f*g)+h";
char postfix[30];
struct stack
{
	char data;
	struct stack* next;
	
};
struct stack* top=NULL;
struct stack* nn(char data)
{
	struct stack* p=(struct stack*)malloc(sizeof(struct stack));
	p->data=data;
	p->next=NULL;
	return p;
}
void push(char data)
{
	struct stack* ptr;
	ptr=nn(data);
	if(top==NULL)
	{
		top=ptr;
	}
	else
	{
		ptr->next=top;
		top=ptr;
	}
}
char pop()
{
	struct stack* ptr;
	char data=top->data;
	ptr=top;
	top=top->next;
	free(ptr);
	ptr=NULL;
	return data; 
}
char peek()
{
	return top->data;
}
int checkOperand(char ch)
{
	if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9'))
		return 1;
	return 0;
}
int priority(char ch)
{
	if(ch=='+'||ch=='-')
		return 1;
	else if(ch=='*'||ch=='/')
		return 2;
	else
		return -1;
}
void infixToPostfix()
{
	int i,j=0;
	for(i=0;infix[i];i++)
	{
		if(checkOperand(infix[i]))
			postfix[j++]=infix[i];
		else if(infix[i]=='(')
			push(infix[i]);
		else if(infix[i]==')')
		{
			while(peek()!='(')
			{
				postfix[j++]=pop();	
			}
			pop();
		}
		else
		{
			while(top!=NULL&&priority(infix[i])<=priority(peek()))
				postfix[j++]=pop();	
			push(infix[i]);
		}
	}
	while(top!=NULL)
		postfix[j++]=pop();
}
int main()
{
	int i;
	infixToPostfix();
	for(i=0;postfix[i];i++)
		printf("%c",postfix[i]);
}









