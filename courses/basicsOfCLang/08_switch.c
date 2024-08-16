#include <stdio.h>

int main()
{
     int choice;
     printf("click on 1 to display number 11111\n");
     printf("click on 2 to display number 22222\n");
     printf("click on 3 to display number 33333\n");
     printf("Choice: ");
     scanf("%d", &choice);

     switch (choice)
     {
     case 1:
          printf("11111");
          break;
     case 2:
          printf("22222");
          break;
     case 3:
          printf("33333");
          break;
     default:
          printf("this number not found!\n");
          break;
     }

     return 0;
}