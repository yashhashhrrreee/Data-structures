#define SIZE 50            
#include<string.h>
#include<conio.h>
#include <ctype.h>
#include<stdio.h>
char s[SIZE];
int top=-1;       

void push(char elem)
{                       
    s[++top]=elem;
}

char pop()
{                      
    return(s[top--]);
}

int pr(char elem)
{                 
    switch(elem)
    {
    case '#': return 0;
    case ')': return 1;
    case '+':
    case '-': return 2;
    case '*':
    case '/': return 3;
    }
}

int main()
{                        
    char infx[50],prfx[50],ch,elem;
    int i=0,k=0;
    printf("\n\nRead the Infix Expression : ");
    scanf("%s",infx);
    push('#');
    strrev(infx);
    while( (ch=infx[i++]) != '\0')
    {
        if( ch == ')') push(ch);
        else
            if(isalnum(ch)) prfx[k++]=ch;
            else
                if( ch == '(')
                {
                    while( s[top] != ')')
                        prfx[k++]=pop();
                    elem=pop(); /* Remove ) */
                }
                else
                {       /* Operator */
                    while( pr(s[top]) >= pr(ch) )
                        prfx[k++]=pop();
                    push(ch);
                }
    }
    while( s[top] != '#')     
        prfx[k++]=pop();
    prfx[k]='\0';          
    strrev(prfx);
    strrev(infx);
    printf("\n\nGiven Infix Expn: %s  \nPrefix Expn: %s\n",infx,prfx);
}