#include <stdio.h>

int main() {
    int x = 10;
    int *p = &x;
    int **q = &p;
    
    // Question: What will be the output?
    **q = **q + 1;
    *p = *p + 2;
    printf("%d\n", x);

    return 0;
}
