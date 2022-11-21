//Program to split a linked list into two halves

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};


// To insert new Node in the beginning of the linked list
void push(struct Node** head, int data)
{
	struct Node* new = (struct Node*)malloc(sizeof(struct Node));
	new->data = data;
	new->next = *head;
	*head = new;
}

// Count number of nodes in the list
int Length(struct Node* head)
{
	int count = 0;
	struct Node* current = head;
	while (current != NULL)
	{
		count++;
		current=current->next;
	}
	return count;
}

/*
Split the nodes of the given list into front and back.
If the length is odd, the extra node should go in the front list.
*/
void FrontBackSplit(struct Node* source, struct Node** front,
					struct Node** back)
{
	int temp = Length(source);
	if (temp < 2)
	{
		*front = source;
		*back = NULL;
		return;
	}

	struct Node* current = source;

	int split = (temp - 1) / 2;
	for (int i = 0; i < split; i++)
		current = current->next;

	*front = source;
	*back = current->next;
	current->next = NULL;
}

void displayLL(struct Node* head)
{
	struct Node* pointer = head;
	while (pointer)
	{
		printf("%d -> ", pointer->data);
		pointer = pointer->next;
	}

	printf("null");
}


int main()
{
    int loop;
    printf("Program to split a linked list into two halves \n\n");
	int element[5]={2, 3, 5, 7, 11};

    printf("The original linked list is: ");
    for(loop = 0; loop < 5; loop++)
    printf("%d ", element[loop]);

	int n = sizeof(element)/sizeof(element[0]);
	struct Node* head = NULL;
	for (int i = n-1; i >= 0; i--)
		push(&head, element[i]);

	struct Node *front = NULL, *back = NULL;
	FrontBackSplit(head, &front, &back);

	printf("\nFront List : ");
	displayLL(front);

	printf("\nBack List  :  ");
	displayLL(back);

	return 0;
}
