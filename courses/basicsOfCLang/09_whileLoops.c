#include <stdio.h>
int main()
{
     int x = 7;
     while (x < 10)
     {
          printf("This is a loop!\n");
          x++;
     }
     printf("\n\n\n");
     int y = 3;
     do
     {
          printf("This is a loop!\n");
          y++;
     } while (y < 10);

     return 0;
}