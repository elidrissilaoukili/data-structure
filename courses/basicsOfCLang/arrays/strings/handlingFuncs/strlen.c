#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
     // strlen()
     char name[] = "My name is Muhammed!\n";
     int size = strlen(name);
     printf("Size of the string = %d", size);

     return 0;
}