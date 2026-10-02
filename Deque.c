#include <stdio.h>

#define MAX 100

int deque[MAX];

int front = -1;
int rear = -1;

void insertFront(int value)
{
    if((front == 0 && rear == MAX - 1) ||
       (front == rear + 1))
    {
        printf("Deque is Full\n");
        return;
    }

    if(front == -1)
    {
        front = rear = 0;
    }
    else if(front == 0)
    {
        front = MAX - 1;
    }
    else
    {
        front--;
    }

    deque[front] = value;
}

void insertRear(int value)
{
    if((front == 0 && rear == MAX - 1) ||
       (front == rear + 1))
    {
        printf("Deque is Full\n");
        return;
    }

    if(front == -1)
    {
        front = rear = 0;
    }
    else if(rear == MAX - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }

    deque[rear] = value;
}

void deleteFront()
{
    if(front == -1)
    {
        printf("Deque is Empty\n");
        return;
    }

    printf("Deleted element: %d\n", deque[front]);

    if(front == rear)
    {
        front = rear = -1;
    }
    else if(front == MAX - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}

void deleteRear()
{
    if(front == -1)
    {
        printf("Deque is Empty\n");
        return;
    }

    printf("Deleted element: %d\n", deque[rear]);

    if(front == rear)
    {
        front = rear = -1;
    }
    else if(rear == 0)
    {
        rear = MAX - 1;
    }
    else
    {
        rear--;
    }
}

void display()
{
    if(front == -1)
    {
        printf("Deque is Empty\n");
        return;
    }

    printf("Deque elements: ");

    int i = front;

    while(1)
    {
        printf("%d ", deque[i]);

        if(i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main()
{
    int choice, value;

    while(1)
    {
        printf("\nInsert Front\n");
        printf("Insert Rear\n");
        printf("Delete Front\n");
        printf("Delete Rear\n");
        printf("Display\n");
        printf("Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:

                printf("Enter value: ");
                scanf("%d", &value);

                insertFront(value);

                break;

            case 2:

                printf("Enter value: ");
                scanf("%d", &value);

                insertRear(value);

                break;

            case 3:

                deleteFront();

                break;

            case 4:

                deleteRear();

                break;

            case 5:

                display();

                break;

            case 6:

                return 0;

            default:

                printf("Invalid choice\n");
        }
    }
}