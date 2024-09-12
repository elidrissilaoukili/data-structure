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
    int *p = t2, *q = t1;
    f(&p, q);
    printf("%d %d %d %d", t1[0], t1[1], t2[0], t2[1]);
}