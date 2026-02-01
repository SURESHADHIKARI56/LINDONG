/* DOUBLY LINKED LIST – SORTED ORDER (MENU DRIVEN)
NAME: SURESH
DATE: 16/01/2026
FILENAME: DLL_SORT_MENU.C */

#include <stdio.h>
#include <stdlib.h>

typedef struct dbblinkedlist {
    int data;
    struct dbblinkedlist *next;
    struct dbblinkedlist *prev;
} DBLNK;

DBLNK *Head = NULL;

/* Insert in sorted order */
void insertSorted(int val) {
    DBLNK *newnode, *curr, *prev;

    newnode = (DBLNK *)malloc(sizeof(DBLNK));
    newnode->data = val;
    newnode->next = NULL;
    newnode->prev = NULL;

    /* case 1: empty list */
    if (Head == NULL) {
        Head = newnode;
        return;
    }

    /* case 2: insert at beginning */
    if (val <= Head->data) {
        newnode->next = Head;
        Head->prev = newnode;
        Head = newnode;
        return;
    }

    /* case 3: insert in middle or end */
    prev = Head;
    curr = Head->next;

    while (curr != NULL && curr->data < val) {
        prev = curr;
        curr = curr->next;
    }

    prev->next = newnode;
    newnode->prev = prev;
    newnode->next = curr;

    if (curr != NULL) {
        curr->prev = newnode;
    }
}

/* Delete a node by value */
void deleteNode(int val) {
    DBLNK *temp = Head;

    if (Head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    while (temp != NULL && temp->data != val) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found.\n");
        return;
    }

    /* delete head */
    if (temp == Head) {
        Head = temp->next;
        if (Head != NULL)
            Head->prev = NULL;
    }
    /* delete middle or last */
    else {
        temp->prev->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = temp->prev;
    }

    free(temp);
    printf("Node deleted successfully.\n");
}

/* Display forward */
void displayForward() {
    DBLNK *temp = Head;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Forward: ");
    while (temp != NULL) {
        printf("%d<->", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* Display backward */
void displayBackward() {
    DBLNK *temp = Head;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    printf("Backward: ");
    while (temp != NULL) {
        printf("%d<->",temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

/* Main – Menu Driven */
int main() {
    int choice, val;

    while (1) {
        printf("\n---- DOUBLY LINKED LIST MENU ----\n");
        printf("1. Insert (Sorted Order)\n");
        printf("2. Delete\n");
        printf("3. Display Forward\n");
        printf("4. Display Backward\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
    int n, i;

    printf("Enter number of elements to insert: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        insertSorted(val);
    }
    break;
}
        

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                deleteNode(val);
                break;

            case 3:
                displayForward();
                break;

            case 4:
                displayBackward();
                break;

            case 5:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }
}


