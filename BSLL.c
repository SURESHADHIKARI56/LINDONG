#include <stdio.h>
#include <stdlib.h>

/* Structure for linked list node */
struct node
{
    int data;
    struct node *next;
};

struct node *Head = NULL;

/* Function to input elements into linked list */
void inputList(int n)
{
    int i, value;
    struct node *newNode, *cur;

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &value);

        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = value;
        newNode->next = NULL;

        if(Head == NULL)
        {
            Head = newNode;
        }
        else
        {
            cur = Head;
            while(cur->next != NULL)
                cur = cur->next;
            cur->next = newNode;
        }
    }
}

/* Function to print linked list */
void printList()
{
    struct node *cur = Head;

    while(cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

/* Function to sort linked list using Bubble Sort */
void bubbleSortList()
{
    struct node *i, *j;
    int temp;

    for(i = Head; i != NULL; i = i->next)
    {
        for(j = Head; j->next != NULL; j = j->next)
        {
            if(j->data > j->next->data)
            {
                temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
            }
        }
    }
}

/* Main program */
int main()
{
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    inputList(n);

    printf("\nLinked list before sorting:\n");
    printList();

    bubbleSortList();

    printf("\nLinked list after Bubble Sort:\n");
    printList();

    return 0;
}
