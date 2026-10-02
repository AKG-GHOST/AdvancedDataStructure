#include <stdio.h>
#include <stdlib.h>

int *queue;
int *rear, *front;

void enqueue(int *queue, int *rear, int *front, int vertex)
{
    if(*rear == 9 - 1)
        return;

    if(*front == -1)
        *front = 0;

    (*rear)++;
    queue[*rear] = vertex;
}

int dequeue(int *queue, int *front, int rear)
{
    if(*front == -1 || *front > rear)
        return -1;

    int vertex = queue[*front];

    (*front)++;

    return vertex;
}

void performBFS(int **adj, int n, int startVertex)
{
    int *visited = (int *)calloc(n, sizeof(int));

    queue = (int *)malloc(n * sizeof(int));

    int front = -1;
    int rear = -1;

    printf("\nBFS Traversal starting from vertex %d: ", startVertex);

    visited[startVertex] = 1;

    enqueue(queue, &rear, &front, startVertex);

    while(front != -1 && front <= rear)
    {
        int currentVertex = dequeue(queue, &front, rear);

        printf("%d ", currentVertex);

        for(int i = 0; i < n; i++)
        {
            if(adj[currentVertex * n + i] && visited[i] == 0)
            {
                visited[i] = 1;
                enqueue(queue, &rear, &front, i);
            }
        }
    }

    printf("\n");

    free(visited);
    free(queue);
}

int main()
{
    int choice, n, src, dest, startVertex;
    int *adj = NULL;

    while(1)
    {
        printf("\nGraph Operations\n");
        printf("1. Create Graph\n");
        printf("2. Perform BFS Traversal\n");
        printf("3. Display Adjacency Matrix\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:

                if(adj != NULL)
                {
                    free(adj);
                    adj = NULL;
                }

                printf("Enter number of vertices: ");
                scanf("%d", &n);

                if(n <= 0)
                {
                    printf("Invalid size\n");
                    break;
                }

                adj = (int *)calloc(n * n, sizeof(int));

                printf("Enter number of edges: ");
                scanf("%d", &src);

                for(int i = 0; i < src; i++)
                {
                    printf("Enter Edge (src dest): ");
                    scanf("%d %d", &src, &dest);

                    if(src >= 0 && src < n && dest >= 0 && dest < n)
                    {
                        adj[src * n + dest] = 1;
                        adj[dest * n + src] = 1;

                        printf("Edge added between %d and %d.\n",
                               src, dest);
                    }
                    else
                    {
                        printf("Out of bounds\n");
                    }
                }

                break;

            case 2:

                if(adj == NULL || n == 0)
                {
                    printf("No graph created\n");
                    break;
                }

                printf("Enter Starting node: ");
                scanf("%d", &startVertex);

                if(startVertex < 0 || startVertex >= n)
                {
                    printf("Invalid starting vertex\n");
                    break;
                }

                performBFS(adj, n, startVertex);

                break;

            case 3:

                if(adj == NULL || n == 0)
                {
                    printf("No graph created\n");
                    break;
                }

                printf("\nAdjacency Matrix\n");

                for(int i = 0; i < n; i++)
                {
                    for(int j = 0; j < n; j++)
                    {
                        printf("%d ", adj[i * n + j]);
                    }

                    printf("\n");
                }

                break;

            case 4:
                printf("Terminated\n");
                free(adj);
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}