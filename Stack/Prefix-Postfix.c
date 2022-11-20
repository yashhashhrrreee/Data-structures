#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#define BLANK ' '
#define TAB '\t'
#define MAX 50


struct stack
{
    int top;
    char stac[MAX][MAX];
};

struct istack
{
    int top;

    int stac[MAX];
};


char* pop(struct stack*);
int ipop(struct istack*);
void push(struct stack*, char* str);
void ipush(struct istack*, int str);
int isempty(struct stack* s);
int white_space(char symbol);
void prefix_to_postfix();
int evaluatePostfix(char* exp);


char prefix[MAX];


int main()
{
    printf("Enter Prefix Expression : ");
    gets(prefix);
    prefix_to_postfix();

}

void prefix_to_postfix()
{
    struct stack s;
    s.top = -1;
    int i;
    char operand1[MAX], operand2[MAX];
    char symbol;
    char temp[2];
    char strin[MAX];
    char post_ex[MAX];

    for (i = strlen(prefix) - 1; i >= 0; i--)
    {
        symbol = prefix[i];

        temp[0] = symbol;
        temp[1] = '\0';

        if (!white_space(symbol))
        {
            switch (symbol)
            {
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '^':
                strcpy(operand1, pop(&s));
                strcpy(operand2, pop(&s));
                strcpy(strin, operand1);
                strcat(strin, operand2);
                strcat(strin, temp);
                push(&s,strin);
                break;
            default:
                push(&s,temp);
            }
        }
    }

    strcpy(post_ex,pop(&s));

    printf("\nPostfix Expression :: ");
    puts(post_ex);


    printf("\nResult of Expression :: ");
    printf("%d",evaluatePostfix(post_ex));

} /*End of prefix_to_postfix()*/

int evaluatePostfix(char exp[MAX])
{
    int i;
    struct istack s1;
    s1.top = -1;


    for (i = 0; exp[i]; ++i)
    {
        if (isdigit(exp[i]))
        {
            ipush(&s1,exp[i]);
        }

        else
        {
            int val1 = ipop(&s1);
            int val2 = ipop(&s1);
            switch (exp[i])
            {
            case '+':
                ipush(&s1,val2 + val1);
                break;
            case '-':
                ipush(&s1,val2 - val1);
                break;
            case '*':
                ipush(&s1,val2 * val1);
                break;
            case '/':
                ipush(&s1,val2/val1);
                break;
            }
        }
    }
    return (ipop(&s1));
}


void push(struct stack* s,char* str)
{
    if(s->top > MAX)
    {
        printf("\nStack overflow. Invalid expression.\n");
        exit(1);
    }
    else
    {
        s->top=s->top+1;
        strcpy(s->stac[s->top], str);
    }
}

void ipush(struct istack* s,int str)
{
    if(s->top > MAX)
    {
        printf("\nStack overflow. Invalid expression.\n");
        exit(1);
    }
    else
    {
        s->top=s->top+1;
        s->stac[s->top]= str;
    }
}

char* pop(struct stack* s)
{
    if(s->top == -1 )
    {
        printf("\nStack underflow \n");
        exit(2);
    }
    else
        return (s->stac[s->top--]);
}/*End of pop()*/

int ipop(struct istack* s)
{
    if(s->top == -1 )
    {
        printf("\nStack underflow \n");
        exit(2);
    }
    else
        return (s->stac[s->top--]);
}/*End of pop()*/


int isempty(struct stack* s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}
int white_space(char symbol)
{
    if (symbol == BLANK || symbol == TAB || symbol == '\0')
        return 1;
    else
        return 0;
}
