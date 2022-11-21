#include <stdio.h>
#include <stdlib.h>
 
// Data Structure to store a linked list node
struct Node
{
    int data;
    struct Node* next;
};
 
// Helper function to print given linked list
void printList(struct Node* head)
{
    struct Node* ptr = head;
    while (ptr)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
 
    printf("NULL\n");
}
 
// Helper function to insert new Node in the beginning of the linked list
void push(struct Node** head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}
 
// Takes two lists sorted in increasing order, and merge their nodes
// together to make one big sorted list which is returned
struct Node* SortedMerge(struct Node* a, struct Node* b)
{
    // Base cases
    if (a == NULL)
        return b;
 
    else if (b == NULL)
        return a;
 
    struct Node* result = NULL;
 
    // Pick either a or b, and recur
    if (a->data <= b->data)
    {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
 
    return result;
}
 
// main method
int main(void)
{
    // input keys
    int keys[] = { 1, 2, 3, 4, 5, 6, 7 };
    int n = sizeof(keys)/sizeof(keys[0]);
 
    struct Node *a = NULL, *b = NULL;
    for (int i = n - 1; i >= 0; i = i - 2)
        push(&a, keys[i]);
 
    for (int i = n - 2; i >= 0; i = i - 2)
        push(&b, keys[i]);
 
    // print both linked list
    printf("First List  :  ");
    printList(a);
 
    printf("Second List : ");
    printList(b);
 
    struct Node* head = SortedMerge(a, b);
    printf("After Merge : ");
    printList(head);
 
    return 0;
}