#include <stdio.h>

int RecursiveSearch(int arr[], int low, int high, int target)
{
    if(low > high || target < arr[low] || target > arr[high])
        return -1;

    int pos = low +
        ((double)(high - low) /
        (arr[high] - arr[low])) *
        (target - arr[low]);

    if(arr[pos] == target)
        return pos;

    if(arr[pos] < target)
        return RecursiveSearch(arr, pos + 1, high, target);

    if(arr[pos] > target)
        return RecursiveSearch(arr, low, pos - 1, target);

    return -1;
}

int main()
{
    int n;

    printf("Enter size of Array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter sorted elements in array: ");

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int target;

    printf("Enter element to search: ");
    scanf("%d", &target);

    int result = RecursiveSearch(arr, 0, n - 1, target);

    if(result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}