#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = (int *)malloc(3 * sizeof(int));
    for (int i = 0; i < 3; i++) {
        arr[i] = i * 10;  // arr = {0, 10, 20}
    }
    
    int *p = arr + 1;  // p points to arr[1]
    *p = *(arr + 2) + 5;  // arr[1] = arr[2] + 5 = 20 + 5 = 25
    
    // Question: What will be the output?
    printf("%d, %d, %d\n", arr[0], arr[1], arr[2]);

    free(arr);
    return 0;
}
