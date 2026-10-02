#include <stdio.h>

void rotateArray(int arr[], int n, int pos) {
    int temp[pos];

    for (int i = 0; i < pos; i++)
        temp[i] = arr[n - pos + i];

    for (int i = n - 1; i >= pos; i--)
        arr[i] = arr[i - pos];

    for (int i = 0; i < pos; i++)
        arr[i] = temp[i];
}

int main() {
    int n, pos;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter the rotation position: ");
    scanf("%d", &pos);

    pos = pos % n;
    rotateArray(arr, n, pos);

    printf("Rotated array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
