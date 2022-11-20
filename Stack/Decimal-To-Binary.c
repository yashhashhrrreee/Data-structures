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
    int n,i,r,e=1,bin[6];
    for(i=1;i<=5;i++)
        push(i);
    printf("enter the number : ");
    scanf("%d",&n);    
    while(s.top!=0)
    {
        r=n%2;
        n=n/2;
        bin[s.top]=r;
        pop();
    }
    for(i=1;i<=5;i++)
      printf("%d",bin[i]);
    
    return 0;
}