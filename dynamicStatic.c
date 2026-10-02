#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int x)
{
    struct node *temp;

    temp = (struct node *)malloc(sizeof(struct node));

    if(temp == NULL)
    {
        printf("Stack Overflow\n");
        return;
    }

    temp->data = x;
    temp->next = top;
    top = temp;
}

int pop()
{
    if(top == NULL)
    {
        printf("Stack Underflow\n");
        return -1;
    }

    struct node *temp = top;
    int x = temp->data;

    top = top->next;
    free(temp);

    return x;
}

int peek()
{
    if(top == NULL)
    {
        printf("Stack is Empty\n");
        return -1;
    }

    return top->data;
}

void display()
{
    struct node *temp;

    if(top == NULL)
    {
        printf("Stack is Empty\n");
        return;
    }

    printf("Stack elements are: \n");

    temp = top;

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    int ch, x;

    while(1)
    {
        printf("1. push\n");
        printf("2. pop\n");
        printf("3. peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                push(x);
                break;

            case 2:
                x = pop();

                if(x != -1)
                    printf("Popped element = %d\n", x);

                break;

            case 3:
                printf("Peek = %d\n", peek());
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Program Ended.\n");
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}