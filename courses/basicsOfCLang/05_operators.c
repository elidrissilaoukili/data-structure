#include <stdio.h>

int main()
{
     /*
          Operators
               Addition +
               Substraction –
               Multiplication *
               Division /
               Modulus %
               Increment ++
               Decrement –
     */
     int a, b;
     a = 2;
     b = 3;
     int Addition = a + b;
     int Substraction = b - a;
     int Multiplication = a * b;
     float Division = b / a;
     float Modulus = b % a;
     int Increment = a++;
     int Decrement = b--;

     printf("\na + b = %d", Addition);
     printf("\nb - a = %d", Substraction);
     printf("\nb * a = %d", Multiplication);
     printf("\nb / a = %f", Division);
     printf("\nb moduls a = %f", Modulus);
     printf("\na + 1 = %d", a++);
     printf("\nb - 1 = %d", b--);

     return 0;
}