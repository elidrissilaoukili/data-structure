#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct classe
{
     int mark;
     char name[20];
} classe;

int main()
{
     int i, j, n_students;
     printf("Students = ");
     scanf("%d", &n_students);

     classe student[n_students];

     for (i = 0; i < n_students; i++)
     {
          printf("Enter the name for studnet %d: ", i + 1);
          scanf("%s", student[i].name);
          printf("Enter the mark for studnet %d: ", i + 1);
          scanf("%d", &student[i].mark);
     }
     printf("\n\n");
     printf("Name\t\t|\t\tNotes\t\t|Marks\n--------------------------------------------------------------\n");
     for (j = 0; j < n_students; j++)
     {
          if (student[j].mark > 12)
          {
               printf("%d|| %s\t|\t Greate you are legend!!\t|\t%d\n", j + 1, student[j].name, student[j].mark);
               continue;
          }
          if (student[j].mark < 10)
               printf("%d|| %s\t|\t You are going to fail!!!\t|\t%d\n", j + 1, student[j].name, student[j].mark);
          else
               printf("%d|| %s\t|\t Do more effort next time\t|\t%d\n", j + 1, student[j].name, student[j].mark);
     }

     return 0;
}

/*
get students in a class
get their names
get their marks

if mark > 12
     msg()
if mark < 10
     msg()
else
     msg()
*/