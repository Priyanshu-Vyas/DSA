/*
Write a C Program to evaluate an expression of your choice 
(You have to convert the infix to postifx and also evaluate the postfix expression)
*/
#include<stdio.h>
#define size 100
#include<stdbool.h>
#include<ctype.h>
#include<string.h>
///////////////////////////////////
int top=-1;
char stack[size];
bool isempty()
{
	if(top==-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool isfull()
{
	if(top>=size-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void push(int x)
{
	if(isfull())
	{
		printf("Stack is full\n");
	}
	else
	{
		stack[++top]=x;
	}
}
char pop()
{
	if(isempty())
	{
		printf("Stack is empty\n");
	}
	else
	{
		return(stack[top--]);
	}
}
///////////////////////////////////
int p(char x) {    //p-priority
    int p;
    if (x == '(' || x == '#') p = 1;
    if (x == '+' || x == '-') p = 2;
    if (x == '*' || x == '/') p = 3;
    if (x == '^' || x == '$') p = 4;
    return p;
}
int main()
{
	int a,b=0,c;
	char infix[100],postfix[100];
	printf("ENTER THE VALID INFIX EXPRESSION:");
	gets(infix);
	push('#');
	for(a=0;infix[a]!='\0';a++)
	{
		if(isalnum(infix[a]))
		{
			postfix[b++]=infix[a];
		}
		else if(infix[a]=='(')
		{
			push(infix[a]);
		}
		else if(infix[a]==')')
		{
			while(stack[top]!='(')
				postfix[b++]=pop();
			pop();
		}
		else {
            while (p(stack[top]) >= p(infix[a]))
                postfix[b++] = pop();
            push(infix[a]);
        }
	}
	while(stack[top]!='#')
	{
		postfix[b++]=pop();
	}
	printf("POSTFIX EQUATION:%s\n",postfix);
	//////////////////////////////////////////
	for(c=0;postfix[c]!='\0';c++)
	{
		if(isdigit(postfix[c]))
		{
			push(postfix[c]-'0');
		}
		else
		{
            int y = pop();
            int x = pop();
            switch (postfix[c])
            {
            case '/':
                push(x/y);
                break;
            case '*':
                push(x*y);
                break;
            case '+':
                push(x+y);
                break;
            case '-':
                push(x-y);
                break;
            default:
                printf("Invalid Operator");
            }
		}
	}
	printf("EVALUATE VALUE:%d",pop());
}
