#include <stdio.h>

#define MAX 100

int stack[MAX];
int minStack[MAX];

int top = -1;

void push(int value)
{
    if(top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    top++;

    stack[top] = value;

    if(top == 0)
        minStack[top] = value;
    else if(value < minStack[top - 1])
        minStack[top] = value;
    else
        minStack[top] = minStack[top - 1];
}

int pop()
{
    if(top == -1)
    {
        printf("Stack is empty\n");
        return -1;
    }

    int value = stack[top];

    top--;

    return value;
}

int peek()
{
    if(top == -1)
        return -1;

    return stack[top];
}

int max()
{
    if(top == -1)
        return -1;

    int maximum = stack[0];

    for(int i = 1; i <= top; i++)
    {
        if(stack[i] > maximum)
            maximum = stack[i];
    }

    return maximum;
}

int min()
{
    if(top == -1)
        return -1;

    return minStack[top];
}

void display()
{
    if(top == -1)
    {
        printf("Stack is Empty\n");
        return;
    }

    printf("Stack elements: ");

    for(int i = top; i >= 0; i--)
        printf("%d ", stack[i]);

    printf("\n");

    printf("Max element %d\n", max());
    printf("Min element %d\n", min());
}

int main()
{
    int ch, val;

    while(1)
    {
        printf("\n--- CHOOSE ---\n");
        printf("1. Push into stack\n");
        printf("2. Top from stack\n");
        printf("3. Pop from stack\n");
        printf("4. Maximum element of stack\n");
        printf("5. Minimum element of stack\n");
        printf("6. Display\n");
        printf("7. Exit\n");

        scanf("%d", &ch);

        switch(ch)
        {
            case 1:

                printf("Enter value to insert: ");
                scanf("%d", &val);

                push(val);

                break;

            case 2:

                printf("Top element = %d\n", peek());

                break;

            case 3:

                val = pop();

                if(val != -1)
                    printf("Popped element = %d\n", val);

                break;

            case 4:

                if(top == -1)
                    printf("Stack is empty\n");
                else
                    printf("Max element of stack = %d\n", max());

                break;

            case 5:

                if(top == -1)
                    printf("Stack is empty\n");
                else
                    printf("Min element of stack = %d\n", min());

                break;

            case 6:

                display();

                break;

            case 7:

                return 0;

            default:

                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}