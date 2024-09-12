#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr1, *ptr2;
    ptr1 = (int *)malloc(sizeof(int));
    ptr2 = (int *)malloc(sizeof(int));

    *ptr1 = 10;
    *ptr2 = 20;
    
    *ptr2 = *ptr1 + *ptr2;  // *ptr2 becomes 30
    free(ptr1);
    
    *ptr1 = *ptr2 + 5;  // This line is illegal; ptr1 is already freed.

    printf("%d, %d\n", *ptr1, *ptr2);
    
    free(ptr2);
    return 0;
}
