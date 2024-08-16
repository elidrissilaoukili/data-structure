#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
     int temp = *a;
     *a = *b;
     *b = temp;
}

int main()
{
     int a = 4, b = 8;
     printf("a = %d\tb = %d\n", a, b);
     swap(&a, &b);
     printf("a = %d\tb = %d", a, b);

     return 0;
}