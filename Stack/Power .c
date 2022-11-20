#include<stdio.h>

struct stac
{
int stk[100];
int top;
}s;

void push(int item)
{
s.top++;
s.stk[s.top] = item;
}

void pop()
{
s.top--;
}

int main()
{
    int n,i,p,e=1;
    printf("enter the number : ");
    scanf("%d",&n);
    printf("enter the power : ");
    scanf("%d",&p);
    for(i=1;i<=p;i++)
        push(i);
    while(s.top!=0)
    {
        e=e*n;
        pop();
    }
    printf("the value of %d raised to %d is : %d",n,p,e);
    return 0;
}