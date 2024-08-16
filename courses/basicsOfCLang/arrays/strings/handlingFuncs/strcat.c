#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
     char str1[] = "hello ";
     char str2[] = "world ";
     char str3[] = "to new world!";

     strcat(str1, str2);
     strcat(str1, str3);
     puts(str1);

     return 0;
}