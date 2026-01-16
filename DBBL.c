/*DOUBLY LINKED LIST SORTED ORDER
NAME:SURESH
DATE:16/01/2026
FILENAME:INSERT.C*/
#include <stdio.h>
#include <stdlib.h>
typedef struct dbblinkedlist {
    int data;
    struct dbblinkedlist *next;
    struct dbblinkedlist *prev;
} DBLNK;
DBLNK *Head = NULL;
/* insert in sorted order */
void insertSorted(int val) {
    DBLNK *newnode, *curr, *prev;

    newnode = (DBLNK *)malloc(sizeof(DBLNK));
    newnode->data = val;
    newnode->next = NULL;
    newnode->prev = NULL;

    /* case 1: empty list make upcoming node as head */
    if (Head == NULL) {
        Head = newnode;
        return;
    }

    /* case 2: insert at beginning if value is less than head */
    if (val <= Head->data) {
        newnode->next = Head;
        Head->prev = newnode;
        Head = newnode;
        return;
    }

    /* case 3: insert in middle or end */
    curr = Head;
    while (curr->next != NULL && curr->next->data < val) {
        prev=curr;
        curr = curr->next;
    }
    prev->next = newnode;
    newnode->prev = prev;
    newnode->next = curr;
    curr->prev = newnode;
}
/* display forward */
void displayForward() {
    DBLNK *temp = Head;
    if(temp == NULL) {
        printf("Forward: \n");
        return;
    }
    printf("Forward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}   
/* display backward */
void displayBackward() {        
    DBLNK *temp = Head;
    if (temp == NULL) {
        printf("Backward: \n");
        return;
    }
    while (temp->next != NULL) {
      temp = temp->next;
    }
    printf("Backward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}
int main()
{
    int n, i, a[100];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        insertSorted(a[i]);
    }
    displayForward();
    displayBackward();
    return 0;
}
