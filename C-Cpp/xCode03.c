#include <stdio.h>
int main()
{
    int x = 8, n;
    n = (x++, --x, ++x, x--);
    printf("%d %d\n", n, x);
    return 0;
}