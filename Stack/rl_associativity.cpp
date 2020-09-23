#include<stdio.h>
#include<stdlib.h>
char infix[30]="x+y^z*p/q^r^s";
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
int inPriority(char ch)
{
	if(ch=='+'||ch=='-')            //L-R associativity of + and - ,so inPriority>outPriority,so pop
		return 2;
	else if(ch=='*'||ch=='/')        //L-R associativity of * and / ,so inPriority>outPriority,so pop
		return 4;
	else if(ch=='^')                //R-L associativity of ^ ,so inPriority<outPriority,so push
		return 5;
	else
		return -1;
}
int outPriority(char ch)
{
	if(ch=='+'||ch=='-')            
		return 1;
	else if(ch=='*'||ch=='/')
		return 3;
	else if(ch=='^')
		return 6;
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
				postfix[j++]=pop();	                                                        //priority(infix[i])=>out priority
			}                                                                               //priority(peek())=> in priority
			pop();                                   //pop'('
		}
		else                                      //for operators
		{
			while(top!=NULL&&outPriority(infix[i])<inPriority(peek()))
				postfix[j++]=pop();	                                                      //for operators:
			push(infix[i]);                                                                  //to pop:in priority i.e. priority(peek)> out priority i.e. priority(infix[i])
		}                                                                                   // and to push: in priority i.e. priority(peek)<h out priority i.e. priority(infix[i])
	}
	while(top!=NULL)
		postfix[j++]=pop();
}
int main()
{jj
	int i;
	infixToPostfix();
	for(i=0;postfix[i];i++)
		printf("%c",postfix[i]);
}









