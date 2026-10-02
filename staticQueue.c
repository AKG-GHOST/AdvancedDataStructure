#include <stdio.h>

#define MAX 5

typedef struct
{
    int data[MAX];
    int front;
    int rear;
} Queue;

int main()
{
    Queue q;
    q.front = -1;
    q.rear = -1;

    int choice = 0;
    int val = 0;

    printf("static queue operations");

    while(choice != 2)
    {
        printf("\n1. Enqueue (Insert)\n");
        printf("2. Dequeue (Delete)\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            if((q.rear + 1) % MAX == q.front)
            {
                printf("Queue Overflow\n");
            }
            else
            {
                printf("Enter value");
                scanf("%d", &val);

                if(q.front == -1)
                    q.front = 0;

                q.rear = (q.rear + 1) % MAX;
                q.data[q.rear] = val;

                printf("%d enqueued.\n", val);
            }
        }
        else if(choice == 2)
        {
            if(q.front == -1)
            {
                printf("Queue Underflow\n");
            }
            else
            {
                printf("Dequeue value: %d\n", q.data[q.front]);

                if(q.front == q.rear)
                {
                    q.front = -1;
                    q.rear = -1;
                }
                else
                {
                    q.front = (q.front + 1) % MAX;
                }
            }
        }
        else if(choice == 3)
        {
            printf("Exited\n");
        }
    }

    return 0;
}