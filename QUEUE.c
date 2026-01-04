#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

/* Insert single element */
void enqueue() {
    int item;
    struct node *newNode;

    newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter element: ");
    scanf("%d", &item);

    newNode->data = item;
    newNode->next = NULL;

    if (front == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("%d inserted\n", item);
}

/* Insert many elements at once */
void enqueueMany() {
    int n, i, item;
    struct node *newNode;

    printf("How many elements to insert? ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        newNode = (struct node *)malloc(sizeof(struct node));
        if (newNode == NULL) {
            printf("Memory allocation failed\n");
            return;
        }

        printf("Enter element %d: ", i);
        scanf("%d", &item);

        newNode->data = item;
        newNode->next = NULL;

        if (front == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    printf("%d elements inserted into queue\n", n);
}

/* Delete element */
void dequeue() {
    struct node *temp;

    if (front == NULL) {
        printf("Queue is EMPTY\n");
        return;
    }

    temp = front;
    printf("%d removed from queue\n", front->data);
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
}

/* Display queue */
void display() {
    struct node *temp = front;

    if (front == NULL) {
        printf("Queue is EMPTY\n");
        return;
    }

    printf("Queue: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* Main menu */
int main() {
    int choice;

    while (1) {
        printf("\n--- QUEUE MENU (Linked List) ---\n");
        printf("1. Enqueue (Single)\n");
        printf("2. Enqueue (Many at once)\n");
        printf("3. Dequeue\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                enqueueMany();
                break;
            case 3:
                dequeue();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
