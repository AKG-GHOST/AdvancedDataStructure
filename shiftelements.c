#include <stdio.h>

void shiftEvenOdd(int arr[], int n) {
    int temp[n];
    int index = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0)
            temp[index++] = arr[i];
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0)
            temp[index++] = arr[i];
    }

    for (int i = 0; i < n; i++)
        arr[i] = temp[i];
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    shiftEvenOdd(arr, n);

    printf("Array after shifting even elements to front and odd to end:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
