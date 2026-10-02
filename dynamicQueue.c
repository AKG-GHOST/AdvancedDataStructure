#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

void enqueue(int x)
{
    struct node *temp;

    temp = (struct node *)malloc(sizeof(struct node));

    if(temp == NULL)
    {
        printf("Queue Overflow\n");
        return;
    }

    temp->data = x;
    temp->next = NULL;

    if(front == NULL)
    {
        front = rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }

    printf("%d inserted into queue\n", x);
}

int dequeue()
{
    if(front == NULL)
    {
        printf("Queue Underflow\n");
        return -1;
    }

    struct node *temp = front;
    int x = temp->data;

    front = front->next;

    if(front == NULL)
        rear = NULL;

    free(temp);

    return x;
}

int main()
{
    int choice, value;

    while(1)
    {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                value = dequeue();

                if(value != -1)
                    printf("Dequeued value = %d\n", value);

                break;

            case 3:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}