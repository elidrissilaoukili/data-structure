#include <stdio.h>

int main() {
    int arr[2][2] = {{1, 2}, {3, 4}};
    int *p[] = {arr[0], arr[1]};
    int **q = p;
    
    // Question: What will be the output?
    printf("%d, %d\n", *(*(q+1) + 1), *(*(q) + 1));
    
    return 0;
}
