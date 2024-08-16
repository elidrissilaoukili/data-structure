#include "functions.h"

int main()
{
     int choice, choice2, n_node, i, value, pos;
     char c;
     do
     {
          printf("\nTYPE 01 ---> Inserting\n");
          printf("TYPE 02 ---> Deleting\n");
          printf("TYPE 03 ---> Display\n");
          printf("TYPE 04 ---> Display reverse order.\n");
          printf("Choice = ");
          choice = get_data(choice);
          switch (choice)
          {
          case 1:
               inserting_choices();
               choice2 = get_data(choice2);
               printf("\nEnter how many nodes you want to create: ");
               n_node = get_data(n_node);
               i = 0;
               printf("\nEnter data:\n");
               while (i < n_node)
               {
                    switch (choice2)
                    {
                    case 1:
                         value = get_data(value);
                         insertAtBeginnig(value);
                         break;
                    case 2:
                         value = get_data(value);
                         insertAtEnd(value);
                         break;
                    case 3:
                         if (n_node > 1)
                              printf("You can't insert more than one node.\n");
                         value = get_data(value);
                         pos = get_data(pos);
                         insertAtPosition(value, pos);
                         break;
                    default:
                         printf("Inavlid choice!! Try again.\n");
                         break;
                    }
                    i++;
               }
               break;
          case 2:
               deleting_choices();
               choice2 = get_data(choice2);
               switch (choice2)
               {
               case 1:
                    deleteFromBeginnig();
                    break;
               case 2:
                    deleteFromEnd();
                    break;
               case 3:
                    pos = get_data(pos);
                    deleteFromPosition(pos);
                    break;
               default:
                    printf("Inavlid choice!! Try again.\n");
                    break;
               }
               break;
          case 3:
               display();
               break;
          case 4:
               display_reverse();
               break;
          default:
               printf("Invalid choice!\n");
               break;
          }

          display();

          printf("To continue hit  (y/Y) else any letter: ");
          c = getch();
          fflush(stdin);
     } while (c == 'y' || c == 'Y');

     return 0;
}