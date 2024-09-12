#include <stdio.h>

int main() {
    int a = 100, b = 200;
    int *p1 = &a, *p2 = &b;
    int **q = &p1;
    
    // Question: What will be the output after these statements?
    *q = p2;        // p1 now points to b
    **q = **q + 1;  // *p1 (which is b) is incremented
    
    printf("%d, %d\n", *p1, *p2);

    return 0;
}
