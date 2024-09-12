#include <stdio.h>

int main() {
    char *arr[] = {"C", "Pointers", "Are", "Fun"};
    char **ptr = arr;

    *ptr += 1;
    *(ptr + 1) += 2;
    *(ptr + 2) += 3;

    printf("%s, %s, %s\n", *ptr, *(ptr + 1), *(ptr + 2));

    return 0;
}
