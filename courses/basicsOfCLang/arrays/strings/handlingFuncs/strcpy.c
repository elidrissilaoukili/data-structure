#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
     // strcpy()

     char word[] = "live";
     strcpy(word, "love");
     printf("live = %s", word);

     return 0;
}