#include <stdio.h>
#include <stdlib.h>

int main()
{
     // char array[][30] = {"I", "Love", "Her", "so", "much"};
     // int size = 5;
     // for (int i = 0; i < size; i++)
     // {
     //      printf("%s ", array[i]);
     // }

     int size;
     printf("Size = ");
     scanf("%d", &size);
     char array[size][20];
     printf("Enter the names:\n");
     for (int i = 0; i < size; i++)
     {
          scanf("%s\n", &array[i]);
     }
     for (int i = 0; i < size; i++)
     {
          printf("%s ", array[i]);
     }

     return 0;
}