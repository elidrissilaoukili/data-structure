#include <stdio.h>
void f(int *p, int *q, int *r)
{
    int a, *b;
    b = q;   // 5
    q = r;   // 7
    r = b;   // 5
    a = *p;  // 3
    *p = *q; // 7
    *q = a;  // 3
}
int main()
{
    int x = 3, y = 5, z = 7;
    f(&x, &y, &z);
    printf("%d %d %d", x, y, z);
}