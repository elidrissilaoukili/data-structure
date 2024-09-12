#include <stdio.h>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int *p1 = arr;
    int **p2 = &p1;
    int ***p3 = &p2;

    *p1 += 2;
    **p2 += 3;
    ***p3 += 4;

    p1++;
    *p1 += 5;

    printf("%d, %d, %d, %d, %d\n", arr[0], arr[1], arr[2], arr[3], arr[4]);

    return 0;
}
