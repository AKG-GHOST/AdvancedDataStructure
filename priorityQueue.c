#include <stdio.h>

#define MAX 5

int queue[MAX];
int rear = -1;

void enqueue(int value, int priority)
{
    if(rear == MAX - 1)
    {
        printf("Queue is Full\n");
        return;
    }

    rear++;

    queue[rear] = value;
}

void deleteHighestPriority()
{
    if(rear == -1)
    {
        printf("Queue is Empty\n");
        return;
    }

    int highest = 0;

    for(int i = 1; i <= rear; i++)
    {
        if(queue[i] > queue[highest])
            highest = i;
    }

    printf("Deleted element: %d\n", queue[highest]);

    for(int i = highest; i < rear; i++)
        queue[i] = queue[i + 1];

    rear--;
}

void display()
{
    if(rear == -1)
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue elements: ");

    for(int i = 0; i <= rear; i++)
        printf("%d ", queue[i]);

    printf("\n");
}

int main()
{
    int ch, value, priority;

    while(1)
    {
        printf("\nEnter choice:\n");
        printf("1. Insert\n");
        printf("2. Delete Highest Priority\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        scanf("%d", &ch);

        switch(ch)
        {
            case 1:

                printf("Enter array value and priority: ");
                scanf("%d %d", &value, &priority);

                enqueue(value, priority);

                break;

            case 2:

                deleteHighestPriority();

                break;

            case 3:

                display();

                break;

            case 4:

                return 0;

            default:

                printf("Invalid choice\n");
        }
    }
}