#include <stdio.h>
#include <stdlib.h>

int main()
{
     int a[] = {200, 191, 2125, -452, 2, 235, 3000, -555};
     int size = sizeof(a) / sizeof(a[0]);

     int max = 0, min = 0;

     if (size == 1)
          min = max = a[0];
     if (a[0] > a[1])
     {
          max = a[0];
          min = a[1];
     }
     else
     {
          min = a[0];
          max = a[1];
     }

     for (int i = 2; i < size; i++)
     {
          if (a[i] > max)
               max = a[i];
          else if (a[i] < min)
               min = a[i];
     }

     printf("Max = %d\n", max);
     printf("Min = %d\n", min);

     return 0;
}