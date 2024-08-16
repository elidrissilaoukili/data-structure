#include <stdio.h>

// Binary Search: 𝑂(log⁡𝑛)

// // Quick Sort / Tri rapide
// Best: 𝑂(𝑛log𝑛)
// Average:𝑂(𝑛log⁡𝑛)
// Worst: 𝑂(𝑛^2)

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int arr[], int start, int end)
{
    if (start >= end)
        return;

    int pivot = arr[end];
    int index = start;

    for (int i = start; i < end; i++)
    {
        if (arr[i] <= pivot)
        {
            swap(&arr[i], &arr[index]);
            index++;
        }
    }
    swap(&arr[index], &arr[end]);
    quickSort(arr, start, index - 1);
    quickSort(arr, index + 1, end);
}

int binarySearch(int arr[], int low, int high, int x)
{
    if (high >= low)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] < x)
            return binarySearch(arr, mid + 1, high, x);
        if (arr[mid] > x)
            return binarySearch(arr, low, mid - 1, x);
        if (arr[mid] == x)
            return mid;
    }
    return -1;
}

int main()
{
    int arr[] = {5, 1, 5, 8, 15, 51};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, arr_size - 1);

    int x = 1;
    int result = binarySearch(arr, 0, arr_size - 1, x);
    printf("%d found at %d\n", x, result);

    return 0;
}