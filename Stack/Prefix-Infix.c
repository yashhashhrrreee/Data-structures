#include<stdio.h>
#include<string.h>
#include<stdbool.h>

struct stac
{
char stk[100];
int top;
}s;

void push(char item)
{
s.top++;
s.stk[s.top] = item;
}
void pop()
{
s.top--;
}

bool isOperator(char x) {
switch (x) {
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
char exp[100],op;
printf("enter the prefix expression : ");
gets(exp);
int l,i=0;
l=strlen(exp);
printf("\n\nthe infix expression is : ");
for(i=0;i<l;i++)
   {
      if(isOperator(exp[i]))
      {
         push(exp[i]);
      }
      else
      {
          op=s.stk[s.top];
         pop();
         printf("%c%c",exp[i],op);
      }
   }
   printf("%c",s.stk[s.top]);
return 0;
}
