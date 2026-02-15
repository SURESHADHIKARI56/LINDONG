/*QUICKSORT
NAME:XUNER
DATE:16/02/2026
FILENAME:QUICKSORT.c
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Insert at end
void insertEnd(struct Node** head, int data) {
    struct Node* temp = newNode(data);
    if (*head == NULL) {
        *head = temp;
        return;
    }
    struct Node* cur = *head;
    while (cur->next != NULL)
        cur = cur->next;
    cur->next = temp;
}

// Print list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Get last node
struct Node* getTail(struct Node* cur) {
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return cur;
}

// Partition function
struct Node* partition(struct Node* head, struct Node* end,
                       struct Node** newHead, struct Node** newEnd) {
    struct Node* pivot = end;
    struct Node* prev = NULL;
    struct Node* cur = head;
    struct Node* tail = pivot;

    while (cur != pivot) {
        if (cur->data < pivot->data) {
            if (*newHead == NULL)
                *newHead = cur;
            prev = cur;
            cur = cur->next;
        } else {
            if (prev)
                prev->next = cur->next;

            struct Node* tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    if (*newHead == NULL)
        *newHead = pivot;

    *newEnd = tail;
    return pivot;
}

// QuickSort recursive
struct Node* quickSortRecur(struct Node* head, struct Node* end) {
    if (!head || head == end)
        return head;

    struct Node* newHead = NULL;
    struct Node* newEnd = NULL;

    struct Node* pivot = partition(head, end, &newHead, &newEnd);

    // Sort left part
    if (newHead != pivot) {
        struct Node* tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;

        tmp->next = NULL;

        newHead = quickSortRecur(newHead, tmp);

        tmp = getTail(newHead);
        tmp->next = pivot;
    }

    // Sort right part
    pivot->next = quickSortRecur(pivot->next, newEnd);

    return newHead;
}

// Main QuickSort function
void quickSort(struct Node** headRef) {
    *headRef = quickSortRecur(*headRef, getTail(*headRef));
}

// Main
int main() {
    struct Node* head = NULL;
    int n, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        insertEnd(&head, x);
    }

    printf("Original List: ");
    printList(head);

    quickSort(&head);

    printf("Sorted List (Quick Sort): ");
    printList(head);

    return 0;
}
