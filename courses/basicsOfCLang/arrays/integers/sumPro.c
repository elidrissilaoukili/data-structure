#include <stdio.h>
#include <stdlib.h>

int main()
{
     int sum = 0, product = 1;
     int array[] = {1, 2, 3, 4, 5};
     int size = sizeof(array) / sizeof(array[0]);

     for (int i = 0; i < size; i++)
     {
          sum += array[i];
          product *= array[i];
     }
     printf("Sum = %d\n", sum);
     printf("Product = %d\n", product);

     return 0;
}