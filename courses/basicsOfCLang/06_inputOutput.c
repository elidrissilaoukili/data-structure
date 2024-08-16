#include <stdio.h>

int main()
{

     // method 1
     char str[20];
     printf("Enter string: ");
     scanf("%[^\n]", &str);
     printf("%s", str);

     // method 2
     char text[20];
     printf("Enter text:\n");
     gets(text);
     printf("\nText:\n%s", text);

     //-------------------------------------------------

     int age;
     char name[20];

     // for string
     printf("Enter your name: ");
     scanf("%s", &name);

     // for integers
     printf("Enter your age: ");
     scanf("%d", &age);

     printf("Your name is %s, and you are %d.", name, age);

     return 0;
}