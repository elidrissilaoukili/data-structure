#include <stdio.h>

// // Quick Sort / Tri rapide
// Best: 𝑂(𝑛log𝑛)
// Average:𝑂(𝑛log⁡𝑛)
// Worst: 𝑂(𝑛^2)

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d | ", arr[i]);
    printf("\n");
}

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

    quickSort(arr, start, index - 1); // Sort the left sub-array
    quickSort(arr, index + 1, end);   // Sort the right sub-array
}

int main()
{
    int arr[] = {5, 1, 5, 8, 15, 51};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, arr_size);

    quickSort(arr, 0, arr_size-1);

    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}

// elidrissi laoukili mohammed
// elidrissilaoukili.netlify.app