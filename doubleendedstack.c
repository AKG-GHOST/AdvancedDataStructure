
#include <stdio.h>
#define MAX 10

int a[MAX];
int top1 = -1, top2 = MAX;

void push1(void) {
    int x;
    if (top1 + 1 == top2) {
        printf("Stack Overflow!\n");
        return;
    }
    printf("Enter value: ");
    scanf("%d", &x);
    a[++top1] = x;
}

void push2(void) {
    int x;
    if (top1 + 1 == top2) {
        printf("Stack Overflow!\n");
        return;
    }
    printf("Enter value: ");
    scanf("%d", &x);
    a[--top2] = x;
}

void pop1(void) {
    if (top1 == -1) {
        printf("Stack 1 is empty!\n");
        return;
    }
    printf("Popped: %d\n", a[top1--]);
}

void pop2(void) {
    if (top2 == MAX) {
        printf("Stack 2 is empty!\n");
        return;
    }
    printf("Popped: %d\n", a[top2++]);
}

void display1(void) {
    int i;
    if (top1 == -1) {
        printf("Stack 1 is empty\n");
        return;
    }
    printf("Stack 1: ");
    for (i = top1; i >= 0; i--)
        printf("%d ", a[i]);
    printf("\n");
}

void display2(void) {
    int i;
    if (top2 == MAX) {
        printf("Stack 2 is empty\n");
        return;
    }
    printf("Stack 2: ");
    for (i = top2; i < MAX; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main(void) {
    int ch;
    do {
        printf("\n--- Double-Ended Stack ---\n");
        printf("1. Push Stack 1\n");
        printf("2. Pop Stack 1\n");
        printf("3. Push Stack 2\n");
        printf("4. Pop Stack 2\n");
        printf("5. Display Stack 1\n");
        printf("6. Display Stack 2\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: push1(); break;
            case 2: pop1(); break;
            case 3: push2(); break;
            case 4: pop2(); break;
            case 5: display1(); break;
            case 6: display2(); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (ch != 0);

    return 0;
}
