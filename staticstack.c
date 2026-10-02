#include <stdio.h>

#define MAX 5

typedef struct
{
    int data[MAX];
    int top;
} Stack;

int main()
{
    Stack s;
    s.top = -1;

    int choice = 0;
    int val = 0;

    printf("choose stack operations:");

    while(choice != 3)
    {
        printf("\n1- Push \n2- Pop\n3- Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            if(s.top == MAX-1)
            {
                printf("Stack Overflow\n");
            }
            else
            {
                printf("Enter value: ");
                scanf("%d", &val);
                s.data[++s.top] = val;
                printf("%d pushed\n", val);
            }
        }
        else if(choice == 2)
        {
            if(s.top == -1)
            {
                printf("Stack Underflow\n");
            }
            else
            {
                printf("popped value : %d\n", s.data[s.top]);
                s.top--;
            }
        }
        else if(choice == 3)
        {
            printf("Exiting\n");
        }
    }

    return 0;
}