#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
# define MAX 10


char str[MAX],stack[MAX];
int top=-1;

void push(char c)
{
   stack[++top]=c;
}


char pop()
{
   return stack[top--];
}


void post_pre()
{
   int n,i,j=0;
   char c[20];


   n=strlen(str);


    printf(" The Prefix expression is: \t");

           for(i=n-1;i>=0;i--)
           {
              if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
              {
                 push(str[i]);
              }
              else
              {
                  c[j]=str[i];
                  j++;

                     while(  (top!=-1) && (stack[top]=='#')  )
                    {
                        pop();
                        c[j]=pop();
                        j++;

                    }

                push('#');
              }
           }


   c[j]='\0';

   strrev(c);

   printf("%s",c);
}


int main()
{
   printf("Enter the Postfix Expression: \n");
   gets(str);

    post_pre();
}