#include <stdio.h>

// Un = 2(Un-1 + Un-2)

int main()
{
    int U1 = 1, U2 = 2, Un;
    int n = 5;
    for (int i = 3; i <= n; i++)
    {
        Un = 2 * (U2 + U1);
        U1 = U2;
        U2 = Un;
        printf("U%d = %d\n",i, Un);
    }
    return 0;
}