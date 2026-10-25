
#include <stdio.h>
#define MAX 15

int undo[MAX], redo[MAX];
int utop = -1, rtop = -1;
int value = 0;

void perform(void) {
    if (utop == MAX - 1) {
        printf("Undo stack full!\n");
        return;
    }

    undo[++utop] = value;
    rtop = -1;

    printf("Enter new value: ");
    scanf("%d", &value);
}

void undoOp(void) {
    if (utop == -1) {
        printf("Nothing to undo!\n");
        return;
    }

    if (rtop == MAX - 1) {
        printf("Redo stack full!\n");
        return;
    }

    redo[++rtop] = value;
    value = undo[utop--];

    printf("Undo successful!\n");
}

void redoOp(void) {
    if (rtop == -1) {
        printf("Nothing to redo!\n");
        return;
    }

    if (utop == MAX - 1) {
        printf("Undo stack full!\n");
        return;
    }

    undo[++utop] = value;
    value = redo[rtop--];

    printf("Redo successful!\n");
}

int main(void) {
    int ch;

    do {
        printf("\n1. Enter value\n");
        printf("2. Undo\n");
        printf("3. Redo\n");
        printf("4. Display value\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                perform();
                break;
            case 2:
                undoOp();
                break;
            case 3:
                redoOp();
                break;
            case 4:
                printf("Current value: %d\n", value);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (ch != 0);

    return 0;
}
