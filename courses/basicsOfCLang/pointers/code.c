#include <stdio.h>
#include <stdlib.h>

int main()
{
     int array[] = {13, 24, 35, 46, 57, 68, 79, 90, 91};
     int *p;
     p = array;

     printf("*p + 3 = %d\n", *p + 3);       // 16
     printf("*(p + 3) = %d\n\n", *(p + 3)); // 46

     // The address of pointer behind the pointer p (rarely used).
     printf("&p + 2 = %d\n", &p + 2);
     printf("&array[2] = %d\n\n", &array[2]);

     // the address of the component array[1].
     printf("&array[5] - 4 = %d\n", &array[5] - 4);
     printf("&array[1] = %d\n\n", &array[1]);

     // the address of the component array[4].
     printf("array + 4 = %d\n", array + 4);
     printf("&array[4] = %d\n\n", &array[4]);

     // 8 { value (index 8) }
     printf("&array[8] - p = %d\n\n", &array[8] - p);

     // the address at the component array[3]
     printf("p + (*p - 10) = %d\n", p + (*p - 10));
     printf("&array[3] = %d\n", &array[3]);
     printf("array[3] = %d\n\n", array[3]);

     printf("*(p + *(p + 8) - array[7]) = %d\n", *(p + *(p + 8) - array[7])); // 24
     /*
     *(p + *(p + 8) - array[7]) = *(p + *(p + 8) - 90)
                                = *(p + 91 - 90)
                                = *(p + 1)
                                = 24
     */

     printf("*p = %d\n", *p); // 13

     return 0;
}