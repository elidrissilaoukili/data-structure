#include <stdio.h>
int t1[] = {2, 3};
int t2[] = {6, 7};
void f(int **p, int *q)
{
    int *r;
    r = *p;
    *p = q;
    q = r;
    (**p)++;
    (*q)++;
}
int main()
{
    int T[] = {10, 23, 15, 32, 9, 61, 2, 90, 95};
    int *p;
    p = T;
    printf("%d", *(p + *(p + 8) - T[7]));
}