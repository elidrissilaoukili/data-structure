#include <stdio.h>
#include <stdlib.h>

int main()
{
     /*
          format specifier         data type
          %d or %i                 int
          %f                       float
          %lf                      double
          %c                       char
          %s                       used for string
     */
     int age = 22;
     float point = 2.2;
     double pi = 3.15446;
     char name[] = "name";
     char fullName[30] = "Full name here";

     printf("Age %d\n", age);
     printf("Point %.2f\n", point);
     printf("Pi %lf\n", pi);
     printf("Name %c\n", name[2]);
     printf("Full name %s\n", fullName);

     return 0;
}