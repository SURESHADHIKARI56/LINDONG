#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

/* Insert unsorted numbers */
void insert() {
    struct node *newnode, *temp;
    int val, n, i;

    printf("How many numbers do you want to insert? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter value %d: ", i + 1);
        scanf("%d", &val);

        newnode->data = val;
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
        } else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
        }
    }
}

/* Display list */
void display() {
    struct node *temp = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* Find maximum value */
void findMax() {
    struct node *temp = head;
    int max;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    max = head->data;
    while (temp != NULL) {
        if (temp->data > max)
            max = temp->data;
        temp = temp->next;
    }
    printf("Maximum value = %d\n", max);
}

/* Count nodes */
void countNodes() {
    struct node *temp = head;
    int count = 0;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Total nodes = %d\n", count);
}

/* Delete a given value */
void deleteValue() {
    struct node *temp = head, *prev = NULL;
    int key;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Enter value to delete: ");
    scanf("%d", &key);

    if (head->data == key) {
        head = head->next;
        free(temp);
        printf("Node deleted\n");
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Node deleted\n");
}

/* Delete last node */
void deleteLast() {
    struct node *temp = head, *prev = NULL;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Last node deleted\n");
        return;
    }

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
    printf("Last node deleted\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n1.Insert\n2.Display\n3.Find Maximum\n4.Count Nodes\n");
        printf("5.Delete by Value\n6.Delete Last Node\n7.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: display(); break;
            case 3: findMax(); break;
            case 4: countNodes(); break;
            case 5: deleteValue(); break;
            case 6: deleteLast(); break;
            case 7: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
