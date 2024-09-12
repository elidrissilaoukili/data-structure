#include <stdio.h>
int main()
{
    int m = 0x328,
        n = -m;
    printf("%x\n",  n);
    printf("%x %x %x\n", m & n, m | n, m ^ n);
    return 0;
}