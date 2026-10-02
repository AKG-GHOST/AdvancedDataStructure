#include <stdio.h>

int n;
int a[100];

void inspos(int a[], int x, int pos) {
    if (pos < 1 || pos > n + 1) {
        printf("Invalid position.\n");
        return;
    }

    for (int i = n - 1; i >= pos - 1; i--)
        a[i + 1] = a[i];

    a[pos - 1] = x;
    n++;
}

void delpos(int a[], int pos) {
    if (pos < 1 || pos > n) {
        printf("Invalid position.\n");
        return;
    }

    for (int i = pos - 1; i < n - 1; i++)
        a[i] = a[i + 1];

    n--;
}

int search(int a[], int x) {
    for (int i = 0; i < n; i++) {
        if (a[i] == x)
            return i;
    }
    return -1;
}

void display() {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int choice, x, pos, index;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &x);
                printf("Enter position: ");
                scanf("%d", &pos);
                inspos(a, x, pos);
                break;

            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                delpos(a, pos);
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &x);
                index = search(a, x);
                if (index == -1)
                    printf("Element not found.\n");
                else
                    printf("Element found at index %d.\n", index);
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

