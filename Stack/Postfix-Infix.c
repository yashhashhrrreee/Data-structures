#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
struct stack
{
    char stk[100];
    int top;
}s;
void push(char item)
{
    s.top++;
    s.stk[s.top]=item;
}
void pop()
{
    s.top--;
}
int isOperand(char ch)
{
    return(ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z');
}
boolisOperator(char x)
{
    switch(x)
    {
    case '+':
    case '-':
    case '/':
    case '*':
        return true;
    }
    return false;
}
int main()
{
    char exp[100],opr;
    printf("\n\tEnter the postfix expression:");
    gets(exp);
    int l,i,k;
    l=strlen(exp);
    strrev(exp);
    printf("\n\tThe infix expression is:");
    for(i=0,k=-1;exp[i];i++)
    {
        if(boolisOperator(exp[i]))
        {
            push(exp[i]);
        }
        else
        {
            exp[++k]=exp[i];
            exp[++k]=s.stk[s.top];
            pop();

        }
    }
    exp[++k];
    strrev(exp);
    puts(exp);
    return 0;

}