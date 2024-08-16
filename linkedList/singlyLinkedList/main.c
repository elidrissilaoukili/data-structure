#include "functions.h"

int main()
{
     int value, pos, i, n_node, choice, choice2;
     char c;
     do
     {
          printf("\nTYPE 01 ---> Inserting\n");
          printf("TYPE 02 ---> Deleting\n");
          printf("TYPE 03 ---> Display reverse order\n");
          printf("Your Choice is: ");
          choice2 = get_data(choice2);
          switch (choice2)
          {
          case 1:
               i = 0;
               printf("\n\nEnter number of nodes: ");
               n_node = get_data(n_node);
               insrting_choices();
               choice = get_data(choice);
               printf("\nEnter the values in one line:\n");
               while (i < n_node)
               {
                    switch (choice)
                    {
                    case 1:
                         value = get_data(value);
                         insertAtBeginning(value);
                         break;
                    case 2:
                         value = get_data(value);
                         insertAtEnd(value);
                         break;
                    case 3:
                         if (n_node > 1)
                         {
                              printf("number of nodes must be equal one in this case.\n");
                              return main();
                         }
                         value = get_data(value);
                         pos = get_data(pos);
                         insertAtPosition(value, pos);
                         break;
                    default:
                         printf("invalid choice!\n");
                         break;
                    }
                    i++;
               }
               break;
          case 2:
               deleteing_choices();
               choice = get_data(choice);
               switch (choice)
               {
               case 1:
                    deleteAtBeginning();
                    break;
               case 2:
                    deleteAtEnd();
                    break;
               case 3:
                    pos = get_data(pos);
                    deleteAtPosition(pos);
                    break;
               }
               break;
          case 3:
               printf("List in reverse order: ");
               listInReverseOrder();
               display();
               break;
          default:
               printf("Invalid choice.\n");
               break;
          }
          display();

          printf("\nif you want to continues reclick on (y/Y), else any letter: ");
          c = getch();
          fflush(stdin);
     } while (c == 'y' || c == 'Y');

     return 0;
}