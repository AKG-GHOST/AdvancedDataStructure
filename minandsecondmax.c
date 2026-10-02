#include <stdio.h>

int minElement(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

int secondMax(int arr[], int n) {
    int max1 = arr[0];
    int max2 = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];
        } else if (arr[i] > max2 && arr[i] != max1) {
            max2 = arr[i];
        }
    }

    return max2;
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Minimum element: %d\n", minElement(arr, n));
    printf("Second maximum element: %d\n", secondMax(arr, n));

    return 0;
}
