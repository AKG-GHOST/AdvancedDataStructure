#include <stdio.h>

int RecursiveBinarySearch(int arr[], int low, int high, int target)
{
    if(low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if(arr[mid] == target)
        return mid;

    if(arr[mid] > target)
        return RecursiveBinarySearch(arr, low, mid - 1, target);

    return RecursiveBinarySearch(arr, mid + 1, high, target);
}

int main()
{
    int n;

    printf("Enter array size: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter sorted elements in array: ");

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int target;

    printf("Enter element to search: ");
    scanf("%d", &target);

    int result = RecursiveBinarySearch(arr, 0, n - 1, target);

    if(result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}