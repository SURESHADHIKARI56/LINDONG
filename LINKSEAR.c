#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct node
{
    int data;
    struct node *next;
};

struct node *Head = NULL;

/* Function to insert node at end */
void insertNode(int value)
{
    struct node *newNode, *cur;

    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    if(Head == NULL)
    {
        Head = newNode;
        return;
    }

    cur = Head;
    while(cur->next != NULL)
        cur = cur->next;

    cur->next = newNode;
}

/* Function to search element using linear search */
int linearSearchList(int key)
{
    struct node *cur = Head;

    while(cur != NULL)
    {
        if(cur->data == key)
            return 1;   // found
        cur = cur->next;
    }
    return -1;          // not found
}

int main()
{
    int n, i, value, key, result;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &value);
        insertNode(value);
    }

    printf("Enter number to search: ");
    scanf("%d", &key);

    result = linearSearchList(key);

    if(result == 1)
        printf("Number FOUND in linked list\n");
    else
        printf("Number NOT FOUND in linked list\n");

    return 0;
}
