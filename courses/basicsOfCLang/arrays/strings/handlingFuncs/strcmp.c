#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
     // strcmp()
     char word[] = "live";
     if (strcmp(word, "live") == -1)
          printf("Words not the same!\n");
     else
          printf("Words are the same!\n");

     return 0;
}