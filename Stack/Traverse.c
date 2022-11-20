#include<stdio.h>


int stack[100];
int top=-1;


void push(int item)
{
top++;
stack[top] = item;
}

void pop()
{
top--;
}

int main()
{
    int arr[50],i,n;
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    printf("\nEnter the elements of the array : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        push(arr[i]);
    }
    while(top!=0)//bcuz we cannot decrement stack after 0
    {
        printf("stack top : %d\n",stack[top]);
        printf("Popping stack top\n\n");
        pop();
    }
    printf("The Stack is now empty \n The array successfully traversed");
    return 0;
}