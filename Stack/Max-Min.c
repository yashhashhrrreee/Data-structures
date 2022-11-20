#include <stdio.h>
#include <string.h>

int i;

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

int pop()
{
    int x;
x=s.stk[s.top--];
return(x);
}

int main()
{
    int i ,n, max=0 , min=0;
    int arr[10] , y;
    printf("enter the length of array");
    scanf("%d",&n);
    printf("enter numbers in an array:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    i=0;
    push(arr[i]);
    max=arr[i];

    for(i=1;i<n;i++)
    {
        push(arr[i]);
        y = pop();
        if(max<y)
        {
            max=arr[i];
        }


    }
    i=0;
    push (arr[i]);
    min = arr[i];
    for(i=1;i<n;i++)
    {
        push(arr[i]);
        y=pop();
        if(min>y)
        {
            min=arr[i];
        }


    }
    printf("the maximun element in an array is:%d",max);
    printf("\n the minimum element in an array is:%d",min);

    }