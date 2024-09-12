#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    // sizeof(short)=2, sizeof(double)=8,
    // sizeof(double *)=4, sizeof(short *)=4
    short n = 100;
    short *ptr1 = &n;
    double *ptr2 = (double *)&n;
    printf("%p %p %p %p\n", ptr1, ptr2, ptr1 + 1, ptr2 + 1);
    printf("%p\n", &n);
    printf("%p %p %p %p\n", ptr1, ptr2, ptr1 + 1, ptr2 + 1);
    return 0;
}
