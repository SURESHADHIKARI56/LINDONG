#include <stdio.h>
#include <stdlib.h>

typedef struct listtype {
    int data;
    struct listtype *next;
} LISTNODE;

LISTNODE *Head;

void initlist();
void insertSorted(int x);   // insert in ORDERED manner
void display();
int search(int key);
void deleteData(int key);

int main() {
    int choice, x,N,i;

    initlist();

    while (1) {
        printf("\n=== ORDERED LINKED LIST ===\n");
        printf("1. Insert a number (sorted)\n");
        printf("2. Display list\n");
        printf("3. Search a number\n");
        printf("4. Delete a number\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("how many numbers do you want to insert:");
            scanf("%d",&N);
            for(i=0;i<N;i++){
            printf("Enter %dnumber: ",i+1);
            scanf("%d", &x);
            insertSorted(x);
            }
        }
        else if (choice == 2) {
            display();
        }
        else if (choice == 3) {
            printf("Enter number to search: ");
            scanf("%d", &x);
            if (search(x))
                printf("%d FOUND in the list.\n", x);
            else
                printf("%d NOT found in the list.\n", x);
        }
        else if (choice == 4) {
            printf("Enter number to delete: ");
            scanf("%d", &x);
            deleteData(x);
        }
        else if (choice == 5) {
            printf("Exiting...\n");
            break;
        }
        else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}

void initlist() {
    Head = NULL;
}

void insertSorted(int x) {
    LISTNODE *node = (LISTNODE *)malloc(sizeof(LISTNODE));
    node->data = x;
    node->next = NULL;

    // Case 1: empty list OR new node should be new head
    if (Head == NULL || x < Head->data) {
        node->next = Head;
        Head = node;
        return;
    }

    // Case 2: find correct position
    LISTNODE *current = Head;
    while (current->next != NULL && current->next->data < x) {
        current = current->next;
    }

    node->next = current->next;
    current->next = node;
}

void display() {
    LISTNODE *current = Head;

    if (current == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Sorted Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int search(int key) {
    LISTNODE *current = Head;

    while (current != NULL) {
        if (current->data == key)
            return 1;   // found
        current = current->next;
    }
    return 0;           // not found
}

void deleteData(int key) {
    if (Head == NULL) {
        printf("List is empty.\n");
        return;
    }

    // Case 1: delete head
    if (Head->data == key) {
        LISTNODE *del = Head;
        Head = Head->next;
        free(del);
        printf("%d deleted successfully.\n", key);
        return;
    }

    // Case 2: delete from middle or end
    LISTNODE *current = Head;
    while (current->next != NULL && current->next->data != key) {
        current = current->next;
    }

    if (current->next == NULL) {
        printf("%d not found in the list.\n", key);
        return;
    }

    LISTNODE *del = current->next;
    current->next = del->next;
    free(del);
    printf("%d deleted successfully.\n", key);
}
