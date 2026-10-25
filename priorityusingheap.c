
#include <stdio.h>

#define MAX 100

struct Item {
    int data;
    int priority;
};

struct Item heap[MAX];
int size = 0;

void swap(struct Item *a, struct Item *b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}

void insert(void) {
    int i;
    struct Item item;

    if (size == MAX) {
        printf("Heap is full!\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &item.data);
    printf("Enter priority (smaller = higher): ");
    scanf("%d", &item.priority);

    i = size;
    heap[size++] = item;

    /* Move the new element upward. */
    while (i > 0 &&
           heap[(i - 1) / 2].priority > heap[i].priority) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }

    printf("Element inserted.\n");
}

void deleteElement(void) {
    int i = 0, left, right, smallest;

    if (size == 0) {
        printf("Priority queue is empty!\n");
        return;
    }

    printf("Deleted data: %d, Priority: %d\n",
           heap[0].data, heap[0].priority);

    heap[0] = heap[size - 1];
    size--;

    /* Restore the min-heap property. */
    while (i < size) {
        left = 2 * i + 1;
        right = 2 * i + 2;
        smallest = i;

        if (left < size &&
            heap[left].priority < heap[smallest].priority) {
            smallest = left;
        }

        if (right < size &&
            heap[right].priority < heap[smallest].priority) {
            smallest = right;
        }

        if (smallest == i)
            break;

        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }
}

void display(void) {
    int i;

    if (size == 0) {
        printf("Priority queue is empty!\n");
        return;
    }

    printf("Data\tPriority\n");

    for (i = 0; i < size; i++) {
        printf("%d\t%d\n", heap[i].data, heap[i].priority);
    }
}

int main(void) {
    int ch;

    do {
        printf("\n--- Priority Queue (Heap) ---\n");
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
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (ch != 0);

    return 0;
}
