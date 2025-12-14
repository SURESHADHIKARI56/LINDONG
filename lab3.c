#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

/* Function to insert element */
void enqueue() {
    int item;
    if (rear == SIZE - 1) {
        printf("Queue is FULL\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    printf("Enter element to insert: ");
    scanf("%d", &item);
    rear++;
    queue[rear] = item;
    printf("%d inserted into queue\n", item);
}

/* Function to delete element */
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is EMPTY\n");
        return;
    }
    printf("%d removed from queue\n", queue[front]);
    front++;
}

/* Main menu */
int main() {
    int choice;
    
    while (1) {
        printf("\n--- QUEUE MENU ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
/* End of program */