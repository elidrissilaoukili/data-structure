#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct MyStruct
{
     /* Data */
     int MyNum;
     char MyLetter;
}frstStruct;

int main()
{
     frstStruct s1, s2, s3, s4;
     s1.MyNum = 15;
     s1.MyLetter = 'M';

     s2.MyNum = 4542;
     s2.MyLetter = 'N';

     s3.MyNum = 45;
     s3.MyLetter = 'L';

     s4.MyNum = 6;
     s4.MyLetter = 'J';

     printf("MyNum = %d\n", s1.MyNum);
     printf("MyLetter = %c\n\n", s1.MyLetter);

     printf("MyNum = %d\n", s2.MyNum);
     printf("MyLetter = %c\n\n", s2.MyLetter);

     printf("MyNum = %d\n", s3.MyNum);
     printf("MyLetter = %c\n\n", s3.MyLetter);

     printf("MyNum = %d\n", s4.MyNum);
     printf("MyLetter = %c\n\n", s4.MyLetter);

     return 0;
}