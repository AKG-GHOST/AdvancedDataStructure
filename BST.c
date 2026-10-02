#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL, *temp;

void insert(int x)
{
    struct node *p, *p1;

    temp = (struct node *)malloc(sizeof(struct node));

    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;

    if(root == NULL)
    {
        root = temp;
        return;
    }

    p = root;

    while(p != NULL)
    {
        p1 = p;

        if(x < p->data)
            p = p->left;
        else
            p = p->right;
    }

    if(x < p1->data)
        p1->left = temp;
    else
        p1->right = temp;
}

void inorder(struct node *p)
{
    if(p != NULL)
    {
        inorder(p->left);
        printf("%d ", p->data);
        inorder(p->right);
    }
}

void preorder(struct node *p)
{
    if(p != NULL)
    {
        printf("%d ", p->data);
        preorder(p->left);
        preorder(p->right);
    }
}

void postorder(struct node *p)
{
    if(p != NULL)
    {
        postorder(p->left);
        postorder(p->right);
        printf("%d ", p->data);
    }
}

void search(int x)
{
    struct node *temp = root;

    while(temp != NULL)
    {
        if(x == temp->data)
        {
            printf("Element Found\n");
            return;
        }
        else if(x < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }

    printf("Element not Found\n");
}

struct node *deleteNode(struct node *root, int key)
{
    struct node *temp;

    if(root == NULL)
    {
        printf("Element Not Found\n");
        return root;
    }

    if(key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if(key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }

        if(root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }

        if(root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }

        temp = root->right;

        while(temp->left != NULL)
            temp = temp->left;

        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

int main()
{
    int choice, x;

    while(1)
    {
        printf("\n1. Insert\n");
        printf("2. Search\n");
        printf("3. Inorder Traversal\n");
        printf("4. Preorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Delete\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                insert(x);
                break;

            case 2:
                printf("Enter element to search: ");
                scanf("%d", &x);
                search(x);
                break;

            case 3:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 4:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 5:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 6:
                printf("Enter element to delete: ");
                scanf("%d", &x);
                root = deleteNode(root, x);
                break;

            case 7:
                printf("Program Terminated\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}