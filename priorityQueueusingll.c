
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int priority;
    struct Node *next;
};

struct Node *head = NULL;

void insert(void) {
    struct Node *newNode, *temp;
    int data, priority;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &data);
    printf("Enter priority (smaller = higher): ");
    scanf("%d", &priority);

    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;

    if (head == NULL || priority < head->priority) {
        newNode->next = head;
        head = newNode;
    } else {
        temp = head;

        while (temp->next != NULL &&
               temp->next->priority <= priority) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    printf("Element inserted.\n");
}

void deleteElement(void) {
    struct Node *temp;

    if (head == NULL) {
        printf("Priority queue is empty!\n");
        return;
    }

    temp = head;
    printf("Deleted data: %d, Priority: %d\n",
           temp->data, temp->priority);

    head = head->next;
    free(temp);
}

void display(void) {
    struct Node *temp = head;

    if (head == NULL) {
        printf("Priority queue is empty!\n");
        return;
    }

    printf("Data\tPriority\n");

    while (temp != NULL) {
        printf("%d\t%d\n", temp->data, temp->priority);
        temp = temp->next;
    }
}

void freeQueue(void) {
    struct Node *temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int ch;

    do {
        printf("\n--- Priority Queue (Linked List) ---\n");
        printf("1. Insert\n");
        printf("2. Delete highest priority\n");
        printf("3. Display\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: insert(); break;
            case 2: deleteElement(); break;
            case 3: display(); break;
            case 0: freeQueue(); printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (ch != 0);

    return 0;
}
