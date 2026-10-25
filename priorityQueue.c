#include <stdio.h>
#define MAX 100

int a[MAX], pr[MAX];
int r = -1, f = 0, i, max_pr;

/* Function to insert an element */
void enqueue(int x, int p)
{
    if (r == MAX - 1)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        r++;
        a[r] = x;
        pr[r] = p;
    }
}

/* Function to delete highest priority element */
void dequeue()
{
    if (r < f)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        max_pr = f;

        for (i = f + 1; i <= r; i++)
        {
            if (pr[i] > pr[max_pr])
            {
                max_pr = i;
            }
        }

        printf("Deleted element is %d\n", a[max_pr]);

        for (i = max_pr; i < r; i++)
        {
            a[i] = a[i + 1];
            pr[i] = pr[i + 1];
        }

        r--;
    }
}

/* Function to find highest priority element */
void peek()
{
    if (r < f)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        max_pr = f;

        for (i = f + 1; i <= r; i++)
        {
            if (pr[i] > pr[max_pr])
            {
                max_pr = i;
            }
        }

        printf("Max priority element is %d\n", a[max_pr]);
    }
}

/* Function to display queue */
void display()
{
    if (r < f)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        for (i = f; i <= r; i++)
        {
            printf("%d -> %d\n", pr[i], a[i]);
        }
    }
}

/* Main function */
int main()
{
    int ch, val, pr;

    printf("Enter choice: ");
    scanf("%d", &ch);

    switch (ch)
    {
        case 1:
            printf("Enter array value and priority:\n");
            scanf("%d %d", &val, &pr);
            enqueue(val, pr);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            peek();
            break;

        case 4:
            display();
            break;

        default:
            printf("Invalid choice! Please try again.\n");
    }

    return 0;
}