
#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(void) {
    int x;

    if ((rear + 1) % MAX == front) {
        printf("Queue is full!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &x);

    if (front == -1)
        front = 0;

    rear = (rear + 1) % MAX;
    queue[rear] = x;

    printf("Inserted: %d\n", x);
}

void dequeue(void) {
    if (front == -1) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Deleted: %d\n", queue[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void display(void) {
    int i;

    if (front == -1) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue: ");
    i = front;

    while (1) {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main(void) {
    int ch;

    do {
        printf("\n--- Circular Queue ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (ch != 0);

    return 0;
}
