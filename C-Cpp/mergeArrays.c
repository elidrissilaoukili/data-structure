#include <stdio.h>

int main()
{
    int a1[] = {2, 5, 9, 7, 6};
    int a2[] = {-5, 0, 8, 9, 10, 150, 1};

    int s1 = sizeof(a1) / sizeof(a1[0]);
    int s2 = sizeof(a2) / sizeof(a2[0]);

    int s;
    int a[s];

    int i = 0, j = 0, k = 0;
    while (a1[i] < a2[i])
    {
        a[k] = a1[i];
        k++;
        i++;
        printf("%d", a[k]);
    }

    return 0;
}