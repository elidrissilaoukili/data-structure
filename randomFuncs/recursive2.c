
#include <stdio.h>

int f(int n)
{
    if (n <= 1)
        return 0;
    f(n / 2);
    f(n / 2);
    printf("%d", n);
}

int main()
{
    // printf("%d", f(4));
    int n = 4;
    if (n <= 1)
        return 0;
    f(n / 2);
    f(n / 2);
    f(n / 2);
    printf("%d", n);
}