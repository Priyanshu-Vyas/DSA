//QUESTION
/*Using the concept of stack check whether the parenthesis in a given expression is balanced or not. For example, in the expression ((a+b)-(c)) the number of right parentheses 
(3) is equal to the left parenthesis (3). Then the expression is said to be balanced. If not, the expression is said to be unbalanced. Implement the same using C Programming.*/
#include <stdio.h>
#include <string.h>
#define max 20
int top=-1;
int item;
char stack[max];
void push(char item)
{
    top=top+1;
    stack[top]=item;
}
char pop()
{
    item = stack[top];
    top=top-1;
    return top;
}
int main()
{
    char s[max];
    int i,k;
    scanf("%s",s);
    for(i=0;i<strlen(s);i++)
    {   if(s[i]=='(')
        {
            push(s[i]);
        }
        if(s[i]==')')
        {
            k=pop();
        }
    }
    if(k==-1)
    {
        printf("Balanced");
    }
    else
    {
        printf("Not Balanced");
    }
    return 0;
}
