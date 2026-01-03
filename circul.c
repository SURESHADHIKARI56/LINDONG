#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

/* Enqueue MANY elements */
void enqueueMany() {
    int n, i, item;
    struct node *newNode;

    printf("How many elements to insert: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newNode = (struct node *)malloc(sizeof(struct node));
        if (newNode == NULL) {
            printf("Memory allocation failed\n");
            return;
        }

        printf("Enter element %d: ", i + 1);
        scanf("%d", &item);

        newNode->data = item;

        if (front == NULL) {   // First node
            front = rear = newNode;
            newNode->next = front;
        } else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front;   // Maintain circular link
        }
    }

    printf("%d elements inserted into circular queue\n", n);
}

/* Dequeue operation */
void dequeue() {
    struct node *temp;

    if (front == NULL) {
        printf("Circular Queue is EMPTY\n");
        return;
    }

    temp = front;
    printf("%d removed from circular queue\n", temp->data);

    if (front == rear) {   // Only one node
        front = rear = NULL;
    } else {
        front = front->next;
        rear->next = front;
    }

    free(temp);
}

/* Display operation */
void display() {
    struct node *temp;

    if (front == NULL) {
        printf("Circular Queue is EMPTY\n");
        return;
    }

    printf("Circular Queue elements: ");
    temp = front;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);

    printf("\n");
}

/* Main menu */
int main() {
    int choice;

    while (1) {
        printf("\n--- CIRCULAR QUEUE USING LINKED LIST ---\n");
        printf("1. Enqueue (Insert MANY)\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueueMany();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
