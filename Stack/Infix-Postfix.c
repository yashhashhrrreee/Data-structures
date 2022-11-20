#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct stac
{
    char stk[100];
    int top;
} s;

void push(char item)
{
    s.top++;
    s.stk[s.top] = item;
}

void pop()
{
    s.top--;
}
int Operand(char sym)
{
    return (sym >= 'a' && sym <= 'z') || (sym >= 'A' && sym <= 'Z');
}
int Prec(char sym)
{
    if (sym == '+' || sym == '-') 
    return 1;
    else if (sym == '*' || sym == '/') 
    return 2;
    else if (sym == '^') 
    return 3;
    else 
    return -1;
}

int main()
{
    char exp[100];
    int i, k;
    printf("Enter Infix Expression:");
    gets(exp);
    for (i = 0, k = -1; exp[i]; ++i)
    {
        if (Operand(exp[i]))
            exp[++k] = exp[i];
        else if (exp[i] == '(')
            push(exp[i]);
        else if (exp[i] == ')')
        {
            while (s.top != 0 && s.stk[s.top] != '(')
            {
                exp[++k] = s.stk[s.top];
                pop();
            }
            if (s.top != 0 && s.stk[s.top] != '(')
                return -1;
            else
                pop();
        }
        else
        {
            while (s.top != 0 && Prec(exp[i]) <= Prec(s.stk[s.top]))
            {
                exp[++k] = s.stk[s.top];
                pop();
            }
            push(exp[i]);
        }
    }
    while (s.top != 0)
    {
        exp[++k] = s.stk[s.top];
        pop();
    }
    exp[++k] = '\0';
    printf("\nConversion of Infix to Postfix Expression is:%s", exp);
    return 0;
}