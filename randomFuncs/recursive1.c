#include <stdio.h>

int f(int n)
{
    if (n == 0)
        return 0;
    f(n - 1);
    printf("%d", n);
    f(n - 1);
}

int main()
{

    printf("%d", f(4));
}