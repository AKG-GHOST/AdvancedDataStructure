#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};

struct node * head = NULL, *temp, *newnode;

void insbeg(int x){
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = head;
    head = newnode;
}

void inspos(int x, int pos){
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;

    if(pos == 1 || head == NULL){
        newnode->next = head;
        head = newnode;
        return;
    }

    temp = head;
    for(int i = 1; i < pos-1 && temp != NULL; i++)
        temp = temp->next;

    if(temp == NULL){
        printf("Position out of range.\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

void insend(int x){
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;

    if(head == NULL){
        head = newnode;
        return;
    }

    temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
}

void delbeg(){
    if(head == NULL){
        printf("List is empty.\n");
        return;
    }

    temp = head;
    head = head->next;
    free(temp);
}

void delpos(int pos){
    struct node *prev = NULL;

    if(head == NULL){
        printf("List is empty.\n");
        return;
    }

    if(pos == 1){
        temp = head;
        head = head->next;
        free(temp);
        return;
    }

    temp = head;
    for(int i = 1; i < pos && temp != NULL; i++){
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL){
        printf("Position out of range.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void delend(){
    struct node *prev = NULL;

    if(head == NULL){
        printf("List is empty.\n");
        return;
    }

    temp = head;
    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }

    if(prev == NULL)
        head = NULL;
    else
        prev->next = NULL;

    free(temp);
}

void display(){
    if(head == NULL){
        printf("List is empty.\n");
        return;
    }

    temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    int choice, value, pos;

    while(1){
        printf("\n1. Insert at Beginning\n2. Insert at Position\n3. Insert at End\n4. Delete from Beginning\n5. Delete from Position\n6. Delete from End\n7. Display\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insbeg(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &pos);
                inspos(value, pos);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                insend(value);
                break;

            case 4:
                delbeg();
                break;

            case 5:
                printf("Enter position: ");
                scanf("%d", &pos);
                delpos(pos);
                break;

            case 6:
                delend();
                break;

            case 7:
                display();
                break;

            case 8:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}