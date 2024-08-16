#include <stdio.h>
#include <stdlib.h>

int main()
{
     // declaring and initializing array variables

     int array[] = {1, 2, 3, 4, 5};
     int size = sizeof(array) / sizeof(array[0]);
     printf("Size of the array = %d", size);

     // input
     // Enter how elements you want to insert in the array
     int size2, i, j;
     printf("\nSize2: ");
     scanf("%d", &size2);
     int array2[size2];
     // input
     for (i = 0; i < size2; i++)
     {
          scanf("%d", &array2[i]);
     }
     // output
     for (j = 0; j < size2; j++)
     {
          printf("elemnet %d\n", array2[j]);
     }

     return 0;
}