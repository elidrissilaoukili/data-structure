#include <stdio.h>

// Linear Search: 𝑂(𝑛)

int main()
{
    int arr[] = {5, 3, 2, 9, 6};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    int search = 9;
    int result = -1; 

    // Perform linear search
    for (int i = 0; i < arr_size; i++) {
        if (arr[i] == search) {
            result = i;
            break; 
        }
    }

    if (result != -1)
        printf("Search Successful, result = %d\n", result);
    else
        printf("Search is not Successful\n");

    return 0;
}
