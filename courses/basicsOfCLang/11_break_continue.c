#include <stdio.h>

int main()
{
     // break
     printf("This is break:\n");
     for (int i = 0; i <= 5; i++)
     {
          if (i == 3)
               break;
          printf("%d\n", i);
     }

     // continue
     printf("This is continue:\n");
     for (int j = 0; j <= 5; j++)
     {
          if (j == 3)
               continue;
          printf("%d\n", j);
     }

     return 0;
}