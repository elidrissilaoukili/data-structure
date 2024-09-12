#include <stdio.h>

int main()
{
    int tab[] = {4, 3, 2, 1};
    int *i1 = tab + 1;
    int *i2 = tab + 2;
    int a = ++*i1 + *i2++;
    int b = *++i1 + *i2--;

    printf("a = %d | b = %d", a, b);

    return 0;
}